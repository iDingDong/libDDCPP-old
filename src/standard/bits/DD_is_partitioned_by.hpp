//	DDCPP/standard/bits/DD_is_partitioned_by.hpp
#ifndef DD_IS_PARTITIONED_BY_HPP_INCLUDED_
#	define DD_IS_PARTITIONED_BY_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicatorT_>
ValidityType is_partitioned_by(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryPredicatorT_ predicator__
) DD_NOEXCEPT_AS(++begin__ != end__ && predicator__(*begin__)) {
	for (; begin__ != end__; ++begin__) {
		if (!predicator__(*begin__)) {
			break;
		}
	}
	while (++begin__ != end__) {
		if (predicator__(*begin__)) {
			return false;
		}
	}
	return true;
}

template <typename UndirectionalRangeT_, typename UnaryPredicatorT_>
inline ValidityType is_partitioned_by(
	UndirectionalRangeT_ const& range__,
	UnaryPredicatorT_ predicator__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(is_partitioned_by(DD_SPLIT_RANGE(range__) DD_COMMA predicator__))) {
	return is_partitioned_by(DD_SPLIT_RANGE(range__), predicator__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::is_partitioned_by;



DD_END_



#endif
