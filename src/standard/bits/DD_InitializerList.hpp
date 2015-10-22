//	DDCPP/standard/bits/DD_InitializerList.hpp
#ifndef DD_INITIALIZER_LIST_HPP_INCLUDED_
#	define DD_INITIALIZER_LIST_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::get_last_argument'.



#	endif
#	include <initializer_list>

#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
using InitializerList = std::initializer_list<ValueT_>;



DD_DETAIL_END_



DD_BEGIN_
using detail_::InitializerList;



DD_END_



#endif
