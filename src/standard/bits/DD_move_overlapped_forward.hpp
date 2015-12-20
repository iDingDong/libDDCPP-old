//	DDCPP/standard/bits/DD_move_overlapped_forward.hpp
#ifndef DD_MOVE_OVERLAPPED_FORWARD_HPP_
#	define DD_MOVE_OVERLAPPED_FORWARD_HPP_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::move_overlapped_forward'.



#	endif
#	include "DD_move.hpp"
#	include "DD_copy_overlapped_forward.hpp"



DD_DETAIL_BEGIN_
template <ValidityType can_trivially_operate_c_>
struct MoveOverlappedForward_ {
	template <typename UndirectionalIteratorT__>
	static UndirectionalIteratorT__ move_overlapped_forward(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		UndirectionalIteratorT__ result_begin___
	) {
		for (; begin___ != end___; ++begin___, ++result_begin___) {
			*result_begin___ = ::DD::move(*begin___);
		}
		return result_begin___;
	}


};



template <>
struct MoveOverlappedForward_<true> {
	template <typename UndirectionalIteratorT__>
	static UndirectionalIteratorT__ move_overlapped_forward(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		UndirectionalIteratorT__ result_begin___
	) {
		return ::DD::copy_overlapped_forward(begin___, end___, result_begin___);
	}


};



template <typename UndirectionalIteratorT_>
inline UndirectionalIteratorT_ move_overlapped_forward(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	UndirectionalIteratorT_ result_begin__
) {
	return MoveOverlappedForward_<
		IsTriviallyCopyAssignable<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT_)>::value
	>::move_overlapped_forward(begin__, end__, result_begin__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::move_overlapped_forward;



DD_END_



#endif

