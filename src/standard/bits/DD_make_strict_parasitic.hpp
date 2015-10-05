//	DDCPP/standard/bits/DD_make_parastic.hpp
#ifndef DD_MAKE_INTRUSIVE_HPP_INCLUDED_
#	define DD_MAKE_INTRUSIVE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::make_parastic'.



#	endif
#	include "DD_StrictParasiticPointer.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, typename... ArgumentsT_>
StrictParasiticPointer<ValueT_> make_strict_parasitic(ArgumentsT_&&... arguments__) DD_NOEXCEPT_AS(
	StrictParasiticPointer<ValueT_>(new StrictParasitifer<ValueT_>(ValueT_(forward<ArgumentsT_>(arguments__)...)))
) {
	return StrictParasiticPointer<ValueT_>(new StrictParasitifer<ValueT_>(ValueT_(forward<ArgumentsT_>(arguments__)...)));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::make_strict_parasitic;



DD_END_



#endif
