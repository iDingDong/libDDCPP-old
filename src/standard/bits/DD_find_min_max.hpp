//	DDCPP/standard/bits/DD_min_max_element.hpp
#ifndef DD_FIND_MIN_MAX_HPP_INCLUDED_
#	define DD_FIND_MIN_MAX_HPP_INCLUDED_ 1



#	include "DD_Pair.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT_>
Pair<UndirectionalIteratorT_> find_min_max(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__
) DD_NOEXCEPT_AS(++begin__ != end__ && *begin__ < *begin__) {
	UndirectionalIteratorT_ min__ = begin__;
	UndirectionalIteratorT_ max__ = begin__;
	for (; begin__ != end__; ++begin__) {
		if (*begin__ < *min__) {
			min__ = begin__;
		} else if (*max__ < *begin__) {
			max__ = begin__;
		}
	}
	return Pair<UndirectionalIteratorT_>{min__, max__};
}

template <typename UndirectionalIteratorT_, typename BinaryPredicatorT_>
Pair<UndirectionalIteratorT_> find_min_max(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ const& end__,
	BinaryPredicatorT_ const& less__
) DD_NOEXCEPT_AS(++begin__ != end__ && less__(*begin__, *begin__)) {
	UndirectionalIteratorT_ min__ = begin__;
	UndirectionalIteratorT_ max__ = begin__;
	for (; begin__ != end__; ++begin__) {
		if (less__(*begin__, *min__)) {
			min__ = begin__;
		} else if (*max__ < *begin__) {
			max__ = begin__;
		}
	}
	return Pair<UndirectionalIteratorT_>{min__, max__};
}



DD_END_



#endif
