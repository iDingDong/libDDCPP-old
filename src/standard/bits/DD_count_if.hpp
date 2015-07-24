//	standard/bits/DD_count_if.hpp
#ifndef _DD_COUNT_IF_HPP_INCLUDED
#	define _DD_COUNT_IF_HPP_INCLUDED 1



#	include "DD_IteratorDifference.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _UnaryPredicator>
DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT) count_if(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_UnaryPredicator const& __predicator
) DD_NOEXCEPT_AS(++__begin != __end && __predicator(*__begin)) {
#	if __cplusplus >= 201103L
	auto _result = DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT)();
#	else
	typedef DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT) _ResultType;
	_ResultType _result = _ResultType();
#	endif
	for (; __begin != __end; ++__begin) {
		if (__predicator(*__begin)) {
			++_result;
		}
	}
	return _result;
}



DD_END



#endif
