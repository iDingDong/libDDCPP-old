//	DDCPP/standard/bits/DD_IsNullPointer.hpp
#ifndef DD_IS_NIL_POINTER_HPP_INCLUDED_
#	define DD_IS_NIL_POINTER_HPP_INCLUDED_ 1



#	include "DD_Nil.hpp"
#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
#	if __cplusplus >= 201103L
struct IsNilPointer_ : StdBoolConstant<std::is_null_pointer<ObjectT_>> {
#	else
struct IsNilPointer_ : FalseType {
#	endif
};



template <>
struct IsNilPointer_<NilPointerType> : TrueType {
};



#	if __cplusplus >= 201103L
template <>
struct IsNilPointer_<std::nullptr_t> : TrueType {
};



#	endif
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsNilPointer : AndType<IsNilPointer<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsNilPointer<ObjectT_> : IsNilPointer_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsNilPointer : IsNilPointer_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsNilPointer;



DD_END_



#endif
