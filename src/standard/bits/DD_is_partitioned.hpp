//	DDCPP/standard/bits/DD_is_partitioned.hpp
#ifndef _DD_IS_PARTITIONED_HPP_INCLUDED
#	define _DD_IS_PARTITIONED_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _ValueT>
ValidityType is_partitioned(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_ValueT const& __value
) DD_NOEXCEPT_AS(++__begin != __end && *__begin < __value) {
	for (; __begin != __end; ++__begin) {
		if (!(*__begin < __value)) {
			break;
		}
	}
	while (++__begin != __end) {
		if (*__begin < __value) {
			return false;
		}
	}
	return true;
}



DD_END



#endif
