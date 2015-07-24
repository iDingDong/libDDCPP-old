// standard/bits/DD_math_square_root.hpp
#ifndef _DD_MATH_SQUARE_ROOT_HPP
#	define _DD_MATH_SQUARE_ROOT_HPP 1



#	include "../../standard/bits/DD_IsIntegral.hpp"

#	include "DD_math_definitions.hpp"



DD_MATH_DETAIL_BEGIN
template <typename ResultT, typename NumberT, ValidityType ResultIsIntegralT>
struct _SquareRootImplement {
#	if __cplusplus >= 201402L
	static ResultT DD_CONSTEXPR square_root(NumberT const& number) DD_NOEXCEPT {
#	else
	static ResultT DD_CONSTEXPR square_root(NumberT const& number) DD_NOEXCEPT {
#	endif
		throw false;
	}
	
	
};



template <typename ResultT, typename NumberT>
struct _SquareRootImplement<ResultT, NumberT, true> {
#	if __cplusplus >= 201402L
	static ResultT DD_CONSTEXPR square_root(NumberT const& number) DD_NOEXCEPT {
#	else
	static ResultT square_root(NumberT const& number) DD_NOEXCEPT {
#	endif
		ResultT low = ResultT();
		ResultT high = number;
		ResultT current;
		do {
			current = (low + high) / 2;
			NumberT current_power = current * current;
			if (number < current_power) {
				low = current;
			} else if (current_power < number) {
				high = current;
			} else {
				return current;
			}
		} while (high - low > 1);
		return low;
	}
	
	
};



DD_MATH_DETAIL_END



DD_MATH_BEGIN
template <typename ResultT, typename NumberT>
ResultT DD_CONSTEXPR square_root(NumberT const& number) DD_NOEXCEPT_AS(
	detail::_SquareRootImplement<ResultT, NumberT, IsIntegral<ResultT>::value>::square_root(number)
) {
	return detail::_SquareRootImplement<ResultT, NumberT, IsIntegral<ResultT>::value>::square_root(number);
}



DD_MATH_END



#endif