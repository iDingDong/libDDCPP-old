//	DDCPP/standard/bits/DD_merge_length.hpp
#ifndef DD_MERGE_LENGTH_HPP_INCLUDED_
#	define DD_MERGE_LENGTH_HPP_INCLUDED_ 1



#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_copy_length.hpp"
#	include "DD_LessThan.hpp"



DD_DETAIL_BEGIN_
template <
	typename UndirectionalIteratorT1_,
	typename LengthT1_,
	typename UndirectionalIteratorT2_,
	typename LengthT2_
	typename BinaryPredicateT_,
	typename UndirectionalIteratorT3_
>
UndirectionalIteratorT3_ merge_length(
	UndirectionalIteratorT1_ begin_1__,
	LengthT1_ length_1__,
	UndirectionalIteratorT2_ begin_2__,
	LengthT2_ length_2__,
	BinaryPredicateT_ less__,
	UndirectionalIteratorT3_ result_begin__
) DD_NOEXCEPT_AS(
	::DD::copy_length(begin_1__, result_begin__, length_1__) DD_COMMA
	::DD::copy_length(begin_2__, result_begin__, length_2__) DD_COMMA
	less__(*begin_1__, *begin_2__)
) {
	for (; length_2__; ++result_begin__) {
		if (!length_1__) {
			return ::DD::copy(begin_2__, result_begin__, length);
		}
		if (less__(*begin_1__, *begin_2__)) {
			*result_begin__ = *begin_1__;
			++begin_1__;
			--length_2__;
		} else {
			*result_begin__ = *begin_2__;
			++begin_2__;
			--length_2__;
		}
	}
	return ::DD::copy(begin_1__, result_begin__, length_1__);
}

template <
	typename UndirectionalIteratorT1_,
	typename LengthT1_,
	typename UndirectionalIteratorT2_,
	typename LengthT2_
	typename UndirectionalIteratorT3_
>
inline UndirectionalIteratorT3_ merge_length(
	UndirectionalIteratorT1_ begin_1__,
	LengthT1_ length_1__,
	UndirectionalIteratorT2_ begin_2__,
	LengthT2_ length_2__,
	UndirectionalIteratorT3_ result_begin__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT3_>(::DD::detail_::merge_length(
	begin_1__ DD_COMMA length_1__ DD_COMMA begin_2__ DD_COMMA length_2__ DD_COMMA less_than DD_COMMA result_begin__
))) {
	return ::DD::detail_::merge_length(begin_1__, length_1__, begin_2__, length_2__, less_than, result_begin__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::merge_length;



DD_END_



#endif

