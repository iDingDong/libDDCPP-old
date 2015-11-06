//	DDCPP/standard/bits/DD_partition_point.hpp
#ifndef DD_PARTITION_POINT_HPP_INCLUDED_
#	define DD_PARTITION_POINT_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_>
UndirectionalIteratorT_ partition_point(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ < value__) {
	while (begin__ != end__ && *begin__ < value__) {
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicatorT_>
UndirectionalIteratorT_ partition_point(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__,
	BinaryPredicatorT_ less__
) DD_NOEXCEPT_AS(++begin__ != end__ && less__(*begin__, value__)) {
	while (begin__ != end__ && less__(*begin__, value__)) {
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) partition_point(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	partition_point(DD_SPLIT_RANGE(range__) DD_COMMA value__)
)) {
	return partition_point(DD_SPLIT_RANGE(range__), value__);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryPredicatorT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) partition_point(
	UndirectionalRangeT_& range__,
	ValueT_ const& value__,
	BinaryPredicatorT_ const& less__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	partition_point(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA less__))
) {
	return partition_point(DD_SPLIT_RANGE(range__), value__, less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::partition_point;



DD_END_



#endif
