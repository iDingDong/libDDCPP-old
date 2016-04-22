//	DDCPP/standard/bits/DD_Allocator.hpp
#ifndef DD_ALLOCATOR_HPP_INCLUDED_
#	define DD_ALLOCATOR_HPP_INCLUDED_ 1



#	include <cstdlib>
#	include <new>

#	include "DD_ValueTypeNested.hpp"
#	include "DD_IntegralConstant.hpp"
#	include "DD_wrap_standard_exception.hpp"
#	include "DD_AllocationFailure.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsTriviallyDestructible.hpp"
#	endif
#	include "DD_debugger_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_ = void>
class Allocator;



template <>
class Allocator<void> {
	public:
	DD_ALIAS(ThisType, Allocator<void>);
	DD_VALUE_TYPE_NESTED(void)

	public:
	DD_ALIAS(SizeType, DD::SizeType);
	DD_ALIAS(LengthType, SizeType);

	public:
	DD_ALIAS(Basic, ThisType);
	DD_ALIAS(NeedInstance, FalseType);


	public:
	static PointerType allocate(SizeType size_) {
		try {
			return ::operator new(size_);
		} catch (std::bad_alloc const& error_) {
			throw ::DD::wrap_standard_exception<AllocationFailure>(error_);
		}
	}


	public:
	static ProcessType deallocate(PointerType pointer_) DD_NOEXCEPT {
		::operator delete(pointer_);
	}


	public:
	static ProcessType deallocate(PointerType pointer_, SizeType size_) DD_NOEXCEPT {
#	if __cplusplus >= 201402L
		::operator delete(pointer_, size_);
#	else
		::operator delete(pointer_);
#	endif
	}


};



template <typename ValueT_>
class Allocator : public Allocator<void> {
	public:
	DD_ALIAS(ThisType, Allocator<ValueT_>);
	DD_ALIAS(SuperType, Allocator<void>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	DD_ALIAS(SizeType, DD::SizeType);
	DD_ALIAS(LengthType, DD::LengthType);

	public:
	DD_ALIAS(Basic, SuperType);
	DD_ALIAS(NeedInstance, FalseType);

	public:
	static SizeType DD_CONSTANT unit = sizeof(ValueT_);


	public:
	static PointerType allocate(LengthType length_) {
		return PointerType(Basic::allocate(unit * length_));
	}


	public:
	static ProcessType deallocate(PointerType pointer_) DD_NOEXCEPT {
		Basic::deallocate(pointer_);
	}


	public:
	static ProcessType deallocate(PointerType pointer_, LengthType length_) DD_NOEXCEPT {
		Basic::deallocate(pointer_, unit * length_);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Allocator;



DD_END_



#endif
