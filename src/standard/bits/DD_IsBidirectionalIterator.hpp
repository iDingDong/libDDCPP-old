//	DDCPP/standard/bits/DD_IsBidirectionalIterator.hpp
#ifndef DD_IS_BIDIRECTIONAL_ITERATOR_HPP_INCLUDED_
#	define DD_IS_BIDIRECTIONAL_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_IsBaseOf.hpp"
#	include "DD_IteratorCatagory.hpp"



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... IteratorsT_>
using IsBidirectionalIterator = IsBaseOf<BidirectionalIterator, IteratorCatagoryType<IteratorsT_>...>;
#	else
template <typename IteratorT_>
struct IsBidirectionalIterator : IsBaseOf<BidirectionalIterator, typename IteratorCatagory<IteratorT_>::Type> {
};
#	endif



DD_END_



#endif
