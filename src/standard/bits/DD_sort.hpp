//	DDCPP/standard/bits/DD_sort.hpp
#ifndef DD_SORT_HPP_INCLUDED_
#	define DD_SORT_HPP_INCLUDED_ 1



#	include "DD_middle.hpp"
#	include "DD_median_target.hpp"
#	include "DD_pivot_partition.hpp"
#	include "DD_heap_sort.hpp"
#	include "DD_insert_sort.hpp"
#	include "DD_select_sort.hpp"



#	if !defined(DDCPP_SORT_RECURSION_DEPTH_LIMIT_RATIO)
#		define DDCPP_SORT_RECURSION_DEPTH_LIMIT_RATIO 2
#	endif

#	if !defined(DDCPP_SORT_MAX_FINAL_INTERVAL)
#		define DDCPP_SORT_MAX_FINAL_INTERVAL 8
#	endif



DD_DETAIL_BEGIN_
inline LengthType DD_CONSTEXPR logarithms_2_(LengthType length_) DD_NOEXCEPT {
#	if __cplusplus >= 201402L || __cplusplus < 201103L
	LengthType result_ = LengthType();
	while (length_ /= 2U) {
		++result_;
	}
	return result_;
#	else
	return length_ / 2U ? ::DD::detail_::logarithms_2_(length_ / 2U) : 0U;
#	endif
}


template <typename FreeAccessIteratorT_>
ProcessType lazy_intro_sort_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	LengthType depth_limit__
) {
	while ((DDCPP_SORT_MAX_FINAL_INTERVAL) < length_difference(begin__, end__)) {
		if (!depth_limit__) {
			::DD::heap_sort(begin__, end__);
			break;
		}
		--depth_limit__;
		swap_target(begin__, median_target(begin__, ::DD::middle(begin__, end__), end__));
		FreeAccessIteratorT_ pivot__(::DD::unguarded_pivot_partition(begin__, end__));
		::DD::detail_::lazy_intro_sort_(pivot__ + 1, end__, depth_limit__);
		end__ = pivot__;
	}
}

template <typename FreeAccessIteratorT_, typename BinaryPrediateT_>
ProcessType lazy_intro_sort_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	BinaryPrediateT_ less__,
	LengthType depth_limit__
) {
	while ((DDCPP_SORT_MAX_FINAL_INTERVAL) < length_difference(begin__, end__)) {
		if (!depth_limit__) {
			::DD::heap_sort(begin__, end__);
			break;
		}
		--depth_limit__;
		swap_target(begin__, median_target(begin__, ::DD::middle(begin__, end__), end__, less__));
		FreeAccessIteratorT_ pivot__(::DD::unguarded_pivot_partition(begin__, end__, less__));
		::DD::detail_::lazy_intro_sort_(pivot__ + 1, end__, less__, depth_limit__);
		end__ = pivot__;
	}
}



template <IteratorCatagoryValue iterator_catagory_c_>
struct Sort_ {
	template <typename UndirectionalIteratorT__>
	static ProcessType sort(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::select_sort(begin___ DD_COMMA end___)) {
		::DD::select_sort(begin___, end___);
	}

	template <typename UndirectionalIteratorT__, typename BinaryPredicateT__>
	static ProcessType sort(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___,
		BinaryPredicateT__ less___
	) DD_NOEXCEPT_AS(::DD::select_sort(begin___ DD_COMMA end___ DD_COMMA less___)) {
		::DD::select_sort(begin___, end___);
	}


};



template <>
struct Sort_<IteratorCatagoryValue::bidirectional> {
	template <typename BidirectionalIteratorT__>
	static ProcessType sort(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::select_sort(begin___ DD_COMMA end___)) {
		::DD::select_sort(begin___, end___);
	}

	template <typename BidirectionalIteratorT__, typename BinaryPredicateT__>
	static ProcessType sort(
		BidirectionalIteratorT__ begin___,
		BidirectionalIteratorT__ end___,
		BinaryPredicateT__ less___
	) DD_NOEXCEPT_AS(::DD::select_sort(begin___ DD_COMMA end___ DD_COMMA less___)) {
		::DD::select_sort(begin___, end___, less___);
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
		(DDCPP_SORT_RECURSION_DEPTH_LIMIT_RATIO) * ::DD::detail_::logarithms_2_(length_difference(begin___ DD_COMMA end___))
	)) && noexcept(::DD::insert_sort(begin___ DD_COMMA end___))) {
		::DD::detail_::lazy_intro_sort_(
			begin___,
			end___,
			(DDCPP_SORT_RECURSION_DEPTH_LIMIT_RATIO) * ::DD::detail_::logarithms_2_(length_difference(begin___, end___))
		);
		::DD::insert_sort(begin___, end___);
	}

	template <typename FreeAccessIteratorT__, typename BinaryPredicateT__>
	static ProcessType sort(
		FreeAccessIteratorT__ begin___,
		FreeAccessIteratorT__ end___,
		BinaryPredicateT__ less___
	) DD_NOEXCEPT_IF(noexcept(::DD::detail_::lazy_intro_sort_(
		begin___ DD_COMMA
		end___ DD_COMMA
		less___ DD_COMMA
		(DDCPP_SORT_RECURSION_DEPTH_LIMIT_RATIO) * ::DD::detail_::logarithms_2_(length_difference(begin___ DD_COMMA end___))
	)) && noexcept(::DD::insert_sort(begin___ DD_COMMA end___ DD_COMMA less___))) {
		::DD::detail_::lazy_intro_sort_(
			begin___,
			end___,
			less___,
			(DDCPP_SORT_RECURSION_DEPTH_LIMIT_RATIO) * ::DD::detail_::logarithms_2_(length_difference(begin___, end___))
		);
		::DD::insert_sort(begin___, end___, less___);
	}


};



template <typename UndirectionalIteratorT_>
inline ProcessType sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__
) DD_NOEXCEPT_AS(Sort_<IteratorCatagory<UndirectionalIteratorT_>::value>::sort(begin__ DD_COMMA end__)) {
	Sort_<IteratorCatagory<UndirectionalIteratorT_>::value>::sort(begin__, end__);
}

template <typename UndirectionalIteratorT_, typename BinaryPredicateT_>
inline ProcessType sort(
	UndirectionalIteratorT_ begin__,
	UndirectionalIteratorT_ end__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(Sort_<IteratorCatagory<UndirectionalIteratorT_>::value>::sort(begin__ DD_COMMA end__ DD_COMMA less__)) {
	Sort_<IteratorCatagory<UndirectionalIteratorT_>::value>::sort(begin__, end__, less__);
}

template <typename UndirectionalRangeT_>
inline ProcessType sort(
	UndirectionalRangeT_& range__
) DD_NOEXCEPT_AS(::DD::detail_::sort(DD_SPLIT_RANGE(range__))) {
	::DD::detail_::sort(DD_SPLIT_RANGE(range__));
}

template <typename UndirectionalRangeT_, typename BinaryPredicateT_>
inline ProcessType sort(
	UndirectionalRangeT_& range__,
	BinaryPredicateT_ less__
) DD_NOEXCEPT_AS(::DD::detail_::sort(DD_SPLIT_RANGE(range__) DD_COMMA less__)) {
	::DD::detail_::sort(DD_SPLIT_RANGE(range__), less__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::sort;



DD_END_



#endif
