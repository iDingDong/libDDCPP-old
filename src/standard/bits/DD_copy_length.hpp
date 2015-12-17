//	DDCPP/standard/bits/DD_copy_length.hpp
#ifndef DD_COPY_LENGTH_HPP_INCLUDED_
#	define DD_COPY_LENGTH_HPP_INCLUDED_ 1



#	include "DD_copy.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_c_>
struct CopyLength_ {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__, typename DifferenceT__>
	static Pair<UndirectionalIteratorT1__, UndirectionalIteratorT2__> copy_length(
		UndirectionalIteratorT1__ begin_1___,
		UndirectionalIteratorT2__ begin_2___,
		DifferenceT__ length___
	) {
		for (; length___ > DifferenceT__(); --length___) {
			*begin_2___ = *begin_1___;
			++begin_1___;
			++begin_2___;
		}
		return Pair<UndirectionalIteratorT1__, UndirectionalIteratorT2__>(begin_1___, begin_2___);
	}


};



template <>
struct CopyLength_<true> {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__, typename DifferenceT__>
	static Pair<UndirectionalIteratorT1__, UndirectionalIteratorT2__> copy_length(
		UndirectionalIteratorT1__ begin_1___,
		UndirectionalIteratorT2__ begin_2___,
		DifferenceT__ length___
	) DD_NOEXCEPT_AS(Pair<UndirectionalIteratorT1__ DD_COMMA UndirectionalIteratorT2__>(
		begin_1___ + length___ DD_COMMA
		::DD::copy(begin_1___ DD_COMMA begin_1___ + length___ DD_COMMA begin_2___)
	)) {
		return Pair<UndirectionalIteratorT1__, UndirectionalIteratorT2__>(
			begin_1___ + length___,
			::DD::copy(begin_1___, begin_1___ + length___, begin_2___)
		);
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename DifferenceT_>
inline Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> copy_length(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT2_ begin_2__,
	DifferenceT_ length__
) DD_NOEXCEPT_AS(static_cast<Pair<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_>>(
	CopyLength_<IsFreeAccessIterator<UndirectionalIteratorT1_>::value>::copy_length(begin_1__ DD_COMMA begin_2__ DD_COMMA length__)
)) {
	return CopyLength_<IsFreeAccessIterator<UndirectionalIteratorT1_>::value>::copy_length(begin_1__, begin_2__, length__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::copy_length;



DD_END_



#endif
