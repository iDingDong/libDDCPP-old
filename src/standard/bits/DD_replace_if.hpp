//	DDCPP/standard/bits/DD_replace_if.hpp
#ifndef _DD_REPLACE_IF_HPP_INCLUDED
#	define _DD_REPLACE_IF_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _UnaryPredicatorT, typename _ValueT>
ProcessType replace_if(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_UnaryPredicatorT __predicator,
	_ValueT __value
) DD_NOEXCEPT_AS(*++__begin = __value DD_COMMA __begin != __end && __predicator(*__begin)) {
	for (; __begin != __end; ++__begin) {
		if (__predicator(*__begin)) {
			*__begin = __value;
		}
	}
}



DD_END



#endif
