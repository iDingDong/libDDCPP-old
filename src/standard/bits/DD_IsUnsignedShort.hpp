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



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsUnsignedShort : AndType<IsUnsignedShort<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsUnsignedShort<ObjectT_> : IsUnsignedShort_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsUnsignedShort : IsUnsignedShort_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsUnsignedShort;



DD_END_



#endif
