//	DDCPP/standard/bits/DD_partition_point_by.hpp
#ifndef _DD_PARTITION_POINT_BY_HPP_INCLUDED
#	define _DD_PARTITION_POINT_BY_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _UndirectionalIteratorT, typename _UnaryPredicatorT>
_UndirectionalIteratorT partition_point_by(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_UndirectionalIteratorT const& __predicator
) DD_NOEXCEPT_AS(++__begin != __end && __predicator(*__begin)) {
	while (__begin != __end && __predicator(*__begin)) {
		++__begin;
	}
	return __begin;
}



_DD_END



#endif
