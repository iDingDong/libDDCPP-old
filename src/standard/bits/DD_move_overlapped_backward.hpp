//	DDCPP/standard/bits/DD_move_overlapped_backward.hpp
#ifndef DD_MOVE_OVERLAPPED_BACKWARD_HPP_
#	define DD_MOVE_OVERLAPPED_BACKWARD_HPP_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::move_overlapped_backward'.



#	endif
#	include "DD_move.hpp"
#	include "DD_copy_overlapped_backward.hpp"



DD_DETAIL_BEGIN_
template <ValidityType can_trivially_operate_c_>
struct MoveOverlappedBackward_ {
	template <typename BidirectionalIteratorT__>
	static BidirectionalIteratorT__ move_overlapped_backward(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___,
		BidirectionalIteratorT__ result_end___
	) {
		while (begin___ != end___) {
			*--result_end___ = ::DD::move(*--end___);
		}
		return result_end___;
	}


};



template <>
struct MoveOverlappedBackward_<true> {
	template <typename BidirectionalIteratorT__>
	static BidirectionalIteratorT__ move_overlapped_backward(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___,
		BidirectionalIteratorT__ result_end___
	) {
		return ::DD::copy_overlapped_backward(begin___, end___, result_end___);
	}


};



template <typename BidirectionalIteratorT_>
inline BidirectionalIteratorT_ move_overlapped_backward(
	BidirectionalIteratorT_ begin__,
	BidirectionalIteratorT_ end__,
	BidirectionalIteratorT_ result_end__
) {
	return MoveOverlappedBackward_<
		IsTriviallyCopyAssignable<DD_MODIFY_TRAIT(IteratorValue, BidirectionalIteratorT_)>::value
	>::move_overlapped_backward(begin__, end__, result_end__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::move_overlapped_backward;



DD_END_



#endif
