//	standard/bits/DD_find_min.hpp
#ifndef _DD_FIND_MIN_HPP_INCLUDED
#	define _DD_FIND_MIN_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT>
_UndirectionalIteratorT find_min(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end
) DD_NOEXCEPT_AS(++__begin != __end && *__begin < *__begin) {
	_UndirectionalIteratorT __min = __begin;
	for (; __begin != __end; ++__begin) {
		if (*__begin < *__min) {
			__min = __begin;
		}
	}
	return __min;
}

template <typename _UndirectionalIteratorT, typename _BinaryPredicator>
_UndirectionalIteratorT find_min(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_BinaryPredicator const& __less
) DD_NOEXCEPT_AS(++__begin != __end && __less(*__begin, *__begin)) {
	_UndirectionalIteratorT __min = __begin;
	for (; __begin != __end; ++__begin) {
		if (__less(*__begin, *__min)) {
			__min = __begin;
		}
	}
	return __min;
}



DD_END



#endif
