//	DDCPP/standard/bits/DD_find_lower_bound.hpp
#ifndef DD_FIND_LOWER_BOUND_HPP_INCLUDED_
#	define DD_FIND_LOWER_BOUND_HPP_INCLUDED_ 1



#	include "DD_middle.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_c_>
struct FindLowerBound_ {
	template <typename UndirectionalIteratorT__, typename ValueT__>
	static UndirectionalIteratorT__ find_lower_bound(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ const& end___,
		ValueT__ const& value___
	) DD_NOEXCEPT_AS(*begin___ < value___ && ++begin___ != end___) {
		while (*begin___ < value___ && begin___ != end___) {
			++begin___;
		}
		return begin___;
	}

	template <typename UndirectionalIteratorT__, typename ValueT__, typename BinaryPredicatorT__>
	static UndirectionalIteratorT__ find_lower_bound(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ const& end___,
		ValueT__ const& value___,
		BinaryPredicatorT__ less___
	) DD_NOEXCEPT_AS(less__(*begin___ DD_COMMA value___) && ++begin___ != end___) {
		while (less___(*begin___, value___) && begin___ != end___) {
			++begin___;
		}
		return begin___;
	}


};



template <>
struct FindLowerBound_<true> {
	template <typename FreeAccessIteratorT__, typename ValueT__>
	static FreeAccessIteratorT__ find_lower_bound(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		ValueT__ const& value___
	) DD_NOEXCEPT_AS(begin___ < end___ && *middle(begin___ DD_COMMA end___) < value___) {
		while (begin___ < end___) {
			FreeAccessIteratorT__ current___ = middle(begin___, end___);
			if (*current___ < value___) {
				begin___ = current___ + 1;
			} else {
				end___ = current___;
			}
		}
		return begin___;
	}

	template <typename FreeAccessIteratorT__, typename ValueT__, typename BinaryPredicatorT__>
	static FreeAccessIteratorT__ find_lower_bound(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		ValueT__ const& value___,
		BinaryPredicatorT__ less___
	) DD_NOEXCEPT_AS(begin___ < end___ && less___(*middle(begin___ DD_COMMA end___) DD_COMMA value___)) {
		while (begin___ < end___) {
			FreeAccessIteratorT__ current___ = middle(begin___, end___);
			if (less___(*current___, value___)) {
				begin___ = current___ + 1;
			} else {
				end___ = current___;
			}
		}
		return begin___;
	}


};



template <typename UndirectionalIteratorT_, typename ValueT_>
inline UndirectionalIteratorT_ find_lower_bound(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(FindLowerBound_<
	IsFreeAccessIterator<UndirectionalIteratorT_>::value
>::find_lower_bound(begin__ DD_COMMA end__ DD_COMMA value__))) {
	return FindLowerBound_<
		IsFreeAccessIterator<UndirectionalIteratorT_>::value
	>::find_lower_bound(begin__, end__, value__);
}

template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicatorT_>
inline UndirectionalIteratorT_ find_lower_bound(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__,
	BinaryPredicatorT_ less__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(FindLowerBound_<
	IsFreeAccessIterator<UndirectionalIteratorT_>::value
>::find_lower_bound(begin__ DD_COMMA end__ DD_COMMA value__ DD_COMMA less__))) {
	return FindLowerBound_<
		IsFreeAccessIterator<UndirectionalIteratorT_>::value
	>::find_lower_bound(begin__, end__, value__, less__);
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_lower_bound(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::find_lower_bound(DD_SPLIT_RANGE(range__) DD_COMMA value__)
)) {
	return ::DD::detail_::find_lower_bound(DD_SPLIT_RANGE(range__), value__);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryPredicatorT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_lower_bound(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicatorT_ less__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::find_lower_bound(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA less__)
)) {
	return ::DD::detail_::find_lower_bound(DD_SPLIT_RANGE(range__), value__, less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_lower_bound;



DD_END_



#endif
