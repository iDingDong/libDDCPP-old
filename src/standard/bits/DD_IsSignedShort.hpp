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



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsSignedShort = AndType<detail_::IsSignedShort_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsSignedShort : detail_::IsSignedShort_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
