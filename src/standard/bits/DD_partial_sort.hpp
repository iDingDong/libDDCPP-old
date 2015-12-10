//	DDCPP/standard/bits/DD_partial_sort.hpp
#ifndef DD_PARTIAL_SORT_HPP_INCLUDED_
#	define DD_PARTIAL_SORT_HPP_INCLUDED_ 1



#	include "DD_IteratorValue.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_GreaterThan.hpp"
#	include "DD_build_heap.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_>
ProcessType partial_sort(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ termination__,
	FreeAccessIteratorT_ end__
) {
	if (begin__ < termination__) {
		DD_ALIAS(ReverseIterator_, DD_MODIFY_TRAIT(IteratorReverse, FreeAccessIteratorT_));
		::DD::build_heap(
			ReverseIterator_(--end__),
			ReverseIterator_(begin__ - 1),
			GreaterThan<DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)>()
		);
		::DD::swap_target(begin__, end__);
		--termination__;
		while (begin__ < termination__) {
			::DD::heapify(
				ReverseIterator_(end__),
				ReverseIterator_(begin__),
				ReverseIterator_(end__),
				GreaterThan<DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)>()
			);
			::DD::swap_target(++begin__, end__);
		}
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::partial_sort;



DD_END_



#endif
