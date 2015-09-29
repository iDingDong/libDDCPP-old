//	DDCPP/standard/bits/DD_SizeTrait.hpp
#ifndef DD_SIZE_TRAIT_HPP_INCLUDED_
#	define DD_SIZE_TRAIT_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <SizeType size_c_>
struct SizeTrait {
	char value[size_c_];

};



DD_END_



#endif
