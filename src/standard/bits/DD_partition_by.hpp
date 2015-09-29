//	DDCPP/standard/bits/DD_partition_by.hpp
#ifndef DD_PARTITION_BY_HPP_INCLUDED_
#	define DD_PARTITION_BY_HPP_INCLUDED_ 1



#	include "DD_swap_target.hpp"



DD_BEGIN_
template <typename BidirectionalIteratorT_, typename UnaryPredicatorT_>
BidirectionalIteratorT_ partition_by(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__,
	UnaryPredicatorT_ const& predicator__
) DD_NOEXCEPT_IF(noexcept(predicator__(*--++begin__)) && noexcept(swap_target(begin__, end__))) {
	while (begin__ != end__) {
		while (predicator__(*begin__)) {
			++begin__;
			if (begin__ == end__) {
				return begin__;
			}
		}
		while (!predicator__(*--end__)) {
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
