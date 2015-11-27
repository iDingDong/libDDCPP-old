//	DDCPP/math/bits/DD_greatest_common_divisor.hpp
#ifndef DD_GREATEST_COMMON_DIVISOR_HPP_INCLUDED_
#	define DD_GREATEST_COMMON_DIVISOR_HPP_INCLUDED_ 1



#	include "DD_math_definitions.hpp"



DD_BEGIN_
template <typename IntegerT_>
inline IntegerT_ DD_CONSTEXPR greatest_common_divisor(
	IntegerT_ integer_1__,
#	if __cplusplus >= 201402L || __cplusplus < 201103L
	IntegerT_ integer_2__
) DD_NOEXCEPT_IF(noexcept(IntegerT_()) && noexcept(integer_1__ = integer_2__ DD_COMMA integer_2__ % integer_2__)) {
	for (IntegerT_ temp__; temp__ = integer_1__ % integer_2__; ) {
		integer_1__ = integer_2__;
		integer_2__ = temp__;
	}
	return integer_2__;
#	else
	IntegerT_ const& integer_2__
) noexcept(noexcept(static_cast<bool>((integer_1__ %= integer_2__)))) {
	return (integer_1__ %= integer_2__) ? greatest_common_divisor(integer_2__, integer_1__) : integer_2__;
#	endif
}



DD_END_



#endif
