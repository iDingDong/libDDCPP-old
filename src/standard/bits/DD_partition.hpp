//	DDCPP/standard/bits/DD_partition.hpp
#ifndef DD_PARTITION_HPP_INCLUDED_
#	define DD_PARTITION_HPP_INCLUDED_ 1



#	include "DD_swap_target.hpp"



DD_BEGIN_
template <typename BidirectionalIteratorT_, typename ValueT_>
BidirectionalIteratorT_ partition(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__,
	ValueT_ key__
) DD_NOEXCEPT_IF(noexcept(*--++begin__ < key__) && noexcept(swap_target(begin__, end__))) {
	while (begin__ != end__) {
		while (*begin__ < key__) {
			++begin__;
			if (begin__ == end__) {
				return begin__;
			}
		}
		while (!(*--end__ < key__)) {
			if (begin__ == end__) {
				return begin__;
			}
		}
		swap_target(begin__, end__);
	}
	return begin__;
}

template <typename BidirectionalIteratorT_, typename ValueT_, typename BinaryPredicateT_>
BidirectionalIteratorT_ partition(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__,
	ValueT_ key__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_IF(noexcept(less__(*--++begin__, key__)) && noexcept(swap_target(begin__, end__))) {
	while (begin__ != end__) {
		while (less__(*begin__, key__)) {
			++begin__;
			if (begin__ == end__) {
				return begin__;
			}
		}
		while (!less__(*--end__, key__)) {
			if (begin__ == end__) {
				return begin__;
			}
		}
		swap_target(begin__, end__);
	}
	return begin__;
}



DD_END_



#endif
