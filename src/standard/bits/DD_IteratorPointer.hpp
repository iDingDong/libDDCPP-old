//	standard/bits/DD_IteratorPointer.hpp
#ifndef _DD_ITERATOR_POINTER_HPP_INCLUDED
#	define _DD_ITERATOR_POINTER_HPP_INCLUDED 1



#	include "DD_IteratorValue.hpp"



#	if DDCPP_COMPAT_STL
DD_DETAIL_BEGIN
DD_NESTED_TYPE_TRAIT(_IteratorPointer, pointer, typename IteratorValue<_MACRO_ObjectT>::Type*)



DD_DETAIL_END



#	endif
DD_BEGIN
#	if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(IteratorPointer, PointerType, typename detail::_IteratorPointer<_MACRO_ObjectT>::Type)
#	else
DD_NESTED_TYPE_TRAIT(IteratorPointer, PointerType, typename IteratorValue<_MACRO_ObjectT>::Type*)
#	endif



#	if __cplusplus >= 201103L
template <typename _IteratorT>
using IteratorPointerType = typename IteratorPointer<_IteratorT>::Type;



#	endif
DD_END



#endif
