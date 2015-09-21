//	DDCPP/standard/bits/DD_find_if.hpp
#ifndef _DD_FIND_IF_HPP_INCLUDED
#	define _DD_FIND_IF_HPP_INCLUDED 1



#	include "DD_Iterator.hpp"



_DD_BEGIN
template <typename _UndirectionalIteratorT, typename _UnaryPredicatorT>
_UndirectionalIteratorT find_if(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_UnaryPredicatorT const& __predicator
) DD_NOEXCEPT_AS(__begin != __end && __predicator(*++__begin)) {
	while (__begin != __end && !__predicator(*__begin)) {
		++__begin;
	}
	return __begin;
}

template <typename _UndirectionalRangeT, typename _UnaryPredicatorT>
inline DD_MODIFY_TRAIT(Iterator, _UndirectionalRangeT) find_if(
	_UndirectionalRangeT& __range,
	_UnaryPredicatorT const& __predicator
) DD_NOEXCEPT_AS(find_if(DD_SPLIT_RANGE(__range) DD_COMMA __predicator)) {
	return find_if(DD_SPLIT_RANGE(__range), __predicator);
}



_DD_END



#endif
