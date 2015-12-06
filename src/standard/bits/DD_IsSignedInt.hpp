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



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsSignedInt : AndType<IsSignedInt<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsSignedInt<ObjectT_> : IsSignedInt_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsSignedInt : IsSignedInt_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsSignedInt;



DD_END_



#endif
