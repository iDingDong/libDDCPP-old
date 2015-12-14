//	DDCPP/standard/bits/DD_IsFreeAccessIterator.hpp
#ifndef DD_IS_FREE_ACCESS_ITERATOR_HPP_INCLUDED_
#	define DD_IS_FREE_ACCESS_ITERATOR_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_IsBaseOf.hpp"
#	else
#		include "DD_IsSame.hpp"
#	endif
#	include "DD_IteratorCatagory.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... IteratorsT_>
struct IsFreeAccessIterator : AndType<IsFreeAccessIterator<IteratorsT_>...> {
};



template <typename IteratorT_>
struct IsFreeAccessIterator<IteratorT_> : IsBaseOf<FreeAccessIterator, IteratorCatagoryType<IteratorT_>> {
};
#	else
template <typename IteratorT_>
struct IsFreeAccessIterator : IsSame<FreeAccessIterator, typename IteratorCatagory<IteratorT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsFreeAccessIterator;



DD_END_



#endif
