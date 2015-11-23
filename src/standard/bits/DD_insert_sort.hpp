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
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
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

	template <typename UndirectionalIteratorT__, typename BinaryPredicateT__>
	static ProcessType insert_sort_(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		BinaryPredicateT__ less___
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
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___
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

	template <typename BidirectionalIteratorT__, typename BinaryPredicateT__>
	static ProcessType insert_sort_(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___,
		BinaryPredicateT__ less___
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



template <typename UndirectionalIteratorT_>
inline ProcessType insert_sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(
	InsertSort_<
		IsBidirectionalIterator<UndirectionalIteratorT_>::value
	>::insert_sort_(begin__ DD_COMMA end__)
) {
	InsertSort_<
		IsBidirectionalIterator<UndirectionalIteratorT_>::value
	>::insert_sort_(begin__, end__);
}

template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
inline ProcessType insert_sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(
	InsertSort_<
		IsBidirectionalIterator<UndirectionalIteratorT_>::value
	>::insert_sort_(begin__ DD_COMMA end__ DD_COMMA less__)
) {
	InsertSort_<
		IsBidirectionalIterator<UndirectionalIteratorT_>::value
	>::insert_sort_(begin__, end__, less__);
}

template <typename UndirectionalRangeT_>
inline ProcessType insert_sort(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(::DD::detail_::insert_sort(DD_SPLIT_RANGE(range__))) {
	::DD::detail_::insert_sort(DD_SPLIT_RANGE(range__));
}

template <typename UndirectionalRangeT_, typename BinaryPredicateT_>
inline ProcessType insert_sort(
	UndirectionalRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(::DD::detail_::insert_sort(DD_SPLIT_RANGE(range__) DD_COMMA less__)) {
	::DD::detail_::insert_sort(DD_SPLIT_RANGE(range__), less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::insert_sort;



DD_END_



#endif
