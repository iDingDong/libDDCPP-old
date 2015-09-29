//	DDCPP/standard/bits/DD_find_min.hpp
#ifndef DD_FIND_MIN_HPP_INCLUDED_
#	define DD_FIND_MIN_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_>
UndirectionalIteratorT_ find_min(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ < *begin__) {
	UndirectionalIteratorT_ min__ = begin__;
	for (; begin__ != end__; ++begin__) {
		if (*begin__ < *min__) {
			min__ = begin__;
		}
	}
	return min__;
}

template <typename UndirectionalIteratorT_, typename BinaryPredicatorT_>
UndirectionalIteratorT_ find_min(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	BinaryPredicatorT_ const& less__
) DD_NOEXCEPT_AS(++begin__ != end__ && less__(*begin__, *begin__)) {
	UndirectionalIteratorT_ min__ = begin__;
	for (; begin__ != end__; ++begin__) {
		if (less__(*begin__, *min__)) {
			min__ = begin__;
		}
	}
	return min__;
}



DD_END_



#endif
