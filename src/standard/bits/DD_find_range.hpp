//	DDCPP/standard/bits/DD_find_range.hpp
#ifndef DD_FIND_RANGE_HPP_INCLUDED_
#	define DD_FIND_RANGE_HPP_INCLUDED_ 1



#	include "DD_kmp_find_range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename FreeAccessIteratorT_>
UndirectionalIteratorT_ find_range(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__,
	FreeAccessIteratorT_ const& pattern_begin__,
	FreeAccessIteratorT_ const& pattern_end__
) DD_NOEXCEPT_AS(UndirectionalIteratorT_(
	kmp_find_range(begin__ DD_COMMA end__ DD_COMMA pattern_begin__ DD_COMMA pattern_end__)
)) {
	return kmp_find_range(begin__, end__, pattern_begin__, pattern_end__);
}

template <typename UndirectionalRangeT_, typename FreeAccessRangeT_>
DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_range(
	UndirectionalRangeT_& range__,
	FreeAccessRangeT_ const& pattern_range__
) DD_NOEXCEPT_AS(
	DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)(::DD::detail_::find_range(DD_SPLIT_RANGE(range__) DD_COMMA DD_SPLIT_RANGE(pattern_range__)))
) {
	return ::DD::detail_::find_range(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(pattern_range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_range;



DD_END_



#endif
