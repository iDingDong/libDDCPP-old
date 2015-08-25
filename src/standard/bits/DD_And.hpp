//	DDCPP/standard/bits/DD_And.hpp
#ifndef _DD_AND_HPP_INCLUDED
#	define _DD_AND_HPP_INCLUDED 1



#	include "DD_IntegralConstant.hpp"



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN
template <typename... _ConditionsT>
struct _And : TrueType {
};



template <typename _ConditionT1, typename _ConditionT2, typename... _ConditionsT>
struct _And<_ConditionT1, _ConditionT2, _ConditionsT...> : _And<_ConditionT1, _And<_ConditionT2, _ConditionsT...>> {
};



template <typename _ConditionT1, typename _ConditionT2>
struct _And<_ConditionT1, _ConditionT2> : BoolConstant<_ConditionT1::value && _ConditionT2::value> {
};



template <typename _ConditionT>
struct _And<_ConditionT> : BoolConstant<_ConditionT::value> {
};



DD_DETAIL_END



#	endif
DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ConditionsT>
using And = _detail::_And<_ConditionsT...>;
template <typename... _ConditionsT>
using AndType = typename And<_ConditionsT...>::Type;
#	else
template <typename _ConditionT1, typename _ConditionT2>
struct And : BoolConstant<_ConditionT1::value && _ConditionT2::value> {
};
#	endif



DD_END



#endif
