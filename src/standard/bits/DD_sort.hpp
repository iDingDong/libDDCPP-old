//	DDCPP/standard/bits/DD_sort.hpp
#ifndef DD_SORT_HPP_INCLUDED_
#	define DD_SORT_HPP_INCLUDED_ 1



#	include <cmath>

#	include "DD_ReadOnlyCall.hpp"
#	include "DD_IteratorValue.hpp"
#	include "DD_IteratorDifference.hpp"
#	include "DD_LessThan.hpp"
#	include "DD_length_difference.hpp"
#	include "DD_insert_sort.hpp"



#	ifndef DDCPP_SORT_FINAL_INSERT_LIMIT
#		define DDCPP_SORT_FINAL_INSERT_LIMIT 8
#	endif



DD_DETAIL_BEGIN_
template <typename LengthT_>
inline LengthT_ logarithms_2_(LengthT_ length_) {
	return std::log(length_) / std::log(2);
}


template <typename IteratorT_>
IteratorT_ find_median_(
	IteratorT_ begin__,
	IteratorT_ middle__,
	IteratorT_ end__
) {
	if (LessThan<DD_MODIFY_TRAIT(IteratorValue, IteratorT_)>::call(*middle__, *begin__)) {
		if (LessThan<DD_MODIFY_TRAIT(IteratorValue, IteratorT_)>::call(*end__, *middle__)) {
			return middle__;
		} else if (LessThan<DD_MODIFY_TRAIT(IteratorValue, IteratorT_)>::call(*end__, *begin__)) {
			return end__;
		}
		return begin__;
	}
	if (LessThan<DD_MODIFY_TRAIT(IteratorValue, IteratorT_)>::call(*middle__, *end__)) {
		return middle__;
	} else if (LessThan<DD_MODIFY_TRAIT(IteratorValue, IteratorT_)>::call(*begin__, *end__)) {
		return end__;
	}
	return begin__;
}


template <typename FreeAccessIteratorT_>
FreeAccessIteratorT_ unguarded_partition_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	FreeAccessIteratorT_ pivot__
) {
	for (; ; ++begin__) {
		while (LessThan<DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)>::call(*begin__, *pivot__)) {
			++begin__;
		}
		while (LessThan<DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)>::call(*pivot__, --*end__)) {
		}
		if (!(begin__ < end__)) {
			break;
		}
		using ::DD::swap_target;
		swap_target(begin__, end__);
	}
	return begin__;
}


template <typename FreeAccessIteratorT_>
inline FreeAccessIteratorT_ unguarded_partition_pivot_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__
) {
	FreeAccessIteratorT_ middle__ = begin__ + length_difference(begin__, end__) / 2;
	using ::DD::swap_target;
	swap_target(begin__, find_median_(begin__, middle__, end__));
	return unguarded_partition_(begin__ + 1, end__, begin__);
}


template <typename FreeAccessIteratorT_>
ProcessType push_heap(
	FreeAccessIteratorT_ begin__,
	DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_) hole_index_,
	DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_) top_index_,
	DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)& value_
) {
	DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_) parent_ = (hole_index_ - 1) / 2;
	for (; hole_index_ > top_index_ && LessThan<DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)>::call(
		*(begin__ + parent_), value_
	); parent_ = (hole_index_ - 1) / 2) {
		*(begin__ + hole_index_) = *(begin__ + parent_);
		hole_index_ = parent_;
	}
	*(begin__ + hole_index_) = value_;
}


template <typename FreeAccessIteratorT_>
ProcessType adjust_heap_(
	FreeAccessIteratorT_ begin__,
	DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_) hole_index_,
	DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_) length_,
	DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)& value_
) {
	DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_) const top_index_ = hole_index_;
	DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_) second_child_ = hole_index_;
	while (second_child_ < (length_ - 1) / 2) {
		++second_child_;
		second_child_ *= 2;
		if (LessThan<DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)>::call(
			*(begin__ + second_child_),
			*(begin__ + second_child_ - 1)
		)) {
			--second_child_;
		}
		*(begin__ + hole_index_) = *(begin__ + second_child_);
		hole_index_ = second_child_;
	}
	if (length_ % 2 == 0 && second_child_ == (length_ - 2) / 2) {
		++second_child_;
		second_child_ *= 2;
		*(begin__ + hole_index_) = *(begin__ + second_child_ - 1);
		hole_index_ = second_child_ - 1;
	}
	push_heap_(begin__, hole_index_, top_index_, value_);
}


template <typename FreeAccessIteratorT_>
inline ProcessType pop_heap_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ last__,
	FreeAccessIteratorT_ result__
) {
	DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_) value_ = *result__;
	*result__ = *begin__;
	adjust_heap_(begin__, DD_MODIFY_TRAIT(IteratorDifference, FreeAccessIteratorT_)(), length_difference(begin__, last__), value_);
}


template <typename FreeAccessIteratorT_>
ProcessType heap_select_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ middle__,
	FreeAccessIteratorT_ end__
) {
	make_heap_(begin__, middle__);
	for (FreeAccessIteratorT_ current__ = middle__; current__ < end__; ++ current__) {
		if (LessThan<DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)>::call(*current__, *begin__)) {
			pop_heap_(begin__, middle__, current__);
		}
	}
}


template <typename FreeAccessIteratorT_>
ProcessType sort_heap_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__
) {
	while (length_difference(begin__, end__) > 1) {
		--end__;
		pop_heap_(begin__, end__, end__);
	}
}


template <typename FreeAccessIteratorT_>
inline ProcessType partitial_sort_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ middle__,
	FreeAccessIteratorT_ end__
) {
	heap_select_(begin__, middle__, end__);
	sort_heap_(begin__, middle__);
}


template <typename FreeAccessIteratorT_>
ProcessType introspective_sort_loop_(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__,
	DD_MODIFY_TRAIT(Iterator, FreeAccessIteratorT_) depth_limit_
) {
	while (length_difference(begin__, end__) > DDCPP_SORT_FINAL_INSERT_LIMIT) {
		if (depth_limit_) {
			FreeAccessIteratorT_ current__(unguarded_partition_pivot_(begin__, end__));
			introspective_sort_loop_(current__, end__, --depth_limit_);
			end__ = current__;
		} else {
			partitial_sort_(begin__, end__, end__);
		}
	}
}


template <typename FreeAccessIteratorT_>
ProcessType final_insert_sort_(
	DD_MODIFY_TRAIT(ReadOnlyCall, FreeAccessIteratorT_) begin__,
	DD_MODIFY_TRAIT(ReadOnlyCall, FreeAccessIteratorT_) end__
) {
	for (FreeAccessIteratorT_ current__ = begin__; ++current__ < end__; ) {
		DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_) temp_ = *current__;
		FreeAccessIteratorT_ front__ = current__;
		for (; LessThan<DD_MODIFY_TRAIT(IteratorValue, FreeAccessIteratorT_)>::call(temp_, *(front__ - 1)) && front__ > begin__; --front__) {
			*front__ = *(front__ - 1);
		}
		*front__ = temp_;
	}
}


template <typename FreeAccessIteratorT_>
inline ProcessType sort(
	FreeAccessIteratorT_ begin__,
	FreeAccessIteratorT_ end__
) {
	if (begin__ < end__) {
		introspective_sort_loop_(begin__, end__, logarithms_2_(length_difference(begin__, end__)) * 2);
		final_insert_sort_<FreeAccessIteratorT_>(begin__, end__);
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::sort;



DD_END_



#endif
