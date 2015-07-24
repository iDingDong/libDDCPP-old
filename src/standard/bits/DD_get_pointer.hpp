//	standard/bits/DD_get_pointer.hpp
#ifndef _DD_GET_POINTER_HPP_INCLUDED
#	define _DD_GET_POINTER_HPP_INCLUDED 1



#	include "DD_address_of.hpp"
#	if __cplusplus < 201103L
#		include "DD_IteratorPointer.hpp"
#	endif



DD_BEGIN
template <typename _PointerT>
#	if __cplusplus >= 201402L
inline auto DD_CONSTEXPR get_pointer(_PointerT const& __pointer) DD_NOEXCEPT {
#	elif __cplusplus >= 201103L
inline auto DD_CONSTEXPR get_pointer(_PointerT const& __pointer) DD_NOEXCEPT -> decltype(address_of(*__pointer)) {
#	else
inline typename IteratorPointer<_PointerT>::Type get_pointer(_PointerT const& __pointer) DD_NOEXCEPT {
#	endif
	return address_of(*__pointer);
}



DD_END



#endif
