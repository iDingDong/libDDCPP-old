//	DDCPP/standard/bits/DD_Value.hpp
#ifndef DD_VALUE_HPP_INCLUDED_
#	define DD_VALUE_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus < 201103L
template <typename ObjectT_>
struct Value_ {
#		if DDCPP_COMPAT_STL
	typedef typename ObjectT_::value_type Type;
#		else
	typedef typename ObjectT_::ValueType Type;
#		endif


};



template <typename ValueT_>
struct Value_<ValueT_*> {
	typedef ValueT_ Type;


};



#	elif DDCPP_COMPAT_STL
template <typename ObjectT_>
struct Value__ {
	using Type = decltype(*ObjectT_());


};



template <typename ValueT_>
struct Value__<ValueT_*> {
	using Type = ValueT_;


};



DD_NESTED_TYPE_TRAIT(Value_, value_type, RemoveReferenceType<typename ::DD::detail_::Value__<MACRO_ObjectT_>::Type>)



#	endif
#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(Value, ValueType, typename ::DD::detail_::Value_<MACRO_ObjectT_>::Type)
#		else
DD_NESTED_TYPE_TRAIT(Value, ValueType, RemoveReferenceType<typename ::DD::detail_::Value__<MACRO_ObjectT_>::Type>)
#		endif
#	else
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(Value, ValueType, typename ::DD::detail_::Value_<typename RemoveCV<MACRO_ObjectT_>::Type>::Type);
#		else
template <typename ObjectT_>
struct Value : Value_<typename RemoveCV<ObjectT_>::Type> {
};
#		endif
#	endif



DD_TRAIT_MODIFIER(Value)



DD_DETAIL_END_



DD_BEGIN_
using detail_::Value;
DD_TRAIT_MODIFIER(Value)



DD_END_



#endif

