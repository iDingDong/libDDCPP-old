//	DDCPP/standard/bits/DD_IsDouble.hpp
#ifndef DD_IS_DOUBLE_HPP_INCLUDED_
#	define DD_IS_DOUBLE_HPP_INCLUDED_



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsDouble_ : FalseType {
};



template <>
struct IsDouble_<double> : TrueType {
};



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsDouble : AndType<IsDouble<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsDouble<ObjectT_> : IsDouble_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsDouble : IsDouble_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsDouble;



DD_END_



#endif
