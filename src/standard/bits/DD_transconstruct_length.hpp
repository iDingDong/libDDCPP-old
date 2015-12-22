//	DDCPP/standard/bits/DD_transconstruct_length.hpp
#ifndef DD_TRANSCONSTRUCT_LENGTH_HPP_INCLUDED_
#	define DD_TRANSCONSTRUCT_LENGTH_HPP_INCLUDED_ 1



#	include "DD_RemoveCV.hpp"
#	include "DD_IsTriviallyCopyable.hpp"
#	include "DD_IsTriviallyDestructible.hpp"
#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	endif
#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"
#	include "DD_copy_length.hpp"



DD_DETAIL_BEGIN_
template <ValidityType can_trivially_operate_c_>
struct TransconstructLength_ {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static Pair<UndirectionalIteratorT1__, UndirectionalIteratorT2__> transconstruct_length(
		UndirectionalIteratorT1__ begin___,
		UndirectionalIteratorT2__ result_begin___,
		LengthType length_
	) DD_NOEXCEPT_AS(*result_begin___ = ::DD::move(*begin___)) {
		UndirectionalIteratorT2__ current___(result_begin___);
		try {
			for (; length_; --length_, ++begin___, ++current___) {
#	if __cplusplus >= 201103L
				::DD::construct(current___, ::DD::move(*begin___));
#	else
				::DD::construct(current___, *begin___);
#	endif
			}
		} catch (...) {
			::DD::destruct(result_begin___, current___);
		}
		return Pair<UndirectionalIteratorT1__, UndirectionalIteratorT2__>(begin___, current___);
	}


};



template <>
struct TransconstructLength_<true> {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static Pair<UndirectionalIteratorT1__, UndirectionalIteratorT2__> transconstruct_length(
		UndirectionalIteratorT1__ begin___,
		UndirectionalIteratorT2__ result_begin___,
		LengthType length_
	) DD_NOEXCEPT_AS(static_cast<Pair<UndirectionalIteratorT1__ DD_COMMA UndirectionalIteratorT2__>>(
		::DD::copy_length(begin___ DD_COMMA result_begin___ DD_COMMA length_)
	)) {
		return ::DD::copy_length(begin___, result_begin___, length_);
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> transconstruct_length(
	UndirectionalIteratorT1_ begin__,
	UndirectionalIteratorT2_ result_begin__,
	LengthType length_
) DD_NOEXCEPT_AS(static_cast<Pair<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_>>(TransconstructLength_<
	IsSame<
		DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_) DD_COMMA
		DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_)
	>::value &&
	IsTriviallyCopyable<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_)>::value &&
	IsTriviallyDestructible<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_)>::value
>::transconstruct_length(begin__ DD_COMMA result_begin__ DD_COMMA length_))) {
	return TransconstructLength_<
		IsSame<
			DD_MODIFY_TRAIT(RemoveCV, DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_)),
			DD_MODIFY_TRAIT(RemoveCV, DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_))
		>::value &&
		IsTriviallyCopyable<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_)>::value &&
		IsTriviallyDestructible<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_)>::value
	>::transconstruct_length(begin__, result_begin__, length_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::transconstruct_length;



DD_END_



#endif
