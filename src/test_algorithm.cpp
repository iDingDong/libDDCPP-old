#include "test_algorithm.h"

#include <ctime>
#include <cstdlib>
#include <algorithm>

#include "standard/DDHub.hpp"

#include "standard/DDArray.hpp"
#include "standard/DDVessel.hpp"
#include "standard/DDUtility.hpp"
#include "standard/DDAlgorithm.hpp"

#define SPEED_TEST DD_ON

template <typename T>
bool greater(T x, T y) {
	return y < x;
}

void test_algorithm() {
	DD::Array<int, 5> arr1 = { 5, 3, 2, 4, 1 };
	DD::Array<int, 5> arr2 = { 1, 4, 5, 3, 2 };
	DD::Array<int, 5> sorted_arr = { 1, 2, 3, 4, 5 };
	DD::Array<int, 5> rsorted_arr = { 5, 4, 3, 2, 1 };
	DD::Array<int, 3> arr3 = { 6, 7, 5 };
	DD_IGNORE_UNUSED arr1, arr2, sorted_arr, rsorted_arr, arr3;
	{
		int right_result[5] = { 5, 3, 2, 4, 1 };
		int wrong_result[5] = { 2, 4, 1, 5, 3 };
		if (
			!DD::equal(arr1, right_result) ||
			DD::equal(arr1, wrong_result)
		) {
			throw "'DD::equal' test failed.";
		}
	}
	{
		using DD::min;
		using DD::max;
		using DD::min_max;
		auto mm1 = min_max(1, 5, 3, 7, -2, 4);
		auto mm2 = min_max(1, 5, 3, 7, -2, 4, greater<int>);
		if (
			min(1, 5, 3, 7, -2, 4) != -2 ||
			min(1, 5, 3, 7, -2, 4, greater<int>) != 7 ||
			max(1, 5, 3, 7, -2, 4) != 7 ||
			max(1, 5, 3, 7, -2, 4, greater<int>) != -2 ||
			mm1.first != -2 ||
			mm1.second != 7 ||
			mm2.first != 7 ||
			mm2.second != -2
		) {
			throw "DD::min/DD::max/DD::min_max test failed.";
		}
	}
	{
		DD::Array<int, 5> temp = arr1;
		DD::reverse(temp);
		int result[5] = { 1, 4, 2, 3, 5 };
		if (!DD::equal(temp, result)) {
			throw "'DD::reverse' test failed.";
		}
	}
	{
		if (
			DD::find(arr1, 1) != std::find(DD_SPLIT_RANGE(arr1), 1) ||
			DD::find(arr1, 2) != std::find(DD_SPLIT_RANGE(arr1), 2) ||
			DD::find(arr1, 3) != std::find(DD_SPLIT_RANGE(arr1), 3) ||
			DD::find(arr1, 4) != std::find(DD_SPLIT_RANGE(arr1), 4) ||
			DD::find(arr1, 5) != std::find(DD_SPLIT_RANGE(arr1), 5)
		) {
			throw "'DD::find' test failed.";
		}
	}
	{
		if (
			DD::find_not(arr1, 1) != std::find_if(DD_SPLIT_RANGE(arr1), [](int x) { return x != 1; }) ||
			DD::find_not(arr1, 2) != std::find_if(DD_SPLIT_RANGE(arr1), [](int x) { return x != 2; }) ||
			DD::find_not(arr1, 3) != std::find_if(DD_SPLIT_RANGE(arr1), [](int x) { return x != 3; }) ||
			DD::find_not(arr1, 4) != std::find_if(DD_SPLIT_RANGE(arr1), [](int x) { return x != 4; }) ||
			DD::find_not(arr1, 5) != std::find_if(DD_SPLIT_RANGE(arr1), [](int x) { return x != 5; })
		) {
			throw "'DD::find_not' test failed.";
		}
	}
	{
		auto f1 = [](int x) { return x > 3; };
		auto f2 = [](int x) { return x == 2; };
		auto f3 = [](int x) { return x < 1; };
		if (
			DD::find_if(arr1, f1) != std::find_if(DD_SPLIT_RANGE(arr1), f1) ||
			DD::find_if(arr1, f2) != std::find_if(DD_SPLIT_RANGE(arr1), f2) ||
			DD::find_if(arr1, f3) != std::find_if(DD_SPLIT_RANGE(arr1), f3)
		) {
			throw "'DD::find_if' test failed.";
		}
	}
	{
		auto f1 = [](int x) { return x > 3; };
		auto f2 = [](int x) { return x == 2; };
		auto f3 = [](int x) { return x < 1; };
		if (
			DD::find_if_not(arr1, f1) != std::find_if_not(DD_SPLIT_RANGE(arr1), f1) ||
			DD::find_if_not(arr1, f2) != std::find_if_not(DD_SPLIT_RANGE(arr1), f2) ||
			DD::find_if_not(arr1, f3) != std::find_if_not(DD_SPLIT_RANGE(arr1), f3)
		) {
			throw "'DD::find_if_not' test failed.";
		}
	}
	{
		if (
			DD::find_first_of(arr1, arr3) != std::find_first_of(DD_SPLIT_RANGE(arr1), DD_SPLIT_RANGE(arr3))
		) {
			throw "'DD::find_first_of' test failed.";
		}
	}
	{
		DD::Array<int, 5> arr = { 1, 2, 5, 17, 29 };
		if (
			DD::binary_find(arr, 1) != DD::find(arr, 1) ||
			DD::binary_find(arr, 2) != DD::find(arr, 2) ||
			DD::binary_find(arr, 5) != DD::find(arr, 5) ||
			DD::binary_find(arr, 17) != DD::find(arr, 17) ||
			DD::binary_find(arr, 29) != DD::find(arr, 29) ||
			DD::binary_find(arr, 14) != DD::find(arr, 14)
		) {
			throw "'DD::binary_find' test failed.";
		}
	}
	{
		DD::Array<int, 5> temp1 = arr1;
		DD::Array<int, 5> temp2 = arr1;
		int result_1[5] = { 1, 2, 3, 4, 5 };
		int result_2[5] = { 5, 4, 3, 2, 1 };
		DD::insert_sort(temp1);
		DD::insert_sort(temp2, greater<int>);
		if (
			!DD::equal(temp1, result_1) &&
			!DD::equal(temp2, result_2)
		) {
			throw "'DD::insert_sort' test failed.";
		}
	}
	{
		DD::Array<int, 23> text = { 3, 2, 3, 4, 1, 5, 3, 2, 4, 2, 4, 1, 2, 5, 3, 2, 4, 3, 2, 1, 4, 6, 3 };
		DD::Array<int, 6> pattern = { 3, 2, 4, 3, 2, 1 };
		if (
			DD::find_range(text, pattern) != std::search(DD_SPLIT_RANGE(text), DD_SPLIT_RANGE(pattern))
		) {
			throw "'DD::find_range' test failed.";
		}
	}
	{
		DD::Array<int, 5> temp = { 0, 0, 0, 0, 0 };
		{
			DD::fill(temp, 1);
			DD::Array<int, 5> result_1 = { 1, 1, 1, 1, 1 };
			if (
				!DD::equal(temp, result_1)
			) {
				throw "'DD::fill' test failed.";
			}
			DD::fill(temp.begin() + 1, temp.end(), 2);
			DD::Array<int, 5> result_2 = { 1, 2, 2, 2, 2 };
			if (
				!DD::equal(temp, result_2)
			) {
				throw "'DD::fill' test failed.";
			}
			DD::fill(temp.begin() + 1, temp.end() - 1, 3);
			DD::Array<int, 5> result_3 = { 1, 3, 3, 3, 2 };
			if (
				!DD::equal(temp, result_3)
			) {
				throw "'DD::fill' test failed.";
			}
		}
		{
			DD::replace(temp, 3, 0);
			DD::Array<int, 5> result_1 = { 1, 0, 0, 0, 2 };
			if (
				!DD::equal(temp, result_1)
			) {
				throw "'DD::replace' test failed.";
			}
			DD::replace(temp, 1, [](int a, int b) { return b <= a; }, 3);
			DD::Array<int, 5> result_2 = { 3, 0, 0, 0, 3 };
			if (
				!DD::equal(temp, result_2)
			) {
				throw "'DD::replace' test failed.";
			}
		}
		{
			DD::replace_if(temp, [](int a) { return a == 0; }, 1);
			DD::Array<int, 5> result = { 3, 1, 1, 1, 3 };
			if (
				!DD::equal(temp, result)
			) {
				throw "'DD::replace_if' test failed.";
			}
		}
		{
			if (
				DD::count(temp, 1) != 3 ||
				DD::count(temp, 2) != 0 ||
				DD::count(temp, 3) != 2
			) {
				throw "'DD::count' test failed.";
			}
			if (
				DD::count(temp, 1, [](int a, int b) { return a != b; }) != 2 ||
				DD::count(temp, 2, [](int a, int b) { return a != b; }) != 5 ||
				DD::count(temp, 3, [](int a, int b) { return a != b; }) != 3
			) {
				throw "'DD::count' test failed.";
			}
		}
		{
			if (
				DD::count_if(temp, [](int a) { return a == 1; }) != 3 ||
				DD::count_if(temp, [](int a) { return a == 2; }) != 0 ||
				DD::count_if(temp, [](int a) { return a == 3; }) != 2
			) {
				throw "'DD::count_if' test failed.";
			}
		}
	}
	{
		DD::Array<int, 5> temp_1 = { 1, 2, 3, 4, 5 };
		DD::Array<int, 5> temp_2 = { 231, 12, 4, 3, -2 };
		if (
			DD::is_sorted(arr1) ||
			!DD::is_sorted(temp_1)
		) {
			throw "'DD::is_sorted' test failed.";
		}
		if (
			DD::is_sorted(arr1, [](int a, int b) { return b < a; }) ||
			!DD::is_sorted(temp_2, [](int a, int b) { return b < a; })
		) {
			throw "'DD::is_sorted' test failed.";
		}
	}
	{
		DD::Array<int, 5> temp = { 0, 0, 1, 2, 2 };
		DD::Array<int, 3> result = { 0, 1, 2 };
		auto result_point = DD::adjacent_unique(temp);
		auto result_range = DD::make_range(temp.begin(), result_point);
		if (
			result_range.get_length() != result.get_length() ||
			!DD::equal(result_range, result)
		) {
			throw  "'DD::adjacent_unique' test failed.";
		}
	}
	{
		DD::Array<int, 13> temp = { 0, 0, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
		DD::Array<int, 3> result_1 = { 4, 4, 4 };
		DD::Array<int, 0> result_2;
		if (
			!DD::equal(find_lower_bound(temp, 4), find_higher_bound(temp, 4), DD_SPLIT_RANGE(result_1)) ||
			!DD::equal(find_lower_bound(temp, 1), find_higher_bound(temp, 1), DD_SPLIT_RANGE(result_2)) ||
			find_bounds(temp, 4).begin() != find_lower_bound(temp, 4) ||
			find_bounds(temp, 1).begin() != find_lower_bound(temp, 1) ||
			find_bounds(temp, 4).end() != find_higher_bound(temp, 4) ||
			find_bounds(temp, 1).end() != find_higher_bound(temp, 1)
		) {
			throw "'DD::find_lower_bound'/'DD::find_higher_bound' test failed.";
		}
	}
	{
		DD::Array<int, 5> temp_1 = arr1;
		DD::Array<int, 5> temp_2 = arr2;
		DD::bubble_sort(temp_1);
		DD::bubble_sort(temp_2);
		if (
			!equal(temp_1, sorted_arr) ||
			!equal(temp_2, sorted_arr)
		) {
			throw "'DD::bubble_sort' test failed.";
		}
	}
	{
		DD::Array<int, 5> temp_1 = arr1;
		DD::Array<int, 5> temp_2 = arr2;
		DD::insert_sort(temp_1);
		DD::insert_sort(temp_2);
		if (
			!equal(temp_1, sorted_arr) ||
			!equal(temp_2, sorted_arr)
		) {
			throw "'DD::insert_sort' test failed.";
		}
	}
	{
		DD::Array<int, 5> temp_1 = arr1;
		DD::Array<int, 5> temp_2 = arr2;
		DD::select_sort(temp_1);
		DD::select_sort(temp_2);
		if (
			!equal(temp_1, sorted_arr) ||
			!equal(temp_2, sorted_arr)
		) {
			throw "'DD::select_sort' test failed.";
		}
	}
	{
		DD::Array<int, 5> temp_1 = arr1;
		DD::Array<int, 5> temp_2 = arr2;
		DD::quick_sort(temp_1);
		DD::quick_sort(temp_2);
		if (
			!equal(temp_1, sorted_arr) ||
			!equal(temp_2, sorted_arr)
		) {
			throw "'DD::quick_sort' test failed.";
		}
	}
	{
		DD::Array<int, 5> temp_1 = arr1;
		DD::Array<int, 5> temp_2 = arr2;
		DD::heap_sort(temp_1);
		DD::heap_sort(temp_2);
		if (
			!equal(temp_1, sorted_arr) ||
			!equal(temp_2, sorted_arr)
		) {
			throw "'DD::heap_sort' test failed.";
		}
	}
	{
		DD::Array<int, 5> temp_1 = arr1;
		DD::Array<int, 5> temp_2 = arr2;
		DD::sort(temp_1);
		DD::sort(temp_2);
		if (
			!equal(temp_1, sorted_arr) ||
			!equal(temp_2, sorted_arr)
		) {
			throw "'DD::sort' test failed.";
		}
	}
#	if SPEED_TEST
	{
		DD::LengthType constexpr length_c = 100000000;
		DD::Vessel<unsigned char> test_sort_1(length_c);
		std::srand(static_cast<unsigned>(std::time(DD::nil_pointer)));
		DD::generate(test_sort_1, [] { return static_cast<unsigned char>(std::rand() % 256); });
		auto test_sort_2 = test_sort_1;
		std::time_t start;
		std::time_t finish;

		time(&start);
		DD::sort(test_sort_1);
		time(&finish);
		DD_PRINT "'DD::sort': ", std::difftime(finish, start), DD::end_line;

		time(&start);
		std::sort(DD_SPLIT_RANGE(test_sort_2));
		time(&finish);
		DD_PRINT "'std::sort': ", std::difftime(finish, start), DD::end_line;

	}
#	endif
}
