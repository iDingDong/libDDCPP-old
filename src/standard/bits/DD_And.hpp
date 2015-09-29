//	DDCPP/standard/bits/DD_And.hpp
#ifndef DD_AND_HPP_INCLUDED_
#	define DD_AND_HPP_INCLUDED_ 1



#	include "DD_IntegralConstant.hpp"



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN_
template <typename... ConditionsT_>
struct And_ : TrueType {
};



template <typename ConditionT1_, typename ConditionT2_, typename... ConditionsT_>
struct And_<ConditionT1_, ConditionT2_, ConditionsT_...> : And_<ConditionT1_, And_<ConditionT2_, ConditionsT_...>> {
};



template <typename ConditionT1_, typename ConditionT2_>
struct And_<ConditionT1_, ConditionT2_> : BoolConstant<ConditionT1_::value && ConditionT2_::value> {
};



template <typename ConditionT_>
struct And_<ConditionT_> : BoolConstant<ConditionT_::value> {
};



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ConditionsT_>
using And = detail_::And_<ConditionsT_...>;
template <typename... ConditionsT_>
using AndType = typename And<ConditionsT_...>::Type;
#	else
template <typename ConditionT1_, typename ConditionT2_>
struct And : BoolConstant<ConditionT1_::value && ConditionT2_::value> {
};
#	endif



DD_END_



#endif
