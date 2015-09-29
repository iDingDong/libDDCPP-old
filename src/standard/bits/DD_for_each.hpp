// standard/bits/DD_for_each.hpp
#ifndef DD_FOR_EACH_HPP_INCLUDED_
#	define DD_FOR_EACH_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryFunctionT_>
inline ProcessType for_each(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryFunctionT_ const& function_
) DD_NOEXCEPT_AS(++begin__ != end__, operation(*begin__)) {
	for (; begin__ != end__; ++begin__) {
		function_(*begin__);
	}
}



template <typename UndirectionalRangeT_, typename UnaryFunctionT_>
inline ProcessType for_each(
	UndirectionalRangeT_ const& range__,
	UnaryFunctionT_ const& function_
) DD_NOEXCEPT(for_each(DD_SPLIT_RANGE(range__), function_)) {
	for_each(DD_SPLIT_RANGE(range__), function_);
}



DD_END_



#endif
