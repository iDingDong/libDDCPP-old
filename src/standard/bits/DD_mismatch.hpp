//	DDCPP/standard/bits/DD_mismatch.hpp
#ifndef DD_MISMATCH_HPP_INCLUDED_
#	define DD_MISMATCH_HPP_INCLUDED_ 1



#	include "DD_Pair.hpp"



DD_BEGIN_
template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> mismatch(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__
) DD_NOEXCEPT_AS(begin_1__ != end_1__ && *++begin_1__ == *++begin_2__) {
	while (begin_1__ != end_1__ && *begin_1__ == *begin_2__) {
		++begin_1__;
		++begin_2__;
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>{begin_1__, begin_2__};
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> mismatch(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ const& end_2__
) DD_NOEXCEPT_AS(begin_1__ != end_1__ && begin_2__ != end_2__ && *++begin_1__ == *++begin_2__) {
	while (begin_1__ != end_1__ && begin_2__ != end_2__ && *begin_1__ == *begin_2__) {
		++begin_1__;
		++begin_2__;
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>{begin_1__, begin_2__};
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicatorT_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> mismatch(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	BinaryPredicatorT_ const& equal__
) DD_NOEXCEPT_AS(begin_1__ != end_1__ && equal__(*++begin_1__, *++begin_2__)) {
	while (begin_1__ != end_1__ && equal__(*begin_1__, *begin_2__)) {
		++begin_1__;
		++begin_2__;
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>{begin_1__, begin_2__};
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicatorT_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> mismatch(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ const& end_2__,
	BinaryPredicatorT_ const& equal__
) DD_NOEXCEPT_AS(begin_1__ != end_1__ && begin_2__ != end_2__ && equal__(*++begin_1__, *++begin_2__)) {
	while (begin_1__ != end_1__ && begin_2__ != end_2__ && equal__(*begin_1__, *begin_2__)) {
		++begin_1__;
		++begin_2__;
	}
	return Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_>{begin_1__, begin_2__};
}



DD_END_



#endif
