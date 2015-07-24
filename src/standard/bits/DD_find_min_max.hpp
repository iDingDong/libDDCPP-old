//	standard/bits/DD_min_max_element.hpp
#ifndef _DD_FIND_MIN_MAX_HPP_INCLUDED
#	define _DD_FIND_MIN_MAX_HPP_INCLUDED 1



#	include "DD_Pair.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT>
Pair<_UndirectionalIteratorT> find_min_max(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end
) DD_NOEXCEPT_AS(++__begin != __end && *__begin < *__begin) {
	_UndirectionalIteratorT __min = __begin;
	_UndirectionalIteratorT __max = __begin;
	for (; __begin != __end; ++__begin) {
		if (*__begin < *__min) {
			__min = __begin;
		} else if (*__max < *__begin) {
			__max = __begin;
		}
	}
	return Pair<_UndirectionalIteratorT>{__min, __max};
}

template <typename _UndirectionalIteratorT, typename _BinaryPredicatorT>
Pair<_UndirectionalIteratorT> find_min_max(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_BinaryPredicatorT const& __less
) DD_NOEXCEPT_AS(++__begin != __end && __less(*__begin, *__begin)) {
	_UndirectionalIteratorT __min = __begin;
	_UndirectionalIteratorT __max = __begin;
	for (; __begin != __end; ++__begin) {
		if (__less(*__begin, *__min)) {
			__min = __begin;
		} else if (*__max < *__begin) {
			__max = __begin;
		}
	}
	return Pair<_UndirectionalIteratorT>{__min, __max};
}



DD_END



#endif
