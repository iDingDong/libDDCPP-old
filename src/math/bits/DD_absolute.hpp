//	DDCPP/standard/bits/DD_absolute.hpp
#ifndef _DD_ABSOLUTE_HPP
#	define _DD_ABSOLUTE_HPP 1



#	include "DD_math_definitions.hpp"



DD_BEGIN
template <typename _NumberT>
inline _NumberT absolute(
	_NumberT const& __number
) DD_NOEXCEPT_AS(__number < 0 ? -__number : __number) {
	return __number < 0 ? -__number : __number;
}




DD_END



#endif
