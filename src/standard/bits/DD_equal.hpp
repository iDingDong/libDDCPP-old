//	DDCPP/standard/bits/DD_equal.hpp
#ifndef DD_EQUAL_HPP_INCLUDED_
#	define DD_EQUAL_HPP_INCLUDED_ 1



#	include <cstring>

#	if __cplusplus >= 201103L
#		include "DD_IsPod.hpp"
#	else
#		include "DD_IsArithmetic.hpp"
#	endif
#	include "DD_IsPointer.hpp"
#	include "DD_IsSame.hpp"
#	include "DD_IsRange.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_length_difference.hpp"
#	include "DD_size_distance.hpp"
#	include "DD_Range.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_trivially_equal_predicatable_c_>
struct Equal_ {
	template <ValidityType is_free_access_iterator_c__, int workaround_c__ = 0>
	struct Equal__ {
		template <typename UndirectionalIteratorT1___, typename UndirectionalIteratorT2___>
		static ValidityType equal_(
			UndirectionalIteratorT1___ begin_1____,
			UndirectionalIteratorT1___ const& end_1____,
			UndirectionalIteratorT2___ begin_2____,
			UndirectionalIteratorT2___ const& end_2____
		) DD_NOEXCEPT_AS(++begin_1____ != end_1____ && ++begin_2____ == end_2____ && *begin_1____ != *begin_2____) {
			for (; begin_1____ != end_1____; ++begin_1____, ++begin_2____) {
				if (begin_2____ == end_2____) {
					return false;
				} else if (*begin_1____ != *begin_2____) {
					return false;
				}
			}
			return begin_2____ == end_2____;
		}

		template <typename UndirectionalIteratorT1___, typename UndirectionalIteratorT2___, typename BinaryPredicator___>
		static ValidityType equal_(
			UndirectionalIteratorT1___ begin_1____,
			UndirectionalIteratorT1___ const& end_1____,
			UndirectionalIteratorT2___ begin_2____,
			UndirectionalIteratorT2___ const& end_2____,
			BinaryPredicator___ const& equal____
		) DD_NOEXCEPT_AS(++begin_1____ != end_1____ && ++begin_2____ == end_2____ && equal____(*begin_1____, *begin_2____)) {
			for (; begin_1____ != end_1____; ++begin_1____, ++begin_2____) {
				if (begin_2____ == end_2____) {
					return false;
				} else if (!equal____(*begin_1____, *begin_2____)) {
					return false;
				}
			}
			return begin_2____ == end_2____;
		}


	};


	template <int workaround_c__>
	struct Equal__<true, workaround_c__> {
		template <typename FreeAccessIteratorT1___, typename FreeAccessIteratorT2___>
		static ValidityType equal_(
			FreeAccessIteratorT1___ const& begin_1____,
			FreeAccessIteratorT1___ const& end_1____,
			FreeAccessIteratorT2___ const& begin_2____,
			FreeAccessIteratorT2___ const& end_2____
		) DD_NOEXCEPT_AS(begin_1____[length_difference(begin_1____, end_1____)] != begin_2____[length_difference(begin_2____, end_2____)]) {
#	if __cplusplus >= 201103L
			auto length_ = length_difference(begin_1____, end_1____);
#	else
			typename IteratorDifference<FreeAccessIteratorT1__>::Type length_ = length_difference(begin_1____, end_1____);
#	endif
			if (length_ != length_difference(begin_2____, end_2____)) {
				return false;
			}
			while (length_--) {
				if (begin_1____[length_] != begin_2____[length_]) {
					return false;
				}
			}
			return true;
		}

		template <typename FreeAccessIteratorT1___, typename FreeAccessIteratorT2___, typename BinaryPredicator___>
		static ValidityType equal_(
			FreeAccessIteratorT1___ const& begin_1____,
			FreeAccessIteratorT1___ const& end_1____,
			FreeAccessIteratorT2___ const& begin_2____,
			FreeAccessIteratorT2___ const& end_2____,
			BinaryPredicator___ const& equal____
		) DD_NOEXCEPT_AS(equal____(begin_1____[length_difference(begin_1____, end_1____)], begin_2____[length_difference(begin_2____, end_2____)])) {
#	if __cplusplus >= 201103L
			auto length_ = length_difference(begin_1____, end_1____);
#	else
			typename IteratorDifference<FreeAccessIteratorT1__>::Type length_ = length_difference(begin_1____, end_1____);
#	endif
			if (length_ != length_difference(begin_2____, end_2____)) {
				return false;
			}
			while (length_--) {
				if (!equal____(begin_1____[length_], begin_2____[length_])) {
					return false;
				}
			}
			return true;
		}


	};


	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static ValidityType equal_(
		UndirectionalIteratorT1__ begin_1___,
		UndirectionalIteratorT1__ const& end_1___,
		UndirectionalIteratorT2__ begin_2___
	) DD_NOEXCEPT_AS(begin_1___ != end_1___ && *++begin_1___ != *++begin_2___) {
		for (; begin_1___ != end_1___; ++begin_1___, ++begin_2___) {
			if (*begin_1___ != *begin_2___) {
				return false;
			}
		}
		return true;
	}

	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static ValidityType equal_(
		UndirectionalIteratorT1__ const& begin_1___,
		UndirectionalIteratorT1__ const& end_1___,
		UndirectionalIteratorT2__ const& begin_2___,
		UndirectionalIteratorT2__ const& end_2___
	) DD_NOEXCEPT_AS(
		Equal__<
			IsFreeAccessIterator<UndirectionalIteratorT1__ DD_COMMA UndirectionalIteratorT2__>::value
		>::equal_(begin_1___ DD_COMMA end_1___ DD_COMMA begin_2___ DD_COMMA end_2___)
	) {
		return Equal__<
#	if __cplusplus >= 201103L
			IsFreeAccessIterator<UndirectionalIteratorT1__, UndirectionalIteratorT2__>::value
#	else
			IsFreeAccessIterator<UndirectionalIteratorT1__>::value && IsFreeAccessIterator<UndirectionalIteratorT2__>::value
#	endif
		>::equal_(begin_1___, end_1___, begin_2___, end_2___);
	}

	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__, typename BinaryPredicator__>
	static ValidityType equal_(
		UndirectionalIteratorT1__ begin_1___,
		UndirectionalIteratorT1__ const& end_1___,
		UndirectionalIteratorT2__ begin_2___,
		BinaryPredicator__ const& equal___
	) DD_NOEXCEPT_AS(begin_1___ != end_1___ && equal___(*++begin_1___, *++begin_2___)) {
		for (; begin_1___ != end_1___; ++begin_1___, ++begin_2___) {
			if (!equal___(*begin_1___, *begin_2___)) {
				return false;
			}
		}
		return true;
	}

	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__, typename BinaryPredicator__>
	static ValidityType equal_(
		UndirectionalIteratorT1__ const& begin_1___,
		UndirectionalIteratorT1__ const& end_1___,
		UndirectionalIteratorT2__ const& begin_2___,
		UndirectionalIteratorT2__ const& end_2___,
		BinaryPredicator__ const& equal___
	) DD_NOEXCEPT_AS(
		Equal__<
			IsFreeAccessIterator<UndirectionalIteratorT1__ DD_COMMA UndirectionalIteratorT2__>::value
		>::equal_(begin_1___ DD_COMMA end_1___ DD_COMMA begin_2___ DD_COMMA end_2___ DD_COMMA equal___)
	) {
		return Equal__<
#	if __cplusplus >= 201103L
			IsFreeAccessIterator<UndirectionalIteratorT1__, UndirectionalIteratorT2__>::value
#	else
			IsFreeAccessIterator<UndirectionalIteratorT1__>::value && IsFreeAccessIterator<UndirectionalIteratorT2__>::value
#	endif
		>::equal_(begin_1___, end_1___, begin_2___, end_2___, equal___);
	}


};



template <>
struct Equal_<true> {
	template <typename PointerT1__, typename PointerT2__>
	static ValidityType equal_(
		PointerT1__ const& begin_1___,
		PointerT1__ const& end_1___,
		PointerT2__ const& begin_2___
	) DD_NOEXCEPT {
		return !std::memcmp(get_pointer(begin_1___), get_pointer(begin_2___), size_distance(begin_1___, end_1___));
	}

	template <typename PointerT1__, typename PointerT2__>
	static ValidityType equal_(
		PointerT1__ const& begin_1___,
		PointerT1__ const& end_1___,
		PointerT2__ const& begin_2___,
		PointerT2__ const& end_2___
	) DD_NOEXCEPT {
		SizeType size_ = size_distance(begin_1___, end_1___);
		return size_ == size_distance(begin_2___, end_2___) && !std::memcmp(get_pointer(begin_1___), get_pointer(begin_2___), size_);
	}


};



template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline ValidityType equal_(
	UndirectionalIteratorT1_ const& begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ const& begin_2__
) DD_NOEXCEPT_AS(
	detail_::Equal_<
		AndType<
			IsPod<IteratorValueType<UndirectionalIteratorT1_>> DD_COMMA
			IsPointer<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_> DD_COMMA
			IsSame<
				RemoveCVType<IteratorValueType<UndirectionalIteratorT1_>> DD_COMMA
				RemoveCVType<IteratorValueType<UndirectionalIteratorT2_>>
			>
		>::value
	>::equal_(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__)
) {
	return detail_::Equal_<
#	if __cplusplus >= 201103L
		AndType<
			IsPod<IteratorValueType<UndirectionalIteratorT1_>>,
			IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>,
			IsSame<
				RemoveCVType<IteratorValueType<UndirectionalIteratorT1_>>,
				RemoveCVType<IteratorValueType<UndirectionalIteratorT2_>>
			>
		>::value
#	else
		IsArithmetic<typename IteratorValue<UndirectionalIteratorT1_>::Type>::value && IsPointer<UndirectionalIteratorT1_>::value && IsPointer<UndirectionalIteratorT2_>::value && IsSame<
			typename RemoveCV<typename IteratorValue<UndirectionalIteratorT1_>::Type>::Type,
			typename RemoveCV<typename IteratorValue<UndirectionalIteratorT2_>::Type>::Type
		>::value
#	endif
	>::equal_(begin_1__, end_1__, begin_2__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline ValidityType equal(
	UndirectionalIteratorT1_ const& begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ const& begin_2__,
	UndirectionalIteratorT2_ const& end_2__
) DD_NOEXCEPT_AS(
	detail_::Equal_<
		AndType<
			IsPod<IteratorValueType<UndirectionalIteratorT1_>> DD_COMMA
			IsPointer<UndirectionalIteratorT1_ DD_COMMA UndirectionalIteratorT2_> DD_COMMA
			IsSame<
				RemoveCVType<IteratorValueType<UndirectionalIteratorT1_>> DD_COMMA
				RemoveCVType<IteratorValueType<UndirectionalIteratorT2_>>
			>
		>::value
	>::equal_(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA end_2__)
) {
	return detail_::Equal_<
#	if __cplusplus >= 201103L
		AndType<
			IsPod<IteratorValueType<UndirectionalIteratorT1_>>,
			IsPointer<UndirectionalIteratorT1_, UndirectionalIteratorT2_>,
			IsSame<
				RemoveCVType<IteratorValueType<UndirectionalIteratorT1_>>,
				RemoveCVType<IteratorValueType<UndirectionalIteratorT2_>>
			>
		>::value
#	else
		IsArithmetic<typename IteratorValue<UndirectionalIteratorT1_>::Type>::value && IsPointer<UndirectionalIteratorT1_>::value && IsPointer<UndirectionalIteratorT2_>::value && IsSame<
			typename RemoveCV<typename IteratorValue<UndirectionalIteratorT1_>::Type>::Type,
			typename RemoveCV<typename IteratorValue<UndirectionalIteratorT2_>::Type>::Type
		>::value
#	endif
	>::equal_(begin_1__, end_1__, begin_2__, end_2__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicatorT_>
inline ValidityType equal_(
	UndirectionalIteratorT1_ const& begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ const& begin_2__,
	BinaryPredicatorT_ const& equal__
) DD_NOEXCEPT_AS(detail_::Equal_<false>::equal_(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA equal__)) {
	return detail_::Equal_<false>::equal_(begin_1__, end_1__, begin_2__, equal__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicatorT_>
inline ValidityType equal(
	UndirectionalIteratorT1_ const& begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ const& begin_2__,
	UndirectionalIteratorT2_ const& end_2__,
	BinaryPredicatorT_ const& equal__
) DD_NOEXCEPT_AS(detail_::Equal_<false>::equal_(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA end_2__ DD_COMMA equal__)) {
	return detail_::Equal_<false>::equal_(begin_1__, end_1__, begin_2__, end_2__, equal__);
}



template <ValidityType is_range_c_>
struct EqualDispatcher_ {
	template <typename UndirectionalIteratorT1__, typename UndirectionalIteratorT2__>
	static ValidityType equal_(
		UndirectionalIteratorT1__ const& begin_1___,
		UndirectionalIteratorT1__ const& end_1___,
		UndirectionalIteratorT2__ const& begin_2___
	) DD_NOEXCEPT_AS(::DD::detail_::equal_(begin_1___ DD_COMMA end_1___ DD_COMMA begin_2___)) {
		return ::DD::detail_::equal_(begin_1___, end_1___, begin_2___);
	}


};



template <>
struct EqualDispatcher_<true> {
	template <typename UndirectionalRangeT1__, typename UndirectionalRangeT2__, typename BinaryPredicatorT__>
	static ValidityType equal_(
		UndirectionalRangeT1__ const& range_1___,
		UndirectionalRangeT2__ const& range_2___,
		BinaryPredicatorT__ const& equal___
	) DD_NOEXCEPT_AS(::DD::detail_::equal_(DD_SPLIT_RANGE(range_1___) DD_COMMA DD_SPLIT_RANGE(range_2___) DD_COMMA equal___)) {
		return ::DD::detail_::equal_(DD_SPLIT_RANGE(range_1___), DD_SPLIT_RANGE(range_2___), equal___);
	}


};



DD_DETAIL_END_



DD_BEGIN_
template <typename ObjectT1_, typename ObjectT2_, typename ObjectT3_>
inline ValidityType equal(
	ObjectT1_ const& object_1__,
	ObjectT2_ const& object_2__,
	ObjectT3_ const& object_3__
) DD_NOEXCEPT_AS(detail_::EqualDispatcher_<IsRange<ObjectT1_>::value>::equal_(object_1__ DD_COMMA object_2__ DD_COMMA object_3__)) {
	return detail_::EqualDispatcher_<IsRange<ObjectT1_>::value>::equal_(object_1__, object_2__, object_3__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_>
inline ValidityType equal(
	UndirectionalIteratorT1_ const& begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ const& begin_2__,
	UndirectionalIteratorT2_ const& end_2__
) DD_NOEXCEPT_AS(detail_::equal_(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA end_2__)) {
	return detail_::equal_(begin_1__, end_1__, begin_2__, end_2__);
}

template <typename UndirectionalIteratorT1_, typename UndirectionalIteratorT2_, typename BinaryPredicatorT_>
inline ValidityType equal(
	UndirectionalIteratorT1_ const& begin_1__,
	UndirectionalIteratorT1_ const& end_1__,
	UndirectionalIteratorT2_ const& begin_2__,
	UndirectionalIteratorT2_ const& end_2__,
	BinaryPredicatorT_ const& equal__
) DD_NOEXCEPT_AS(detail_::equal_(begin_1__ DD_COMMA end_1__ DD_COMMA begin_2__ DD_COMMA end_2__ DD_COMMA equal__)) {
	return detail_::equal_(begin_1__, end_1__, begin_2__, end_2__, equal__);
}

template <typename UndirectionalRangeT1_, typename UndirectionalRangeT2_>
inline ValidityType equal(
	UndirectionalRangeT1_ const& range_1__,
	UndirectionalRangeT2_ const& range_2__
) DD_NOEXCEPT_AS(detail_::equal_(DD_SPLIT_RANGE(range_1__) DD_COMMA DD_SPLIT_RANGE(range_2__))) {
	return detail_::equal_(DD_SPLIT_RANGE(range_1__), DD_SPLIT_RANGE(range_2__));
}



DD_END_



#endif
