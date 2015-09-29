//	DDCPP/standard/bits/DD_partition_point_by.hpp
#ifndef DD_PARTITION_POINT_BY_HPP_INCLUDED_
#	define DD_PARTITION_POINT_BY_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicatorT_>
UndirectionalIteratorT_ partition_point_by(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UndirectionalIteratorT_ const& predicator__
) DD_NOEXCEPT_AS(++begin__ != end__ && predicator__(*begin__)) {
	while (begin__ != end__ && predicator__(*begin__)) {
		++begin__;
	}
	return begin__;
}



DD_END_



#endif
