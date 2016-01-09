//	DDCPP/standard/bits/DD_find_range.hpp
#ifndef DD_FIND_RANGE_HPP_INCLUDED_
#	define DD_FIND_RANGE_HPP_INCLUDED_ 1



#	include "DD_kmp_find_range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename FreeAccessIteratorT_, typename BinaryPredicateT_>
inline UndirectionalIteratorT_ find_range(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	FreeAccessIteratorT_ pattern_begin__,
	FreeAccessIteratorT_ pattern_end__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(
	::DD::kmp_find_range(begin__ DD_COMMA end__ DD_COMMA pattern_begin__ DD_COMMA pattern_end__ DD_COMMA equal__)
)) {
	return ::DD::kmp_find_range(begin__, end__, pattern_begin__, pattern_end__, equal__);
}

template <typename UndirectionalIteratorT_, typename FreeAccessIteratorT_>
inline UndirectionalIteratorT_ find_range(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	FreeAccessIteratorT_ pattern_begin__,
	FreeAccessIteratorT_ pattern_end__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(
	::DD::detail_::find_range(begin__ DD_COMMA end__ DD_COMMA pattern_begin__ DD_COMMA pattern_end__ DD_COMMA equal_to)
)) {
	return kmp_find_range(begin__, end__, pattern_begin__, pattern_end__, equal_to);
}

template <typename UndirectionalRangeT_, typename FreeAccessRangeT_, typename BinaryPredicateT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_range(
	UndirectionalRangeT_& range__,
	FreeAccessRangeT_ const& pattern_range__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::find_range(DD_SPLIT_RANGE(range__) DD_COMMA DD_SPLIT_RANGE(pattern_range__) DD_COMMA equal__)
)) {
	return ::DD::detail_::find_range(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(pattern_range__), equal__);
}

template <typename UndirectionalRangeT_, typename FreeAccessRangeT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_range(
	UndirectionalRangeT_& range__,
	FreeAccessRangeT_ const& pattern_range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	::DD::detail_::find_range(range__ DD_COMMA pattern_range__ DD_COMMA equal_to)
)) {
	return ::DD::detail_::find_range(range__, pattern_range__, equal_to);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::find_range;



DD_END_



#endif
