//	DDCPP/standard/bits/DD_Conditional.hpp
#ifndef _DD_CONDITIONAL_HPP_INCLUDED
#	define _DD_CONDITIONAL_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_DETAIL_BEGIN
template <ValidityType _condition_c, typename _ThenT, typename _ElseT>
struct _Conditional {
	DD_ALIAS(Type, _ElseT);


};



template <typename _ThenT, typename _ElseT>
struct _Conditional<true, _ThenT, _ElseT> {
	DD_ALIAS(Type, _ThenT);


};



_DD_DETAIL_END



_DD_BEGIN
#	if __cplusplus >= 201103L
template <ValidityType _condition_c, typename _ThenT, typename _ElseT>
using Conditional = _detail::_Conditional<_condition_c, _ThenT, _ElseT>;
template <ValidityType _condition_c, typename _ThenT, typename _ElseT>
using ConditionalType = typename Conditional<_condition_c, _ThenT, _ElseT>::Type;
#	else
template <ValidityType _condition_c, typename _ThenT, typename _ElseT>
struct Conditional : _detail::_Conditional<_condition_c, _ThenT, _ElseT> {
};
#	endif



_DD_END



#endif
