//	DDCPP/standard/bits/DD_IsUnsigned.hpp
#ifndef _DD_IS_UNSIGNED_HPP_INCLUDED
#	define _DD_IS_UNSIGNED_HPP_INCLUDED 1



#	include "DD_IsArithmetic.hpp"



_DD_DETAIL_BEGIN
template <typename _ObjectT, ValidityType _is_arithmetic_c>
#	if __cplusplus >= 201103L
struct _IsUnsigned : StdBoolConstant<std::is_unsigned<_ObjectT>> {
#	else
struct _IsUnsigned : FalseType {
#	endif
};



template <typename _ObjectT>
struct _IsUnsigned<_ObjectT, true> : BoolConstant<_ObjectT(0) < _ObjectT(-1)> {
};



_DD_DETAIL_END



_DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsUnsigned = AndType<_detail::_IsUnsigned<_ObjectsT, IsArithmetic<_ObjectsT>::value>...>;
#	else
template <typename _ObjectT>
struct IsUnsigned : _detail::_IsUnsigned<_ObjectT, IsArithmetic<_ObjectT>::value> {
};
#	endif



_DD_END



#endif
