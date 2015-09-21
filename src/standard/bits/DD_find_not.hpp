//	DDCPP/standard/bits/DD_find_not.hpp
#ifndef _DD_FIND_NOT_HPP_INCLUDED
#	define _DD_FIND_NOT_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _UndirectionalIteratorT, typename _ValueT>
_UndirectionalIteratorT find_not(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT const& __value
) DD_NOEXCEPT_AS(__begin != __end && *++__begin == __value) {
	while (__begin != __end && *__begin == __value) {
		++__begin;
	}
	return __begin;
}

template <typename _UndirectionalIteratorT, typename _ValueT, typename _BinaryPredicatorT>
_UndirectionalIteratorT find_not(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT const& __value,
	_BinaryPredicatorT const& __equal
) DD_NOEXCEPT_AS(__begin != __end && __equal(*++__begin, __value)) {
	while (__begin != __end && __equal(*__begin, __value)) {
		++__begin;
	}
	return __begin;
}

template <typename _UndirectionalRangeT, typename _ValueT>
DD_MODIFY_TRAIT(Iterator, _UndirectionalRangeT) find_not(
	_UndirectionalRangeT& __range,
	_ValueT const& __value
) DD_NOEXCEPT_AS(find_not(DD_SPLIT_RANGE(__range) DD_COMMA __value)) {
	return find_not(DD_SPLIT_RANGE(__range), __value);
}

template <typename _UndirectionalRangeT, typename _ValueT, typename _BinaryPredicatorT>
inline DD_MODIFY_TRAIT(Iterator, _UndirectionalRangeT) find_not(
	_UndirectionalRangeT& __range,
	_ValueT const& __value,
	_BinaryPredicatorT const& __equal
) DD_NOEXCEPT_AS(find_not(DD_SPLIT_RANGE(__range) DD_COMMA __value DD_COMMA __equal)) {
	return find_not(DD_SPLIT_RANGE(__range), __value, __equal);
}



_DD_END



#endif
