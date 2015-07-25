//	DDCPP/standard/bits/DD_IsArray.hpp
#ifndef _DD_IS_ARRAY_HPP_INCLUDED
#	define _DD_IS_ARRAY_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_Nil.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
#	if __cplusplus >= 201103L
struct _IsArray : StdBoolConstant<std::is_array<_ObjectT>> {
#	else
struct _IsArray : FalseType {
#	endif
};



template <typename _ValueT>
struct _IsArray<_ValueT[]> : TrueType {
};



template <typename _ValueT, LengthType _length_c>
struct _IsArray<_ValueT[_length_c]> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsArray = AndType<detail::_IsArray<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct IsArray : detail::_IsArray<_ObjectT> {
};
#	endif



DD_END



#endif
