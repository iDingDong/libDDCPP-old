//	DDCPP/standard/bits/DD_SizeTrait.hpp
#ifndef _DD_SIZE_TRAIT_HPP_INCLUDED
#	define _DD_SIZE_TRAIT_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <SizeType _size_c>
struct SizeTrait {
	char value[_size_c];

};



_DD_END



#endif
