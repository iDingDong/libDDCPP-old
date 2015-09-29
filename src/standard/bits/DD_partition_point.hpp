//	DDCPP/standard/bits/DD_partition_point.hpp
#ifndef DD_PARTITION_POINT_HPP_INCLUDED_
#	define DD_PARTITION_POINT_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_>
UndirectionalIteratorT_ partition_point(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ < value__) {
	while (begin__ != end__ && *begin__ < value__) {
		++begin__;
	}
	return begin__;
}



DD_END_



#endif
