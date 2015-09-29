//	DDCPP/standard/bits/DD_IsSignedLong.hpp
#ifndef DD_IS_SIGNED_LONG_HPP_INCLUDED_
#	define DD_IS_SIGNED_LONG_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsSignedLong_ : FalseType {
};



template <>
struct IsSignedLong_<signed long> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsSignedLong = AndType<detail_::IsSignedLong_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsSignedLong : detail_::IsSignedLong_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
