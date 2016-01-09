//	DDCPP/standard/bits/DD_find_max.hpp
#ifndef DD_FIND_MAX_HPP_INCLUDED_
#	define DD_FIND_MAX_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_LessThan.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
UndirectionalIteratorT_ find_max(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(++begin__ != end__ && less__(*begin__, *begin__)) {
	if (begin__ != end__) {
		for (UndirectionalIteratorT_ current__(begin__); ++current__ != end__; ) {
			if (less__(*begin__, *current__)) {
				begin__ = current__;
			}
		}
	}
	return begin__;
}

template <typename UndirectionalIteratorT_>
inline UndirectionalIteratorT_ find_max(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(
	::DD::detail_::find_max(begin__ DD_COMMA end__ DD_COMMA less_than)
)) {
	return ::DD::detail_::find_max(begin__, end__, less_than);
}

template <typename UndirectionalRangeT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_max(
	UndirectionalRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(::DD::detail_::find_max(DD_SPLIT_RANGE(range__) DD_COMMA less__)) {
	return ::DD::detail_::find_max(DD_SPLIT_RANGE(range__), less__);
}

template <typename UndirectionalRangeT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_max(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::find_max(range__, less_than)
)) {
	return ::DD::detail_::find_max(range__, less_than);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_max;



DD_END_



#endif
