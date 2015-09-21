//	DDCPP/math/bits/DD_greatest_common_divisor.hpp
#ifndef _DD_GREATEST_COMMON_DIVISOR_HPP_INCLUDED
#	define _DD_GREATEST_COMMON_DIVISOR_HPP_INCLUDED 1



#	include "DD_math_definitions.hpp"



_DD_BEGIN
template <typename _IntegerT>
inline _IntegerT DD_CONSTEXPR greatest_common_divisor(
	_IntegerT __integer_1,
#	if __cplusplus >= 201402L || __cplusplus < 201103L
	_IntegerT __integer_2
) DD_NOEXCEPT_IF(noexcept(__IntegerT()) && noexcept(__integer_1 = __integer_2 DD_COMMA __integer_2 % __integer_2)) {
	for (_IntegerT __temp; __temp = __integer_1 % __integer_2; ) {
		__integer_1 = __integer_2;
		__integer_2 = __temp;
	}
	return __integer_2;
#	else
	_IntegerT const& __integer_2
) noexcept(noexcept(static_cast<bool>((__integer_1 %= __integer_2)))) {
	return (__integer_1 %= __integer_2) ? greatest_common_divisor(__integer_2, __integer_1) : __integer_2;
#	endif
}



_DD_END



#endif
