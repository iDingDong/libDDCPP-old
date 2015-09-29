//	DDCPP/standard/bits/DD_IteratorDifference.hpp
#ifndef DD_ITERATOR_DIFFERENCE_HPP_INCLUDED_
#	define DD_ITERATOR_DIFFERENCE_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"



DD_BEGIN_
DD_NESTED_TYPE_TRAIT(IteratorDifference, DifferenceType, DD::DifferenceType)



#	if __cplusplus >= 201103L
template <typename IteratorT_>
using IteratorDifferenceType = typename IteratorDifference<IteratorT_>::Type;



#	endif
DD_END_



#endif
