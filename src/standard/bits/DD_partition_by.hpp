//	DDCPP/standard/bits/DD_partition_by.hpp
#ifndef _DD_PARTITION_BY_HPP_INCLUDED
#	define _DD_PARTITION_BY_HPP_INCLUDED 1



#	include "DD_swap_target.hpp"



DD_BEGIN
template <typename _BidirectionalIteratorT, typename _UnaryPredicatorT>
_BidirectionalIteratorT partition_by(
	_BidirectionalIteratorT __begin,
	_BidirectionalIteratorT __end,
	_UnaryPredicatorT const& __predicator
) DD_NOEXCEPT_IF(noexcept(__predicator(*--++__begin)) && noexcept(swap_target(__begin, __end))) {
	while (__begin != __end) {
		while (__predicator(*__begin)) {
			++__begin;
			if (__begin == __end) {
				return __begin;
			}
		}
		while (!__predicator(*--__end)) {
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
