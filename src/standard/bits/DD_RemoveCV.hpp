//	DDCPP/standard/bits/DD_RemoveCV.hpp
#ifndef DD_REMOVE_C_V_HPP_INCLUDED_
#	define DD_REMOVE_C_V_HPP_INCLUDED_ 1



#	include "DD_RemoveConst.hpp"
#	include "DD_RemoveVolatile.hpp"



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename ObjectT_>
using RemoveCV = RemoveVolatile<RemoveConstType<ObjectT_>>;
#	else
template <typename ObjectT_>
struct RemoveCV : RemoveVolatile<typename RemoveConst<ObjectT_>::Type> {
};
#	endif



DD_TRAIT_MODIFIER(RemoveCV)



DD_END_



#endif
