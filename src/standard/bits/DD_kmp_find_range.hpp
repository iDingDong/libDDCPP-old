//	DDCPP/standard/bits/DD_kmp_find_range.hpp
#ifndef DD_KMP_FIND_RANGE_HPP_INCLUDED_
#	define DD_KMP_FIND_RANGE_HPP_INCLUDED_ 1



#	include "DD_UniquePointer.hpp"
#	include "DD_IsFreeAccessIterator.hpp"
#	include "DD_Iterator.hpp"
#	include "DD_Range.hpp"
#	include "DD_EqualTo.hpp"
#	include "DD_next.hpp"
#	include "DD_equal.hpp"



DD_DETAIL_BEGIN_
template <typename FreeAccessIteratorT_, typename DifferenceT_, typename BinaryPredicateT_>
#	if __cplusplus >= 201103L
UniquePointer<DifferenceT_[]> process_kmp_pattern(
#	else
DifferenceT_* process_kmp_pattern(
#	endif
	FreeAccessIteratorT_ begin__,
	DifferenceT_ length__,
	BinaryPredicateT_ equal__
) {
	UniquePointer<DifferenceT_[]> result(new DifferenceT_[length__]);
	while (--length__) {
		DifferenceT_ common_length_ = length__;
		while (--common_length_ && !equal(
			begin__, ::DD::next(begin__, common_length_), ::DD::next(begin__, length__ - common_length_), equal__
		)) {
		}
		result[length__] = length__ - common_length_;
	}
	*result = 1;
	return result;
}



template <ValidityType is_free_access_iterator_c_>
struct KmpFindRangeImplement_ {
	template <
		typename FreeAccessIteratorT1__,
		typename FreeAccessIteratorT2__,
		typename DifferenceT__,
		typename BinaryPredicateT__
	>
	static FreeAccessIteratorT1__ kmp_find_range_apply(
		FreeAccessIteratorT1__ begin___,
		FreeAccessIteratorT1__ end___,
		FreeAccessIteratorT2__ pattern_begin___,
		BinaryPredicateT__ equal___,
		UniquePointer<DifferenceT__[]> const& processed_pattern_,
		DifferenceT__ const& length___
	) {
		int i = 0;
		for (; begin___ <= end___ - length___; ) {
			for (DifferenceT__ current___ = DifferenceT__(); ; ++current___) {
				if (current___ == length___) {
					return begin___;
				}
				if (!equal___(*(begin___ + current___), *(pattern_begin___ + current___))) {
					begin___ += processed_pattern_[current___];
					i += processed_pattern_[current___];
					break;
				}
			}
		}
		return end___;
	}


};



template <
	typename UndirectionalIteratorT_, typename FreeAccessIteratorT_, typename DifferenceT_, typename BinaryPredicateT_
>
inline UndirectionalIteratorT_ kmp_find_range_apply(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	FreeAccessIteratorT_ pattern_begin__,
	BinaryPredicateT_ equal__,
	UniquePointer<DifferenceT_[]> const& processed_pattern_,
	DifferenceT_ const& length__
) DD_NOEXCEPT_AS(UndirectionalIteratorT_(
	KmpFindRangeImplement_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::kmp_find_range_apply(
		begin__ DD_COMMA
		end__ DD_COMMA
		pattern_begin__ DD_COMMA
		equal__ DD_COMMA
		processed_pattern_ DD_COMMA
		length__
	)
)) {
	return KmpFindRangeImplement_<IsFreeAccessIterator<UndirectionalIteratorT_>::value>::kmp_find_range_apply(
		begin__,
		end__,
		pattern_begin__,
		equal__,
		processed_pattern_,
		length__
	);
}



template <typename UndirectionalIteratorT_, typename FreeAccessIteratorT_, typename BinaryPredicateT_>
inline UndirectionalIteratorT_ kmp_find_range(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	FreeAccessIteratorT_ pattern_begin__,
	FreeAccessIteratorT_ pattern_end__,
	BinaryPredicateT_ equal__
) DD_NOEXCEPT_AS(UndirectionalIteratorT_(
	::DD::detail_::kmp_find_range_apply(
		begin__ DD_COMMA
		end__ DD_COMMA
		pattern_begin__ DD_COMMA
		equal__ DD_COMMA
		::DD::detail_::process_kmp_pattern(pattern_begin__ DD_COMMA pattern_end__ - pattern_begin__ DD_COMMA equal__) DD_COMMA
		pattern_end__ - pattern_begin__
	)
)) {
	return ::DD::detail_::kmp_find_range_apply(
		begin__,
		end__,
		pattern_begin__,
		equal__,
		::DD::detail_::process_kmp_pattern(pattern_begin__, pattern_end__ - pattern_begin__, equal__),
		pattern_end__ - pattern_begin__
	);
}

template <typename UndirectionalIteratorT_, typename FreeAccessIteratorT_>
UndirectionalIteratorT_ kmp_find_range(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	FreeAccessIteratorT_ pattern_begin__,
	FreeAccessIteratorT_ pattern_end__
) {
	return ::DD::detail_::kmp_find_range(begin__, end__, pattern_begin__, pattern_end__, equal_to);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::process_kmp_pattern;
using detail_::kmp_find_range_apply;
using detail_::kmp_find_range;



DD_END_



#endif
