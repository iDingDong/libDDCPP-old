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
	ProcessType quick_sort(
		BidirectionalIteratorT__ first___,
		BidirectionalIteratorT__ last___,
	) {
		while (first___ != last___) {
			BidirectionalIteratorT__ low___(first___);
			BidirectionalIteratorT__ high___(last___);
			for (; ; ) {
				for (; ; ) {
					while (!(*high___ < *low___)) {
						if (low___ == --high___) {
							goto outside_;
						}
					}
					swap_target(low___, high___);
					while (!(*high___ < *low___)) {
						if (++low___ == high___) {
							goto outside_;
						}
					}
					swap_target(low___, high___);
				}
			}
			outside_:
			if (high___ != last___) {
				quick_sort(next(high___), last___);
			}
			last___ = low___;
		}
	}


};



template <typename BidirectionalIteratorT_>
ProcessType quick_sort(
	BidirectionalIteratorT_ const& begin__,
	BidirectionalIteratorT_ const& end__,
) {
	if (begin__ != end__) {
		QuickSort_<IsFreeAccessIterator<BidirectionalIteratorT_>::value>::quick_sort(begin__, previous(end__));
	}
}



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
