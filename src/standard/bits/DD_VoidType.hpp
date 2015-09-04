//	DDCPP/standard/bits/DD_VoidType.hpp
#ifndef _DD_VOID_TYPE_HPP_INCLUDED
#	define _DD_VOID_TYPE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::VoidType'.



#	endif
#	include "DD_global_definitions.hpp"



#	if __cplusplus < 201402L
DD_DETAIL_BEGIN
template <typename... _ObjectsT>
struct _VoidTypeWorkaround {
	using Type = void;
	
	
};



DD_DETAIL_END



#	endif
DD_BEGIN
template <typename... _ObjectsT>
#	if __cplusplus >= 201402L
using VoidType = void;
#	else
using VoidType = typename _detail::_VoidTypeWorkaround<_ObjectsT...>::Type;
#	endif



DD_END



#endif
