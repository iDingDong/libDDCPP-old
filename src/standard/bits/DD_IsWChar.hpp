//	DDCPP/standard/bits/DD_IsWChar.hpp
#ifndef _DD_IS_W_CHAR_HPP_INCLUDED
#	define _DD_IS_W_CHAR_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsWChar : FalseType {
};



template <>
struct _IsWChar<wchar_t> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsWChar = AndType<_detail::_IsWChar<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsWChar : _detail::_IsWChar<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
