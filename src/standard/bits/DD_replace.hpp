//	standard/bits/DD_replace.hpp
#ifndef _DD_REPLACE_HPP_INCLUDED
#	define _DD_REPLACE_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _ValueT1, typename _ValueT2>
ProcessType replace(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT1 const& __old,
	_ValueT2 __value
) DD_NOEXCEPT_AS(*++__begin = __value DD_COMMA __begin != __end && *__begin == __old) {
	for (; __begin != __end; ++__begin) {
		if (*__begin == __old) {
			*__begin = __value;
		}
	}
}

template <typename _UndirectionalIteratorT, typename _ValueT1, typename _BinaryPredicator, typename _ValueT2>
ProcessType replace(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT1 __old,
	_BinaryPredicator const& __equal,
	_ValueT2 __value
) DD_NOEXCEPT_AS(*++__begin = __value DD_COMMA __begin != __end && __equal(*__begin, __old)) {
	for (; __begin != __end; ++__begin) {
		if (__equal(*__begin, __old)) {
			*__begin = __value;
		}
	}
}



DD_END



#endif
