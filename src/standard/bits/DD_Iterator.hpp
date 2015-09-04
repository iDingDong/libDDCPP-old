//	DDCPP/standard/bits/DD_Iterator.hpp
#ifndef _DD_ITERATOR_HPP_INCLUDED
#	define _DD_ITERATOR_HPP_INCLUDED 1 



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"



#	if __cplusplus < 201103L
DD_DETAIL_BEGIN
template <typename _RangeT>
struct _Iterator {
#		if DDCPP_COMPAT_STL
	typedef typename _RangeT::Iterator Type;
#		else
	typedef typename _RangeT::Iterator Type;
#		endif
	
	
};



template <typename _ValueT, LengthType _length_c>
struct _Iterator<_ValueT[_length_c]> {
	typedef _ValueT* Type;
	
	
};



template <typename _ValueT>
struct _Iterator<_ValueT[]> {
	typedef _ValueT* Type;
	
	
};



template <typename _ValueT>
struct _Iterator<_ValueT*> {
	typedef _ValueT* Type;
	
	
};



DD_DETAIL_END



#	elif DDCPP_COMPAT_STL
DD_DETAIL_BEGIN
DD_NESTED_TYPE_TRAIT(_Iterator, iterator, RemoveReferenceType<decltype(*_MACRO_ObjectT())>)



DD_DETAIL_END



#	endif
DD_BEGIN
#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(Iterator, Iterator, typename _detail::_Iterator<_MACRO_ObjectT>::Type)
#		else
DD_NESTED_TYPE_TRAIT(Iterator, Iterator, RemoveReferenceType<decltype(*_MACRO_ObjectT())>)
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
