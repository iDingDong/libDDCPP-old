//	DDCPP/standard/bits/DD_swap_target.hpp
#ifndef DD_SWAP_TARGET_HPP_INCLUDED_
#	define DD_SWAP_TARGET_HPP_INCLUDED_ 1



#	include "DD_swap.hpp"



DD_DETAIL_BEGIN_
DD_MEMBER_FUNCTION_CHECK(HasSwapTarget1_, swap, ::DD::ProcessType, MACRO_ObjectT__ const&)
DD_MEMBER_FUNCTION_CHECK(HasSwapTarget2_, swap, ::DD::ProcessType, MACRO_ObjectT__)



template <ValidityType has_swap_target_c_>
struct SwapTarget_ {
	template <typename PointerT__>
	static ProcessType swap_target(
		PointerT__ pointer_1___,
		PointerT__ pointer_2___
	) DD_NOEXCEPT_AS(::DD::swap(*pointer_1___, *pointer_2___)) {
		::DD::swap(*pointer_1___, *pointer_2___);
	}


};



template <>
struct SwapTarget_<true> {
	template <typename PointerT__>
	static ProcessType swap_target(
		PointerT__ pointer_1___,
		PointerT__ pointer_2___
	) DD_NOEXCEPT_AS(pointer_1___.swap_target(pointer_2___)) {
		pointer_1___.swap_target(pointer_2___);
	}


};



template <typename PointerT_>
inline ProcessType swap_target(
	PointerT_ pointer_1__,
	PointerT_ pointer_2__
) DD_NOEXCEPT_AS(SwapTarget_<
	HasSwapTarget1_<PointerT_>::value || HasSwapTarget2_<PointerT_>::value
>::swap_target(pointer_1__, pointer_2__)) {
	SwapTarget_<
		HasSwapTarget1_<PointerT_>::value || HasSwapTarget2_<PointerT_>::value
	>::swap_target(pointer_1__, pointer_2__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::swap_target;



DD_END_



#endif
