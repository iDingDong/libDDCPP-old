//	standard/bits/DD_find.hpp
#ifndef _DD_FIND_HPP_INCLUDED
#	define _DD_FIND_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _ValueT>
_UndirectionalIteratorT find(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT const& __value
) DD_NOEXCEPT_AS(__begin != __end && *++__begin != __value) {
	while (__begin != __end && *__begin != __value) {
		++__begin;
	}
	return __begin;
}

template <typename _UndirectionalIteratorT, typename _ValueT, typename _BinaryPredicator>
_UndirectionalIteratorT find(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT const& __value,
	_BinaryPredicator const& __equal
) DD_NOEXCEPT_AS(__begin != __end && __equal(*++__begin, __value)) {
	while (__begin != __end && __equal(*__begin, __value)) {
		++__begin;
	}
	return __begin;
}



DD_END



#endif
