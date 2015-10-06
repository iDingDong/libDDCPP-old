//	DDCPP/standard/bits/DD_address_of.hpp
#ifndef DD_ADDRESS_OF_HPP_INCLUDED_
#	define DD_ADDRESS_OF_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
ValueT_ DD_CONSTEXPR* address_of(ValueT_& object__) DD_NOEXCEPT {
	return reinterpret_cast<ValueT_*>(&const_cast<char&>(reinterpret_cast<char const volatile&>(object__)));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::address_of;



DD_END_



#endif
