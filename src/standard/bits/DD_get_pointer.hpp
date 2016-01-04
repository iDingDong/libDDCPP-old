//	DDCPP/standard/bits/DD_get_pointer.hpp
#ifndef DD_GET_POINTER_HPP_INCLUDED_
#	define DD_GET_POINTER_HPP_INCLUDED_ 1



#	include "DD_address_of.hpp"
#	if __cplusplus < 201103L
#		include "DD_IteratorPointer.hpp"
#	endif



DD_DETAIL_BEGIN_
inline GlobalPointerType get_pointer(GlobalPointerType pointer__) DD_NOEXCEPT {
	return pointer__;
}


template <typename PointerT_>
#	if __cplusplus >= 201402L
inline auto DD_CONSTEXPR get_pointer(PointerT_ const& pointer__) DD_NOEXCEPT_AS(::DD::address_of(*pointer__)) {
#	elif __cplusplus >= 201103L
inline auto DD_CONSTEXPR get_pointer(PointerT_ const& pointer__) DD_NOEXCEPT_AS(
	::DD::address_of(*pointer__)
) -> decltype(address_of(*pointer__)) {
#	else
inline typename IteratorPointer<PointerT_>::Type get_pointer(PointerT_ const& pointer__) DD_NOEXCEPT {
#	endif
	return ::DD::address_of(*pointer__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::get_pointer;



DD_END_



#endif
