//	standard/bits/DD_release.hpp
#ifndef _DD_RELEASE_HPP_INCLUDED
#	define _DD_RELEASE_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _PointerT>
inline _PointerT DD_CONSTEXPR release(_PointerT& __pointer, _PointerT __new_pointer = _PointerT(), _PointerT __workaround = _PointerT()) DD_NOEXCEPT {
	return __workaround = __pointer, __pointer = __new_pointer, __workaround;
}



DD_END



#endif
