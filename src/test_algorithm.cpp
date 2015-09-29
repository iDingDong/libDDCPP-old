#include "test_algorithm.h"

#include <algorithm>

#include "standard/DDArray.hpp"
#include "standard/DDUtility.hpp"
#include "standard/DDAlgorithm.hpp"

template <typename T>
bool greater(T x, T y) {
	return y < x;
}

void test_algorithm() {
	DD::Array<int, 5> arr1 = {5, 3, 2, 4, 1};
	DD::Array<int, 5> arr2 = {1, 4, 5, 3, 2};
	DD::Array<int, 3> arr3 = {6, 7, 5};
	DD_IGNORE_UNUSED arr1, arr2, arr3;
	{
		int right_result[5] = {5, 3, 2, 4, 1};
		int wrong_result[5] = {2, 4, 1, 5, 3};
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
		int result[5] = {1, 4, 2, 3, 5};
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
		DD::Array<int, 5> temp1 = arr1;
		DD::Array<int, 5> temp2 = arr1;
		int result_1[5] = {1, 2, 3, 4, 5};
		int result_2[5] = {5, 4, 3, 2, 1};
		DD::insert_sort(temp1);
		DD::insert_sort(temp2, greater<int>);
		if (
			!DD::equal(temp1, result_1) &&
			!DD::equal(temp2, result_2)
		) {
			throw "'DD::insert_sort' test failed.";
		}
	}


	/*
	std::cout << DD::is_sorted(arr1.begin(), arr1.end()) << std::endl;
	std::cout << DD::is_sorted_until(arr1.begin(), arr1.end()) - arr1.begin() << std::endl;
	DD::insert_sort(arr1.begin(), arr1.end());
	print_container(arr1);
	std::cout << DD::is_sorted(arr1.begin(), arr1.end()) << std::endl;
	std::cout << DD::is_sorted_until(arr1.begin(), arr1.end()) - arr1.begin() << std::endl;
	*/
}
