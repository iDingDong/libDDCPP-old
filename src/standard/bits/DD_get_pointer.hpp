//	DDCPP/standard/bits/DD_get_pointer.hpp
#ifndef DD_GET_POINTER_HPP_INCLUDED_
#	define DD_GET_POINTER_HPP_INCLUDED_ 1



#	include "DD_address_of.hpp"
#	if __cplusplus < 201103L
#		include "DD_IteratorPointer.hpp"
#	endif



DD_BEGIN_
template <typename PointerT_>
#	if __cplusplus >= 201402L
inline auto DD_CONSTEXPR get_pointer(PointerT_ const& pointer__) DD_NOEXCEPT {
#	elif __cplusplus >= 201103L
inline auto DD_CONSTEXPR get_pointer(PointerT_ const& pointer__) DD_NOEXCEPT -> decltype(address_of(*pointer__)) {
#	else
inline typename IteratorPointer<PointerT_>::Type get_pointer(PointerT_ const& pointer__) DD_NOEXCEPT {
#	endif
	return address_of(*pointer__);
}



DD_END_



#endif
