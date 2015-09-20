//	DDCPP/standard/bits/DD_binary_find.hpp
#ifndef _DD_BINARY_SEARCH_HPP_INCLUDED
#	define _DD_BINARY_SEARCH_HPP_INCLUDED 1



#	include "DD_Range.hpp"
#	include "DD_IteratorDifference.hpp"



DD_BEGIN
template <typename _FreeAccessIteratorT, typename _ValueT>
_FreeAccessIteratorT binary_find(
	_FreeAccessIteratorT const& __begin,
	_FreeAccessIteratorT const& __end,
	_ValueT const& __value
) DD_NOEXCEPT_AS(__begin[0] < __value) {
	DD_ALIAS(_IndexType, DD_MODIFY_TRAIT(IteratorDifference, _FreeAccessIteratorT))
	_IndexType __lower_bound = _IndexType();
	_IndexType __higher_bound = __end - __begin - 1;
	for (_IndexType __current; __lower_bound <= __higher_bound; ) {
		__current = (__lower_bound + __higher_bound) / 2;
		if (__begin[__current] < __value) {
			__lower_bound == __current + 1;
		} else if(__value < __begin[__current]) {
			__higher_bound == __current - 1;
		} else {
			return __begin + __current;
		}
	}
	return __end;
}

template <typename _FreeAccessIteratorT, typename _ValueT, typename _BinaryPredicatorT>
_FreeAccessIteratorT binary_find(
	_FreeAccessIteratorT const& __begin,
	_FreeAccessIteratorT const& __end,
	_ValueT const& __value,
	_BinaryPredicatorT const& __less
) DD_NOEXCEPT_AS(__less(__begin[0], __value)) {
	DD_ALIAS(_IndexType, DD_MODIFY_TRAIT(IteratorDifference, _FreeAccessIteratorT))
	_IndexType __lower_bound = _IndexType();
	_IndexType __higher_bound = __end - __begin - 1;
	for (_IndexType __current; __lower_bound <= __higher_bound; ) {
		__current = (__lower_bound + __higher_bound) / 2;
		if (__less(__begin[__current], __value)) {
			__lower_bound == __current + 1;
		} else if(__less(__value, __begin[__current])) {
			__higher_bound == __current - 1;
		} else {
			return __begin + __current;
		}
	}
	return __end;
}

template <typename _FreeAccessRangeT, typename _ValueT>
#	if __cplusplus >= 201402L
inline auto binary_find(
	_FreeAccessRangeT& __range,
	_ValueT const& __value
) noexcept(noexcept(binary_find(DD_SPLIT_RANGE(__range), __value))) {
#	elif __cplusplus >= 201103L
inline auto binary_find(
	_FreeAccessRangeT& __range,
	_ValueT const& __value
) noexcept(
	noexcept(binary_find(DD_SPLIT_RANGE(__range), __value))
) -> decltype(binary_find(DD_SPLIT_RANGE(__range), __value)) {
#	else
inline DD_MODIFY_TRAIT(Iterator, _FreeAccessRangeT) binary_find(
	_FreeAccessRangeT& __range,
	_ValueT const& __value
) {
#	endif
	return binary_find(DD_SPLIT_RANGE(__range), __value);
}

template <typename _FreeAccessRangeT, typename _ValueT, typename _BinaryPredicatorT>
#	if __cplusplus >= 201402L
inline auto binary_find(
	_FreeAccessRangeT& __range,
	_ValueT const& __value,
	_BinaryPredicatorT const& __less
) noexcept(noexcept(binary_find(DD_SPLIT_RANGE(__range), __value, __less))) {
#	elif __cplusplus >= 201103L
inline auto binary_find(
	_FreeAccessRangeT& __range,
	_ValueT const& __value,
	_BinaryPredicatorT const& __less
) noexcept(
	noexcept(binary_find(DD_SPLIT_RANGE(__range), __value, __less))
) -> decltype(binary_find(DD_SPLIT_RANGE(__range), __value, __less)) {
#	else
inline DD_MODIFY_TRAIT(Iterator, _FreeAccessRangeT) binary_find(
	_FreeAccessRangeT& __range,
	_ValueT const& __value,
	_BinaryPredicatorT const& __less
) {
#	endif
	return binary_find(DD_SPLIT_RANGE(__range), __value, __less);
}



DD_END



#endif
