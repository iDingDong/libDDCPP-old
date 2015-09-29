//	DDCPP/standard/bits/DD_release.hpp
#ifndef DD_RELEASE_HPP_INCLUDED_
#	define DD_RELEASE_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename PointerT_>
inline PointerT_ DD_CONSTEXPR release(PointerT_& pointer__, PointerT_ new_pointer__ = PointerT_(), PointerT_ workaround__ = PointerT_()) DD_NOEXCEPT {
	return workaround__ = pointer__, pointer__ = new_pointer__, workaround__;
}



DD_END_



#endif
