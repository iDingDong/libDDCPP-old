//	DDCPP/standard/bits/DD_release.hpp
#ifndef DD_RELEASE_HPP_INCLUDED_
#	define DD_RELEASE_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename PointerT_>
inline PointerT_ release(PointerT_& pointer__) DD_NOEXCEPT {
	PointerT_ result__(pointer__);
	pointer__ = PointerT_();
	return result__;
}

template <typename PointerT_>
inline PointerT_ release(PointerT_& pointer__, PointerT_ const& new_pointer__) DD_NOEXCEPT {
	PointerT_ result__(pointer__);
	pointer__ = new_pointer__;
	return result__;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::release;



DD_END_



#endif
