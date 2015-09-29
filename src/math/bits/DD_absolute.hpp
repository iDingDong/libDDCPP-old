//	DDCPP/standard/bits/DD_absolute.hpp
#ifndef DD_ABSOLUTE_HPP_
#	define DD_ABSOLUTE_HPP_ 1



#	include "DD_math_definitions.hpp"



DD_BEGIN_
template <typename NumberT_>
inline NumberT_ absolute(
	NumberT_ const& number__
) DD_NOEXCEPT_AS(number__ < 0 ? -number__ : number__) {
	return number__ < 0 ? -number__ : number__;
}




DD_END_



#endif
