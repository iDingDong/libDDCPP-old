//	DDCPP/standard/bits/DD_ObserverPointer.hpp
#ifndef DD_OBSERVER_POINTER_HPP_INCLUDED_
#	define DD_OBSERVER_POINTER_HPP_INCLUDED_



#	include "DD_ValueTypeNested.hpp"
#	include "DD_Comparable.hpp"
#	include "DD_get_pointer.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct ObserverPointer : Comparable<ValueT_> {
	public:
	DD_ALIAS(ThisType, ObserverPointer);
	DD_VALUE_TYPE_NESTED(ValueT_)


	public:
	PointerType m_pointer_ DD_IN_CLASS_INITIALIZE(PointerType());


#	if __cplusplus >= 201103L
	public:
	constexpr ObserverPointer() = default;

	public:
	constexpr ObserverPointer(ThisType const& origin_) = default;

	public:
	constexpr ObserverPointer(ThisType&& origin_) = default;
#	else
	public:
	ObserverPointer() throw() : m_pointer_() {
	}
#	endif

	public:
	template <typename PointerT__>
	DD_CONSTEXPR ObserverPointer(
		PointerT__ const& pointer___
	) : m_pointer_(::DD::get_pointer(pointer___)) {
	}


#	if __cplusplus >= 201103L
	public:
	~ObserverPointer() = default;


#	endif
	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return m_pointer_;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;

#	endif
	public:
	template <typename PointerT__>
	ThisType& operator =(PointerT__ const& pointer___) DD_NOEXCEPT {
		m_pointer_ = ::DD::get_pointer(pointer___);
	}


	public:
	ReferenceType DD_CONSTEXPR operator *() const DD_NOEXCEPT {
		return *get_pointer();
	}


	public:
	PointerType DD_CONSTEXPR operator ->() const DD_NOEXCEPT {
		return get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit constexpr operator PointerType() const DD_NOEXCEPT {
		return get_pointer();
	}


#	endif
};



template <typename ValueT_>
inline ValidityType DD_CONSTEXPR operator ==(
	ObserverPointer<ValueT_> const& observer_pointer_1_,
	ObserverPointer<ValueT_> const& observer_pointer_2_
) DD_NOEXCEPT {
	return observer_pointer_1_.get_pointer() == observer_pointer_2_.get_pointer();
}


template <typename ValueT_>
inline ValidityType DD_CONSTEXPR operator <(
	ObserverPointer<ValueT_> const& observer_pointer_1_,
	ObserverPointer<ValueT_> const& observer_pointer_2_
) DD_NOEXCEPT {
	return observer_pointer_1_.get_pointer() < observer_pointer_2_.get_pointer();
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::ObserverPointer;



DD_END_



#endif
