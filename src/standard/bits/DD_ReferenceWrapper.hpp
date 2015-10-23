//	DDCPP/standard/bits/DD_ReferenceWrapper.hpp
#ifndef DD_REFERENCE_WRAPPER_HPP_
#	define DD_REFERENCE_WRAPPER_HPP_ 1



#	include "DD_address_of.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct ReferenceWrapper {
	public:
	DD_ALIAS(ThisType, ReferenceWrapper<ObjectT_>);
	DD_ALIAS(Type, ObjectT_);

	public:
	DD_VALUE_TYPE_NESTED(Type)


	private:
	PointerType m_pointer_;


	public:
	DD_DELETE_DEFAULT_CONSTRUCTOR(ReferenceWrapper)

#	if __cplusplus >= 201103L
	public:
	constexpr ReferenceWrapper(ThisType const& origin_) = default;

#	endif
	public:
	DD_DELETE_MOVE_CONSTRUCTOR(ReferenceWrapper);


	public:
	DD_CONSTEXPR ReferenceWrapper(Type& object_) DD_NOEXCEPT : m_pointer_(address_of(object_)) {
	}

#	if __cplusplus >= 201103L
	public:
	ReferenceWrapper(Type&& object_) = delete;

#	endif

	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return m_pointer_;
	}

	public:
	ReferenceType DD_CONSTEXPR get_reference() const DD_NOEXCEPT {
		return *get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
	public:
	DD_CONSTEXPR operator ReferenceType() const DD_NOEXCEPT {
		return get_reference();
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::ReferenceType;



DD_END_



#endif
