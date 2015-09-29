//	DDCPP/standard/bits/DD_insert_sort.hpp
#ifndef DD_INSERT_SORT_HPP_INCLUDED_
#	define DD_INSERT_SORT_HPP_INCLUDED_


#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	else
#		include "DD_IteratorValue.hpp"
#	endif
#	include "DD_IsBidirectionalIterator.hpp"
#	include "DD_swap_target.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_bidirectional_iterator_c_>
struct InsertSort_ {
	template <typename UndirectionalIteratorT__>
	static ProcessType insert_sort_(
		UndirectionalIteratorT__ const& begin___,
		UndirectionalIteratorT__ const& end___
	) DD_NOEXCEPT_IF(
		noexcept(swap_target(begin___, end___)) &&
		noexcept(++const_cast<UndirectionalIteratorT__&>(begin___) != end___) &&
		noexcept(*begin___ < *end___)
	) {
		if (begin___ != end___) {
			for (UndirectionalIteratorT__ current___(begin___), front___; ++current___ != end___; ) {
				front___ = begin___;
				do {
					if (*current___ < *front___) {
						do {
							swap_target(front___, current___);
						} while (++front___ != current___);
						break;
					}
				} while (++front___ != current___);
			}
		}
	}

	template <typename UndirectionalIteratorT__, typename BinaryPredicatorT__>
	static ProcessType insert_sort_(
		UndirectionalIteratorT__ const& begin___,
		UndirectionalIteratorT__ const& end___,
		BinaryPredicatorT__ const& less___
	) DD_NOEXCEPT_IF(
		noexcept(swap_target(begin___, end___)) &&
		noexcept(++const_cast<UndirectionalIteratorT__&>(begin___) != end___) &&
		noexcept(less___(*begin___, *end___))
	) {
		if (begin___ != end___) {
			for (UndirectionalIteratorT__ current___(begin___), front___; ++current___ != end___; ) {
				front___ = begin___;
				do {
					if (less___(*current___, *front___)) {
						do {
							swap_target(front___, current___);
						} while (++front___ != current___);
						break;
					}
				} while (++front___ != current___);
			}
		}
	}


};



template <>
struct InsertSort_<true> {
	template <typename BidirectionalIteratorT__>
	static ProcessType insert_sort_(
		BidirectionalIteratorT__ const& begin___,
		BidirectionalIteratorT__ const& end___
	) DD_NOEXCEPT_IF(
		noexcept(IteratorValueType<BidirectionalIteratorT__>(move(*begin___))) &&
		noexcept(++const_cast<BidirectionalIteratorT__&>(begin___) == end___) &&
		noexcept(*begin___ < *end___)
	) {
		if (begin___ != end___) {
			for (BidirectionalIteratorT__ current___(begin___), front___; ++current___ != end___; ) {
				front___ = current___;
#	if __cplusplus >= 201103L
				auto temp_ = move(*front___);
				for (auto previous___(front___); temp_ < *--previous___; ) {
					*front___ = move(*previous___);
					--front___;
					if (front___ == begin___) {
						break;
					}
				}
				*front___ = move(temp_);
#	else
				typename IteratorValue<BidirectionalIteratorT__>::Type temp_ = *current___;
				for (BidirectionalIteratorT__ previous___(front___); temp_ < *--previous___; ) {
					*front___ = *previous___;
					--front___;
					if (previous___ == begin___) {
						break;
					}
				}
				*front___ = temp_;
#	endif
			}
		}
	}

	template <typename BidirectionalIteratorT__, typename BinaryPredicatorT__>
	static ProcessType insert_sort_(
		BidirectionalIteratorT__ const& begin___,
		BidirectionalIteratorT__ const& end___,
		BinaryPredicatorT__ const& less___
	) DD_NOEXCEPT_IF(
		noexcept(IteratorValueType<BidirectionalIteratorT__>(move(*begin___))) &&
		noexcept(++const_cast<BidirectionalIteratorT__&>(begin___) == end___) &&
		noexcept(less___(*begin___, *end___))
	) {
		if (begin___ != end___) {
			for (BidirectionalIteratorT__ current___(begin___), front___; ++current___ != end___; ) {
				front___ = current___;
#	if __cplusplus >= 201103L
				auto temp_ = move(*front___);
				for (auto previous___(front___); less___(temp_, *--previous___); ) {
					*front___ = move(*previous___);
					--front___;
					if (front___ == begin___) {
						break;
					}
				}
				*front___ = move(temp_);
#	else
				typename IteratorValue<BidirectionalIteratorT__>::Type temp_ = *current___;
				for (BidirectionalIteratorT__ previous___(front___); less___(temp_, *--previous___); ) {
					*front___ = *previous___;
					--front___;
					if (previous___ == begin___) {
						break;
					}
				}
				*front___ = temp_;
#	endif
			}
		}
	}


};



DD_DETAIL_END_



DD_BEGIN_
template <typename UndirectionalIteratorT_>
inline ProcessType insert_sort(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__
) DD_NOEXCEPT_AS(
	detail_::InsertSort_<
		IsBidirectionalIterator<UndirectionalIteratorT_>::value
	>::insert_sort_(begin__ DD_COMMA end__)
) {
	detail_::InsertSort_<
		IsBidirectionalIterator<UndirectionalIteratorT_>::value
	>::insert_sort_(begin__, end__);
}

template <typename UndirectionalIteratorT_, typename BinaryPredicatorT_>
inline ProcessType insert_sort(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__,
	BinaryPredicatorT_ const& less__
) DD_NOEXCEPT_AS(
	detail_::InsertSort_<
		IsBidirectionalIterator<UndirectionalIteratorT_>::value
	>::insert_sort_(begin__ DD_COMMA end__ DD_COMMA less__)
) {
	detail_::InsertSort_<
		IsBidirectionalIterator<UndirectionalIteratorT_>::value
	>::insert_sort_(begin__, end__, less__);
}

template <typename UndirectionalRangeT_>
inline ProcessType insert_sort(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(DD_SPLIT_RANGE(range__)) {
	insert_sort(DD_SPLIT_RANGE(range__));
}

template <typename UndirectionalRangeT_, typename BinaryPredicatorT_>
inline ProcessType insert_sort(
	UndirectionalRangeT_& range__,
	BinaryPredicatorT_ const& less__
) DD_NOEXCEPT_AS(DD_SPLIT_RANGE(range__) DD_COMMA less__) {
	insert_sort(DD_SPLIT_RANGE(range__), less__);
}



DD_END_



#endif
