//	DDCPP/standard/bits/DD_IsBidirectionalIterator.hpp
#ifndef DD_IS_BIDIRECTIONAL_ITERATOR_HPP_INCLUDED_
#	define DD_IS_BIDIRECTIONAL_ITERATOR_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_IsBaseOf.hpp"
#	elif
#		include "DD_IsSame.hpp"
#	endif
#	include "DD_IteratorCatagory.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... IteratorsT_>
struct IsBidirectionalIterator : AndType<IsBidirectionalIterator<IteratorsT_>...> {
};



template <typename IteratorT_>
struct IsBidirectionalIterator<IteratorT_> : IsBaseOf<BidirectionalIterator, IteratorCatagoryType<IteratorT_>> {
};
#	else
template <typename IteratorT_>
struct IsBidirectionalIterator : IsSame<BidirectionalIterator, typename IteratorCatagory<IteratorT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsBidirectionalIterator;



DD_END_



#endif
