//	DDCPP/standard/bits/DD_square_root.hpp
#ifndef _DD_SQUARE_ROOT_HPP
#	define _DD_SQUARE_ROOT_HPP 1



#	include "../../standard/bits/DD_IsIntegral.hpp"

#	include "DD_math_definitions.hpp"



_DD_DETAIL_BEGIN
template <typename _ResultT, ValidityType _has_integral_result_c = IsIntegral<_ResultT>::value>
struct _SquareRoot {
	template <typename _NumberT>
#	if __cplusplus >= 201402L
	static _ResultT constexpr _square_root(
		_NumberT const& __number
	) DD_NOEXCEPT {
#	else
	static _ResultT _square_root(
		_NumberT const& __number
	) DD_NOEXCEPT {
#	endif
		throw false;
	}


};



template <typename _ResultT>
struct _SquareRoot<_ResultT, true> {
	template <typename _NumberT>
#	if __cplusplus >= 201402L
	static _ResultT constexpr _square_root(
		_NumberT const& __number
	) DD_NOEXCEPT {
#	else
	static _ResultT _square_root(
		_NumberT const& __number
	) DD_NOEXCEPT {
#	endif
		_ResultT __low = _ResultT();
		_ResultT __high = __number;
		_ResultT __current;
		do {
			__current = (__low + __high) / 2;
			_NumberT __current_power = __current * __current;
			if (__current_power < __number) {
				__low = __current;
			} else if (__number < __current_power) {
				__high = __current;
			} else {
				return __current;
			}
		} while (__high - __low > 1);
		return __low;
	}


};



_DD_DETAIL_END



_DD_BEGIN
template <typename _ResultT, typename _NumberT>
inline _ResultT DD_CONSTEXPR square_root(
	_NumberT const& __number
) DD_NOEXCEPT_AS(_detail::_SquareRoot<_ResultT>::_square_root(__number)) {
	return _detail::_SquareRoot<_ResultT>::_square_root(__number);
}



_DD_END



#endif
