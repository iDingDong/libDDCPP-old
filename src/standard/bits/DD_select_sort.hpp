//	standard/bits/DD_select_sort.hpp
#ifndef _DD_SELECT_SORT_HPP_INCLUDED
#	define _DD_SELECT_SORT_HPP_INCLUDED



#	include "DD_swap_target.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT>
ProcessType select_sort(_UndirectionalIteratorT __begin, _UndirectionalIteratorT const& __end) DD_NOEXCEPT_IF(
	noexcept(__begin != __end) &&
	noexcept(++__begin) &&
	noexcept(_UndirectionalIteratorT()) &&
	noexcept(__begin = __begin) &&
	noexcept(*__begin < *__begin) &&
	noexcept(swap_target(__begin, __begin))
) {
	for (_UndirectionalIteratorT __current, __tagged; __begin != __end; ++__begin) {
		__current = __begin;
		__tagged = __current;
		while (++__current != __end) {
			if (*__current < *__tagged) {
				__tagged = __current;
			}
		}
		using DD::swap_target;
		swap_target(__begin, __tagged);
	}
}



DD_END



#endif
