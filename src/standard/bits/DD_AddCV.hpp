//	DDCPP/standard/bits/DD_AddCV.hpp
#ifndef _DD_ADD_C_V_HPP_INCLUDED
#	define _DD_ADD_C_V_HPP_INCLUDED 1



#	include "DD_AddConst.hpp"
#	include "DD_AddVolatile.hpp"



_DD_BEGIN
#	if __cplusplus >= 201103L
template <typename _ObjectT>
using AddCV = AddConst<AddVolatileType<_ObjectT>>;
#	else
template <typename _ObjectT>
struct AddCV : AddConst<typename AddVolatile<_ObjectT>::Type> {
};
#	endif



DD_TRAIT_MODIFIER(AddCV)



_DD_END



#endif
