//	DDCPP/standard/bits/DD_copy.hpp
#ifndef DD_COPY_HPP_INCLUDED_
#	define DD_COPY_HPP_INCLUDED_ 1



#	include <cstring>

#	include "DD_IsSame.hpp"
#	include "DD_IsPointer.hpp"
#	include "DD_IsTriviallyCopyable.hpp"
#	include "DD_Iterator.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_IteratorDifference.hpp"
#	include "DD_get_pointer.hpp"
#	include "DD_size_distance.hpp"
#	include "DD_Range.hpp"
#	include "DD_min.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_memmoveable_c_>
struct Copy_ {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static UndirectionalIteratorT2__ copy(
		UndirectionalIteratorT1__ begin___,
		UndirectionalIteratorT1__ const& end___,
		UndirectionalIteratorT2__ result_begin___
	) DD_NOEXCEPT_IF(noexcept(begin___ != end___) && noexcept(*++result_begin___ = *++begin___)) {
		for (; begin___ != end___; ++begin___, ++result_begin___) {
			*result_begin___ = *begin___;
		}
		return result_begin___;
	}

	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static Pair<UndirectionalIteratorT1__, UndirectionalIteratorT2__> copy(
		UndirectionalIteratorT1__ begin___,
		UndirectionalIteratorT1__ const& end___,
		UndirectionalIteratorT2__ result_begin___,
		UndirectionalIteratorT2__ const& result_end___
	) DD_NOEXCEPT_IF(
		noexcept(begin___ != end___) && noexcept(result_begin___ != result_end___) && noexcept(*++result_begin___ = *++begin___)
	) {
		for (; begin___ != end___ && result_begin___ != result_end___; ++begin___, ++result_begin___) {
			*result_begin___ = *begin___;
		}
		return Pair<UndirectionalIteratorT1__, UndirectionalIteratorT2__>(begin___, result_begin___);
	}


};



template <>
struct Copy_<true> {
	template <typename PointerT1__, typename PointerT2__>
	static PointerT2__ copy(
		PointerT1__ const& begin___,
		PointerT1__ const& end___,
		PointerT2__ const& result_begin___
	) DD_NOEXCEPT_AS(size_distance(begin___, end___) DD_COMMA std::memcpy(
		::DD::get_pointer(result_begin___) DD_COMMA
		::DD::get_pointer(begin___) DD_COMMA
		::DD::size_distance(begin___ DD_COMMA end___)
	)) {
		DD_MODIFY_TRAIT(IteratorDifference, PointerT1__) length_ = ::DD::size_distance(begin___, end___);
		std::memcpy(::DD::get_pointer(result_begin___), ::DD::get_pointer(begin___), length_);
		return result_begin___ + length_;
	}

	template <typename PointerT1__, typename PointerT2__>
	static Pair<PointerT1__, PointerT2__> copy(
		PointerT1__ const& begin___,
		PointerT1__ const& end___,
		PointerT2__ const& result_begin___,
		PointerT2__ const& result_end___
	) DD_NOEXCEPT_AS(size_distance(begin___, end___) DD_COMMA std::memcpy(
		::DD::get_pointer(result_begin___) DD_COMMA
		::DD::get_pointer(begin___) DD_COMMA
		::DD::size_distance(begin___ DD_COMMA end___)
	)) {
		DD_MODIFY_TRAIT(IteratorDifference, PointerT1__) length_ = ::DD::min(
			::DD::size_distance(begin___, end___),
			::DD::size_distance(result_begin___, result_end___)
		);
		std::memcpy(::DD::get_pointer(result_begin___), ::DD::get_pointer(begin___), length_);
		return Pair<PointerT1__, PointerT2__>(begin___ + length_, result_begin___ + length_);
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

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
Pair<UndirectionalIteratorT1_, UndirectionalIteratorT2_> copy(
	UndirectionalIteratorT1_ const& begin__,
	UndirectionalIteratorT1_ const& end__,
	UndirectionalIteratorT2_ const& result_begin__,
	UndirectionalIteratorT2_ const& result_end__
) DD_NOEXCEPT_AS(static_cast<Pair<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_>>(Copy_<
	IsSame<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_), DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_)>::value &&
	IsPointer<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_>::value &&
	IsTriviallyCopyable<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_)>::value
>::copy(begin__ DD_COMMA end__ DD_COMMA result_begin__ DD_COMMA result_end__))) {
	DD_ALIAS(ValueType, DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT2_));
	return Copy_<
		IsSame<DD_MODIFY_TRAIT(IteratorValue, UndirectionalIteratorT1_), ValueType>::value &&
		IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>::value &&
		IsTriviallyCopyable<ValueType>::value
	>::copy(begin__, end__, result_begin__, result_end__);
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_>
Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_), DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)> copy(
	UndirectionalRangeT1_& range__,
	UndirectionalRangeT2_& result_range__
) DD_NOEXCEPT_AS(static_cast<Pair<DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT1_) DD_COMMA DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT2_)>>(
	::DD::detail_::copy(DD_SPLIT_RANGE(range__) DD_COMMA DD_SPLIT_RANGE(result_range__))
)) {
	return ::DD::detail_::copy(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(result_range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::copy;



DD_END_



#endif
