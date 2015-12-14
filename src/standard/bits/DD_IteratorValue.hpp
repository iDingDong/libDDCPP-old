//	DDCPP/standard/bits/DD_IteratorValue.hpp
#ifndef DD_ITERATOR_VALUE_HPP_INCLUDED_
#	define DD_ITERATOR_VALUE_HPP_INCLUDED_ 1



#	include "DD_Value.hpp"



DD_DETAIL_BEGIN_
template <typename IteratorT_>
struct IteratorValue : Value<IteratorT_> {
};



DD_TRAIT_MODIFIER(IteratorValue)



DD_DETAIL_END_



DD_BEGIN_
using detail_::IteratorValue;
#	if __cplusplus >= 201103L
using detail_::IteratorValueType;
#	endif



DD_END_



#endif
