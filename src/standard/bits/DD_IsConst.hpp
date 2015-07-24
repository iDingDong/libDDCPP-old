//	standard/bits/DD_IsConst.hpp
#ifndef _DD_IS_CONST_HPP_INCLUDED
#	define _DD_IS_CONST_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN
template <typename _ObjectT>
#	if __cplusplus >= 201103L
struct _IsConst : StdBoolConstant<std::is_const<_ObjectT>> {
#	else
struct _IsConst : FalseType {
#	endif
};



template <typename _ObjectT>
struct _IsConst<_ObjectT const> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsConst = AndType<detail::_IsConst<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct IsConst : detail::_IsConst<_ObjectT> {
};
#	endif



DD_END



#endif
