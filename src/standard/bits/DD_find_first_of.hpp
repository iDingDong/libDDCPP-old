//	DDCPP/standard/bits/DD_find_first_of.hpp
#ifndef DD_FIRST_OF_HPP_INCLUDED_
#	define DD_FIRST_OF_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"
#	include "DD_Iterator.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIterator1_, typename UndirectionalIterator2_>
UndirectionalIterator1_ find_first_of(
	UndirectionalIterator1_ begin__,
	UndirectionalIterator1_ const& end__,
	UndirectionalIterator2_ const& sample_begin__,
	UndirectionalIterator2_ const& sample_end__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ == *++const_cast<UndirectionalIterator2_&>(sample_begin__)) {
	for (; begin__ != end__; ++begin__) {
		for (UndirectionalIterator2_ current__ = sample_begin__; current__ != sample_end__; ++current__) {
			if (*begin__ == *current__) {
				return begin__;
			}
		}
	}
	return begin__;
}

template <typename UndirectionalIterator1_, typename UndirectionalIterator2_, typename BinaryPredicatorT_>
UndirectionalIterator1_ find_first_of(
	UndirectionalIterator1_ begin__,
	UndirectionalIterator1_ const& end__,
	UndirectionalIterator2_ const& sample_begin__,
	UndirectionalIterator2_ const& sample_end__,
	BinaryPredicatorT_ equal__
) DD_NOEXCEPT_AS(++begin__ != end__ && equal__(*begin__, *++const_cast<UndirectionalIterator2_&>(sample_begin__))) {
	for (; begin__ != end__; ++begin__) {
		for (UndirectionalIterator2_ current__ = sample_begin__; current__ != sample_end__; ++current__) {
			if (equal__(*begin__, *current__)) {
				return begin__;
			}
		}
	}
	return begin__;
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) find_first_of(
	UndirectionalRangeT1_& range__,
	UndirectionalRangeT2_ const& sample_range__
) DD_NOEXCEPT_AS(find_first_of(DD_SPLIT_RANGE(range__) DD_COMMA DD_SPLIT_RANGE(sample_range__))) {
	return find_first_of(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(sample_range__));
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_, typename BinaryPredicatorT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) find_first_of(
	UndirectionalRangeT1_& range__,
	UndirectionalRangeT2_ const& sample_range__,
	BinaryPredicatorT_ equal__
) DD_NOEXCEPT_AS(find_first_of(DD_SPLIT_RANGE(range__) DD_COMMA DD_SPLIT_RANGE(sample_range__) DD_COMMA equal__)) {
	return find_first_of(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(sample_range__), equal__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_first_of;



DD_END_



#endif
