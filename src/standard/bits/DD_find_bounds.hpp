//	DDCPP/standard/bits/DD_find_bounds.hpp
#ifndef DD_FIND_BOUNDS_HPP_INCLUDED_
#	define DD_FIND_BOUNDS_HPP_INCLUDED_ 1



#	include "DD_find_lower_bound.hpp"
#	include "DD_find_higher_bound.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_c_>
struct FindBounds_ {
	template <typename UndirectionalIteratorT__, typename ValueT__, typename BinaryPredicateT__>
	static Range<UndirectionalIteratorT__> find_bounds(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		ValueT__ const& value___,
		BinaryPredicateT__ less___
	) {
		for (; begin___ != end___; ++begin___) {
			if (!less___(*begin___, value___)) {
				UndirectionalIteratorT__ current___ = begin___;
				while (!less___(value___, *current___) && ++current___ != end___) {
				}
				return Range<UndirectionalIteratorT__>(begin___, current___);
			}
		}
		return Range<UndirectionalIteratorT__>(begin___, begin___);
	}


};



template <>
struct FindBounds_<true> {
	template <typename FreeAccessIteratorT__, typename ValueT__, typename BinaryPredicateT__>
	static Range<FreeAccessIteratorT__> find_bounds(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		ValueT__ const& value___,
		BinaryPredicateT__ less___
	) {
		while (begin___ < end___) {
			FreeAccessIteratorT__ current___(middle(begin___, end___));
			if (less___(*current___, value___)) {
				begin___ = current___ + 1;
			} else if (less___(value___, *current___)) {
				end___ = current___;
			} else {
				return Range<FreeAccessIteratorT__>(
					::DD::find_lower_bound(begin___, current___, value___, less___),
					::DD::find_higher_bound(current___ + 1, end___, value___, less___)
				);
			}
		}
		return Range<FreeAccessIteratorT__>(begin___, end___);
	}


};



template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicateT_>
Range<UndirectionalIteratorT_> find_bounds(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ const& value__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<Range<UndirectionalIteratorT_>>(
	FindBounds_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::find_bounds(begin__ DD_COMMA end__ DD_COMMA value__ DD_COMMA less__)
)) {
	return FindBounds_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::find_bounds(begin__, end__, value__, less__);
}

template <typename UndirectionalIteratorT_, typename ValueT_>
inline Range<UndirectionalIteratorT_> find_bounds(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<Range<UndirectionalIteratorT_>>(
	::DD::detail_::find_bounds(begin__ DD_COMMA end__ DD_COMMA less_than)
)) {
	return ::DD::detail_::find_bounds(begin__, end__, less_than);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryPredicateT_>
Range<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)> find_bounds(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<Range<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>>(
	::DD::detail_::find_bounds(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA less__)
)) {
	return ::DD::detail_::find_bounds(DD_SPLIT_RANGE(range__), value__, less__);
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline Range<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)> find_bounds(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<Range<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>>(
	::DD::detail_::find_bounds(range__ DD_COMMA value__ DD_COMMA less_than)
)) {
	return ::DD::detail_::find_bounds(range__, value__, less_than);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_bounds;



DD_END_



#endif
