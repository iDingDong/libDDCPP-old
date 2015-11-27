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
#	include "DD_LessThan.hpp"
#	include "DD_get_pointer.hpp"
#	include "DD_length_difference.hpp"
#	include "DD_mismatch.hpp"



DD_DETAIL_BEGIN_
template <ValidityType can_trivially_operate_c_>
struct Less_ {
	template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
	static ValidityType less(
		UndirectionalIteratorT1_ begin_1__,
		UndirectionalIteratorT1_ end_1__,
		UndirectionalIteratorT2_ begin_2__
	) {
		::DD::mate(begin_1__, begin_2__) = ::DD::mismatch(begin_1__, end_1__, begin_2__);
		return begin_1__ != end_1__ && LessThan<
			DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_),
			DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_)
		>::call(*begin_1__ < *begin_2__);
	}


};



template <>
struct Less_<true> {
	template <typename PointerT1_, typename PointerT2_>
	static ValidityType less(
		PointerT1_ begin_1__,
		PointerT1_ end_1__,
		PointerT2_ begin_2__
	) {
		return memcmp(::DD::get_pointer(begin_1__), ::DD::get_pointer(begin_2__), ::DD::length_difference(begin_1__, end_1__)) < 0;
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline ValidityType less(
	UndirectionalIteratorT1_ begin_1__,
	UndirectionalIteratorT1_ end_1__,
	UndirectionalIteratorT1_ begin_2__
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



DD_DETAIL_END_



DD_BEGIN_
DD_END_



#endif
