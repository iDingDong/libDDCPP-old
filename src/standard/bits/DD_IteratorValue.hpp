//	DDCPP/standard/bits/DD_IteratorValue.hpp
#ifndef DD_ITERATOR_VALUE_HPP_INCLUDED_
#	define DD_ITERATOR_VALUE_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"



#	if __cplusplus < 201103L
DD_DETAIL_BEGIN_
template <typename IteratorT_>
struct IteratorValue_ {
#		if DDCPP_COMPAT_STL
	typedef typename IteratorT_::value_type Type;
#		else
	typedef typename IteratorT_::ValueType Type;
#		endif


};



template <typename ValueT_>
struct IteratorValue_<ValueT_*> {
	typedef ValueT_ Type;


};



DD_DETAIL_END_



#	elif DDCPP_COMPAT_STL
DD_DETAIL_BEGIN_
DD_NESTED_TYPE_TRAIT(IteratorValue_, value_type, RemoveReferenceType<decltype(*MACRO_ObjectT_())>)



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(IteratorValue, ValueType, typename detail_::IteratorValue_<MACRO_ObjectT_>::Type)
#		else
DD_NESTED_TYPE_TRAIT(IteratorValue, ValueType, RemoveReferenceType<decltype(*MACRO_ObjectT_())>)
#		endif
#	else
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(IteratorValue, ValueType, typename detail_::IteratorValue_<typename RemoveCV<MACRO_ObjectT_>::Type>::Type);
#		else
template <typename IteratorT_>
struct IteratorValue : detail_::IteratorValue_<typename RemoveCV<IteratorT_>::Type> {
};
#		endif
#	endif



DD_TRAIT_MODIFIER(IteratorValue)



DD_END_



#endif
