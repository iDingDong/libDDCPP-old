//	DDCPP/standard/bits/DD_IsPointer.hpp
#ifndef _DD_IS_POINTER_HPP_INCLUDED
#	define _DD_IS_POINTER_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"
#	include "DD_Nil.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
#	if __cplusplus >= 201103L
struct _IsPointer : StdBoolConstant<std::is_pointer<_ObjectT>> {
#	else
struct _IsPointer : FalseType {
#	endif
};



template <typename _ValueT>
struct _IsPointer<_ValueT*> : TrueType {
};



template <>
struct _IsPointer<NilPointerType> : TrueType {
};



#	if __cplusplus >= 201103L
template <>
struct _IsPointer<std::nullptr_t> : TrueType {
};
#	endif



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsPointer = AndType<detail::_IsPointer<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsPointer : detail::_IsPointer<typename RemoveCV<_ObjectT>::type> {
};
#	endif



DD_END



#endif
