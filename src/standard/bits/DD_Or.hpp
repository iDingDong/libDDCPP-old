//	DDCPP/standard/bits/DD_Or.hpp
#ifndef DD_OR_HPP_INCLUDED_
#	define DD_OR_HPP_INCLUDED_ 1



#	include "DD_IntegralConstant.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ContidionsT>
struct Or : FalseType {
};



template <typename ConditionT1_, typename ConditionT2_, typename... ConditionsT_>
struct Or<ConditionT1_, ConditionT2_, ConditionsT_...> : Or<ConditionT1_, Or<ConditionT2_, ConditionsT_...>> {
};



template <typename ConditionT1_, typename ConditionT2_>
struct Or<ConditionT1_, ConditionT2_> : BoolConstant<ConditionT1_::value || ConditionT2_::value> {
};



template <typename ConditionT_>
struct Or<ConditionT_> : BoolConstant<ConditionT_::value> {
};



template <typename... ConditionsT_>
using OrType = typename Or<ConditionsT_...>::Type;
#	else
template <typename ConditionT1_, typename ConditionT2_>
struct Or : BoolConstant<ConditionT1_::value && ConditionT2_::value> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::Or;
#	if __cplusplus >= 201103L
using detail_::OrType;
#	endif



DD_END_



#endif
