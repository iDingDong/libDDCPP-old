//	DDCPP/standard/bits/DD_inplace_merge_sort.hpp
#ifndef DD_IN_PLACE_MERGE_SORT_HPP_INCLUDED_
#	define DD_IN_PLACE_MERGE_SORT_HPP_INCLUDED_ 1



#	include "DD_length_difference.hpp"
#	include "DD_inplace_merge_sort_length.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
inline ProcessType inplace_merge_sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(::DD::inplace_merge_sort_length(
	begin__ DD_COMMA ::DD::length_difference(begin__ DD_COMMA end__) DD_COMMA less__
)) {
	::DD::inplace_merge_sort_length(begin__, ::DD::length_difference(begin__, end__), less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::inplace_merge_sort;



DD_END_



#endif
