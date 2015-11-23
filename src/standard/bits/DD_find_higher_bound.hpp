//	DDCPP/standard/bits/DD_higher_bound.hpp
#ifndef DD_HIGHER_BOUND_HPP_INCLUDED_
#	define DD_HIGHER_BOUND_HPP_INCLUDED_ 1



#	include "DD_middle.hpp"



DD_DETAIL_BEGIN_
template <IteratorCatagoryValue iterator_catagory_c_>
struct FindHigherBound_ {
	template <typename UndirectionalIteratorT__, typename ValueT__>
	static UndirectionalIteratorT__ find_higher_bound(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		ValueT__ const& value___
	) {
		while (begin___ != end___ && !(value___ < *begin___)) {
			++begin___;
		}
		return begin___;
	}

	template <typename UndirectionalIteratorT__, typename ValueT__, typename BinaryPredicatorT__>
	static UndirectionalIteratorT__ find_higher_bound(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		ValueT__ const& value___,
		BinaryPredicatorT__ less___
	) {
		while (!less___(value___, *begin___) && begin___ != end___) {
			++begin___;
		}
		return begin___;
	}


};



template <>
struct FindHigherBound_<IteratorCatagoryValue::bidirectional> {
	template <typename BidirectionalIteratorT__, typename ValueT__>
	static BidirectionalIteratorT__ find_higher_bound(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___,
		ValueT__ const& value___
	) {
		for (; begin___ != end___; --end___) {
			if (!(value___ < *end___)) {
				return ::DD::next(end___);
			}
		}
		return end___;
	}

	template <typename BidirectionalIteratorT__, typename ValueT__, typename BinaryPredicatorT__>
	static BidirectionalIteratorT__ find_higher_bound(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___,
		ValueT__ const& value___,
		BinaryPredicatorT__ less___
	) {
		for (; begin___ != end___; --end___) {
			if (!less___(value___, *end___)) {
				return ::DD::next(end___);
			}
		}
		return end___;
	}


};



template <>
struct FindHigherBound_<IteratorCatagoryValue::free_access> {
	template <typename FreeAccessIteratorT__, typename ValueT__>
	static FreeAccessIteratorT__ find_higher_bound(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		ValueT__ const& value___
	) {
		while (begin___ < end___) {
			FreeAccessIteratorT__ current___(middle(begin___, end___));
			if (value___ < *current___) {
				end___ = current___;
			} else {
				begin___ = current___ + 1;
			}
		}
		return end___;
	}

	template <typename FreeAccessIteratorT__, typename ValueT__, typename BinaryPredicateT__>
	static FreeAccessIteratorT__ find_higher_bound(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		ValueT__ const& value___,
		BinaryPredicateT__ less___
	) {
		while (begin___ < end___) {
			FreeAccessIteratorT__ current___(middle(begin___, end___));
			if (less___(value___, *current___)) {
				end___ = current___;
			} else {
				begin___ = current___ + 1;
			}
		}
		return end___;
	}


};



template <typename UndirectionalIteratorT_, typename ValueT_>
inline UndirectionalIteratorT_ find_higher_bound(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(
	FindHigherBound_<IteratorCatagory<UndirectionalIteratorT_>::value>::find_higher_bound(begin__ DD_COMMA end__ DD_COMMA value__)
)) {
	return FindHigherBound_<IteratorCatagory<UndirectionalIteratorT_>::value>::find_higher_bound(begin__, end__, value__);
}

template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicateT_>
inline UndirectionalIteratorT_ find_higher_bound(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ const& value__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(FindHigherBound_<
	IteratorCatagory<UndirectionalIteratorT_>::value
>::find_higher_bound(begin__ DD_COMMA end__ DD_COMMA value__ DD_COMMA less__))) {
	return FindHigherBound_<IteratorCatagory<UndirectionalIteratorT_>::value>::find_higher_bound(begin__, end__, value__, less__);
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_higher_bound(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::find_higher_bound(DD_SPLIT_RANGE(range__) DD_COMMA value__)
)) {
	return ::DD::detail_::find_higher_bound(DD_SPLIT_RANGE(range__), value__);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_higher_bound(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::find_higher_bound(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA less__)
)) {
	return ::DD::detail_::find_higher_bound(DD_SPLIT_RANGE(range__), value__, less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_higher_bound;



DD_END_



#endif
