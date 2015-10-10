//	DDCPP/standard/bits/DD_find_min.hpp
#ifndef DD_FIND_MIN_HPP_INCLUDED_
#	define DD_FIND_MIN_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
UndirectionalIteratorT_ find_min(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ < *begin__) {
	UndirectionalIteratorT_ min__ = begin__;
	for (; begin__ != end__; ++begin__) {
		if (*begin__ < *min__) {
			min__ = begin__;
		}
	}
	return min__;
}

template <typename UndirectionalIteratorT_, typename BinaryPredicatorT_>
UndirectionalIteratorT_ find_min(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	BinaryPredicatorT_ less__
) DD_NOEXCEPT_AS(++begin__ != end__ && less__(*begin__, *begin__)) {
	UndirectionalIteratorT_ min__ = begin__;
	for (; begin__ != end__; ++begin__) {
		if (less__(*begin__, *min__)) {
			min__ = begin__;
		}
	}
	return min__;
}

template <typename UndirectionalRangeT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_min(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(find_min(DD_SPLIT_RANGE(range__))) {
	return find_min(DD_SPLIT_RANGE(range__));
}

template <typename UndirectionalRangeT_, typename BinaryPredicatorT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_min(
	UndirectionalRangeT_& range__,
	BinaryPredicatorT_ less__
) DD_NOEXCEPT_AS(find_min(DD_SPLIT_RANGE(range__) DD_COMMA less__)) {
	return find_min(DD_SPLIT_RANGE(range__), less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_min;



DD_END_



#endif
