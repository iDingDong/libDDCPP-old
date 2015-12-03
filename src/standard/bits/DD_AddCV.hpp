//	DDCPP/standard/bits/DD_AddCV.hpp
#ifndef DD_ADD_C_V_HPP_INCLUDED_
#	define DD_ADD_C_V_HPP_INCLUDED_ 1



#	include "DD_AddConst.hpp"
#	include "DD_AddVolatile.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ObjectT_>
using AddCV = AddConst<AddVolatileType<ObjectT_>>;
#	else
template <typename ObjectT_>
struct AddCV : AddConst<typename AddVolatile<ObjectT_>::Type> {
};
#	endif



DD_TRAIT_MODIFIER(AddCV)



DD_DETAIL_END_



DD_BEGIN_
using detail_::AddCV;
#	if __cplusplus >= 201103L
using detail_::AddCVType;
#	endif


DD_END_



#endif
