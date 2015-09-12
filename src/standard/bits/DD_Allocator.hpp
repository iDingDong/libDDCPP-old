//	DDCPP/standard/bits/DD_Allocator.hpp
#ifndef _DD_ALLOCATOR_HPP_INCLUDED
#	define _DD_ALLOCATOR_HPP_INCLUDED 1



#	include <cstdlib>

#	include "DD_AllocationFailure.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsTriviallyDestructible.hpp"
#	endif
#	include "DD_debugger_definitions.hpp"
#	include "DD_address_of.hpp"



DD_BEGIN
template <typename _ValueT = void>
class Allocator {
	public:
	DD_ALIAS(ThisType, Allocator<_ValueT>)
	DD_ALIAS(ValueType, _ValueT)
	
	public: 
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(SizeType, DD::SizeType)
	
	
};



template <>
class Allocator<void> {
	public:
	DD_ALIAS(ThisType, Allocator<void>)
	DD_ALIAS(ValueType, void)
	
	public:
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(SizeType, DD::SizeType)
	
	
	static PointerType allocate(SizeType _size) {
		PointerType temp = ::operator new(_size);
		if (temp) {
			return temp;
		}
		throw AllocationFailure("'DD::Allocator' Failed to allocate.");
	}
	
	
	static ProcessType deallocate(PointerType _pointer) DD_NOEXCEPT {
		::operator delete(_pointer);
	}
	
	
	static ProcessType deallocate(PointerType _pointer, SizeType _size) DD_NOEXCEPT {
		::operator delete(_pointer, _size);
	}
	
	
};



DD_END



#endif
