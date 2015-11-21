//	DDCPP/standard/bits/DD_reverse.hpp
#ifndef DD_REVERSE_HPP_INCLUDED_
#	define DD_REVERSE_HPP_INCLUDED_ 1



#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_swap_target.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_c_>
struct Reverse_ {
	template <typename BidirectionalIteratorT__>
	static ProcessType reverse(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::swap_target(++begin___, --end___) DD_COMMA ValidityType(begin___ != end___)) {
		for (; begin___ != end___ && begin___ != --end___; ++begin___) {
			::DD::swap_target(begin___, end___);
		}
	}


};



template <>
struct Reverse_<true> {
	template <typename FreeAccessIteratorT__>
	static ProcessType reverse(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::swap_target(++begin___, --end___) DD_COMMA ValidityType(begin___ < end___)) {
		for (; begin___ < --end___; ++begin___) {
			::DD::swap_target(begin___, end___);
		}
	}


};



template <typename BidirectionalIteratorT_>
inline ProcessType reverse(
	BidirectionalIteratorT_ const& begin__,
	BidirectionalIteratorT_ const& end__
) DD_NOEXCEPT_AS(Reverse_<IsFreeAccessIterator<BidirectionalIteratorT_>::value>::reverse(begin__ DD_COMMA end__)) {
	Reverse_<IsFreeAccessIterator<BidirectionalIteratorT_>::value>::reverse(begin__, end__);
}



template <typename BidirectionalRangeT_>
inline ProcessType reverse(
	BidirectionalRangeT_& range__
) DD_NOEXCEPT_AS(::DD::detail_::reverse(DD_SPLIT_RANGE(range__))) {
	::DD::detail_::reverse(DD_SPLIT_RANGE(range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::reverse;



DD_END_



#endif
