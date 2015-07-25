//	DDCPP/standard/bits/DD_IsBool.hpp
#ifndef _DD_IS_BOOL_HPP_INCLUDED
#	define _DD_IS_BOOL_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsBool : FalseType {
};



template <>
struct _IsBool<bool> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsBool = AndType<detail::_IsBool<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsBool : detail::_IsBool<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
