//	DDCPP/standard/bits/DD_merge.hpp
#ifndef DD_MERGE_HPP_INCLUDED_
#	define DD_MERGE_HPP_INCLUDED_ 1



#	include "DD_copy.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename UndirectionalIteratorT3_>
UndirectionalIteratorT3_ merge(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ const& end_2__,
	UndirectionalIteratorT3_ result_begin__
) DD_NOEXCEPT_AS(copy(begin_1__, end_1__, result_begin__) DD_COMMA copy(begin_2__, end_2__, result_begin__) DD_COMMA *begin_1__ < *begin_2__) {
	for (; begin_2__ != end_2__; ++result_begin__) {
		if (begin_1__ == end_1__) {
			return copy(begin_2__, end_2__, result_begin__);
		}
		if (*begin_1__ < *begin_2__) {
			*result_begin__ = *begin_1__;
			++begin_1__;
		} else {
			*result_begin__ = *begin_2__;
			++begin_1__;
		}
	}
	return copy(begin_1__, end_1__, result_begin__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename UndirectionalIteratorT3_, typename BinaryPredicatorT_>
UndirectionalIteratorT3_ merge(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ const& end_2__,
	BinaryPredicatorT_ const& less__,
	UndirectionalIteratorT3_ result_begin__
) DD_NOEXCEPT_AS(copy(begin_1__, end_1__, result_begin__) DD_COMMA copy(begin_2__, end_2__, result_begin__) DD_COMMA less__(*begin_1__, *begin_2__)) {
	for (; begin_2__ != end_2__; ++result_begin__) {
		if (begin_1__ == end_1__) {
			return copy(begin_2__, end_2__, result_begin__);
		}
		if (less__(*begin_1__, *begin_2__)) {
			*result_begin__ = *begin_1__;
			++begin_1__;
		} else {
			*result_begin__ = *begin_2__;
			++begin_1__;
		}
	}
	return copy(begin_1__, end_1__, result_begin__);
}



DD_END_



#endif
