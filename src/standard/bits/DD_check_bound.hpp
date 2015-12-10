//	DDCPP/standard/bits/DD_check_bound.hpp
#ifndef DD_CHECK_BOUND_HPP_INCLUDED_
#	define DD_CHECK_BOUND_HPP_INCLUDED_ 1



#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_>
inline ValidityType check_bound(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	FreeAccessIteratorT_ iterator__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(!(iterator__ < begin__) && iterator__ < end__)) {
	return !(iterator__ < begin__) && iterator__ < end__;
}

template <typename FreeAccessRangeT_, typename FreeAccessIteratorT_>
inline ValidityType check_bound(
	FreeAccessRangeT_& range__,
	FreeAccessIteratorT_ iterator_
) DD_NOEXCEPT_AS(::DD::detail_::check_bound(DD_SPLIT_RANGE(range__) DD_COMMA iterator_)) {
	return ::DD::detail_::check_bound(DD_SPLIT_RANGE(range__), iterator_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::check_bound;



DD_END_



#endif
