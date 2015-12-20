//	DDCPP/standard/bits/DD_copy_overlapped_backward.hpp
#ifndef DD_OVERLAPPED_BACKWARD_HPP_INCLUDED_
#	define DD_OVERLAPPED_BACKWARD_HPP_INCLUDED_ 1



#	include "DD_copy.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
inline UndirectionalIteratorT_ copy_overlapped_backward(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	UndirectionalIteratorT_ result_begin__
) {
	return ::DD::copy(begin__, end__, result_begin__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::copy_overlapped_backward;



DD_END_



#endif
