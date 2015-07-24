//	standard/bits/DD_IsBidirectionalIterator.hpp
#ifndef _DD_IS_BIDIRECTIONAL_ITERATOR_HPP_INCLUDED
#	define _DD_IS_BIDIRECTIONAL_ITERATOR_HPP_INCLUDED 1



#	include "DD_IsBaseOf.hpp"
#	include "DD_IteratorCatagory.hpp"



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _IteratorsT>
using IsBidirectionalIterator = IsBaseOf<BidirectionalIterator, IteratorCatagoryType<_IteratorsT>...>;
#	else
template <typename _IteratorT>
struct IsBidirectionalIterator : IsBaseOf<BidirectionalIterator, typename IteratorCatagory<_IteratorT>::Type> {
};
#	endif



DD_END



#endif
