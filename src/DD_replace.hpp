// standard/bits/DD_replace.hpp
#ifndef _DD_REPLACE_HPP
#	define _DD_REPLACE_HPP 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _ValueT1, typename _ValueT2>
ProcessType replace(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT1 __old,
	_ValueT2 __value
) {
	for (; __begin != __end; ++__begin) {
		if (*__begin == __old) {
			*__begin = __value;
		}
	}
}



DD_END



#endif