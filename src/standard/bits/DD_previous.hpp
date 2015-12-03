//	DDCPP/standard/bits/DD_previous.hpp
#ifndef DD_PREVIOUS_HPP_INCLUDED_
#	define DD_PREVIOUS_HPP_INCLUDED_ 1



#	include "DD_retreat.hpp"



DD_DETAIL_BEGIN_
template <typename BidirectionalIteratorT_>
inline BidirectionalIteratorT_ previous(BidirectionalIteratorT_ iterator__) DD_NOEXCEPT_AS(retreat(iterator__)) {
	retreat(iterator__);
	return iterator__;
}

template <typename BidirectionalIteratorT_, typename DifferenceT_>
inline BidirectionalIteratorT_ previous(
	BidirectionalIteratorT_ iterator__,
	DifferenceT_ const& step__
) DD_NOEXCEPT_AS(retreat(iterator__, step__)) {
	retreat(iterator__, step__);
	return iterator__;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::previous;



DD_END_



#endif
