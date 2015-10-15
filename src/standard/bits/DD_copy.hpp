//	DDCPP/standard/bits/DD_copy.hpp
#ifndef DD_COPY_HPP_INCLUDED_
#	define DD_COPY_HPP_INCLUDED_ 1



#	include <cstring>

#	include "DD_IsSame.hpp"
#	include "DD_IsPointer.hpp"
#	include "DD_IsTriviallyCopyable.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_size_distance.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_memmoveable_c_>
struct Copy_ {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static UndirectionalIteratorT2__ copy(
		UndirectionalIteratorT1__ begin___,
		UndirectionalIteratorT1__ const& end___,
		UndirectionalIteratorT2__ result_begin___
	) DD_NOEXCEPT_IF(noexcept(++begin___) && noexcept(++result_begin___) && noexcept(*result_begin___ = *begin___)) {
		for (; begin___ != end___; ++begin___, ++result_begin___) {
			*result_begin___ = *begin___;
		}
		return result_begin___;
	}


};



template <>
struct Copy_<true> {
	template <typename PointerT1__, typename PointerT2__>
	static PointerT2__ copy(
		PointerT1__ const& begin___,
		PointerT1__ const& end___,
		PointerT2__ const& result_begin___
	) DD_NOEXCEPT_AS(std::memmove(result_begin___, begin___, size_distance(begin___, end___))) {
		return std::memmove(result_begin___, begin___, size_distance(begin___, end___)), result_begin___ + (end___ - begin___);
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
UndirectionalIteratorT2_ copy(
	UndirectionalIteratorT1_ const& begin__,
	UndirectionalIteratorT1_ const& end__,
	UndirectionalIteratorT2_ const& result_begin__
) {
	DD_ALIAS(ValueType, DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_));
	return Copy_<
		IsSame<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_), ValueType>::value &&
		IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>::value &&
		IsTriviallyCopyable<ValueType>::value
	>::copy(begin__, end__, result_begin__);
}



template <typename UndirectionalRangeT_, typename UndirectionalIteratorT_>
UndirectionalIteratorT_ copy(
	UndirectionalRangeT_& range__,
	UndirectionalIteratorT_ const& result_begin__
) DD_NOEXCEPT_AS(static_cast<UndirectionalIteratorT_>(copy(DD_SPLIT_RANGE(range__) DD_COMMA result_begin__))) {
	return copy(DD_SPLIT_RANGE(range__), result_begin__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::copy;



DD_END_



#endif
