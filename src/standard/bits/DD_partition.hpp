//	DDCPP/standard/bits/DD_partition.hpp
#ifndef _DD_PARTITION_HPP_INCLUDED
#	define _DD_PARTITION_HPP_INCLUDED 1



#	include "DD_swap_target.hpp"



DD_BEGIN
template <typename _BidirectionalIteratorT, typename _ValueT>
_BidirectionalIteratorT partition(
	_BidirectionalIteratorT __begin,
	_BidirectionalIteratorT __end,
	_ValueT __key
) DD_NOEXCEPT_IF(noexcept(*--++__begin < __key) && noexcept(swap_target(__begin, __end))) {
	while (__begin != __end) {
		while (*__begin < __key) {
			++__begin;
			if (__begin == __end) {
				return __begin;
			}
		}
		while (!(*--__end < __key)) {
			if (__begin == __end) {
				return __begin;
			}
		}
		swap_target(__begin, __end);
	}
	return __begin;
}

template <typename _BidirectionalIteratorT, typename _ValueT, typename _BinaryPredicatorT>
_BidirectionalIteratorT partition(
	_BidirectionalIteratorT __begin,
	_BidirectionalIteratorT __end,
	_ValueT __key,
	_BinaryPredicatorT __less
) DD_NOEXCEPT_IF(noexcept(__less(*--++__begin, __key)) && noexcept(swap_target(__begin, __end))) {
	while (__begin != __end) {
		while (__less(*__begin, __key)) {
			++__begin;
			if (__begin == __end) {
				return __begin;
			}
		}
		while (!__less(*--__end, __key)) {
			if (__begin == __end) {
				return __begin;
			}
		}
		swap_target(__begin, __end);
	}
	return __begin;
}



DD_END



#endif
