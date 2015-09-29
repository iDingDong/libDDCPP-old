//	DDCPP/standard/bits/DD_IsUnsignedLong.hpp
#ifndef DD_IS_UNSIGNED_LONG_HPP_INCLUDED_
#	define DD_IS_UNSIGNED_LONG_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsUnsignedLong_ : FalseType {
};



template <>
struct IsUnsignedLong_<unsigned long> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsUnsignedLong = AndType<detail_::IsUnsignedLong_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsUnsignedLong : detail_::IsUnsignedLong_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
