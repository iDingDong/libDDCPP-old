//	DDCPP/standard/bits/DD_find_range.hpp
#ifndef DD_FIND_RANGE_HPP_INCLUDED_
#	define DD_FIND_RANGE_HPP_INCLUDED_ 1



#	include "DD_StrictPointer.hpp"
#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_next.hpp"
#	include "DD_equal.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_, typename DifferenceT_>
#	if __cplusplus >= 201103L
StrictPointer<DifferenceT_[]> process_kmp_pattern(
#	else
DifferenceT_* process_kmp_pattern(
#	endif
	FreeAccessIteratorT_ const& begin__,
	DifferenceT_ length__
) {
	StrictPointer<DifferenceT_[]> result(new DifferenceT_[length__]);
	while (--length__) {
		DifferenceT_ common_length_ = length__;
		while (common_length_ && !equal(begin__, next(begin__, common_length_), next(begin__, length__ - common_length_ + 1))) {
			--common_length_;
		}
		result[length__] = length__ + 1 - common_length_;
	}
	*result = 1;
#	if __cplusplus >= 201103L
	return result;
#	else
	return result.release();
#	endif
}



template <ValidityType is_free_access_iterator_c_>
struct KmpFindRangeImplement_ {
	template <typename FreeAccessIteratorT1__, typename FreeAccessIteratorT2__, typename DifferenceT__>
	static FreeAccessIteratorT1__ kmp_find_range_apply(
		FreeAccessIteratorT1__ begin___,
		FreeAccessIteratorT1__ const& end___,
		FreeAccessIteratorT2__ const& pattern_begin___,
		DifferenceT__* processed_pattern_,
		DifferenceT__ const& length___
	) {
		for (DifferenceT__ current___ = DifferenceT__(); begin___ <= end___ - length___; ) {
			for (; ; ++current___) {
				if (current___ == length___) {
					return begin___;
				}
				if (*(begin___ + current___) != *(pattern_begin___ + current___)) {
					begin___ += processed_pattern_[current___];
					break;
				}
			}
		}
		return end___;
	}


};



template <typename UndirectionalIteratorT_, typename FreeAccessIteratorT_, typename DifferenceT_>
UndirectionalIteratorT_ kmp_find_range_apply(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__,
	FreeAccessIteratorT_ const& pattern_begin__,
	DifferenceT_* processed_pattern_,
	DifferenceT_ const& length__
) DD_NOEXCEPT_AS(UndirectionalIteratorT_(
	KmpFindRangeImplement_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::kmp_find_range_apply(
		begin__ DD_COMMA
		end__ DD_COMMA
		pattern_begin__ DD_COMMA
		processed_pattern_ DD_COMMA
		length__
	)
)) {
	return KmpFindRangeImplement_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::kmp_find_range_apply(
		begin__,
		end__,
		pattern_begin__,
		processed_pattern_,
		length__
	);
}



template <typename UndirectionalIteratorT_, typename FreeAccessIteratorT_>
UndirectionalIteratorT_ kmp_find_range(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__,
	FreeAccessIteratorT_ const& pattern_begin__,
	FreeAccessIteratorT_ const& pattern_end__
) DD_NOEXCEPT_AS(UndirectionalIteratorT_(
	kmp_find_range_apply(
		begin__ DD_COMMA
		end__ DD_COMMA
		pattern_begin__ DD_COMMA
		get_pointer(process_kmp_pattern(pattern_begin__, pattern_end__ - pattern_begin__)) DD_COMMA
		pattern_end__ - pattern_begin__
	)
)) {
	return kmp_find_range_apply(
		begin__,
		end__,
		pattern_begin__,
		get_pointer(process_kmp_pattern(pattern_begin__, pattern_end__ - pattern_begin__)),
		pattern_end__ - pattern_begin__
	);
}



template <typename UndirectionalIteratorT_, typename FreeAccessIteratorT_>
UndirectionalIteratorT_ find_range(
	UndirectionalIteratorT_ const& begin__,
	UndirectionalIteratorT_ const& end__,
	FreeAccessIteratorT_ const& pattern_begin__,
	FreeAccessIteratorT_ const& pattern_end__
) DD_NOEXCEPT_AS(UndirectionalIteratorT_(
	kmp_find_range(begin__ DD_COMMA end__ DD_COMMA pattern_begin__ DD_COMMA pattern_end__)
)) {
	return kmp_find_range(begin__, end__, pattern_begin__, pattern_end__);
}

template <typename UndirectionalRangeT_, typename FreeAccessRangeT_>
DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_) find_range(
	UndirectionalRangeT_& range__,
	FreeAccessRangeT_ const& pattern_range__
) DD_NOEXCEPT_AS(
	DD_MODIFY_TRAIT(Iterator, UndirectionalRangeT_)(find_range(DD_SPLIT_RANGE(range__) DD_COMMA DD_SPLIT_RANGE(pattern_range__)))
) {
	return find_range(DD_SPLIT_RANGE(range__), DD_SPLIT_RANGE(pattern_range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::process_kmp_pattern;
using detail_::kmp_find_range_apply;
using detail_::kmp_find_range;
using detail_::find_range;



DD_END_



#endif
