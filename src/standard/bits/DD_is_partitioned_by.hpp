//	DDCPP/standard/bits/DD_is_partitioned_by.hpp
#ifndef _DD_IS_PARTITIONED_BY_HPP_INCLUDED
#	define _DD_IS_PARTITIONED_BY_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _UnaryPredicatorT>
ValidityType is_partitioned_by(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_UnaryPredicatorT const& __predicator
) DD_NOEXCEPT_AS(++__begin != __end && __predicator(*__begin)) {
	for (; __begin != __end; ++__begin) {
		if (!__predicator(*__begin)) {
			break;
		}
	}
	while (++__begin != __end) {
		if (__predicator(*__begin)) {
			return false;
		}
	}
	return true;
}



DD_END



#endif
