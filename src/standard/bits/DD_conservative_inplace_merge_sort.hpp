//	DDCPP/standard/bits/DD_conservative_inplace_merge_sort.hpp
#ifndef DD_CONSERVATIVE_INPLACE_MERGE_SORT_HPP_INCLUDED_
#	define DD_CONSERVATIVE_INPLACE_MERGE_SORT_HPP_INCLUDED_ 1



#	include "DD_is_sorted_until.hpp"
#	include "DD_inplace_merge.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
ProcessType conservative_inplace_merge_sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) {
	UndirectionalIteratorT_ current__(::DD::is_sorted_until(begin__, end__));
	for (; ; ) {
		UndirectionalIteratorT_ next_to_merge__(::DD::is_sorted_until(current__, end__));
		if (next_to_merge__ == end__) {
			return;
		}
		::DD::inplace_merge(begin__, current__, next_to_merge__);
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::conservative_inplace_merge_sort;



DD_END_



#endif
