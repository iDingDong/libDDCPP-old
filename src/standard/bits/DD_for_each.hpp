// standard/bits/DD_for_each.hpp
#ifndef _DD_FOR_EACH_HPP_INCLUDED
#	define _DD_FOR_EACH_HPP_INCLUDED 1



#	include "DD_Range.hpp"



_DD_BEGIN
template <typename _UndirectionalIteratorT, typename _UnaryFunctionT>
inline ProcessType for_each(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_UnaryFunctionT const& _function
) DD_NOEXCEPT_AS(++__begin != __end, operation(*__begin)) {
	for (; __begin != __end; ++__begin) {
		_function(*__begin);
	}
}



template <typename _UndirectionalRangeT, typename _UnaryFunctionT>
inline ProcessType for_each(
	_UndirectionalRangeT const& __range,
	_UnaryFunctionT const& _function
) DD_NOEXCEPT(for_each(DD_SPLIT_RANGE(__range), _function)) {
	for_each(DD_SPLIT_RANGE(__range), _function);
}



_DD_END



#endif
