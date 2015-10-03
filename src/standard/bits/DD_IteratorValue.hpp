//	DDCPP/standard/bits/DD_IteratorValue.hpp
#ifndef DD_ITERATOR_VALUE_HPP_INCLUDED_
#	define DD_ITERATOR_VALUE_HPP_INCLUDED_ 1



#	include "DD_Value.hpp"



DD_BEGIN_
template <typename IteratorT_>
#	if __cplusplus >= 201103L
using IteratorValue = Value<IteratorT_>;
#	else
struct IteratorValue : Value<IteratorT_> {
}
#	endif



DD_TRAIT_MODIFIER(IteratorValue)



DD_END_



#endif
