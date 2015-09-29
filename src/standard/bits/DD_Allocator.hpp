//	DDCPP/standard/bits/DD_Allocator.hpp
#ifndef DD_ALLOCATOR_HPP_INCLUDED_
#	define DD_ALLOCATOR_HPP_INCLUDED_ 1



#	include <cstdlib>

#	include "DD_ValueTypeNested.hpp"
#	include "DD_IntegralConstant.hpp"
#	include "DD_AllocationFailure.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsTriviallyDestructible.hpp"
#		include "DD_forward.hpp"
#	endif
#	include "DD_debugger_definitions.hpp"
#	include "DD_address_of.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_ = void>
class Allocator {
	public:
	DD_ALIAS(ThisType, Allocator<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	DD_ALIAS(NeedInstance, TrueType);
	DD_ALIAS(Basic, Allocator<void>);


};



template <>
class Allocator<void> {
	public:
	DD_ALIAS(ThisType, Allocator<void>);
	DD_ALIAS(ValueType, void);

	public:
	DD_ALIAS(NeedInstance, TrueType);
	DD_ALIAS(Basic, Allocator<void>);

	public:
	DD_ALIAS(PointerType, ValueType*);
	DD_ALIAS(SizeType, DD::SizeType);


	static PointerType allocate(SizeType size_) {
		PointerType temp = ::operator new(size_);
		if (temp) {
			return temp;
		}
		throw AllocationFailure("'DD::Allocator' Failed to allocate.");
	}


	static ProcessType deallocate(PointerType pointer_) DD_NOEXCEPT {
		::operator delete(pointer_);
	}


	static ProcessType deallocate(PointerType pointer_, SizeType size_) DD_NOEXCEPT {
		::operator delete(pointer_);
	}


#	if __cplusplus >= 201103L
	template <typename ValueT__, typename... ArgumentsT__>
	static ProcessType construct(ValueT__* pointer_, ArgumentsT__&&... arguments___) noexcept(
		noexcept(new (pointer_) ValueT__(forward<ArgumentsT__>(arguments___)...))
	) {
		new (pointer_) ValueT__(forward<ArgumentsT__>(arguments___)...);
	}
#	else
	template <typename ValueT__>
	static ProcessType construct(ValueT__* pointer_, ValueT__ const& value___) {
		new (pointer_) ValueT__(value___);
	}
#	endif


	template <typename ValueT__>
	static ProcessType destruct(ValueT__* pointer_) {
		pointer_->~ValueT__();
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Allocator;



DD_END_



#endif
