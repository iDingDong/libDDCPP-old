// standard/bits/DD_absolute.hpp
#ifndef _DD_ABSOLUTE_HPP
#	define _DD_ABSOLUTE_HPP 1



#	include "DD_math_definitions.hpp"



DD_MATH_BEGIN
template <typename NumberT>
NumberT absolute(NumberT const& number) {
	return number < 0 ? -number : number;
}




DD_MATH_END



#endif