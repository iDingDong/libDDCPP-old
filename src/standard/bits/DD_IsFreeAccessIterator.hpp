//	DDCPP/standard/bits/DD_IsFreeAccessIterator.hpp
#ifndef _DD_IS_FREE_ACCESS_ITERATOR_HPP_INCLUDED
#	define _DD_IS_FREE_ACCESS_ITERATOR_HPP_INCLUDED 1



#	include "DD_IsBaseOf.hpp"
#	include "DD_IteratorCatagory.hpp"



_DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _IteratorsT>
using IsFreeAccessIterator = IsBaseOf<FreeAccessIterator, IteratorCatagoryType<_IteratorsT>...>;
#	else
template <typename _IteratorT>
struct IsFreeAccessIterator : IsBaseOf<FreeAccessIterator, typename IteratorCatagory<_IteratorT>::Type> {
};
#	endif



_DD_END



#endif
