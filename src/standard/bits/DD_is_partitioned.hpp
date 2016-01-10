//	DDCPP/standard/bits/DD_is_partitioned.hpp
#ifndef DD_IS_PARTITIONED_HPP_INCLUDED_
#	define DD_IS_PARTITIONED_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"
#	include "DD_LessThan.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicateT_>
ValidityType is_partitioned(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ const& value__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(++begin__ != end__ && less__(*begin__, value__)) {
	for (; begin__ != end__; ++begin__) {
		if (!less__(*begin__, value__)) {
			break;
		}
	}
	while (++begin__ != end__) {
		if (less__(*begin__, value__)) {
			return false;
		}
	}
	return true;
}

template <typename UndirectionalIteratorT_, typename ValueT_>
inline ValidityType is_partitioned(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(
	::DD::detail_::is_partitioned(begin__ DD_COMMA end__ DD_COMMA value__ DD_COMMA less_than)
)) {
	return ::DD::detail_::is_partitioned(begin__, end__, value__, less_than);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryPredicateT_>
inline ValidityType is_partitioned(
	UndirectionalRangeT_ const& range__,
	ValueT_ const& value__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(::DD::detail_::is_partitioned(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA less__))) {
	return ::DD::detail_::is_partitioned(DD_SPLIT_RANGE(range__), value__, less__);
}

template <typename UndirectionalRangeT_, typename ValueT_>
inline ValidityType is_partitioned(
	UndirectionalRangeT_ const& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(::DD::detail_::is_partitioned(range__ DD_COMMA value__ DD_COMMA less_than))) {
	return ::DD::detail_::is_partitioned(range__, value__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::is_partitioned;



DD_END_



#endif
