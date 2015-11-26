//	DDCPP/standard/bits/DD_sort.hpp
#ifndef DD_SORT_HPP_INCLUDED_
#	define DD_SORT_HPP_INCLUDED_ 1



#	include <cmath>

#	include "DD_middle.hpp"
#	include "DD_heap_sort.hpp"
#	include "DD_insert_sort.hpp"
#	include "DD_select_sort.hpp"



#	if !defined(DDCPP_SORT_MAX_FINAL_INTERVAL)
#		define DDCPP_SORT_MAX_FINAL_INTERVAL 8
#	endif



DD_DETAIL_BEGIN_
inline LengthType logarithms_2_(LengthType length_) DD_NOEXCEPT {
	LengthType result_ = LengthType();
	while (length_ /= 2) {
		++result_;
	}
	return result_;
}



template <typename IteratorT_>
inline IteratorT_ median_target(
	IteratorT_ first__,
	IteratorT_ second__,
	IteratorT_ third__
) {
	if (*first__ < *second__) {
		if (*second__ < *third__) {
			return second__;
		}
		return *first__ < *third__ ? third__ : first__;
	}
	if (*third__ < *second__) {
		return second__;
	}
	return *third__ < *first__ ? third__ : first__;
}


template <typename FreeAccessIteratorT_>
ProcessType lazy_intro_sort_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	LengthType depth_limit__
) {
	while (DDCPP_SORT_MAX_FINAL_INTERVAL < length_difference(begin__, end__)) {
		if (!depth_limit__) {
			::DD::heap_sort(begin__, end__);
			break;
		}
		--depth_limit__;
		swap_target(begin__, median_target(begin__, ::DD::middle(begin__, end__), end__));
		FreeAccessIteratorT_ low__(begin__);
		FreeAccessIteratorT_ high__(end__);
		for (; ; ) {
			do {
				if (low__ >= --high__) {
					goto out_side_;
				}
			} while (!(*high__ < *low__));
			swap_target(low__, high__);
			do {
				if (++low__ >= high__) {
					goto out_side_;
				}
			} while (!(*high__ < *low__));
			swap_target(low__, high__);
		}
		out_side_:
		::DD::detail_::lazy_intro_sort_(begin__, low__, depth_limit__);
		begin__ = high__ + 1;
	}
}



template <IteratorCatagoryValue iterator_catagory_c_>
struct Sort_ {
	template <typename UndirectionalIteratorT__>
	static ProcessType sort(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::select_sort(begin___, end___)) {
		::DD::select_sort(begin___, end___);
	}



};



template <>
struct Sort_<IteratorCatagoryValue::bidirectional> {
	template <typename BidirectionalIteratorT__>
	static ProcessType sort(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::select_sort(begin___, end___)) {
		::DD::select_sort(begin___, end___);
	}


};



template <>
struct Sort_<IteratorCatagoryValue::free_access> {
	template <typename FreeAccessIteratorT__>
	static ProcessType sort(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___
	) DD_NOEXCEPT_IF(noexcept(::DD::detail_::lazy_intro_sort_(
		begin___ DD_COMMA
		end___ DD_COMMA
		2 * ::DD::detail_::logarithms_2_(length_difference(begin___ DD_COMMA end___))
	)) && noexcept(::DD::insert_sort(begin___, end___))) {
		::DD::detail_::lazy_intro_sort_(begin___, end___, 2 * ::DD::detail_::logarithms_2_(length_difference(begin___, end___)));
		::DD::insert_sort(begin___, end___);
	}


};



template <typename UndirectionalIteratorT_>
inline ProcessType sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(Sort_<IteratorCatagory<UndirectionalIteratorT_>::value>::sort(begin__, end__)) {
	Sort_<IteratorCatagory<UndirectionalIteratorT_>::value>::sort(begin__, end__);
}

template <typename UndirectionalRangeT_>
inline ProcessType sort(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(::DD::detail_::sort(DD_SPLIT_RANGE(range__))) {
	::DD::detail_::sort(DD_SPLIT_RANGE(range__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::sort;



DD_END_



#endif
