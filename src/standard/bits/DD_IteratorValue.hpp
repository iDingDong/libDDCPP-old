//	DDCPP/standard/bits/DD_IteratorValue.hpp
#ifndef _DD_ITERATOR_VALUE_HPP_INCLUDED
#	define _DD_ITERATOR_VALUE_HPP_INCLUDED 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"



#	if __cplusplus < 201103L
_DD_DETAIL_BEGIN
template <typename _IteratorT>
struct _IteratorValue {
#		if DDCPP_COMPAT_STL
	typedef typename _IteratorT::value_type Type;
#		else
	typedef typename _IteratorT::ValueType Type;
#		endif


};



template <typename _ValueT>
struct _IteratorValue<_ValueT*> {
	typedef _ValueT Type;


};



_DD_DETAIL_END



#	elif DDCPP_COMPAT_STL
_DD_DETAIL_BEGIN
DD_NESTED_TYPE_TRAIT(_IteratorValue, value_type, RemoveReferenceType<decltype(*_MACRO_ObjectT())>)



_DD_DETAIL_END



#	endif
_DD_BEGIN
#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(IteratorValue, ValueType, typename _detail::_IteratorValue<_MACRO_ObjectT>::Type)
#		else
DD_NESTED_TYPE_TRAIT(IteratorValue, ValueType, RemoveReferenceType<decltype(*_MACRO_ObjectT())>)
#		endif



template <typename _IteratorT>
using IteratorValueType = typename IteratorValue<_IteratorT>::Type;
#	else
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(IteratorValue, ValueType, typename _detail::_IteratorValue<typename RemoveCV<_MACRO_ObjectT>::Type>::Type);
#		else
template <typename _IteratorT>
struct IteratorValue : _detail::_IteratorValue<typename RemoveCV<_IteratorT>::Type> {
};
#		endif
#	endif



_DD_END



#endif
