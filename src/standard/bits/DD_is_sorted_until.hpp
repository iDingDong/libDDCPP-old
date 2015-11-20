//	DDCPP/standard/bits/DD_is_sorted_until.hpp
#ifndef DD_IS_SORTED_UNTIL_HPP_INCLUDED_
#	define DD_IS_SORTED_UNTIL_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"
#	include "DD_IsFreeAccessIterator.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_>
struct IsSortedUntil_ {
	template <typename UndirectionalIteratorT__>
	static UndirectionalIteratorT__ is_sorted_until_(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ const& end___
	) DD_NOEXCEPT_AS(++begin___ != end___ && *begin___ < *begin___ DD_COMMA UndirectionalIteratorT__(begin___)) {
		if (begin___ != end___) {
			for (UndirectionalIteratorT__ front___(begin___); ++begin___ != end___ && !(*begin___ < *front___); ) {
				front___ = begin___;
			}
		}
		return begin___;
	}

	template <typename UndirectionalIteratorT__, typename BinaryPredicateT__>
	static UndirectionalIteratorT__ is_sorted_until_(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ const& end___,
		BinaryPredicateT__ const& less___
	) DD_NOEXCEPT_AS(++begin___ != end___ && less___(*begin___ DD_COMMA *begin___) DD_COMMA UndirectionalIteratorT__(begin___)) {
		if (begin___ != end___) {
			for (UndirectionalIteratorT__ front___(begin___); ++begin___ != end___ && !less___(*begin___, *front___); ) {
				front___ = begin___;
			}
		}
		return begin___;
	}


};



template <>
struct IsSortedUntil_<true> {
	template <typename FreeAccessIteratorT__>
	static FreeAccessIteratorT__ is_sorted_until_(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ const& end___
	) DD_NOEXCEPT_AS(++begin___ < end___ && *begin___ < *(begin___ - 1)) {
		while (++begin___ < end___ && !(*begin___ < *(begin___ - 1))) {
		}
		return begin___;
	}

	template <typename FreeAccessIteratorT__, typename BinaryPredicateT__>
	static FreeAccessIteratorT__ is_sorted_until_(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ const& end___,
		BinaryPredicateT__ const& less___
	) DD_NOEXCEPT_AS(++begin___ < end___ && less___(*begin___ DD_COMMA *(begin___ - 1))) {
		while (++begin___ < end___ && !less___(*begin___, *(begin___ - 1))) {
		}
		return begin___;
	}


};



DD_DETAIL_END_



DD_BEGIN_
template <typename UndirectionalIteratorT_>
inline UndirectionalIteratorT_ is_sorted_until(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__
) DD_NOEXCEPT_AS(detail_::IsSortedUntil_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_until_(begin__ DD_COMMA end__)) {
	return detail_::IsSortedUntil_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_until_(begin__, end__);
}

template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
inline UndirectionalIteratorT_ is_sorted_until(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__,
	BinaryPredicateT_ const& less__
) DD_NOEXCEPT_AS(detail_::IsSortedUntil_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_until_(begin__ DD_COMMA end__ DD_COMMA less__)) {
	return detail_::IsSortedUntil_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_until_(begin__, end__, less__);
}



DD_END_



#endif
