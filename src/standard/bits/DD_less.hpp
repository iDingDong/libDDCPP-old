//	DDCPP/standard/bits/DD_less.hpp
#ifndef DD_LESS_HPP_INCLUDED_
#	define DD_LESS_HPP_INCLUDED_ 1



#	include <cstring>

#	if __cplusplus >= 201103L
#		include "DD_IsScalar.hpp"
#	else
#		include "DD_IsArithmetic.hpp"
#	endif
#	include "DD_IsSame.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_get_pointer.hpp"
#	include "DD_length_difference.hpp"
#	include "DD_min.hpp"
#	include "DD_mismatch.hpp"



DD_DETAIL_BEGIN_
template <ValidityType can_trivially_operate_c_>
struct Less_ {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static ValidityType less(
		UndirectionalIteratorT1__ begin_1___,
		UndirectionalIteratorT1__ end_1___,
		UndirectionalIteratorT2__ begin_2___
	) {
		::DD::mate(begin_1___, begin_2___) = ::DD::mismatch(begin_1___, end_1___, begin_2___);
		return begin_1___ != end_1___ && *begin_1___ < *begin_2___;
	}

	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static ValidityType less(
		UndirectionalIteratorT1__ begin_1___,
		UndirectionalIteratorT1__ end_1___,
		UndirectionalIteratorT2__ begin_2___,
		UndirectionalIteratorT2__ end_2___
	) {
		::DD::mate(begin_1___, begin_2___) = ::DD::mismatch(begin_1___, end_1___, begin_2___, end_2___);
		return begin_1___ != end_1___ && begin_2___!= end_2___ && *begin_1___ < *begin_2___;
	}


};



template <>
struct Less_<true> {
	template <typename PointerT1__, typename PointerT2__>
	static ValidityType less(
		PointerT1__ begin_1___,
		PointerT1__ end_1___,
		PointerT2__ begin_2___
	) DD_NOEXCEPT {
		return memcmp(::DD::get_pointer(begin_1___), ::DD::get_pointer(begin_2___), ::DD::length_difference(begin_1___, end_1___)) < 0;
	}

	template <typename PointerT1__, typename PointerT2__>
	static ValidityType less(
		PointerT1__ begin_1___,
		PointerT1__ end_1___,
		PointerT2__ begin_2___,
		PointerT2__ end_2___
	) DD_NOEXCEPT {
		DD_MODIFY_TRAIT(IteratorDifference, PointerT1__) length_1_ = ::DD::length_difference(begin_1___, end_1___);
		DD_MODIFY_TRAIT(IteratorDifference, PointerT2__) length_2_ = ::DD::length_difference(begin_2___, end_2___);
		int result = memcmp(::DD::get_pointer(begin_1___), ::DD::get_pointer(begin_2___), min(length_1_, length_2_));
		return result < 0 || (result == 0 && length_1_ < length_2_);
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline ValidityType less(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__
) DD_NOEXCEPT_AS(Less_<AndType<
	IsPointer<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_> DD_COMMA
	IsSame<IteratorValueType<UndirectionalIteratorT1_> DD_COMMA IteratorValueType<UndirectionalIteratorT2_>> DD_COMMA
	IsScalar<IteratorValueType<UndirectionalIteratorT1_>>
>::value>::less(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__)) {
#	if __cplusplus >= 201103L
	return Less_<AndType<
		IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>,
		IsSame<IteratorValueType<UndirectionalIteratorT1_>, IteratorValueType<UndirectionalIteratorT2_>>,
		IsScalar<IteratorValueType<UndirectionalIteratorT1_>>
	>::value>::less(begin_1__, end_1__, begin_2__);
#	else
	return Less_<
		IsPointer<UndirectionalIteratorT1_> &&
		IsPointer<UndirectionalIteratorT2_> &&
		IsSame<typename IteratorValue<UndirectionalIteratorT1_>::Type, typename IteratorValue<UndirectionalIteratorT2_>::Type> &&
		IsArithmetic<typename IteratorValue<UndirectionalIteratorT1_>::Type>
	>::value>::less(begin_1__, end_1__, begin_2__);
#	endif
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline ValidityType less(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT2_ begin_2__,
	UndirectionalIteratorT2_ end_2__
) DD_NOEXCEPT_AS(Less_<AndType<
	IsPointer<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_> DD_COMMA
	IsSame<IteratorValueType<UndirectionalIteratorT1_> DD_COMMA IteratorValueType<UndirectionalIteratorT2_>> DD_COMMA
	IsScalar<IteratorValueType<UndirectionalIteratorT1_>>
>::value>::less(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA end_2__)) {
#	if __cplusplus >= 201103L
	return Less_<AndType<
		IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>,
		IsSame<IteratorValueType<UndirectionalIteratorT1_>, IteratorValueType<UndirectionalIteratorT2_>>,
		IsScalar<IteratorValueType<UndirectionalIteratorT1_>>
	>::value>::less(begin_1__, end_1__, begin_2__, end_2__);
#	else
	return Less_<
		IsPointer<UndirectionalIteratorT1_> &&
		IsPointer<UndirectionalIteratorT2_> &&
		IsSame<typename IteratorValue<UndirectionalIteratorT1_>::Type, typename IteratorValue<UndirectionalIteratorT2_>::Type> &&
		IsArithmetic<typename IteratorValue<UndirectionalIteratorT1_>::Type>
	>::value>::less(begin_1__, end_1__, begin_2__, end_2__);
#	endif
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::less;



DD_END_



#endif
