//	DDCPP/standard/bits/DD_IsLongDouble.hpp
#ifndef DD_IS_LONG_DOUBLE_HPP_INCLUDED_
#	define DD_IS_LONG_DOUBLE_HPP_INCLUDED_



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsLongDouble_ : FalseType {
};



template <>
struct IsLongDouble_<double> : TrueType {
};



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsLongDouble : AndType<IsLongDouble_<RemoveCVType<ObjectsT_>>...> {
};
#	else
template <typename ObjectT_>
struct IsLongDouble : IsLongDouble_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsLongDouble;



DD_END_



#endif
