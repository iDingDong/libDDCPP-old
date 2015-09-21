//	DDCPP/standard/bits/DD_IsVolatile.hpp
#ifndef _DD_IS_Volatile_HPP_INCLUDED
#	define _DD_IS_Volatile_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



_DD_DETAIL_BEGIN
template <typename _ObjectT>
#	if __cplusplus >= 201103L
struct _IsVolatile : StdBoolConstant<std::is_volatile<_ObjectT>> {
#	else
struct _IsVolatile : FalseType {
#	endif
};



template <typename _ObjectT>
struct _IsVolatile<_ObjectT volatile> : TrueType {
};



_DD_DETAIL_END



_DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsVolatile = AndType<_detail::_IsVolatile<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct IsVolatile : _detail::_IsVolatile<_ObjectT> {
};
#	endif



_DD_END



#endif
