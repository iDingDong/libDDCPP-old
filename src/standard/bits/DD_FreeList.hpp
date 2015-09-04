//	DDCPP/standard/bits/DD_FreeList.hpp
#ifndef _DD_FREE_LIST_HPP_INCLUDED
#	define _DD_FREE_LIST_HPP_INCLUDED 1



#	include "DD_SizeTrait.hpp"



DD_BEGIN
template <LengthType _length_c>
struct FreeList {
	DD_STATIC_ASSERT(_length_c > 0, "Length of 'DD::FreeList' should be no less than 1.")
	
	
	static DD_CONSTANT LengthType length = _length_c;
	
	static DD_CONSTANT SizeType unit = sizeof(void*);
	static DD_CONSTANT SizeType size = length * unit;
	
	
	union {
		FreeList* next;
		SizeTrait<size> memory;
	};
	
	
	void* get_memory() DD_NOEXCEPT {
		return &memory;
	}
	
	
};



template <LengthType _length_c>
inline void* get_memory(FreeList<_length_c>& _free_list) DD_NOEXCEPT_AS(static_cast<void*>(_free_list.get_memory())) {
	return _free_list.get_memory();
};



DD_END



#endif
