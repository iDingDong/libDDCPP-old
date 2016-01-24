//	DDCPP/standard/bits/DD_Not.hpp
#ifndef DD_NOT_HPP_INCLUDED_
#	define DD_NOT_HPP_INCLUDED_ 1



#	include "DD_IntegralConstant.hpp"



DD_DETAIL_BEGIN_
template <typename ConditionT_>
struct Not : BoolConstant<!ConditionT_::value> {
};



DD_TRAIT_MODIFIER(Not)



DD_DETAIL_END_



DD_BEGIN_
using detail_::Not;
#	if __cplusplus >= 201103L
using detail_::NotType;
#	endif



DD_END_



#endif
