//	DDCPP/standard/bits/DD_copy_overlapped_backward.hpp
#ifndef DD_COPY_OVERLAPPED_BACKWARD_HPP_INCLUDED_
#	define DD_COPY_OVERLAPPED_BACKWARD_HPP_INCLUDED_ 1



#	include "DD_IsPointer.hpp"
#	include "DD_IsTriviallyCopyAssignable.hpp"
#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_Iterator.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_get_pointer.hpp"
#	include "DD_memory_move.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <ValidityType can_trivially_operate_c_>
struct CopyOverlappedBackward_ {
	template <typename BidirectionalIteratorT__>
	static BidirectionalIteratorT__ copy_overlapped_backward(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___,
		BidirectionalIteratorT__ result_end___
	) {
		while (begin___ != end___) {
			*--result_end___ = *--end___;
		}
		return result_end___;
	}


};



template <>
struct CopyOverlappedBackward_<true> {
	template <typename PointerT__>
	static PointerT__ copy_overlapped_backward(
		PointerT__ begin___,
		PointerT__ end___,
		PointerT__ result_end___
	) {
		DD::memory_move(begin___, end___, result_end___ -= (end___ - begin___));
		return result_end___;
	}


};



template <typename BidirectionalIteratorT_>
BidirectionalIteratorT_ copy_overlapped_backward(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__,
	BidirectionalIteratorT_ result_end__
) {
	return CopyOverlappedBackward_<
		IsPointer<BidirectionalIteratorT_>::value &&
		IsTriviallyCopyAssignable<DD_MODIFY_TRAIT(IteratorValue, BidirectionalIteratorT_)>::value
	>::copy_overlapped_backward(begin__, end__, result_end__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::copy_overlapped_backward;



DD_END_



#endif
