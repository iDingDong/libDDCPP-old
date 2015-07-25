//	DDCPP/standard/bits/DD_find_if_not.hpp
#ifndef _DD_FIND_IF_NOT_HPP_INCLUDED
#	define _DD_FIND_IF_NOT_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _UnaryPredicatorT>
_UndirectionalIteratorT find_if_not(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_UnaryPredicatorT const& __predication
) DD_NOEXCEPT_AS(__begin != __end && predication(*++__begin)) {
	while (__begin != __end && predication(*__begin)) {
		++__begin;
	}
	return __begin;
}



DD_END



#endif 
