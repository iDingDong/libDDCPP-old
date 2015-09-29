//	DDCPP/standard/bits/DD_is_partitioned.hpp
#ifndef DD_IS_PARTITIONED_HPP_INCLUDED_
#	define DD_IS_PARTITIONED_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_, typename ValueT_>
ValidityType is_partitioned(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	ValueT_ const& value__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ < value__) {
	for (; begin__ != end__; ++begin__) {
		if (!(*begin__ < value__)) {
			break;
		}
	}
	while (++begin__ != end__) {
		if (*begin__ < value__) {
			return false;
		}
	}
	return true;
}



DD_END_



#endif
