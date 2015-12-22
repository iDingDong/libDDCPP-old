//	DDCPP/standard/bits/DD_transconstruct.hpp
#ifndef DD_TRANS_CONSTRUCT_HPP_INCLUDED_
#	define DD_TRANS_CONSTRUCT_HPP_INCLUDED_ 1



#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_transconstruct_length.hpp"



DD_DETAIL_BEGIN_

template <ValidityType is_free_access_iterator_c_>
struct Transconstruct_ {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static UndirectionalIteratorT2__ transconstruct(
		UndirectionalIteratorT1__ begin___,
		UndirectionalIteratorT1__ end___,
		UndirectionalIteratorT2__ result_begin___
	) DD_NOEXCEPT_AS(::DD::construct(result_begin___ DD_COMMA ::DD::move(*begin___))) {
		UndirectionalIteratorT2__ current___(result_begin___);
		try {
			for (; begin___ < end___; ++begin___, ++current___) {
#	if __cplusplus >= 201103L
				::DD::construct(current___, ::DD::move(*begin___));
#	else
				::DD::construct(current___, *begin___);
#	endif
			}
		} catch (...) {
			::DD::destruct(result_begin___, current___);
			throw;
		}
		return current___;
	}


};



template <>
struct Transconstruct_<true> {
	template <typename FreeAccessIteratorT__, typename UndirectionalIteratorT__>
	static UndirectionalIteratorT__ transconstruct(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		UndirectionalIteratorT__ result_begin___
	) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT__>(
		::DD::transconstruct_length(begin___ DD_COMMA result_begin___ DD_COMMA end___ - begin___).second
	)) {
		return ::DD::transconstruct_length(begin___, result_begin___, end___ - begin___).second;
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
UndirectionalIteratorT2_ transconstruct(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT1_ end__,
	UndirectionalIteratorT2_ destination__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT2_>(Transconstruct_<
	IsFreeAccessIterator<UndirectionalIteratorT1_>::value
>::transconstruct(begin__ DD_COMMA end__ DD_COMMA destination__))) {
	return Transconstruct_<
		IsFreeAccessIterator<UndirectionalIteratorT1_>::value
	>::transconstruct(begin__, end__, destination__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::transconstruct;



DD_END_



#endif
