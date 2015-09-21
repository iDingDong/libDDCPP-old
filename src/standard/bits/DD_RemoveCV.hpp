//	DDCPP/standard/bits/DD_RemoveCV.hpp
#ifndef _DD_REMOVE_C_V_HPP_INCLUDED
#	define _DD_REMOVE_C_V_HPP_INCLUDED 1



#	include "DD_RemoveConst.hpp"
#	include "DD_RemoveVolatile.hpp"



_DD_BEGIN
#	if __cplusplus >= 201103L
template <typename _ObjectT>
using RemoveCV = RemoveVolatile<RemoveConstType<_ObjectT>>;
DD_TRAIT_MODIFIER(RemoveCV)
#	else
template <typename _ObjectT>
struct RemoveCV : RemoveVolatile<typename RemoveConst<_ObjectT>::Type> {
};
#	endif



_DD_END



#endif
