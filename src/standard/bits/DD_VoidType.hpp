//	DDCPP/standard/bits/DD_VoidType.hpp
#ifndef DD_VOID_TYPE_HPP_INCLUDED_
#	define DD_VOID_TYPE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::VoidType'.



#	endif
#	include "DD_global_definitions.hpp"



#	if __cplusplus < 201402L
DD_DETAIL_BEGIN_
template <typename... ObjectsT_>
struct VoidTypeWorkaround_ {
	using Type = void;


};



DD_DETAIL_END_



#	endif
DD_BEGIN_
template <typename... ObjectsT_>
#	if __cplusplus >= 201402L
using VoidType = void;
#	else
using VoidType = typename detail_::VoidTypeWorkaround_<ObjectsT_...>::Type;
#	endif



DD_END_



#endif
