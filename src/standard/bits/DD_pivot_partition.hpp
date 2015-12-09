//	DDCPP/standard/bits/DD_pivot_partition.hpp
#ifndef DD_PIVOT_PARTITION_HPP_INCLUDED_
#	define DD_PIVOT_PARTITION_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_LessThan.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename BidirectionalIteratorT_>
inline BidirectionalIteratorT_ unguarded_pivot_partition(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__
) {
#	if __cplusplus >= 201103L
	IteratorValueType<BidirectionalIteratorT_> key_ = ::DD::move(*begin__);
#	else
	typename IteratorValue<BidirectionalIteratorT_>::Type key_ = *begin__;
#	endif
	for (; ; ) {
		while (!(*--end__ < key_)) {
			if (begin__ == end__) {
				goto outside_;
			}
		}
#	if __cplusplus >= 201103L
		*begin__ = ::DD::move(*end__);
#	else
		*begin__ = *end__;
#	endif
		while (!(key_ < *++begin__)) {
			if (begin__ == end__) {
				goto outside_;
			}
		}
#	if __cplusplus >= 201103L
		*end__ = ::DD::move(*begin__);
#	else
		*end__ = *begin__;
#	endif
	}
	outside_:
#	if __cplusplus >= 201103L
		*begin__ = ::DD::move(key_);
#	else
		*begin__ = key_;
#	endif
	return begin__;
}



template <typename BidirectionalIteratorT_, typename BinaryPredicateT_>
BidirectionalIteratorT_ unguarded_pivot_partition(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) {
#	if __cplusplus >= 201103L
	IteratorValueType<BidirectionalIteratorT_> key_ = ::DD::move(*begin__);
#	else
	typename IteratorValue<BidirectionalIteratorT_>::Type key_ = *begin__;
#	endif
	for (; ; ) {
		while (!less__(*--end__, key_)) {
			if (begin__ == end__) {
				goto outside_;
			}
		}
#	if __cplusplus >= 201103L
		*begin__ = ::DD::move(*end__);
#	else
		*begin__ = *end__;
#	endif
		while (!less__(key_, *++begin__)) {
			if (begin__ == end__) {
				goto outside_;
			}
		}
#	if __cplusplus >= 201103L
		*end__ = ::DD::move(*begin__);
#	else
		*end__ = *begin__;
#	endif
	}
	outside_:
#	if __cplusplus >= 201103L
		*begin__ = ::DD::move(key_);
#	else
		*begin__ = key_;
#	endif
	return begin__;
}

template <typename BidirectionalRangeT_>
inline DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_) unguarded_pivot_partition(
	BidirectionalRangeT_& range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_)>(
	unguarded_pivot_partition(DD_SPLIT_RANGE(range__))
)) {
	return unguarded_pivot_partition(DD_SPLIT_RANGE(range__));
}

template <typename BidirectionalRangeT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_) unguarded_pivot_partition(
	BidirectionalRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_)>(
	unguarded_pivot_partition(DD_SPLIT_RANGE(range__) DD_COMMA less__)
)) {
	return unguarded_pivot_partition(DD_SPLIT_RANGE(range__), less__);
}


template <typename BidirectionalIteratorT_>
inline BidirectionalIteratorT_ pivot_partition(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(static_cast<BidirectionalIteratorT_>(
	begin__ == end__ ? begin__ : ::DD::detail_::unguarded_pivot_partition(begin__ DD_COMMA end__)
)) {
	return begin__ == end__ ? begin__ : ::DD::detail_::unguarded_pivot_partition(begin__, end__);
}

template <typename BidirectionalIteratorT_, typename BinaryPredicateT_>
inline BidirectionalIteratorT_ pivot_partition(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<BidirectionalIteratorT_>(
	begin__ == end__ ? begin__ : ::DD::detail_::unguarded_pivot_partition(begin__ DD_COMMA end__ DD_COMMA less__)
)) {
	return begin__ == end__ ? begin__ : ::DD::detail_::unguarded_pivot_partition(begin__, end__, less__);
}

template <typename BidirectionalRangeT_>
inline DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_) pivot_partition(
	BidirectionalRangeT_& range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_)>(
	pivot_partition(DD_SPLIT_RANGE(range__))
)) {
	return pivot_partition(DD_SPLIT_RANGE(range__));
}

template <typename BidirectionalRangeT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_) pivot_partition(
	BidirectionalRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, BidirectionalRangeT_)>(
	pivot_partition(DD_SPLIT_RANGE(range__) DD_COMMA less__)
)) {
	return pivot_partition(DD_SPLIT_RANGE(range__), less__);
}




DD_DETAIL_END_



DD_BEGIN_
using detail_::unguarded_pivot_partition;
using detail_::pivot_partition;



DD_END_



#endif
