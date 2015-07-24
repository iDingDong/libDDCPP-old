//	standard/bits/DD_address_of.hpp
#ifndef _DD_ADDRESS_OF_HPP_INCLUDED
#	define _DD_ADDRESS_OF_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ValueT>
_ValueT DD_CONSTEXPR* address_of(_ValueT& __object) DD_NOEXCEPT {
	return reinterpret_cast<_ValueT*>(&const_cast<char&>(reinterpret_cast<char const volatile&>(__object)));
}



DD_END



#endif
