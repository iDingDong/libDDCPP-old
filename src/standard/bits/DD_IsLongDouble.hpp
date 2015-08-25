//	DDCPP/standard/bits/DD_IsLongDouble.hpp
#ifndef _DD_IS_LONG_DOUBLE_HPP_INCLUDED
#	define _DD_IS_LONG_DOUBLE_HPP_INCLUDED



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsLongDouble : FalseType {
};



template <>
struct _IsLongDouble<double> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsLongDouble = AndType<_detail::_IsLongDouble<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsLongDouble : _detail::_IsLongDouble<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
