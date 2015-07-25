//	DDCPP/standard/bits/DD_IsDouble.hpp
#ifndef _DD_IS_DOUBLE_HPP_INCLUDED
#	define _DD_IS_DOUBLE_HPP_INCLUDED



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsDouble : FalseType {
};



template <>
struct _IsDouble<double> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsDouble = AndType<detail::_IsDouble<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsDouble : detail::_IsDouble<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
