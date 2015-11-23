//	DDCPP/standard/bits/DD_fill.hpp
#ifndef DD_FILL_HPP_INCLUDED_
#	define DD_FILL_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_>
inline ProcessType fill(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(*++begin__ = value__ DD_COMMA begin__ != end__) {
	for (; begin__ != end__; ++begin__) {
		*begin__ = value__;
	}
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline ProcessType fill(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(::DD::detail_::fill(DD_SPLIT_RANGE(range__) DD_COMMA value__)) {
	::DD::detail_::fill(DD_SPLIT_RANGE(range__), value__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::fill;



DD_END_



#endif
