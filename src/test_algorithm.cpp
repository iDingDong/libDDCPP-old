#include "test_algorithm.h"
#include "standard/DDArray.hpp"
#include "standard/DDAlgorithm.hpp"



void test_algorithm() {
	DD::Array<int, 5> arr1 = {5, 3, 2, 4, 1};
	DD::reverse(arr1.begin(), arr1.end());
	print_container(arr1);
	std::cout << DD::is_sorted(arr1.begin(), arr1.end()) << std::endl;
	std::cout << DD::is_sorted_until(arr1.begin(), arr1.end()) - arr1.begin() << std::endl;
	DD::insert_sort(arr1.begin(), arr1.end());
	print_container(arr1);
	std::cout << DD::is_sorted(arr1.begin(), arr1.end()) << std::endl;
	std::cout << DD::is_sorted_until(arr1.begin(), arr1.end()) - arr1.begin() << std::endl;
}
