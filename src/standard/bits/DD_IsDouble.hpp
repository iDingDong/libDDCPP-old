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



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsDouble = AndType<detail_::IsDouble_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsDouble : detail_::IsDouble_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
