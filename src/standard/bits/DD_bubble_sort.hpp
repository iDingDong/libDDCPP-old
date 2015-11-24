//	DDCPP/standard/bits/DD_bubble_sort.hpp
#ifndef DD_BUBBLE_SORT_HPP_INCLUDED_
#	define DD_BUBBLE_SORT_HPP_INCLUDED_



#	include "DD_Range.hpp"
#	include "DD_next.hpp"
#	include "DD_swap_target.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
ProcessType bubble_sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) {
	if (begin__ != end__) {
		ValidityType need_to_continue_;
		do {
			UndirectionalIteratorT_ current__(::DD::next(begin__));
			if (current__ == end__) {
				return;
			}
			need_to_continue_ = false;
			UndirectionalIteratorT_ front__(begin__);
			do {
				if (*current__ < *front__) {
					swap_target(front__, current__);
					need_to_continue_ = true;
				}
				++front__;
			} while (++current__ != end__);
			end__ = front__;
		} while (need_to_continue_);
	}
}

template <typename UndirectionalRangeT_>
inline ProcessType bubble_sort(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(::DD::detail_::bubble_sort(DD_SPLIT_RANGE(range__))) {
	::DD::detail_::bubble_sort(DD_SPLIT_RANGE(range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::bubble_sort;



DD_END_



#endif
