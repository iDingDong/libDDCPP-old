//	DDCPP/standard/bits/DD_fill.hpp
#ifndef _DD_FILL_HPP_INCLUDED
#	define _DD_FILL_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _UndirectionalIteratorT, typename _ValueT>
ProcessType fill(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT const& __value
) DD_NOEXCEPT_AS(*++__begin = __value DD_COMMA __begin != __end) {
	for (; __begin != __end; ++__begin) {
		*__begin = __value;
	}
}



_DD_END



#endif
