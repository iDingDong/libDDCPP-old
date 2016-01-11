//	DDCPP/standard/bits/DD_swap_length.hpp
#ifndef DD_SWAP_LENGTH_HPP_INCLUDED_
#	define DD_SWAP_LENGTH_HPP_INCLUDED_ 1



#	include "DD_swap_target.hpp"
#	include "DD_Pair.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename LengthT_>
inline Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> swap_length(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT2_ begin_2__,
	LengthT_ length__
) {
	//UndirectionalIteratorT1_ begin__(begin_1__);
	for (; length__; --length__, ++begin_1__, ++begin_2__) {
		::DD::detail_::swap_target(begin_1__, begin_2__);
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>(begin_1__, begin_2__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::swap_length;



DD_END_



#endif
