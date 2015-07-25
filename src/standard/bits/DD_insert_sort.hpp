//	standard/bits/DD_insert_sort.hpp
#ifndef _DD_INSERT_SORT_HPP_INCLUDED
#	define _DD_INSERT_SORT_HPP_INCLUDED


#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	else
#		include "DD_IteratorValue.hpp"
#	endif
#	include "DD_IsBidirectionalIterator.hpp"
#	include "DD_swap_target.hpp"



DD_DETAIL_BEGIN
template <typename _UndirectionalIteratorT, ValidityType _is_bidirectional_iterator_c>
struct _InsertSort {
	static ProcessType _insert_sort(_UndirectionalIteratorT const& __begin, _UndirectionalIteratorT const& __end) DD_NOEXCEPT_IF(false) {
		if (__begin != __end) {
			for (_UndirectionalIteratorT __current(__begin), __front; ++__current != __end; ) {
				__front = __begin;
				do {
					if (*__current < *__front) {
						do {
							using DD::swap_target;
							swap_target(__front, __current);
						} while (++__front != __current);
						break;
					}
				} while (++__front != __current);
			}
		}
	}
	
	
};



template <typename _BidirectionalIteratorT>
struct _InsertSort<_BidirectionalIteratorT, true> {
	static ProcessType _insert_sort(_BidirectionalIteratorT const& __begin, _BidirectionalIteratorT const& __end) DD_NOEXCEPT_IF(false) {
		if (__begin != __end) {
			for (_BidirectionalIteratorT __current(__begin), __front; ++__current != __end; ) {
				__front = __current;
#	if __cplusplus >= 201103L
				auto __temp = move(*__front);
				for (auto __previous(__front); __temp < *--__previous; ) {
					*__front = move(*__previous);
					__front = __previous;
					if (__front == __begin) {
						break;
					}
				}
				*__front = move(__temp);
#	else
				typename IteratorValue<_BidirectionalIteratorT>::Type __temp = *__current;
				for (_BidirectionalIteratorT __previous(__front); temp < *--__previous; ) {
					*__front = *__previous;
					__front = __previous;
					if (__previous == __begin) {
						break;
					}
				}
				*__front = __temp;
#	endif
			}
		}
	}
	
	
};



DD_DETAIL_END



DD_BEGIN
template <typename _UndirectionalIteratorT>
inline ProcessType insert_sort(_UndirectionalIteratorT const& __begin, _UndirectionalIteratorT const& __end) DD_NOEXCEPT_AS(
	detail::_InsertSort<_UndirectionalIteratorT DD_COMMA IsBidirectionalIterator<_UndirectionalIteratorT>::value>::_insert_sort(__begin, __end)
) {
	detail::_InsertSort<_UndirectionalIteratorT, IsBidirectionalIterator<_UndirectionalIteratorT>::value>::_insert_sort(__begin, __end);
}



DD_END



#endif
