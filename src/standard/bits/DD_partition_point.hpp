//	DDCPP/standard/bits/DD_partition_point.hpp
#ifndef _DD_PARTITION_POINT_HPP_INCLUDED
#	define _DD_PARTITION_POINT_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _ValueT>
_UndirectionalIteratorT partition_point(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT const& __value
) DD_NOEXCEPT_AS(++__begin != __end && *__begin < __value) {
	while (__begin != __end && *__begin < __value) {
		++__begin;
	}
	return __begin;
}



DD_END



#endif
