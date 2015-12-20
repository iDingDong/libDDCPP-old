//	DDCPP/standard/bits/DDAlgorithm.hpp
#ifndef DDALGORITHM_HPP_INCLUDED_
#	define DDALGORITHM_HPP_INCLUDED_ 1



#	include "bits/DD_min.hpp"
#	include "bits/DD_max.hpp"
#	include "bits/DD_min_max.hpp"
#	include "bits/DD_accumulate.hpp"
#	include "bits/DD_partial_sum.hpp"
#	include "bits/DD_equal.hpp"
#	include "bits/DD_less.hpp"
#	include "bits/DD_mismatch.hpp"
#	include "bits/DD_find.hpp"
#	include "bits/DD_find_if.hpp"
#	include "bits/DD_find_if_not.hpp"
#	include "bits/DD_find_first_of.hpp"
#	include "bits/DD_binary_find.hpp"
#	include "bits/DD_find_bounds.hpp"
#	if __cplusplus < 201103L
#		include "bits/DD_find_min.hpp"
#		include "bits/DD_find_max.hpp"
#		include "bits/DD_find_min_max.hpp"
#	endif
#	include "bits/DD_find_range.hpp"
#	include "bits/DD_count.hpp"
#	include "bits/DD_count_if.hpp"
#	include "bits/DD_is_partitioned.hpp"
#	include "bits/DD_is_partitioned_by.hpp"
#	include "bits/DD_partition_point.hpp"
#	include "bits/DD_partition_point_by.hpp"
#	include "bits/DD_is_sorted.hpp"
#	include "bits/DD_is_sorted_until.hpp"
#	include "bits/DD_for_each.hpp"
#	include "bits/DD_copy_length.hpp"
#	include "bits/DD_copy_construct_length.hpp"
#	if __cplusplus < 201103L
#		include "bits/DD_move_overlapped_backward.hpp"
#	else
#		include "bits/DD_copy_overlapped_backward.hpp"
#	endif
#	include "bits/DD_fill.hpp"
#	include "bits/DD_generate.hpp"
#	include "bits/DD_transfer.hpp"
#	include "bits/DD_transform.hpp"
#	include "bits/DD_replace.hpp"
#	include "bits/DD_replace_if.hpp"
#	include "bits/DD_partition.hpp"
#	include "bits/DD_partition_by.hpp"
#	include "bits/DD_merge.hpp"
#	include "bits/DD_partial_sort.hpp"
#	include "bits/DD_bubble_sort.hpp"
#	include "bits/DD_insert_sort.hpp"
#	include "bits/DD_quick_sort.hpp"
#	include "bits/DD_heap_sort.hpp"
#	include "bits/DD_sort.hpp"
#	include "bits/DD_next_permutation.hpp"
#	include "bits/DD_adjacent_unique.hpp"



#endif
