#include <iostream>
#include <array>
#include <algorithm>
#include "standard/DDArray.hpp"
#include "standard/DDAlgorithm.hpp"

template <typename ContainerT>
void print(ContainerT const& container) {
	for (auto& element : container) {
		std::cout << element << ", ";
	}
	std::cout << std::endl;
}

int main() {
	DD::Array<int, 9> arr0 = {4, 2, 6, 7, 3, 5, 1, 8, 9};
	std::array<int, 4> stdArr0 = {7, 5, 8, 6};
	
#if 0
	std::cout << *DD::partition(arr0.begin(), arr0.end(), 7) << std::endl;
	print(arr0);
	std::cout << std::endl;
	std::cout << *DD::partition_by(arr0.begin(), arr0.end(), [](int a) { return a >= 5; }) << std::endl;
	print(arr0);
#endif
	
#if 0
	DD::fill(arr0.begin(), arr0.end(), arr0[2]);
	print(arr0);
#endif
	
#if 0
	int i = 1;
	DD::generate(arr0.begin(), arr0.end(), [&i]() { return ++i; });
	print(arr0);
#endif
	
#if 0
	std::cout << DD::count(arr0.begin(), arr0.end(), 3, [](int a, int b) { return a != b; }) << std::endl;
	print(arr0);
	DD::replace(arr0.begin(), arr0.end(), 3, [](int a, int b) { return a != b; }, 7);
	print(arr0);
#endif

#if 1
	std::cout << *DD::find_first_of(arr0.begin(), arr0.end(), stdArr0.begin(), stdArr0.end()) << std::endl;
	std::cout << *DD::find_first_of(arr0.begin(), arr0.end(), stdArr0.begin(), stdArr0.end(), [](int a, int b) { return a > b + 1; }) << std::endl;
#endif
	
	return 0;
}