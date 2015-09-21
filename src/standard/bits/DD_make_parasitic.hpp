//	DDCPP/standard/bits/DD_make_parastic.hpp
#ifndef _DD_MAKE_INTRUSIVE_HPP_INCLUDED
#	define _DD_MAKE_INTRUSIVE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::make_parastic'.



#	endif
#	include "DD_ParasiticPointer.hpp"



_DD_BEGIN
template <typename _ValueT, typename... _ArgumentsT>
ParasiticPointer<_ValueT> make_parasitic(_ArgumentsT&&... __arguments) DD_NOEXCEPT_AS(typename ParasiticPointer<_ValueT>::ParasitiferValueType(0 DD_COMMA _ValueT(__arguments...))) {
	return ParasiticPointer<_ValueT>(new typename ParasiticPointer<_ValueT>::ParasitiferValueType(0, _ValueT(__arguments...)));
}



_DD_END



#endif
