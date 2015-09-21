//	DDCPP/standard/bits/DD_IsSignedInt.hpp
#ifndef _DD_IS_SIGNED_INT_HPP_INCLUDED
#	define _DD_IS_SIGNED_INT_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



_DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsSignedInt : FalseType {
};



template <>
struct _IsSignedInt<signed int> : TrueType {
};



_DD_DETAIL_END



_DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsSignedInt = AndType<_detail::_IsSignedInt<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsSignedInt : _detail::_IsSignedInt<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



_DD_END



#endif
