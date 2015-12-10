//	DDCPP/standard/bits/DD_transform.hpp
#ifndef DD_TRANSFORM_HPP_INCLUDED_
#	define DD_TRANSFORM_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT1_, typename UnaryFunctionT_, typename UndirectionalIteratorT2_>
UndirectionalIteratorT2_ transform(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ end__,
	UnaryFunctionT_ function__,
	UndirectionalIteratorT2_ result_begin__
) {
	for (; begin__ != end__; ++begin__, ++result_begin__) {
		*result_begin__ = function__(*begin__);
	}
	return result_begin__;
}

template <typename UndirectionalIteratorT1_, typename UnaryFunctionT_, typename UndirectionalIteratorT2_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> transform(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ end__,
	UnaryFunctionT_ function__,
	UndirectionalIteratorT2_ result_begin__,
	UndirectionalIteratorT2_ result_end__
) {
	for (; begin__ != end__ && result_begin__ != result_end__; ++begin__, ++result_begin__) {
		*result_begin__ = function__(*begin__);
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>(begin__, result_begin__);
}


template <typename UndirectionalRangeT1_, typename UnaryFunctionT_, typename UndirectionalRangeT2_>
inline Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_), DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)> transform(
	UndirectionalRangeT1_& range__,
	UnaryFunctionT_ function__,
	UndirectionalRangeT2_& result_range__
) DD_NOEXCEPT_AS(static_cast<Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) DD_COMMA DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)>>(
	::DD::detail_::transform(DD_SPLIT_RANGE(range__) DD_COMMA function__ DD_COMMA DD_SPLIT_RANGE(result_range__))
)) {
	return ::DD::detail_::transform(DD_SPLIT_RANGE(range__), function__, DD_SPLIT_RANGE(result_range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::transform;



DD_END_



#endif
