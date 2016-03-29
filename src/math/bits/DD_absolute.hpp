//	DDCPP/standard/bits/DD_absolute.hpp
#ifndef DD_ABSOLUTE_HPP_
#	define DD_ABSOLUTE_HPP_ 1



#	include <standard/bits/DD_IsUnsigned.hpp>

#	include "DD_math_definitions.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_unsigned_c_>
struct Absolute_ {
	template <typename NumberT__>
	static NumberT__ DD_CONSTEXPR absolute(
		NumberT__ const& number___
	) DD_NOEXCEPT_AS(number___ < 0 ? -number___ : number___) {
		return number___ < 0 ? -number___ : number___;
	}


};



template <>
struct Absolute_<true> {
	template <typename NumberT__>
	static NumberT__ DD_CONSTEXPR absolute(
		NumberT__ const& number___
	) DD_NOEXCEPT_AS(NumberT__(number___)) {
		return number___;
	}


};



template <typename NumberT_>
inline NumberT_ DD_CONSTEXPR absolute(
	NumberT_ const& number__
) DD_NOEXCEPT_AS(number__ < 0 ? -number__ : number__) {
	return Absolute_<IsUnsigned<NumberT_>::value>::absolute(number__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::absolute;



DD_END_



#endif
