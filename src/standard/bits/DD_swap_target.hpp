//	DDCPP/standard/bits/DD_swap_target.hpp
#ifndef _DD_SWAP_TARGET_HPP_INCLUDED
#	define _DD_SWAP_TARGET_HPP_INCLUDED 1



#	include "DD_swap.hpp"



_DD_BEGIN
template <typename _PointerT>
inline ProcessType swap_target(
	_PointerT const& __pointer_1,
	_PointerT const& __pointer_2
) DD_NOEXCEPT_AS(swap(*__pointer_1, *__pointer_2)) {
	using DD::swap;
	swap(*__pointer_1, *__pointer_2);
}



_DD_END



#endif
