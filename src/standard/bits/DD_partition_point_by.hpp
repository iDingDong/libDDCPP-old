//	DDCPP/standard/bits/DD_partition_point_by.hpp
#ifndef DD_PARTITION_POINT_BY_HPP_INCLUDED_
#	define DD_PARTITION_POINT_BY_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicateT_>
UndirectionalIteratorT_ partition_point_by(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryPredicateT_ predicate__
) DD_NOEXCEPT_AS(++begin__ != end__ && predicate__(*begin__)) {
	while (begin__ != end__ && predicate__(*begin__)) {
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalRangeT_, typename UnaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) partition_point_by(
	UndirectionalRangeT_& range__,
	UnaryPredicateT_ predicate__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	partition_point_by(DD_SPLIT_RANGE(range__) DD_COMMA predicate__)
)) {
	return partition_point_by(DD_SPLIT_RANGE(range__), predicate__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::partition_point_by;



DD_END_



#endif
