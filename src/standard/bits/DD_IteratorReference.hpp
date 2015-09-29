//	DDCPP/standard/bits/DD_IteratorReference.hpp
#ifndef DD_ITERATOR_REFERENCE_HPP_INCLUDED_
#	define DD_ITERATOR_REFERENCE_HPP_INCLUDED_ 1



#	include "DD_IteratorValue.hpp"



#	if DDCPP_COMPAT_STL
DD_DETAIL_BEGIN_
DD_NESTED_TYPE_TRAIT(IteratorReference_, reference, typename IteratorValue<MACRO_ObjectT_>::Type&)



DD_DETAIL_END_



#	endif
DD_BEGIN_
#	if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(IteratorReference, ReferenceType, typename detail_::IteratorReference_<MACRO_ObjectT_>::Type)
#	else
DD_NESTED_TYPE_TRAIT(IteratorReference, ReferenceType, typename IteratorValue<MACRO_ObjectT_>::Type&)
#	endif



#	if __cplusplus >= 201103L
template <typename IteratorT_>
using IteratorReferenceType = typename IteratorReference<IteratorT_>::Type;



#	endif
DD_END_



#endif
