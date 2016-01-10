//	DDCPP/standard/bits/DD_bubble_sort.hpp
#ifndef DD_BUBBLE_SORT_HPP_INCLUDED_
#	define DD_BUBBLE_SORT_HPP_INCLUDED_



#	include "DD_Range.hpp"
#	include "DD_next.hpp"
#	include "DD_LessThan.hpp"
#	include "DD_swap_target.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
ProcessType bubble_sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
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
				if (less__(*current__, *front__)) {
					swap_target(front__, current__);
					need_to_continue_ = true;
				}
				++front__;
			} while (++current__ != end__);
			end__ = front__;
		} while (need_to_continue_);
	}
}

template <typename UndirectionalIteratorT_>
inline ProcessType bubble_sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(::DD::detail_::bubble_sort(begin__ DD_COMMA end__ DD_COMMA less_than)) {
	::DD::detail_::bubble_sort(begin__, end__, less_than);
}

template <typename UndirectionalRangeT_, typename BinaryPredicateT_>
inline ProcessType bubble_sort(
	UndirectionalRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(::DD::detail_::bubble_sort(DD_SPLIT_RANGE(range__) DD_COMMA less__)) {
	::DD::detail_::bubble_sort(DD_SPLIT_RANGE(range__), less__);
}

template <typename UndirectionalRangeT_>
inline ProcessType bubble_sort(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(::DD::detail_::bubble_sort(range__ DD_COMMA less_than)) {
	::DD::detail_::bubble_sort(range__, less_than);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::bubble_sort;



DD_END_



#endif
