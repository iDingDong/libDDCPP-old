//	DDCPP/standard/bits/DD_pop_heap.hpp
#ifndef DD_POP_HEAP_HPP_INCLUDED_
#	define DD_POP_HEAP_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	endif
#	include "DD_heapify.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_, typename BinaryPredicateT_>
inline ProcessType pop_heap(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	BinaryPredicateT_ less__
) {
#	if __cplusplus >= 201103L
	*begin__ = ::DD::move(*(end__ - 1));
#	else
	*begin__ = *(end__ - 1);
#	endif
	::DD::heapify(begin__, begin__, end__ - 1, less__);
}

template <typename FreeAccessIteratorT_>
inline ProcessType pop_heap(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__
) DD_NOEXCEPT_AS(::DD::detail_::pop_heap(begin__ DD_COMMA end__ DD_COMMA less_than)) {
	return ::DD::detail_::pop_heap(begin__, end__, less_than);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::pop_heap;



DD_END_



#endif
