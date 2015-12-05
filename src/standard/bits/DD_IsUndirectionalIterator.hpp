//	DDCPP/standard/bits/DD_IsUndirectionalIterator.hpp
#ifndef DD_IS_UNDIRECTIONAL_ITERATOR_HPP_INCLUDED_
#	define DD_IS_UNDIRECTIONAL_ITERATOR_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_IsBaseOf.hpp"
#	elif
#		include "DD_IsSame.hpp"
#	endif
#	include "DD_IteratorCatagory.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... IteratorsT_>
struct IsUndirectionalIterator : IsBaseOf<UndirectionalIterator, IteratorCatagoryType<IteratorsT_>...> {
};
#	else
template <typename IteratorT_>
struct IsUndirectionalIterator : IsSame<UndirectionalIterator, typename IteratorCatagory<IteratorT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsUndirectionalIterator;



DD_END_



#endif
