//	DDCPP/standard/bits/DD_partition_point_by.hpp
#ifndef DD_PARTITION_POINT_BY_HPP_INCLUDED_
#	define DD_PARTITION_POINT_BY_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicatorT_>
UndirectionalIteratorT_ partition_point_by(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryPredicatorT_ predicator__
) DD_NOEXCEPT_AS(++begin__ != end__ && predicator__(*begin__)) {
	while (begin__ != end__ && predicator__(*begin__)) {
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalRangeT_, typename UnaryPredicatorT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) partition_point_by(
	UndirectionalRangeT_& range__,
	UnaryPredicatorT_ predicator__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	partition_point_by(DD_SPLIT_RANGE(range__) DD_COMMA predicator__)
)) {
	return partition_point_by(DD_SPLIT_RANGE(range__), predicator__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::partition_point_by;



DD_END_



#endif
