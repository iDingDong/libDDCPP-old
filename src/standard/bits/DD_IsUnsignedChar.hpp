//	standard/bits/DD_IsUnsignedChar.hpp
#ifndef _DD_IS_UNSIGNED_CHAR_HPP_INCLUDED
#	define _DD_IS_UNSIGNED_CHAR_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsUnsignedChar : FalseType {
};



template <>
struct _IsUnsignedChar<unsigned char> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsUnsignedChar = AndType<detail::_IsUnsignedChar<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsUnsignedChar : detail::_IsUnsignedChar<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
