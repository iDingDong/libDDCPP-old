//	standard/bits/DD_merge.hpp
#ifndef _DD_MERGE_HPP_INCLUDED
#	define _DD_MERGE_HPP_INCLUDED 1



#	include "DD_copy.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2, typename _UndirectionalIteratorT3>
_UndirectionalIteratorT3 merge(
	_UndirectionalIteratorT1 __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 __begin_2,
	_UndirectionalIteratorT2 const& __end_2,
	_UndirectionalIteratorT3 __result_begin
) DD_NOEXCEPT_AS(copy(__begin_1, __end_1, __result_begin) DD_COMMA copy(__begin_2, __end_2, __result_begin) DD_COMMA *__begin_1 < *__begin_2) {
	for (; __begin_2 != __end_2; ++__result_begin) {
		if (__begin_1 == __end_1) {
			return copy(__begin_2, __end_2, __result_begin);
		}
		if (*__begin_1 < *__begin_2) {
			*__result_begin = *__begin_1;
			++__begin_1;
		} else {
			*__result_begin = *__begin_2;
			++__begin_1;
		}
	}
	return copy(__begin_1, __end_1, __result_begin);
}

template <typename _UndirectionalIteratorT1, typename _UndirectionalIteratorT2, typename _UndirectionalIteratorT3, typename _BinaryPredicator>
_UndirectionalIteratorT3 merge(
	_UndirectionalIteratorT1 __begin_1,
	_UndirectionalIteratorT1 const& __end_1,
	_UndirectionalIteratorT2 __begin_2,
	_UndirectionalIteratorT2 const& __end_2,
	_BinaryPredicator const& __less,
	_UndirectionalIteratorT3 __result_begin
) DD_NOEXCEPT_AS(copy(__begin_1, __end_1, __result_begin) DD_COMMA copy(__begin_2, __end_2, __result_begin) DD_COMMA __less(*__begin_1, *__begin_2)) {
	for (; __begin_2 != __end_2; ++__result_begin) {
		if (__begin_1 == __end_1) {
			return copy(__begin_2, __end_2, __result_begin);
		}
		if (__less(*__begin_1, *__begin_2)) {
			*__result_begin = *__begin_1;
			++__begin_1;
		} else {
			*__result_begin = *__begin_2;
			++__begin_1;
		}
	}
	return copy(__begin_1, __end_1, __result_begin);
}



DD_END



#endif
