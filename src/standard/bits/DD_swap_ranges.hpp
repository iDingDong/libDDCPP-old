//	DDCPP/standard/bits/DD_swap_ranges.hpp
#ifndef DD_SWAP_RANGES_HPP_INCLUDED_
#	define DD_SWAP_RANGES_HPP_INCLUDED_ 1



#	include "DD_swap_target.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT1_, typename UndirecitonalIteratorT2_>
inline ProcessType swap_ranges(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__
) DD_NOEXCEPT_AS(begin_1__ != end_1__ ? ::DD::detail_::swap_target(++begin_1__ DD_COMMA ++begin_2__)) {
	for (; begin_1__ != end_1__; ++begin_1__, ++begin_2__) {
		::DD::detail_::swap_target(begin_1__, begin_2__);
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::swap_ranges;



DD_END_



#endif
