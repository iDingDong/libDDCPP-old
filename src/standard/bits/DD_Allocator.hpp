//	DDCPP/standard/bits/DD_Allocator.hpp
#ifndef DD_ALLOCATOR_HPP_INCLUDED_
#	define DD_ALLOCATOR_HPP_INCLUDED_ 1



#	include <cstdlib>
#	include <new>

#	include "DD_ValueTypeNested.hpp"
#	include "DD_IntegralConstant.hpp"
#	include "DD_AllocationFailure.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsTriviallyDestructible.hpp"
#	endif
#	include "DD_debugger_definitions.hpp"
#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_ = void>
class Allocator;



template <>
class Allocator<void> {
	public:
	DD_ALIAS(ThisType, Allocator<void>);
	DD_ALIAS(ValueType, void);

	public:
	DD_ALIAS(PointerType, ValueType*);
	DD_ALIAS(SizeType, DD::SizeType);

	public:
	DD_ALIAS(Basic, Allocator<void>);
	DD_ALIAS(NeedInstance, FalseType);


	public:
	static PointerType allocate(SizeType size_) {
		try {
			return ::operator new(size_);
		} catch (std::bad_alloc& error_) {
			throw AllocationFailure("'DD::Allocator' Failed to allocate.");
		}
	}


	public:
	static ProcessType deallocate(PointerType pointer_) DD_NOEXCEPT {
		::operator delete(pointer_);
	}


	public:
	static ProcessType deallocate(PointerType pointer_, SizeType size_) DD_NOEXCEPT {
		::operator delete(pointer_);
	}


	public:
#	if __cplusplus >= 201103L
	template <typename ValueT__, typename... ArgumentsT__>
	static ProcessType construct(ValueT__* pointer_, ArgumentsT__&&... arguments___) noexcept(
		noexcept(::DD::construct(pointer_, forward<ArgumentsT__>(arguments___)...))
	) {
		::DD::construct(pointer_, forward<ArgumentsT__>(arguments___)...);
	}
#	else
	template <typename ValueT__>
	static ProcessType construct(ValueT__* pointer_, ValueT__ const& value___) {
		::DD::construct(pointer_, value__);
	}
#	endif


	public:
	template <typename ValueT__>
	static ProcessType destruct(ValueT__* pointer_) DD_NOEXCEPT {
		::DD::destruct(pointer_);
	}


	public:
	template <typename ValueT__>
	static ProcessType destruct(ValueT__* begin_, ValueT__* end_) DD_NOEXCEPT {
		::DD::destruct(begin_, end_);
	}


};



template <typename ValueT_>
class Allocator : Allocator<void> {
	public:
	DD_ALIAS(ThisType, Allocator<ValueT_>);
	DD_ALIAS(SuperType, Allocator<void>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	DD_ALIAS(LengthType, DD::LengthType);
	DD_ALIAS(SizeType, DD::SizeType);

	public:
	DD_ALIAS(Basic, SuperType);
	DD_ALIAS(NeedInstance, FalseType);

	public:
	static SizeType DD_CONSTANT unit = sizeof(ValueT_);


	public:
	static PointerType allocate(LengthType length_) {
		return Basic::allocate(unit * length_);
	}


	public:
	static ProcessType deallocate(PointerType pointer_) DD_NOEXCEPT {
		Basic::deallocate(pointer_);
	}


	public:
	static ProcessType deallocate(PointerType pointer_, LengthType length_) DD_NOEXCEPT {
		Basic::deallocate(pointer_, unit * length_);
	}


	public:
#	if __cplusplus >= 201103L
	template <typename... ArgumentsT__>
	static ProcessType construct(PointerType pointer_, ArgumentsT__&&... arguments___) noexcept(
		noexcept(Basic::construct(pointer_, forward<ArgumentsT__>(arguments___)...))
	) {
		Basic::construct(pointer_, forward<ArgumentsT__>(arguments___)...);
	}
#	else
	template <typename ValueT__>
	static ProcessType construct(PointerType pointer_, ValueT__ const& value___) {
		Basic::construct(pointer_, value___);
	}
#	endif


	public:
	static ProcessType destruct(PointerType pointer_) DD_NOEXCEPT {
		Basic::destruct(pointer_);
	}


	public:
	static ProcessType destruct(PointerType begin_, PointerType end_) DD_NOEXCEPT {
		Basic::destruct(begin_, end_);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Allocator;



DD_END_



#endif
