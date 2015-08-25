//	DDCPP/standard/bits/DD_IteratorReference.hpp
#ifndef _DD_ITERATOR_REFERENCE_HPP_INCLUDED
#	define _DD_ITERATOR_REFERENCE_HPP_INCLUDED 1



#	include "DD_IteratorValue.hpp"



#	if DDCPP_COMPAT_STL
DD_DETAIL_BEGIN
DD_NESTED_TYPE_TRAIT(_IteratorReference, reference, typename IteratorValue<_MACRO_ObjectT>::Type&)



DD_DETAIL_END



#	endif
DD_BEGIN
#	if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(IteratorReference, ReferenceType, typename _detail::_IteratorReference<_MACRO_ObjectT>::Type)
#	else
DD_NESTED_TYPE_TRAIT(IteratorReference, ReferenceType, typename IteratorValue<_MACRO_ObjectT>::Type&)
#	endif



#	if __cplusplus >= 201103L
template <typename _IteratorT>
using IteratorReferenceType = typename IteratorReference<_IteratorT>::Type;



#	endif
DD_END



#endif
