//	DDCPP/standard/bits/DD_is_partitioned.hpp
#ifndef DD_IS_PARTITIONED_HPP_INCLUDED_
#	define DD_IS_PARTITIONED_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_>
ValidityType is_partitioned(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ < value__) {
	for (; begin__ != end__; ++begin__) {
		if (!(*begin__ < value__)) {
			break;
		}
	}
	while (++begin__ != end__) {
		if (*begin__ < value__) {
			return false;
		}
	}
	return true;
}

template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicatorT_>
ValidityType is_partitioned(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__,
	BinaryPredicatorT_ less__
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

template <typename UndirectionalRangeT_, typename ValueT_>
inline ValidityType is_partitioned(
	UndirectionalRangeT_ const& range__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(is_partitioned(DD_SPLIT_RANGE(range__) DD_COMMA value__))) {
	return is_partitioned(DD_SPLIT_RANGE(range__), value__);
}

template <typename UndirectionalRangeT_, typename ValueT_, typename BinaryPredicatorT_>
inline ValidityType is_partitioned(
	UndirectionalRangeT_ const& range__,
	ValueT_ const& value__,
	BinaryPredicatorT_ less__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(is_partitioned(DD_SPLIT_RANGE(range__) DD_COMMA value__ DD_COMMA less__))) {
	return is_partitioned(DD_SPLIT_RANGE(range__), value__, less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::is_partitioned;



DD_END_



#endif
