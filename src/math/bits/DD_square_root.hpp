//	DDCPP/standard/bits/DD_square_root.hpp
#ifndef DD_SQUARE_ROOT_HPP_
#	define DD_SQUARE_ROOT_HPP_ 1



#	include "../../standard/bits/DD_IsIntegral.hpp"

#	include "DD_math_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ResultT_, ValidityType has_integral_result_c_ = IsIntegral<ResultT_>::value>
struct SquareRoot_ {
	template <typename NumberT_>
#	if __cplusplus >= 201402L
	static ResultT_ constexpr square_root_(
		NumberT_ const& number__
	) DD_NOEXCEPT {
#	else
	static ResultT_ square_root_(
		NumberT_ const& number__
	) DD_NOEXCEPT {
#	endif
		throw false;
	}


};



template <typename ResultT_>
struct SquareRoot_<ResultT_, true> {
	template <typename NumberT_>
#	if __cplusplus >= 201402L
	static ResultT_ constexpr square_root_(
		NumberT_ const& number__
	) DD_NOEXCEPT {
#	else
	static ResultT_ square_root_(
		NumberT_ const& number__
	) DD_NOEXCEPT {
#	endif
		ResultT_ low__ = ResultT_();
		ResultT_ high__ = number__;
		do {
			ResultT_ current__ = (low__ + high__) / 2;
			NumberT_ current_power__ = current__ * current__;
			if (current_power__ < number__) {
				low__ = current__;
			} else if (number__ < current_power__) {
				high__ = current__;
			} else {
				return current__;
			}
		} while (high__ - low__ > 1);
		return low__;
	}


};



DD_DETAIL_END_



DD_BEGIN_
template <typename ResultT_, typename NumberT_>
inline ResultT_ DD_CONSTEXPR square_root(
	NumberT_ const& number__
) DD_NOEXCEPT_AS(detail_::SquareRoot_<ResultT_>::square_root_(number__)) {
	return detail_::SquareRoot_<ResultT_>::square_root_(number__);
}



DD_END_



#endif
