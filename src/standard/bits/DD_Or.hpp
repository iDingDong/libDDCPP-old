//	DDCPP/standard/bits/DD_Or.hpp
#ifndef DD_OR_HPP_INCLUDED_
#	define DD_OR_HPP_INCLUDED_ 1



#	include "DD_IntegralConstant.hpp"



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN_
template <typename... ContidionsT>
struct Or_ : FalseType {
};



template <typename ConditionT1_, typename ConditionT2_, typename... ConditionsT_>
struct Or_<ConditionT1_, ConditionT2_, ConditionsT_...> : Or_<ConditionT1_, Or_<ConditionT2_, ConditionsT_...>> {
};



template <typename ConditionT1_, typename ConditionT2_>
struct Or_<ConditionT1_, ConditionT2_> : BoolConstant<ConditionT1_::value || ConditionT2_::value> {
};



template <typename ConditionT_>
struct Or_<ConditionT_> : BoolConstant<ConditionT_::value> {
};



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ConditionsT_>
using Or = detail_::Or_<ConditionsT_...>;
template <typename... ConditionsT_>
using OrType = typename Or<ConditionsT_...>::Type;
#	else
template <typename ConditionT1_, typename ConditionT2_>
struct Or : BoolConstant<ConditionT1_::value && ConditionT2_::value> {
};
#	endif



DD_END_



#endif
