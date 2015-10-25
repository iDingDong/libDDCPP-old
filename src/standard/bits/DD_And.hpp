//	DDCPP/standard/bits/DD_And.hpp
#ifndef DD_AND_HPP_INCLUDED_
#	define DD_AND_HPP_INCLUDED_ 1



#	include "DD_IntegralConstant.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ConditionsT_>
struct And : TrueType {
};



template <typename ConditionT1_, typename ConditionT2_, typename... ConditionsT_>
struct And<ConditionT1_, ConditionT2_, ConditionsT_...> : And<ConditionT1_, And<ConditionT2_, ConditionsT_...>> {
};



template <typename ConditionT1_, typename ConditionT2_>
struct And<ConditionT1_, ConditionT2_> : BoolConstant<ConditionT1_::value && ConditionT2_::value> {
};



template <typename ConditionT_>
struct And<ConditionT_> : BoolConstant<ConditionT_::value> {
};



template <typename... ConditionsT_>
using AndType = typename And<ConditionsT_...>::Type;
#	else
template <typename ConditionT1_, typename ConditionT2_>
struct And : BoolConstant<ConditionT1_::value && ConditionT2_::value> {
};
#	endif



DD_DETAIL_END_




DD_BEGIN_
using detail_::And;
#	if __cplusplus >= 201103L
using detail_::AndType;
#	endif



DD_END_



#endif
