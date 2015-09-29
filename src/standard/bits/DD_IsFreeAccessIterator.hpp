//	DDCPP/standard/bits/DD_IsFreeAccessIterator.hpp
#ifndef DD_IS_FREE_ACCESS_ITERATOR_HPP_INCLUDED_
#	define DD_IS_FREE_ACCESS_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_IsBaseOf.hpp"
#	include "DD_IteratorCatagory.hpp"



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... IteratorsT_>
using IsFreeAccessIterator = IsBaseOf<FreeAccessIterator, IteratorCatagoryType<IteratorsT_>...>;
#	else
template <typename IteratorT_>
struct IsFreeAccessIterator : IsBaseOf<FreeAccessIterator, typename IteratorCatagory<IteratorT_>::Type> {
};
#	endif



DD_END_



#endif
