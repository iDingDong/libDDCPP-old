//	DDCPP/standard/bits/DD_merge.hpp
#ifndef DD_MERGE_HPP_INCLUDED_
#	define DD_MERGE_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_copy.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename UndirectionalIteratorT3_>
UndirectionalIteratorT3_ merge(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ const& end_2__,
	UndirectionalIteratorT3_ result_begin__
) DD_NOEXCEPT_AS(copy(begin_1__, end_1__, result_begin__) DD_COMMA copy(begin_2__, end_2__, result_begin__) DD_COMMA *begin_1__ < *begin_2__) {
	for (; begin_2__ != end_2__; ++result_begin__) {
		if (begin_1__ == end_1__) {
			return copy(begin_2__, end_2__, result_begin__);
		}
		if (*begin_1__ < *begin_2__) {
			*result_begin__ = *begin_1__;
			++begin_1__;
		} else {
			*result_begin__ = *begin_2__;
			++begin_1__;
		}
	}
	return copy(begin_1__, end_1__, result_begin__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename UndirectionalIteratorT3_, typename BinaryPredicateT_>
UndirectionalIteratorT3_ merge(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ const& end_2__,
	BinaryPredicateT_ less__,
	UndirectionalIteratorT3_ result_begin__
) DD_NOEXCEPT_AS(copy(begin_1__, end_1__, result_begin__) DD_COMMA copy(begin_2__, end_2__, result_begin__) DD_COMMA less__(*begin_1__, *begin_2__)) {
	for (; begin_2__ != end_2__; ++result_begin__) {
		if (begin_1__ == end_1__) {
			return copy(begin_2__, end_2__, result_begin__);
		}
		if (less__(*begin_1__, *begin_2__)) {
			*result_begin__ = *begin_1__;
			++begin_1__;
		} else {
			*result_begin__ = *begin_2__;
			++begin_1__;
		}
	}
	return copy(begin_1__, end_1__, result_begin__);
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_, typename UndirectionalIteratorT_>
inline UndirectionalIteratorT_ merge(
	UndirectionalRangeT1_& range_1__,
	UndirectionalRangeT2_& range_2__,
	UndirectionalIteratorT_ const& result_begin__
) DD_NOEXCEPT_AS(merge(DD_SPLIT_RANGE(range_1__) DD_COMMA DD_SPLIT_RANGE(range_2__) DD_COMMA result_begin__)) {
	return merge(DD_SPLIT_RANGE(range_1__) DD_COMMA DD_SPLIT_RANGE(range_2__) DD_COMMA result_begin__);
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_, typename UndirectionalIteratorT_, typename BinaryPredicateT_>
inline UndirectionalIteratorT_ merge(
	UndirectionalRangeT1_& range_1__,
	UndirectionalRangeT2_& range_2__,
	UndirectionalIteratorT_ const& result_begin__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(merge(DD_SPLIT_RANGE(range_1__) DD_COMMA DD_SPLIT_RANGE(range_2__) DD_COMMA result_begin__) DD_COMMA less__) {
	return merge(DD_SPLIT_RANGE(range_1__) DD_COMMA DD_SPLIT_RANGE(range_2__) DD_COMMA result_begin__, less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::merge;



DD_END_



#endif
