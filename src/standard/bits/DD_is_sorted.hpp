//	DDCPP/standard/bits/DD_is_sorted.hpp
#ifndef DD_IS_SORTED_HPP_INCLUDED_
#	define DD_IS_SORTED_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"
#	include "DD_IsFreeAccessIterator.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_>
struct IsSorted_ {
	template <typename UndirectionalIteratorT__>
	static ValidityType is_sorted_(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ const& end___
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

	template <typename UndirectionalIteratorT__, typename BinaryPredicatorT__>
	static ValidityType is_sorted_(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ const& end___,
		BinaryPredicatorT__ const& less___
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
	static ValidityType is_sorted_(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ const& end___
	) DD_NOEXCEPT_AS(++begin___ < end___ && *begin___ < *(begin___ - 1)) {
		while (++begin___ < end___) {
			if (*begin___ < *(begin___ - 1)) {
				return false;
			}
		}
		return true;
	}

	template <typename FreeAccessIteratorT__, typename BinaryPredicatorT__>
	static ValidityType is_sorted_(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ const& end___,
		BinaryPredicatorT__ const& less___
	) DD_NOEXCEPT_AS(++begin___ < end___ && less___(*begin___ DD_COMMA *(begin___ - 1))) {
		while (++begin___ < end___) {
			if (less___(*begin___, *(begin___ - 1))) {
				return false;
			}
		}
		return true;
	}


};



DD_DETAIL_END_



DD_BEGIN_
template <typename UndirectionalIteratorT_>
inline ValidityType is_sorted(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__
) DD_NOEXCEPT_AS(detail_::IsSorted_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_(begin__ DD_COMMA end__)) {
	return detail_::IsSorted_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_(begin__, end__);
}

template <typename UndirectionalIteratorT_, typename BinaryPredicatorT_>
inline ValidityType is_sorted(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__,
	BinaryPredicatorT_ const& less__
) DD_NOEXCEPT_AS(detail_::IsSorted_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_(begin__ DD_COMMA end__ DD_COMMA less__)) {
	return detail_::IsSorted_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::is_sorted_(begin__, end__, less__);
}



DD_END_



#endif
