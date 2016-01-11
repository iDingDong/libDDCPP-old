//	DDCPP/standard/bits/DD_inplace_merge.hpp
#ifndef DD_INPLACE_MERGE_HPP_INCLUDED_
#	define DD_INPLACE_MERGE_HPP_INCLUDED_ 1



#	include "DD_length_difference.hpp"
#	include "DD_inplace_merge_length.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
ProcessType inplace_merge(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ middle__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(::DD::inplace_merge_length(
	begin__ DD_COMMA
	::DD::length_difference(begin__, middle__) DD_COMMA
	::DD::length_difference(middle__ DD_COMMA end__) DD_COMMA
	less__
)) {
	return ::DD::inplace_merge_length(
		begin__, ::DD::length_difference(begin__, middle__), ::DD::length_difference(middle__, end__), less__
	);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::inplace_merge;



DD_END_



#endif
