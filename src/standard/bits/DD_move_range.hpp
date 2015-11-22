//	DDCPP/standard/bits/DD_move_range.hpp
#ifndef DD_MOVE_RANGE_HPP_INCLUDED_
#	define DD_MOVE_RANGE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::move_range'.



#	endif
#	include "DD_Iterator.hpp"
#	include "DD_move.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
UndirectionalIteratorT1_ move_range(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ const& end__,
	UndirectionalIteratorT2_ result_begin__
) noexcept(noexcept(begin__ != end__) && noexcept(*++result_begin__ = ::DD::detail_::move(*++begin__))) {
	for (; begin__ != end__; ++begin__, ++result_begin__) {
		*result_begin__ = ::DD::detail_::move(*begin__);
	}
	return result_begin__;
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> move_range(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ const& end__,
	UndirectionalIteratorT2_ result_begin__,
	UndirectionalIteratorT2_ const& result_end__
) noexcept(
	noexcept(begin__ != end__) &&
	noexcept(result_begin__ != result_end__) &&
	noexcept(*++result_begin__ = ::DD::detail_::move(*++begin__))
) {
	for (; begin__ != end__ && result_begin__ != result_end__; ++begin__, ++result_begin__) {
		*result_begin__ = ::DD::detail_::move(*begin__);
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>(begin__, result_begin__);
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_>
inline Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_), DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)> move_range(
	UndirectionalRangeT1_& range__,
	UndirectionalRangeT2_& result_range__
) noexcept(noexcept(static_cast<Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_), DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)>>(
	::DD::detail_::move_range(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(result_range__))
))) {
	return ::DD::detail_::move_range(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(result_range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::move_range;



DD_END_



#endif
