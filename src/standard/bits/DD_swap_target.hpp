//	DDCPP/standard/bits/DD_swap_target.hpp
#ifndef DD_SWAP_TARGET_HPP_INCLUDED_
#	define DD_SWAP_TARGET_HPP_INCLUDED_ 1



#	include "DD_swap.hpp"



DD_BEGIN_
template <typename PointerT_>
inline ProcessType swap_target(
	PointerT_ pointer_1__,
	PointerT_ pointer_2__
) DD_NOEXCEPT_AS(swap(*pointer_1__, *pointer_2__)) {
	using DD::swap;
	swap(*pointer_1__, *pointer_2__);
}



DD_END_



#endif
