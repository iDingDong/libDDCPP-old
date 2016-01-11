//	DDCPP/standard/bits/DD_inplace_merge_length.hpp
#ifndef DD_INPLACE_MERGE_LENGTH_HPP_INCLUDED_
#	define DD_INPLACE_MERGE_LENGTH_HPP_INCLUDED_ 1



#	include "DD_next.hpp"
#	include "DD_Agent.hpp"
#	include "DD_swap_length.hpp"
#	include "DD_sort.hpp"



DD_DETAIL_BEGIN_
inline LengthType DD_UNCONSTRIANED_CONSTEXPR square_root_to_ceil_(LengthType length_) DD_NOEXCEPT {
	LengthType low_ = 0;
	LengthType high_ = length_;
	while (low_ + 1 < high_) {
		LengthType current_ = (low_ + high_) / 2;
		LengthType square_value_ = current_ * current_;
		if (length_ < square_value_) {
			high_ = current_;
		} else if (square_value_ < length_) {
			current_ = low_;
		} else {
			return current_;
		}
	}
	return high_;
}



template <typename UndirectionalIteratorT_, typename LengthT_, typename BinaryPredicateT_>
ProcessType inplace_merge_interval_(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ middle__,
	LengthT_ interval__,
	UndirectionalIteratorT_ helper__,
	BinaryPredicateT_ less__
) {
	::DD::swap_length(begin__, helper__, interval__);
	LengthT_ next_interval__(interval__);
	do {
		if (less__(*middle__, *helper__)) {
			::DD::swap_target(begin__, middle__);
			--next_interval__;
		} else {
			::DD::swap_target(helper__, middle__);
			--interval__;
		}
		if (interval__) {
			return;
		}
		++begin__;
	} while (next_interval__);
	::DD::swap_length(begin__, helper__, interval__);
}



template <typename UndirectionalIteratorT_, typename LengthT_, typename BinaryPredicateT_>
ProcessType inplace_merge_length(
	UndirectionalIteratorT_ begin__,
	LengthT_ left_length__,
	LengthT_ right_length__,
	BinaryPredicateT_ less__
) {
	if (left_length__ && right_length__) {
		LengthT_ length__ = left_length__ + right_length__;
		LengthT_ interval__ = ::DD::detail_::square_root_to_ceil_(length__);
		LengthT_ full_interval_quantity__ = length__ / interval__;
		UndirectionalIteratorT_ helper__ = ::DD::next(begin__, full_interval_quantity__ * interval__);
		LengthT_ middle_interval_index__ = (left_length__ - 1) / interval__ + 1;
		::DD::swap_length(
			::DD::next(begin__, middle_interval_index__ * interval__),
			helper__,
			interval__
		);
		for (
			UndirectionalIteratorT_ current_begin__(begin__);
			current_begin__ != helper__;
			::DD::advance(current_begin__, interval__)
		) {
			UndirectionalIteratorT_ current_min__(current_begin__);
			for (
				UndirectionalIteratorT_ current__(::DD::next(current_begin__, interval__));
				current__ != helper__;
				::DD::advance(current__, interval__)
			) {
				if (less__(*current__, *current_min__)) {
					current_min__ = current__;
				}
			}
			if (current_begin__ != current_min__) {
				::DD::swap_length(current_begin__, current_min__, interval__);
			}
		}
		for (
			UndirectionalIteratorT_ current_front__(begin__), current__(::DD::next(begin__, interval__));
			current__ != helper__;
			current_front__ = current__, ::DD::advance(current__, interval__)
		) {
			::DD::detail_::inplace_merge_interval_(current_front__, current__, interval__, helper__, less__);
		}
		::DD::sort(helper__, ::DD::next(helper__, length__ - full_interval_quantity__ * interval__), less__);
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::inplace_merge_length;



DD_END_



#endif

