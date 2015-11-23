//	DDCPP/standard/bits/DD_select_sort.hpp
#ifndef DD_SELECT_SORT_HPP_INCLUDED_
#	define DD_SELECT_SORT_HPP_INCLUDED_



#	include "DD_swap_target.hpp"



DD_DETAIL_BEGIN_
template <typename UndirectionalIteratorT_>
ProcessType select_sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_IF(
	noexcept(++begin__ != end__) &&
	noexcept(begin__ = begin__) &&
	noexcept(*begin__ < *end__) &&
	noexcept(swap_target(begin__, begin__))
) {
	for (; begin__ != end__; ++begin__) {
		UndirectionalIteratorT_ current__(begin__);
		UndirectionalIteratorT_ tagged__(current__);
		while (++current__ != end__) {
			if (*current__ < *tagged__) {
				tagged__ = current__;
			}
		}
		using DD::swap_target;
		swap_target(begin__, tagged__);
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::select_sort;



DD_END_



#endif
