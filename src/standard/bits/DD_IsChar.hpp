//	standard/bits/DD_IsChar.hpp
#ifndef _DD_IS_CHAR_HPP_INCLUDED
#	define _DD_IS_CHAR_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsChar : FalseType {
};



template <>
struct _IsChar<char> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsChar = AndType<detail::_IsChar<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsChar : detail::_IsChar<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
