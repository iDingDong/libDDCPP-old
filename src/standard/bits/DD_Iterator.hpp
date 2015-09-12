//	DDCPP/standard/bits/DD_Iterator.hpp
#ifndef _DD_ITERATOR_HPP_INCLUDED
#	define _DD_ITERATOR_HPP_INCLUDED 1 



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"



DD_DETAIL_BEGIN
#	if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(_IteratorOfStl, _RangeT::iterator, void)



#	endif
template <typename _RangeT>
struct _Iterator {
#	if DDCPP_COMPAT_STL
	DD_ALIAS(Type, DD_MODIFY_TRAIT(_IteratorOfStl, _RangeT))
#	else
	DD_ALIAS(Type, void)
#	endif
	
	
};



template <typename _ValueT, LengthType _length_c>
struct _Iterator<_ValueT[_length_c]> {
	DD_ALIAS(Type, _ValueT*)
	
	
};



template <typename _ValueT>
struct _Iterator<_ValueT[]> {
	DD_ALIAS(Type, _ValueT*)
	
	
};



template <typename _ValueT>
struct _Iterator<_ValueT*> {
	DD_ALIAS(Type, _ValueT*)
	
	
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(Iterator, Iterator, typename _detail::_Iterator<_MACRO_ObjectT>::Type)
#		else
DD_NESTED_TYPE_TRAIT(Iterator, Iterator, typename _detail::_Iterator<_MACRO_ObjectT>::Type)
#		endif



template <typename _RangeT>
using IteratorType = typename Iterator<_RangeT>::Type;
#	else
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(Iterator, Iterator, typename _detail::_Iterator<typename RemoveCV<_MACRO_ObjectT>::Type>::Type);
#		else
template <typename _RangeT>
struct Iterator : _detail::_Iterator<typename RemoveCV<_RangeT>::Type> {
};
#		endif
#	endif



DD_END



#endif
