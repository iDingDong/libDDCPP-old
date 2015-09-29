//	DDCPP/standard/bits/DD_IteratorPointer.hpp
#ifndef DD_ITERATOR_POINTER_HPP_INCLUDED_
#	define DD_ITERATOR_POINTER_HPP_INCLUDED_ 1



#	include "DD_IteratorValue.hpp"



#	if DDCPP_COMPAT_STL
DD_DETAIL_BEGIN_
DD_NESTED_TYPE_TRAIT(IteratorPointer_, pointer, typename IteratorValue<MACRO_ObjectT_>::Type*)



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(IteratorPointer, PointerType, typename detail_::IteratorPointer_<MACRO_ObjectT_>::Type)
#	else
DD_NESTED_TYPE_TRAIT(IteratorPointer, PointerType, typename IteratorValue<MACRO_ObjectT_>::Type*)
#	endif



#	if __cplusplus >= 201103L
template <typename IteratorT_>
using IteratorPointerType = typename IteratorPointer<IteratorT_>::Type;



#	endif
DD_END_



#endif
