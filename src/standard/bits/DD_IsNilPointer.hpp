//	DDCPP/standard/bits/DD_IsNullPointer.hpp
#ifndef _DD_IS_NIL_POINTER_HPP_INCLUDED
#	define _DD_IS_NIL_POINTER_HPP_INCLUDED 1



#	include "DD_Nil.hpp"
#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
#	if __cplusplus >= 201103L
struct _IsNilPointer : StdBoolConstant<std::is_null_pointer<_ObjectT>> {
#	else
struct _IsNilPointer : FalseType {
#	endif
};



template <>
struct _IsNilPointer<NilPointerType> : TrueType {
};



#	if __cplusplus >= 201103L
template <>
struct _IsNilPointer<std::nullptr_t> : TrueType {
};



#	endif
DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsNilPointer = AndType<_detail::_IsNilPointer<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsNilPointer : _detail::_IsNilPointer<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
