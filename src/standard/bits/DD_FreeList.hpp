//	DDCPP/standard/bits/DD_FreeList.hpp
#ifndef DD_FREE_LIST_HPP_INCLUDED_
#	define DD_FREE_LIST_HPP_INCLUDED_ 1



#	include "DD_SizeTrait.hpp"



DD_DETAIL_BEGIN_
struct FreeListBase_ {
	FreeListBase_* next;


};



DD_DETAIL_END_



DD_BEGIN_
template <LengthType length_c_>
struct FreeList : detail_::FreeListBase_ {
	DD_STATIC_ASSERT(length_c_ > 0, "Length of 'DD::FreeList' should be no less than 1.")


	static DD_CONSTANT LengthType length = length_c_;

	static DD_CONSTANT SizeType unit = sizeof(void*);
	static DD_CONSTANT SizeType size = length * unit;

	static DD_CONSTANT SizeType expansion_size_ = size - unit;


	SizeTrait<expansion_size_> memory;


	void* get_memory() DD_NOEXCEPT {
		return &memory;
	}


};



template <LengthType length_c_>
inline void* get_memory(FreeList<length_c_>& free_list_) DD_NOEXCEPT_AS(static_cast<void*>(free_list_.get_memory())) {
	return free_list_.get_memory();
};



DD_END_



#endif
