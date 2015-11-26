//	DDCPP/standard/bits/DD_median_target.hpp
#ifndef DD_MEDIAN_TARGET_HPP_INCLUDED_
#	define DD_MEDIAN_TARGET_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename IteratorT_>
inline IteratorT_ median_target(
	IteratorT_ first__,
	IteratorT_ second__,
	IteratorT_ third__
) {
	if (*first__ < *second__) {
		if (*second__ < *third__) {
			return second__;
		}
		return *first__ < *third__ ? third__ : first__;
	}
	if (*third__ < *second__) {
		return second__;
	}
	return *third__ < *first__ ? third__ : first__;
}

template <typename IteratorT_, typename BinaryPredicateT_>
inline IteratorT_ median_target(
	IteratorT_ first__,
	IteratorT_ second__,
	IteratorT_ third__,
	BinaryPredicateT_ less__
) {
	if (less__(*first__, *second__)) {
		if (less__(*second__, *third__)) {
			return second__;
		}
		return less__(*first__, *third__) ? third__ : first__;
	}
	if (less__(*third__, *second__)) {
		return second__;
	}
	return less__(*third__, *first__) ? third__ : first__;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::median_target;



DD_END_



#endif
