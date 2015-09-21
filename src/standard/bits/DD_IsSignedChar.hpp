//	DDCPP/standard/bits/DD_IsSignedChar.hpp
#ifndef _DD_IS_SIGNED_CHAR_HPP_INCLUDED
#	define _DD_IS_SIGNED_CHAR_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



_DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsSignedChar : FalseType {
};



template <>
struct _IsSignedChar<signed char> : TrueType {
};



_DD_DETAIL_END



_DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsSignedChar = AndType<_detail::_IsSignedChar<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsSignedChar : _detail::_IsSignedChar<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



_DD_END



#endif
