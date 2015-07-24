//	standard/bits/DD_IsUndirectionalIterator.hpp
#ifndef _DD_IS_UNDIRECTIONAL_ITERATOR_HPP_INCLUDED
#	define _DD_IS_UNDIRECTIONAL_ITERATOR_HPP_INCLUDED 1



#	include "DD_IsBaseOf.hpp"
#	include "DD_IteratorCatagory.hpp"



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _IteratorsT>
using IsUndirectionalIterator = IsBaseOf<UndirectionalIterator, IteratorCatagoryType<_IteratorsT>...>;
#	else
template <typename _IteratorT>
struct IsUndirectionalIterator : IsBaseOf<UndirectionalIterator, typename IteratorCatagory<_IteratorT>::Type> {
};
#	endif



DD_END



#endif
