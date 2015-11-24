//	DDCPP/standard/bits/DD_quick_sort.hpp
#ifndef DD_QUICK_SORT_HPP_INCLUDED_
#	define DD_QUICK_SORT_HPP_INCLUDED_ 1



#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_next.hpp"
#	include "DD_previous.hpp"
#	include "DD_swap_target.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_c_>
struct QuickSort_ {
	template <typename BidirectionalIteratorT__>
	static ProcessType quick_sort(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___
	) {
		while (begin___ != end___) {
			BidirectionalIteratorT__ low___(begin___);
			BidirectionalIteratorT__ high___(end___);
			for (; ; ) {
				while (!(*--high___ < *low___)) {
					if (low___ == high___) {
						goto outside_;
					}
				}
				swap_target(low___, high___);
				do {
					if (low___ == high___) {
						goto outside_;
					}
				} while (!(*high___ < *++low___));
				swap_target(low___, high___);
			}
			outside_:
			if (high___ != end___) {
				quick_sort(::DD::next(high___), end___);
			}
			end___ = low___;
		}
	}


};



template <>
struct QuickSort_<true> {
	template <typename FreeAccessIteratorT__>
	static ProcessType quick_sort(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___
	) {
		while (begin___ < end___) {
			FreeAccessIteratorT__ low___(begin___);
			FreeAccessIteratorT__ high___(end___);
			for (; ; ) {
				while (!(*--high___ < *low___)) {
					if (low___ >= high___) {
						goto outside_;
					}
				}
				swap_target(low___, high___);
				do {
					if (low___ >= high___) {
						goto outside_;
					}
				} while (!(*high___ < *++low___));
				swap_target(low___, high___);
			}
			outside_:
			quick_sort(::DD::next(high___), end___);
			end___ = low___;
		}
	}


};



template <typename BidirectionalIteratorT_>
inline ProcessType quick_sort(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(QuickSort_<IsFreeAccessIterator<BidirectionalIteratorT_>::value>::quick_sort(begin__, end__)) {
	QuickSort_<IsFreeAccessIterator<BidirectionalIteratorT_>::value>::quick_sort(begin__, end__);
}

template <typename BidirectionalRangeT_>
inline ProcessType quick_sort(
	BidirectionalRangeT_& range__
) DD_NOEXCEPT_AS(::DD::detail_::quick_sort(DD_SPLIT_RANGE(range__))) {
	::DD::detail_::quick_sort(DD_SPLIT_RANGE(range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::quick_sort;



DD_END_



#endif
