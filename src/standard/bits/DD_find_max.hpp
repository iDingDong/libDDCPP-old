//	DDCPP/standard/bits/DD_find_max.hpp
#ifndef _DD_FIND_MAX_HPP_INCLUDED
#	define _DD_FIND_MAX_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _UndirectionalIteratorT>
_UndirectionalIteratorT find_max(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end
) DD_NOEXCEPT_AS(++__begin != __end && *__begin < *__begin) {
	_UndirectionalIteratorT __max = __begin;
	for (; __begin != __end; ++__begin) {
		if (*__max < *__begin) {
			__max = __begin;
		}
	}
	return __max;
}

template <typename _UndirectionalIteratorT, typename _BinaryPredicatorT>
_UndirectionalIteratorT find_max(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_BinaryPredicatorT const& __less
) DD_NOEXCEPT_AS(++__begin != __end && __less(*__begin, *__begin)) {
	_UndirectionalIteratorT __max = __begin;
	for (; __begin != __end; ++__begin) {
		if (__less(*__max, *__begin)) {
			__max = __begin;
		}
	}
	return __max;
}



_DD_END



#endif
