//	DDCPP/standard/bits/DD_find_first_of.hpp
#ifndef _DD_FIRST_OF_HPP_INCLUDED
#	define _DD_FIRST_OF_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIterator1, typename _UndirectionalIterator2>
_UndirectionalIterator1 find_first_of(
	_UndirectionalIterator1 __begin,
	_UndirectionalIterator1 const& __end,
	_UndirectionalIterator2 const& __sample_begin,
	_UndirectionalIterator2 const& __sample_end
) DD_NOEXCEPT_AS(++__begin != __end && *__begin == *++const_cast<_UndirectionalIterator2&>(__sample_begin)) {
	for (; __begin != __end; ++__begin) {
		for (_UndirectionalIterator2 __current = __sample_begin; __current != __sample_end; ++__current) {
			if (*__begin == *__current) {
				return __begin;
			}
		}
	}
	return __begin;
}

template <typename _UndirectionalIterator1, typename _UndirectionalIterator2, typename _BinaryPredicator>
_UndirectionalIterator1 find_first_of(
	_UndirectionalIterator1 __begin,
	_UndirectionalIterator1 const& __end,
	_UndirectionalIterator2 const& __sample_begin,
	_UndirectionalIterator2 const& __sample_end,
	_BinaryPredicator const& __equal
) DD_NOEXCEPT_AS(++__begin != __end && __equal(*__begin, *++const_cast<_UndirectionalIterator2&>(__sample_begin))) {
	for (; __begin != __end; ++__begin) {
		for (_UndirectionalIterator2 __current = __sample_begin; __current != __sample_end; ++__current) {
			if (__equal(*__begin, *__current)) {
				return __begin;
			}
		}
	}
	return __begin;
}



DD_END



#endif
