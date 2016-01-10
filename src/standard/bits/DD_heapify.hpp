//	DDCPP/standard/bits/DD_heapify.hpp
#ifndef DD_HEAPIFY_HPP_INCLUDED_
#	define DD_HEAPIFY_HPP_INCLUDED_ 1



#	include "DD_debugger_definitions.hpp"
#	include "DD_middle.hpp"
#	include "DD_LessThan.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_>
inline FreeAccessIteratorT_ unguarded_heap_left_child_(
	FreeAccessIteratorT_ root__,
	FreeAccessIteratorT_ current__
) DD_NOEXCEPT_AS(static_cast<FreeAccessIteratorT_>(current__ + (current__ - root__) + 1)) {
	DD_ASSERT(root__ <= current__, "Invalid access: 'DD::heap_left_child/heap_right_child'");
	return current__ + (current__ - root__) + 1;
}


template <typename FreeAccessIteratorT_>
inline FreeAccessIteratorT_ unguarded_heap_right_child_(
	FreeAccessIteratorT_ root__,
	FreeAccessIteratorT_ current__
) DD_NOEXCEPT_AS(static_cast<FreeAccessIteratorT_>(::DD::detail_::unguarded_heap_left_child_(root__, current__) + 1)) {
	return ::DD::detail_::unguarded_heap_left_child_(root__, current__) + 1;
}


template <typename FreeAccessIteratorT_, typename BinaryPredicateT_>
ProcessType heapify(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	FreeAccessIteratorT_ current__,
	BinaryPredicateT_ less__
) {
	DD_ASSERT(begin__ <= current__, "Invalid access: 'DD::heapify'");
	for (; ; ) {
		FreeAccessIteratorT_ left__(unguarded_heap_left_child_(begin__, current__));
		if (left__ < end__) {
			FreeAccessIteratorT_ largest__(less__(*current__, *left__) ? left__ : current__);
			FreeAccessIteratorT_ right__(left__ + 1);
			if (right__ < end__ && less__(*largest__, *right__)) {
				largest__ = right__;
			}
			using ::DD::swap_target;
			if (current__ != largest__) {
				swap_target(current__, largest__);
				current__ = largest__;
				continue;
			}
		}
		return;
	}
}

template <typename FreeAccessIteratorT_>
inline ProcessType heapify(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	FreeAccessIteratorT_ current__
) DD_NOEXCEPT_AS(::DD::detail_::heapify(begin__ DD_COMMA end__ DD_COMMA current__ DD_COMMA less_than)) {
	::DD::detail_::heapify(begin__, end__, current__, less_than);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::heapify;



DD_END_



#endif
