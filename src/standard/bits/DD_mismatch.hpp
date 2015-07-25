//	DDCPP/standard/bits/DD_mismatch.hpp
#ifndef _DD_MISMATCH_HPP_INCLUDED
#	define _DD_MISMATCH_HPP_INCLUDED 1



#	include "DD_Pair.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2>
Pair<_UndirectionalIteratorT1, _UndirectionalIteratorT2> mismatch(
	_UndirectionalIteratorT1 __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 __begin_2
) DD_NOEXCEPT_AS(__begin_1 != __end_1 && *++__begin_1 == *++__begin_2) {
	while (__begin_1 != __end_1 && *__begin_1 == *__begin_2) {
		++__begin_1;
		++__begin_2;
	}
	return Pair<_UndirectionalIteratorT1, _UndirectionalIteratorT2>{__begin_1, __begin_2};
}

template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2>
Pair<_UndirectionalIteratorT1, _UndirectionalIteratorT2> mismatch(
	_UndirectionalIteratorT1 __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 __begin_2,
	_UndirectionalIteratorT2 const& __end_2
) DD_NOEXCEPT_AS(__begin_1 != __end_1 && __begin_2 != __end_2 && *++__begin_1 == *++__begin_2) {
	while (__begin_1 != __end_1 && __begin_2 != __end_2 && *__begin_1 == *__begin_2) {
		++__begin_1;
		++__begin_2;
	}
	return Pair<_UndirectionalIteratorT1, _UndirectionalIteratorT2>{__begin_1, __begin_2};
}

template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2, typename _BinaryPredicator>
Pair<_UndirectionalIteratorT1, _UndirectionalIteratorT2> mismatch(
	_UndirectionalIteratorT1 __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 __begin_2,
	_BinaryPredicator const& __equal
) DD_NOEXCEPT_AS(__begin_1 != __end_1 && __equal(*++__begin_1, *++__begin_2)) {
	while (__begin_1 != __end_1 && __equal(*__begin_1, *__begin_2)) {
		++__begin_1;
		++__begin_2;
	}
	return Pair<_UndirectionalIteratorT1, _UndirectionalIteratorT2>{__begin_1, __begin_2};
}

template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2, typename _BinaryPredicator>
Pair<_UndirectionalIteratorT1, _UndirectionalIteratorT2> mismatch(
	_UndirectionalIteratorT1 __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 __begin_2,
	_UndirectionalIteratorT2 const& __end_2,
	_BinaryPredicator const& __equal
) DD_NOEXCEPT_AS(__begin_1 != __end_1 && __begin_2 != __end_2 && __equal(*++__begin_1, *++__begin_2)) {
	while (__begin_1 != __end_1 && __begin_2 != __end_2 && __equal(*__begin_1, *__begin_2)) {
		++__begin_1;
		++__begin_2;
	}
	return Pair<_UndirectionalIteratorT1, _UndirectionalIteratorT2>{__begin_1, __begin_2};
}



DD_END



#endif
