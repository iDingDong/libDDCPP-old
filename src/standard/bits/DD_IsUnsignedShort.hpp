//	DDCPP/standard/bits/DD_IsUnsignedShort.hpp
#ifndef DD_IS_UNSIGNED_SHORT_HPP_INCLUDED_
#	define DD_IS_UNSIGNED_SHORT_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsUnsignedShort_ : FalseType {
};



template <>
struct IsUnsignedShort_<unsigned short> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsUnsignedShort = AndType<detail_::IsUnsignedShort_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsUnsignedShort : detail_::IsUnsignedShort_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
