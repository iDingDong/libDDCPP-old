//	DDCPP/standard/bits/DD_IsSignedLong.hpp
#ifndef _DD_IS_SIGNED_LONG_HPP_INCLUDED
#	define _DD_IS_SIGNED_LONG_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsSignedLong : FalseType {
};



template <>
struct _IsSignedLong<signed long> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsSignedLong = AndType<_detail::_IsSignedLong<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsSignedLong : _detail::_IsSignedLong<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
