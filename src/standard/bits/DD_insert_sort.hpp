//	DDCPP/standard/bits/DD_insert_sort.hpp
#ifndef DD_INSERT_SORT_HPP_INCLUDED_
#	define DD_INSERT_SORT_HPP_INCLUDED_


#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	else
#		include "DD_IteratorValue.hpp"
#	endif
#	include "DD_IteratorCatagory.hpp"
#	include "DD_find_min.hpp"
#	include "DD_find_max.hpp"
#	include "DD_swap_target.hpp"
#	include "DD_transfer_forward.hpp"



DD_DETAIL_BEGIN_
template <IteratorCatagoryValue iterator_catagory_c_>
struct InsertSort_ {
	template <typename UndirectionalIteratorT__>
	static ProcessType insert_sort(
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
	static ProcessType insert_sort(
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
struct InsertSort_<IteratorCatagoryValue::bidirectional> {
	template <typename BidirectionalIteratorT__>
	static ProcessType insert_sort(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___
	) DD_NOEXCEPT_IF(
		noexcept(IteratorValueType<BidirectionalIteratorT__>(move(*begin___))) &&
		noexcept(::DD::find_min(begin___ DD_COMMA end___))
	) {
		if (begin___ != end___) {
			swap_target(begin___, ::DD::find_min(begin___, end___));
			for (BidirectionalIteratorT__ current___(begin___), front___; ++current___ != end___; ) {
				front___ = current___;
#	if __cplusplus >= 201103L
				auto temp_ = move(*front___);
				for (auto previous___(front___); temp_ < *--previous___; ) {
					*front___ = move(*previous___);
					--front___;
				}
				*front___ = move(temp_);
#	else
				typename IteratorValue<BidirectionalIteratorT__>::Type temp_ = *current___;
				for (BidirectionalIteratorT__ previous___(front___); temp_ < *--previous___; ) {
					*front___ = *previous___;
					--front___;
				}
				*front___ = temp_;
#	endif
			}
		}
	}

	template <typename BidirectionalIteratorT__, typename BinaryPredicateT__>
	static ProcessType insert_sort(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___,
		BinaryPredicateT__ less___
	) DD_NOEXCEPT_IF(
		noexcept(IteratorValueType<BidirectionalIteratorT__>(move(*begin___))) &&
		noexcept(::DD::find_min(begin___ DD_COMMA end___ DD_COMMA less___))
	) {
		if (begin___ != end___) {
			swap_target(begin___, ::DD::find_min(begin___, end___, less___));
			for (BidirectionalIteratorT__ current___(begin___), front___; ++current___ != end___; ) {
				front___ = current___;
#	if __cplusplus >= 201103L
				auto temp_ = move(*front___);
				for (auto previous___(front___); less___(temp_, *--previous___); ) {
					*front___ = move(*previous___);
					--front___;
				}
				*front___ = move(temp_);
#	else
				typename IteratorValue<BidirectionalIteratorT__>::Type temp_ = *current___;
				for (BidirectionalIteratorT__ previous___(front___); less___(temp_, *--previous___); ) {
					*front___ = *previous___;
					--front___;
				}
				*front___ = temp_;
#	endif
			}
		}
	}


};



template <>
struct InsertSort_<IteratorCatagoryValue::free_access> {
	template <typename FreeAccessIteratorT__>
	static ProcessType insert_sort(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___
	) DD_NOEXCEPT_IF(
		noexcept(++begin___ < --end___ - 1) &&
		noexcept(swap_target(::DD::find_max(begin___ DD_COMMA end___) DD_COMMA end___ - 1)) &&
		noexcept(transfer_forward(begin___ DD_COMMA end___))
	) {
		if (begin___ < end___ - 1) {
			swap_target(::DD::find_max(begin___, end___), end___ - 1);
			FreeAccessIteratorT__ current___(end___ - 3);
			for (; begin___ < current___; --current___) {
				FreeAccessIteratorT__ front___(current___ + 1);
				while (*front___ < *current___) {
					++front___;
				}
				transfer_forward(current___, front___ - 1);
			}
		}
	}

	template <typename FreeAccessIteratorT__, typename BinaryPredicateT__>
	static ProcessType insert_sort(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		BinaryPredicateT__ less___
	) DD_NOEXCEPT_IF(
		noexcept(++begin___ < --end___ - 1) &&
		noexcept(swap_target(::DD::find_max(begin___ DD_COMMA end___ DD_COMMA less___) DD_COMMA end___ - 1)) &&
		noexcept(transfer_forward(begin___ DD_COMMA end___))
	) {
		if (begin___ < end___ - 1) {
			swap_target(::DD::find_max(begin___, end___, less___), end___ - 1);
			FreeAccessIteratorT__ current___(end___ - 3);
			for (; begin___ < current___; -- current___) {
				FreeAccessIteratorT__ front___(current___ + 1);
				while (less___(*front___, *current___)) {
					++front___;
				}
				transfer_forward(current___, front___ - 1);
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
		IteratorCatagory<UndirectionalIteratorT_>::value
	>::insert_sort(begin__ DD_COMMA end__)
) {
	InsertSort_<
		IteratorCatagory<UndirectionalIteratorT_>::value
	>::insert_sort(begin__, end__);
}

template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
inline ProcessType insert_sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(
	InsertSort_<
		IteratorCatagory<UndirectionalIteratorT_>::value
	>::insert_sort(begin__ DD_COMMA end__ DD_COMMA less__)
) {
	InsertSort_<
		IteratorCatagory<UndirectionalIteratorT_>::value
	>::insert_sort(begin__, end__, less__);
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
