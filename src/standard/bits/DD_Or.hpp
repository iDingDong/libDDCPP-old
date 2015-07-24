//	standard/bits/DD_Or.hpp
#ifndef _DD_OR_HPP_INCLUDED
#	define _DD_OR_HPP_INCLUDED 1



#	include "DD_IntegralConstant.hpp"



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN
template <typename... ContidionsT>
struct _Or : FalseType {
};



template <typename _ConditionT1, typename _ConditionT2, typename... _ConditionsT>
struct _Or<_ConditionT1, _ConditionT2, _ConditionsT...> : _Or<_ConditionT1, _Or<_ConditionT2, _ConditionsT...>> {
};



template <typename _ConditionT1, typename _ConditionT2>
struct _Or<_ConditionT1, _ConditionT2> : BoolConstant<_ConditionT1::value || _ConditionT2::value> {
};



template <typename _ConditionT>
struct _Or<_ConditionT> : BoolConstant<_ConditionT::value> {
};



DD_DETAIL_END



#	endif
DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ConditionsT>
using Or = detail::_Or<_ConditionsT...>;
template <typename... _ConditionsT>
using OrType = typename Or<_ConditionsT...>::Type;
#	else
template <typename _ConditionT1, typename _ConditionT2>
struct Or : BoolConstant<_ConditionT1::value && _ConditionT2::value> {
};
#	endif



DD_END



#endif
