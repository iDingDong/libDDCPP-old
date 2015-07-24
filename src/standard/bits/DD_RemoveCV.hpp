//	standard/bits/DD_RemoveCV.hpp
#ifndef _DD_REMOVE_C_V_HPP_INCLUDED
#	define _DD_REMOVE_C_V_HPP_INCLUDED 1



#	include "DD_RemoveConst.hpp"
#	include "DD_RemoveVolatile.hpp"



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename _ObjectT>
using RemoveCV = RemoveVolatile<RemoveConstType<_ObjectT>>;
template <typename _ObjectT>
using RemoveCVType = typename RemoveCV<_ObjectT>::Type;
#	else
template <typename _ObjectT>
struct RemoveCV : RemoveVolatile<typename RemoveConst<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
