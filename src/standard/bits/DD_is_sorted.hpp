//	DDCPP/standard/bits/DD_is_sorted.hpp
#ifndef DD_IS_SORTED_HPP_INCLUDED_
#	define DD_IS_SORTED_HPP_INCLUDED_ 1



#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_>
struct IsSorted_ {
	template <typename UndirectionalIteratorT__>
	static ValidityType is_sorted(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(++begin___ != end___ && *begin___ < *begin___ DD_COMMA UndirectionalIteratorT__(begin___)) {
		if (begin___ != end___) {
			UndirectionalIteratorT__ front___(begin___);
			for (; ++begin___ != end___; front___ = begin___) {
				if (*begin___ < *front___) {
					return false;
				}
			}
		}
		return true;
	}

	template <typename UndirectionalIteratorT__, typename BinaryPredicateT__>
	static ValidityType is_sorted(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		BinaryPredicateT__ const& less___
	) DD_NOEXCEPT_AS(++begin___ != end___ && less___(*begin___ DD_COMMA *begin___) DD_COMMA UndirectionalIteratorT__(begin___)) {
		if (begin___ != end___) {
			UndirectionalIteratorT__ front___(begin___);
			for (; ++begin___ != end___; front___ = begin___) {
				if (less___(*begin___, *front___)) {
					return false;
				}
			}
		}
		return true;
	}


};



template <>
struct IsSorted_<true> {
	template <typename FreeAccessIteratorT__>
	static ValidityType is_sorted(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___
	) DD_NOEXCEPT_AS(++begin___ < end___ && *begin___ < *(begin___ - 1)) {
		while (++begin___ < end___) {
			if (*begin___ < *(begin___ - 1)) {
				return false;
			}
		}
		return true;
	}

	template <typename FreeAccessIteratorT__, typename BinaryPredicateT__>
	static ValidityType is_sorted(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		BinaryPredicateT__ const& less___
	) DD_NOEXCEPT_AS(++begin___ < end___ && less___(*begin___ DD_COMMA *(begin___ - 1))) {
		while (++begin___ < end___) {
			if (less___(*begin___, *(begin___ - 1))) {
				return false;
			}
		}
		return true;
	}


};



template <typename UndirectionalIteratorT_>
inline ValidityType is_sorted(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(IsSorted_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted(begin__ DD_COMMA end__)) {
	return IsSorted_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted(begin__, end__);
}

template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
inline ValidityType is_sorted(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(IsSorted_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted(begin__ DD_COMMA end__ DD_COMMA less__)) {
	return IsSorted_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted(begin__, end__, less__);
}

template <typename UndirectionalRangeT_>
inline ValidityType is_sorted(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(::DD::detail_::is_sorted(DD_SPLIT_RANGE(range__)))) {
	return ::DD::detail_::is_sorted(DD_SPLIT_RANGE(range__));
}

template <typename UndirectionalRangeT_, typename BinaryPredicateT_>
inline ValidityType is_sorted(
	UndirectionalRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(::DD::detail_::is_sorted(DD_SPLIT_RANGE(range__) DD_COMMA less__))) {
	return ::DD::detail_::is_sorted(DD_SPLIT_RANGE(range__), less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::is_sorted;



DD_END_



#endif
