//	DDCPP/standard/bits/DD_Conditional.hpp
#ifndef DD_CONDITIONAL_HPP_INCLUDED_
#	define DD_CONDITIONAL_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <ValidityType condition_c_, typename ThenT_, typename ElseT_>
struct Conditional_ {
	DD_ALIAS(Type, ElseT_);


};



template <typename ThenT_, typename ElseT_>
struct Conditional_<true, ThenT_, ElseT_> {
	DD_ALIAS(Type, ThenT_);


};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <ValidityType condition_c_, typename ThenT_, typename ElseT_>
using Conditional = detail_::Conditional_<condition_c_, ThenT_, ElseT_>;
template <ValidityType condition_c_, typename ThenT_, typename ElseT_>
using ConditionalType = typename Conditional<condition_c_, ThenT_, ElseT_>::Type;
#	else
template <ValidityType condition_c_, typename ThenT_, typename ElseT_>
struct Conditional : detail_::Conditional_<condition_c_, ThenT_, ElseT_> {
};
#	endif



DD_END_



#endif
