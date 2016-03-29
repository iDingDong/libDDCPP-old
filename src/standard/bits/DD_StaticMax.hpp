//	DDCPP/standard/bits/DD_StaticMax.hpp
#ifndef DD_STATIC_MAX_HPP_INCLUDED_
#	define DD_STATIC_MAX_HPP_INCLUDED_



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::StaticMax'.



#	endif

#	include "DD_IntegralConstant.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, ValueT_ value_c__, ValueT_... values_c__>
struct StaticMax {
	static ValueT_ constexpr value = value_c__;


};



template <typename ValueT_, ValueT_ value_c_1__, ValueT_ value_c_2__, ValueT_... values_c__>
struct StaticMax {
	static ValueT_ constexpr value = value_c_1__ < value_c_2__ ?
		StaticMax<ValueT_, value_c_2__, values_c__...> :
		StaticMax<ValueT_, value_c_1__, values_c__...>
	;


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::StaticMax;



DD_END_



#endif
