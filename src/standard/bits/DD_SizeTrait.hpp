//	DDCPP/standard/bits/DD_SizeTrait.hpp
#ifndef _DD_SIZE_TRAIT_HPP_INCLUDED
#	define _DD_SIZE_TRAIT_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



#	if __cplusplus < 201103L || DDCPP_COMPAT_DEPRECATION
#		if __cplusplus >= 201103L && DDCPP_DEPRECATION_WARNING
#			warning 'DD_SizeTrait.hpp' is deprecated with ISO/IEC 14882:2011 or a later version support.
#		endif
DD_BEGIN
template <SizeType _size_c>
struct SizeTrait {
	char value[_size_c];
	
};



DD_END



#	endif
#endif
