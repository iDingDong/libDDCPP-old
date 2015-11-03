//	DDCPP/standard/bits/DD_Conditional.hpp
#ifndef DD_CONDITIONAL_HPP_INCLUDED_
#	define DD_CONDITIONAL_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <ValidityType condition_c_, typename ThenT_, typename ElseT_>
struct Conditional {
	DD_ALIAS(Type, ElseT_);


};



template <typename ThenT_, typename ElseT_>
struct Conditional<true, ThenT_, ElseT_> {
	DD_ALIAS(Type, ThenT_);


};



#	if __cplusplus >= 201103L
template <ValidityType condition_c_, typename ThenT_, typename ElseT_>
using ConditionalType = typename Conditional<condition_c_, ThenT_, ElseT_>::Type;



#	endif
DD_DETAIL_END_



DD_BEGIN_
using detail_::Conditional;
#	if __cplusplus >= 201103L
using detail_::ConditionalType;
#	endif



DD_END_



#endif
