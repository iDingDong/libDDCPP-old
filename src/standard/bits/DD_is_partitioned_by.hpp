//	DDCPP/standard/bits/DD_is_partitioned_by.hpp
#ifndef DD_IS_PARTITIONED_BY_HPP_INCLUDED_
#	define DD_IS_PARTITIONED_BY_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename UnaryPredicatorT_>
ValidityType is_partitioned_by(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	UnaryPredicatorT_ const& predicator__
) DD_NOEXCEPT_AS(++begin__ != end__ && predicator__(*begin__)) {
	for (; begin__ != end__; ++begin__) {
		if (!predicator__(*begin__)) {
			break;
		}
	}
	while (++begin__ != end__) {
		if (predicator__(*begin__)) {
			return false;
		}
	}
	return true;
}



DD_END_



#endif
