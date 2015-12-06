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



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsSignedLong : AndType<IsSignedLong<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsSignedLong<ObjectT_> : IsSignedLong_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsSignedLong : IsSignedLong_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsSignedLong;



DD_END_



#endif
