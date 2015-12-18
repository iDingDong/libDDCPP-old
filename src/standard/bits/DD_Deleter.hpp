//	DDCPP/standard/bits/DD_Deleter.hpp
#ifndef DD_DELETER_HPP_INCLUDED_
#	define DD_DELETER_HPP_INCLUDED_ 1



#	include "DD_Tags.hpp"
#	include "DD_Value.hpp"
#	include "DD_NeedInstance.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_Allocator.hpp"
#	include "DD_destruct.hpp"



DD_DETAIL_BEGIN_
template <typename AllocatorT_, ValidityType need_instance_c_>
class Deleter_ {
	public:
	DD_ALIAS(ThisType, Deleter_<AllocatorT_ DD_COMMA need_instance_c_>);
	DD_ALIAS(AllocatorType, AllocatorT_);

	public:
	DD_VALUE_TYPE_NESTED(DD_MODIFY_TRAIT(Value, AllocatorType))


#	if __cplusplus >= 201103L
	public:
	constexpr Deleter_() = default;

	public:
	constexpr Deleter_(ThisType const& origin_) = default;

	public:
	constexpr Deleter_(ThisType&& origin_) = default;


#	endif
	public:
	ProcessType operator ()(PointerType pointer_) DD_NOEXCEPT {
		destroy(pointer_);
	}


	public:
	static ProcessType destroy(PointerType pointer_) DD_NOEXCEPT {
		if (pointer_) {
			::DD::destruct(pointer_);
			AllocatorType::deallocate(pointer_, 1);
		}
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



template <typename AllocatorT_>
class Deleter_<AllocatorT_, true> {
	public:
	DD_ALIAS(ThisType, Deleter_<AllocatorT_ DD_COMMA true>);
	DD_ALIAS(AllocatorType, AllocatorT_);

	public:
	DD_VALUE_TYPE_NESTED(DD_MODIFY_TRAIT(Value, AllocatorType))


	private:
	AllocatorType m_allocator_ DD_IN_CLASS_INITIALIZE(AllocatorType());


#	if __cplusplus >= 201103L
	public:
	constexpr Deleter_() = default;

	public:
	constexpr Deleter_(ThisType const& origin_) = default;

	public:
	constexpr Deleter_(ThisType&& origin_) = default;
#	else
	public:
	Deleter_() : m_allocator_() {
	};
#	endif

	public:
	template <typename AllocatorT__>
#	if __cplusplus >= 201103L
	constexpr Deleter_(AllocatorT__&& allocator___) noexcept(
		noexcept(AllocatorType(forward<AllocatorT__>(allocator___)))
	) : m_allocator_(forward<AllocatorT__>(allocator___)) {
	}
#	else
	Deleter_(AllocatorT__ const& allocator___) : m_allocator_(allocator___) {
	}
#	endif


	public:
	ProcessType operator ()(PointerType pointer_) DD_NOEXCEPT {
		destroy(pointer_);
	}


	public:
	ProcessType destroy(PointerType pointer_) DD_NOEXCEPT {
		if (pointer_) {
			::DD::destruct(pointer_);
			m_allocator_.deallocate(pointer_, 1);
		}
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



#	if __cplusplus >= 201103L
template <typename AllocatorT_ = Allocator<void>>
#	else
template <typename AllocatorT_ = Allocator<void> >
#	endif
class Deleter : Deleter_<AllocatorT_, NeedInstance<AllocatorT_>::value> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Deleter;



DD_END_



#endif
