//	DDCPP/standard/bits/DD_IteratorDifference.hpp
#ifndef _DD_ITERATOR_DIFFERENCE_HPP_INCLUDED
#	define _DD_ITERATOR_DIFFERENCE_HPP_INCLUDED 1



#	include "DD_NestedTypeCheck.hpp"



_DD_BEGIN
DD_NESTED_TYPE_TRAIT(IteratorDifference, DifferenceType, DD::DifferenceType)



#	if __cplusplus >= 201103L
template <typename _IteratorT>
using IteratorDifferenceType = typename IteratorDifference<_IteratorT>::Type;



#	endif
_DD_END



#endif
