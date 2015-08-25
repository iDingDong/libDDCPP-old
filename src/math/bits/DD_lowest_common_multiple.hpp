//	DDCPP/math/bits/DD_lowest_common_multiple.hpp
#ifndef _DD_LOWEST_COMMON_MULTIPLE_HPP_INCLUDED
#	define _DD_LOWEST_COMMON_MULTIPLE_HPP_INCLUDED 1



#	include "DD_greatest_common_divisor.hpp"



DD_BEGIN
template <typename _IntegerT>
inline _IntegerT DD_CONSTEXPR lowest_common_multiple(
	_IntegerT const& __integer_1,
	_IntegerT const& __integer_2
) DD_NOEXCEPT_AS(static_cast<_IntegerT>(__integer_1 * __integer_2 / greatest_common_divisor(__integer_1, __integer_2))) {
	return __integer_1 * __integer_2 / greatest_common_divisor(__integer_1, __integer_2);
}



DD_END



#endif
