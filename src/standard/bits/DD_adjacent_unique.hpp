//	DDCPP/standard/bits/DD_adjacent_unique.hpp
#ifndef DD_ADJACENT_UNIQUE_HPP_INCLUDED_
#	define DD_ADJACENT_UNIQUE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	endif
#	include "DD_next.hpp"
#	include "DD_find_not.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
UndirectionalIteratorT_ adjacent_unique(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__
) {
	if (begin__ != end__) {
		for (UndirectionalIteratorT_ current__ = begin__; ; ) {
			current__ = find_not(next(current__), end__, *begin__);
			if (current__ == end__) {
				break;
			}
#	if __cplusplus >= 201103L
			*++begin__ = move(*current__);
#	else
			*++begin__ = *current__;
#	endif
		}
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalIteratorT_, typename BinaryPredicatorT_>
UndirectionalIteratorT_ adjacent_unique(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	BinaryPredicatorT_ equal__
) {
	if (begin__ != end__) {
		for (UndirectionalIteratorT_ current__ = begin__; ; ) {
			current__ = find_not(next(current__), end__, *begin__, equal__);
			if (current__ == end__) {
				break;
			}
#	if __cplusplus >= 201103L
			*++begin__ = move(*current__);
#	else
			*++begin__ = *current__;
#	endif
		}
		++begin__;
	}
	return begin__;
}

template <typename UndirectionalRangeT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) adjacent_unique(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	adjacent_unique(DD_SPLIT_RANGE(range__))
)) {
	return adjacent_unique(DD_SPLIT_RANGE(range__));
}

template <typename UndirectionalRangeT_, typename BinaryPredicatorT_>
inline DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) adjacent_unique(
	UndirectionalRangeT_& range__,
	BinaryPredicatorT_ equal__
) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)>(
	adjacent_unique(DD_SPLIT_RANGE(range__) DD_COMMA equal__)
)) {
	return adjacent_unique(DD_SPLIT_RANGE(range__), equal__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::adjacent_unique;



DD_END_



#endif
