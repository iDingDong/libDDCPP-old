// standard/bits/DD_for_each.hpp
#ifndef DD_FOR_EACH_HPP_INCLUDED_
#	define DD_FOR_EACH_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryFunctionT_>
inline UnaryFunctionT_ for_each(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	UnaryFunctionT_ function_
) DD_NOEXCEPT_AS(++begin__ != end__ DD_COMMA function_(*begin__)) {
	for (; begin__ != end__; ++begin__) {
		function_(*begin__);
	}
	return function_;
}



template <typename UndirectionalRangeT_, typename UnaryFunctionT_>
inline UnaryFunctionT_ for_each(
	UndirectionalRangeT_& range__,
	UnaryFunctionT_ function_
) DD_NOEXCEPT_AS(static_cast<UnaryFunctionT_>(::DD::detail_::for_each(DD_SPLIT_RANGE(range__) DD_COMMA function_))) {
	return ::DD::detail_::for_each(DD_SPLIT_RANGE(range__), function_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::for_each;



DD_END_



#endif
