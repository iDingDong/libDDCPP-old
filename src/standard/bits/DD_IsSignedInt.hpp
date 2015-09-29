//	DDCPP/standard/bits/DD_IsSignedInt.hpp
#ifndef DD_IS_SIGNED_INT_HPP_INCLUDED_
#	define DD_IS_SIGNED_INT_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsSignedInt_ : FalseType {
};



template <>
struct IsSignedInt_<signed int> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsSignedInt = AndType<detail_::IsSignedInt_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsSignedInt : detail_::IsSignedInt_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
