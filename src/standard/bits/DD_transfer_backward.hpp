//	DDCPP/standard/bits/DD_transfer_backward.hpp
#ifndef DD_TRANSFER_BACKWARD_HPP_INCLUDED_
#	define DD_TRANSFER_BACKWARD_HPP_INCLUDED_ 1



#	include "DD_IteratorReverse.hpp"
#	include "DD_transfer_forward.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
inline ProcessType transfer_backward(UndirectionalIteratorT_ const& from_, UndirectionalIteratorT_ const& to_) {
	DD_ALIAS(ReverseIterator, DD_MODIFY_TRAIT(IteratorReverse, UndirectionalIteratorT_));
	::DD::transfer_forward(ReverseIterator(from_), ReverseIterator(to_));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::transfer_backward;



DD_END_



#endif

