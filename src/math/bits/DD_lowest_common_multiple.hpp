//	DDCPP/math/bits/DD_lowest_common_multiple.hpp
#ifndef DD_LOWEST_COMMON_MULTIPLE_HPP_INCLUDED_
#	define DD_LOWEST_COMMON_MULTIPLE_HPP_INCLUDED_ 1



#	include "DD_greatest_common_divisor.hpp"



DD_BEGIN_
template <typename IntegerT_>
inline IntegerT_ DD_CONSTEXPR lowest_common_multiple(
	IntegerT_ const& integer_1__,
	IntegerT_ const& integer_2__
) DD_NOEXCEPT_AS(static_cast<IntegerT_>(integer_1__ * integer_2__ / greatest_common_divisor(integer_1__, integer_2__))) {
	return integer_1__ * integer_2__ / greatest_common_divisor(integer_1__, integer_2__);
}



DD_END_



#endif
