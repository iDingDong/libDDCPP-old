//	DDCPP/standard/bits/DD_FreeList.hpp
#ifndef _DD_FREE_LIST_HPP_INCLUDED
#	define _DD_FREE_LIST_HPP_INCLUDED 1



#	include "DD_SizeTrait.hpp"



DD_BEGIN
template <SizeType size>
union FreeList {
	FreeList* next;
	SizeTrait<size> memory;
	
	
};



DD_END



#endif
