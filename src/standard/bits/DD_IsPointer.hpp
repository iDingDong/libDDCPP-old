//	DDCPP/standard/bits/DD_IsPointer.hpp
#ifndef DD_IS_POINTER_HPP_INCLUDED_
#	define DD_IS_POINTER_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"
#	include "DD_Nil.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
#	if __cplusplus >= 201103L
struct IsPointer_ : StdBoolConstant<std::is_pointer<ObjectT_>> {
#	else
struct IsPointer_ : FalseType {
#	endif
};



template <typename ValueT_>
struct IsPointer_<ValueT_*> : TrueType {
};



template <>
struct IsPointer_<NilPointerType> : TrueType {
};



#	if __cplusplus >= 201103L
template <>
struct IsPointer_<std::nullptr_t> : TrueType {
};
#	endif



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsPointer : AndType<IsPointer<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsPointer<ObjectT_> : IsPointer_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsPointer : IsPointer_<typename RemoveCV<ObjectT_>::type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsPointer;



DD_END_



#endif
