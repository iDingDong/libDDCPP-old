//	DDCPP/standard/bits/DD_mismatch.hpp
#ifndef DD_MISMATCH_HPP_INCLUDED_
#	define DD_MISMATCH_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> mismatch(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__
) DD_NOEXCEPT_AS(begin_1__ != end_1__ && *++begin_1__ == *++begin_2__) {
	while (begin_1__ != end_1__ && *begin_1__ == *begin_2__) {
		++begin_1__;
		++begin_2__;
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>(begin_1__, begin_2__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> mismatch(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ const& end_2__
) DD_NOEXCEPT_AS(begin_1__ != end_1__ && begin_2__ != end_2__ && *++begin_1__ == *++begin_2__) {
	while (begin_1__ != end_1__ && begin_2__ != end_2__ && *begin_1__ == *begin_2__) {
		++begin_1__;
		++begin_2__;
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>(begin_1__, begin_2__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicateT_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> mismatch(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(begin_1__ != end_1__ && equal__(*++begin_1__, *++begin_2__)) {
	while (begin_1__ != end_1__ && equal__(*begin_1__, *begin_2__)) {
		++begin_1__;
		++begin_2__;
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>(begin_1__, begin_2__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicateT_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> mismatch(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ const& end_2__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(begin_1__ != end_1__ && begin_2__ != end_2__ && equal__(*++begin_1__, *++begin_2__)) {
	while (begin_1__ != end_1__ && begin_2__ != end_2__ && equal__(*begin_1__, *begin_2__)) {
		++begin_1__;
		++begin_2__;
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>(begin_1__, begin_2__);
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_>
inline Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_), DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)> mismatch(
	UndirectionalRangeT1_& range_1__,
	UndirectionalRangeT2_& range_2__
) DD_NOEXCEPT_AS(static_cast<Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) DD_COMMA DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)>>(
	::DD::detail_::mismatch(DD_SPLIT_RANGE(range_1__) DD_COMMA DD_SPLIT_RANGE(range_2__))
)) {
	return ::DD::detail_::mismatch(DD_SPLIT_RANGE(range_1__), DD_SPLIT_RANGE(range_2__));
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_, typename BinaryPredicateT_>
inline Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_), DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)> mismatch(
	UndirectionalRangeT1_& range_1__,
	UndirectionalRangeT2_& range_2__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(static_cast<Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) DD_COMMA DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)>>(
	::DD::detail_::mismatch(DD_SPLIT_RANGE(range_1__) DD_COMMA DD_SPLIT_RANGE(range_2__) DD_COMMA equal__)
)) {
	return ::DD::detail_::mismatch(DD_SPLIT_RANGE(range_1__), DD_SPLIT_RANGE(range_2__), equal__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::mismatch;



DD_END_



#endif
