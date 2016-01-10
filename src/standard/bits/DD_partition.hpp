//	DDCPP/standard/bits/DD_partition.hpp
#ifndef DD_PARTITION_HPP_INCLUDED_
#	define DD_PARTITION_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_swap_target.hpp"
#	include "DD_LessThan.hpp"



DD_DETAIL_BEGIN_
template <typename BidirectionalIteratorT_, typename ValueT_, typename BinaryPredicateT_>
BidirectionalIteratorT_ partition(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__,
	ValueT_ const& key__,
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

template <typename BidirectionalIteratorT_, typename ValueT_>
inline BidirectionalIteratorT_ partition(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__,
	ValueT_ const& key__
) DD_NOEXCEPT_AS(static_cast<BidirectionalIteratorT_>(
	::DD::detail_::partition(begin__ DD_COMMA end__ DD_COMMA key__ DD_COMMA less_than)
)) {
	return ::DD::detail_::partition(begin__, end__, key__, less_than);
}

template <typename BidirectionalRangeT_, typename ValueT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_) partition(
	BidirectionalRangeT_& range__,
	ValueT_ const& key__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_)>(
	::DD::detail_::partition(DD_SPLIT_RANGE(range__) DD_COMMA key__ DD_COMMA less__)
)) {
	return ::DD::detail_::partition(DD_SPLIT_RANGE(range__), key__, less__);
}

template <typename BidirectionalRangeT_, typename ValueT_>
inline DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_) partition(
	BidirectionalRangeT_& range__,
	ValueT_ const& key__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_)>(
	::DD::detail_::partition(range__ DD_COMMA key__ DD_COMMA less_than)
)) {
	return ::DD::detail_::partition(range__, key__, less_than);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::partition;



DD_END_



#endif
