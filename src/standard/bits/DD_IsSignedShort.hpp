//	DDCPP/standard/bits/DD_IsSignedShort.hpp
#ifndef DD_IS_SIGNED_SHORT_HPP_INCLUDED_
#	define DD_IS_SIGNED_SHORT_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsSignedShort_ : FalseType {
};



template <>
struct IsSignedShort_<signed short> : TrueType {
};



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsSignedShort : AndType<IsSignedShort<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsSignedShort<ObjectT_> : IsSignedShort_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsSignedShort : IsSignedShort_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsSignedShort;



DD_END_



#endif
