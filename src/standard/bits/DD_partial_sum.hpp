//	DDCPP/standard/bits/DD_partial_sum.hpp
#ifndef DD_PARTIAL_SUM_INCLUDED_
#	define DD_PARTIAL_SUM_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_next.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
UndirectionalIteratorT2_ partial_sum(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ end__,
	UndirectionalIteratorT2_ result_begin__
) {
	if (begin__ != end__) {
		*result_begin__ = *begin__;
		for (; ++begin__ != end__; ++result_begin__) {
			*::DD::next(result_begin__) = *result_begin__ + *begin__;
		}
	}
	return result_begin__;
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryFunctionT_>
UndirectionalIteratorT2_ partial_sum(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ end__,
	UndirectionalIteratorT2_ result_begin__,
	BinaryFunctionT_ add__
) {
	if (begin__ != end__) {
		*result_begin__ = *begin__;
		for (; ++begin__ != end__; ++result_begin__) {
			*::DD::next(result_begin__) = add__(*result_begin__, *begin__);
		}
	}
	return result_begin__;
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> partial_sum(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ end__,
	UndirectionalIteratorT1_ result_begin__,
	UndirectionalIteratorT1_ result_end__
) {
	if (begin__ != end__ && result_begin__ != result_end__) {
		*result_begin__ = *begin__;
		for (; ++begin__ != end__ && ::DD::next(result_end__) != end__; ++result_begin__) {
			*::DD::next(result_begin__) = *result_begin__ + *begin__;
		}
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>(begin__, result_begin__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryFunctionT_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> partial_sum(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ end__,
	UndirectionalIteratorT1_ result_begin__,
	UndirectionalIteratorT1_ result_end__,
	BinaryFunctionT_ add__
) {
	if (begin__ != end__ && result_begin__ != result_end__) {
		*result_begin__ = *begin__;
		for (; ++begin__ != end__ && ::DD::next(result_end__) != end__; ++result_begin__) {
			*::DD::next(result_begin__) = add__(*result_begin__, *begin__);
		}
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>(begin__, result_begin__);
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_>
inline Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_), DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)> partial_sum(
	UndirectionalRangeT1_& range__,
	UndirectionalRangeT1_& result_range__
) DD_NOEXCEPT_AS(static_cast<Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) DD_COMMA DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)>>(
	::DD::detail_::partial_sum(DD_SPLIT_RANGE(range__) DD_COMMA DD_SPLIT_RANGE(result_range__))
)) {
	return ::DD::detail_::partial_sum(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(result_range__));
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_, typename BinaryFunctionT_>
inline Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_), DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)> partial_sum(
	UndirectionalRangeT1_& range__,
	UndirectionalRangeT1_& result_range__,
	BinaryFunctionT_ add__
) DD_NOEXCEPT_AS(static_cast<Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) DD_COMMA DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)>>(
	::DD::detail_::partial_sum(DD_SPLIT_RANGE(range__) DD_COMMA DD_SPLIT_RANGE(result_range__) DD_COMMA add__)
)) {
	return ::DD::detail_::partial_sum(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(result_range__), add__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::partial_sum;



DD_END_



#endif
