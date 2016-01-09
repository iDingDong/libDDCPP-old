//	DDCPP/standard/bits/DD_find_first_of.hpp
#ifndef DD_FIRST_OF_HPP_INCLUDED_
#	define DD_FIRST_OF_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"
#	include "DD_Iterator.hpp"
#	include "DD_EqualTo.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIterator1_, typename UndirectionalIterator2_, typename BinaryPredicateT_>
UndirectionalIterator1_ find_first_of(
	UndirectionalIterator1_ begin__,
	UndirectionalIterator1_ end__,
	UndirectionalIterator2_ sample_begin__,
	UndirectionalIterator2_ sample_end__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(++begin__ != end__ && equal__(*begin__, *++sample_begin__)) {
	for (; begin__ != end__; ++begin__) {
		for (UndirectionalIterator2_ current__ = sample_begin__; current__ != sample_end__; ++current__) {
			if (equal__(*begin__, *current__)) {
				return begin__;
			}
		}
	}
	return begin__;
}

template <typename UndirectionalIterator1_, typename UndirectionalIterator2_>
inline UndirectionalIterator1_ find_first_of(
	UndirectionalIterator1_ begin__,
	UndirectionalIterator1_ end__,
	UndirectionalIterator2_ sample_begin__,
	UndirectionalIterator2_ sample_end__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIterator1_>(
	::DD::detail_::find_first_of(begin__ DD_COMMA end__ DD_COMMA sample_begin__ DD_COMMA sample_end__ DD_COMMA equal_to)
)) {
	return ::DD::detail_::find_first_of(begin__, end__, sample_begin__, sample_end__, equal_to);
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) find_first_of(
	UndirectionalRangeT1_& range__,
	UndirectionalRangeT2_ const& sample_range__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(::DD::detail_::find_first_of(DD_SPLIT_RANGE(range__) DD_COMMA DD_SPLIT_RANGE(sample_range__) DD_COMMA equal__)) {
	return ::DD::detail_::find_first_of(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(sample_range__), equal__);
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) find_first_of(
	UndirectionalRangeT1_& range__,
	UndirectionalRangeT2_ const& sample_range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_)>(
	::DD::detail_::find_first_of(range__ DD_COMMA sample_range__ DD_COMMA equal_to)
)) {
	return ::DD::detail_::find_first_of(range__, sample_range__, equal_to);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_first_of;



DD_END_



#endif
