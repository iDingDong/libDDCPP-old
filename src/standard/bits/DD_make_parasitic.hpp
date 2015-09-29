//	DDCPP/standard/bits/DD_make_parastic.hpp
#ifndef DD_MAKE_INTRUSIVE_HPP_INCLUDED_
#	define DD_MAKE_INTRUSIVE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::make_parastic'.



#	endif
#	include "DD_ParasiticPointer.hpp"



DD_BEGIN_
template <typename ValueT_, typename... ArgumentsT_>
ParasiticPointer<ValueT_> make_parasitic(ArgumentsT_&&... arguments__) DD_NOEXCEPT_AS(typename ParasiticPointer<ValueT_>::ParasitiferValueType(0 DD_COMMA ValueT_(arguments__...))) {
	return ParasiticPointer<ValueT_>(new typename ParasiticPointer<ValueT_>::ParasitiferValueType(0, ValueT_(arguments__...)));
}



DD_END_



#endif
