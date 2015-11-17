//	DDCPP/standard/bits/DD_replace.hpp
#ifndef DD_REPLACE_HPP_INCLUDED_
#	define DD_REPLACE_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT1_, typename ValueT2_>
ProcessType replace(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT1_ const& old__,
	ValueT2_ const& value__
) DD_NOEXCEPT_AS(*++begin__ = value__ DD_COMMA begin__ != end__ && *begin__ == old__) {
	for (; begin__ != end__; ++begin__) {
		if (*begin__ == old__) {
			*begin__ = value__;
		}
	}
}

template <typename UndirectionalIteratorT_, typename ValueT1_, typename BinaryPredicatorT_, typename ValueT2_>
ProcessType replace(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT1_ const& old__,
	BinaryPredicatorT_ equal__,
	ValueT2_ const& value__
) DD_NOEXCEPT_AS(*++begin__ = value__ DD_COMMA begin__ != end__ && equal__(*begin__, old__)) {
	for (; begin__ != end__; ++begin__) {
		if (equal__(*begin__, old__)) {
			*begin__ = value__;
		}
	}
}

template <typename UndirectionalRangeT_, typename ValueT1_, typename ValueT2_>
ProcessType replace(
	UndirectionalRangeT_& range__,
	ValueT1_ const& old__,
	ValueT2_ const& value__
) DD_NOEXCEPT_AS(replace(DD_SPLIT_RANGE(range__) DD_COMMA old__ DD_COMMA value__)) {
	replace(DD_SPLIT_RANGE(range__), old__, value__);
}

template <typename UndirectionalRangeT_, typename ValueT1_, typename BinaryPredicatorT_, typename ValueT2_>
ProcessType replace(
	UndirectionalRangeT_& range__,
	ValueT1_ const& old__,
	BinaryPredicatorT_ equal__,
	ValueT2_ const& value__
) DD_NOEXCEPT_AS(replace(DD_SPLIT_RANGE(range__) DD_COMMA old__ DD_COMMA equal__ DD_COMMA value__)) {
	replace(DD_SPLIT_RANGE(range__), old__, equal__, value__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::replace;



DD_END_



#endif
