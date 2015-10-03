//	DDCPP/standard/bits/DD_Value.hpp
#ifndef DD_VALUE_HPP_INCLUDED_
#	define DD_VALUE_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"



#	if __cplusplus < 201103L
DD_DETAIL_BEGIN_
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



DD_DETAIL_END_



#	elif DDCPP_COMPAT_STL
DD_DETAIL_BEGIN_
DD_NESTED_TYPE_TRAIT(Value_, value_type, RemoveReferenceType<decltype(*MACRO_ObjectT_())>)



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(Value, ValueType, typename detail_::Value_<MACRO_ObjectT_>::Type)
#		else
DD_NESTED_TYPE_TRAIT(Value, ValueType, RemoveReferenceType<decltype(*MACRO_ObjectT_())>)
#		endif
#	else
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(Value, ValueType, typename detail_::Value_<typename RemoveCV<MACRO_ObjectT_>::Type>::Type);
#		else
template <typename ObjectT_>
struct Value : detail_::Value_<typename RemoveCV<ObjectT_>::Type> {
};
#		endif
#	endif



DD_TRAIT_MODIFIER(Value)



DD_END_



#endif

