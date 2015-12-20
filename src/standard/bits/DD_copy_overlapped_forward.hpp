//	DDCPP/standard/bits/DD_copy_overlapped_forward.hpp
#ifndef DD_COPY_OVERLAPPED_FORWARD_HPP_INCLUDED_
#	define DD_COPY_OVERLAPPED_FORWARD_HPP_INCLUDED_ 1



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
struct CopyOverlappedForward_ {
	template <typename UndirectionalIteratorT__>
	static UndirectionalIteratorT__ copy_overlapped_forward(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		UndirectionalIteratorT__ result_begin___
	) {
		for (; begin___ != end___; ++begin___, ++result_begin___) {
			*result_begin___ = *begin___;
		}
		return result_begin___;
	}


};



template <>
struct CopyOverlappedForward_<true> {
	template <typename PointerT__>
	static PointerT__ copy_overlapped_forward(
		PointerT__ begin___,
		PointerT__ end___,
		PointerT__ result_begin___
	) {
		DD::memory_move(begin___, end___, result_begin___);
		return result_begin___ + (end___ - begin___);
	}


};



template <typename UndirectionalIteratorT_>
UndirectionalIteratorT_ copy_overlapped_forward(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	UndirectionalIteratorT_ result_begin__
) {
	return CopyOverlappedForward_<
		IsPointer<UndirectionalIteratorT_>::value &&
		IsTriviallyCopyAssignable<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT_)>::value
	>::copy_overlapped_forward(begin__, end__, result_begin__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::copy_overlapped_forward;



DD_END_



#endif
