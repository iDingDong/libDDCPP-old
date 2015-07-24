//	standard/bits/DD_InitializerList.hpp
#ifndef _DD_INITIALIZER_LIST_HPP_INCLUDED
#	define _DD_INITIALIZER_LIST_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::get_last_argument'.



#	endif
#	include <initializer_list>

#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ValueT>
using InitializerList = std::initializer_list<_ValueT>;



DD_END



#endif
