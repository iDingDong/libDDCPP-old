//	standard/bits/DD_count.hpp
#ifndef _DD_COUNT_HPP_INCLUDED
#	define _DD_COUNT_HPP_INCLUDED 1



#	include "DD_IteratorDifference.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _ValueT>
DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT) count(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT const& __value
) DD_NOEXCEPT_AS(++__begin != __end && *__begin == __value) {
#	if __cplusplus >= 201103L
	auto _result = DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT)();
#	else
	typedef DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT) _ResultType;
	_ResultType _result = _ResultType();
#	endif
	for (; __begin != __end; ++__begin) {
		if (*__begin == __value) {
			++_result;
		}
	}
	return _result;
}

template <typename _UndirectionalIteratorT, typename _ValueT, typename _BinaryPredicator>
DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT) count(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT const& __value,
	_BinaryPredicator const& __equal
) DD_NOEXCEPT_AS(++__begin != __end && __equal(*__begin, __value)) {
#	if __cplusplus >= 201103L
	auto _result = DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT)();
#	else
	typedef DD_MODIFY_TRAIT(IteratorDifference, _UndirectionalIteratorT) _ResultType;
	_ResultType _result = _ResultType();
#	endif
	for (; __begin != __end; ++__begin) {
		if (__equal(*__begin, __value)) {
			++_result;
		}
	}
	return _result;
}



DD_END



#endif
