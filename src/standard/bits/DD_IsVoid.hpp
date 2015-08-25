//	DDCPP/standard/bits/DD_IsVoid.hpp
#ifndef _DD_IS_VOID_HPP_INCLUDED
#	define _DD_IS_VOID_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN
template <typename _ObjectT>
#	if __cplusplus >= 201103L
struct _IsVoid : StdBoolConstant<std::is_void<_ObjectT>> {
#	else
struct _IsVoid : FalseType {
#	endif
};



template <>
struct _IsVoid<void> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsVoid = AndType<_detail::_IsVoid<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct IsVoid : _detail::_IsVoid<_ObjectT> {
};
#	endif



DD_END



#endif
