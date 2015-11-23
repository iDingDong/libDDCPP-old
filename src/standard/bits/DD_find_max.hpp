//	DDCPP/standard/bits/DD_find_max.hpp
#ifndef DD_FIND_MAX_HPP_INCLUDED_
#	define DD_FIND_MAX_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
UndirectionalIteratorT_ find_max(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ < *begin__) {
	UndirectionalIteratorT_ max__ = begin__;
	for (; begin__ != end__; ++begin__) {
		if (*max__ < *begin__) {
			max__ = begin__;
		}
	}
	return max__;
}

template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
UndirectionalIteratorT_ find_max(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(++begin__ != end__ && less__(*begin__, *begin__)) {
	UndirectionalIteratorT_ max__ = begin__;
	for (; begin__ != end__; ++begin__) {
		if (less__(*max__, *begin__)) {
			max__ = begin__;
		}
	}
	return max__;
}

template <typename UndirectionalRangeT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_max(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(::DD::detail_::find_max(DD_SPLIT_RANGE(range__))) {
	return ::DD::detail_::find_max(DD_SPLIT_RANGE(range__));
}

template <typename UndirectionalRangeT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_max(
	UndirectionalRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(::DD::detail_::find_max(DD_SPLIT_RANGE(range__) DD_COMMA less__)) {
	return ::DD::detail_::find_max(DD_SPLIT_RANGE(range__), less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_max;



DD_END_



#endif
