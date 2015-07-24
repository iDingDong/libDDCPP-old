#include <iostream>
#include "standard/DDTrait.hpp"
#include "standard/DDArray.hpp"
#include "standard/DDAlgorithm.hpp"

bool greater(int a, int b) {
	return b < a;
}

template <typename T, typename... Ts>
void func(T const&, Ts&&...) {}

template <typename T, typename T_>
T const& fun1(T const& a, T const&, T_ const&) {
	std::cout << "1" << std::endl;
	return a;
}
template <typename T, typename... Ts>
T const& fun1(T const& a, T const& b, Ts const&... c) {
	std::cout << "2" << std::endl;
	return fun1(a, b, DD::get_last_argument(c...));
}

int main() {
	
	/*
	DD::Array<unsigned, 5> arr1 = {1, 7, 3, 5, 4};
	DD::Array<unsigned, 5> arr2 = {1, 7, 3, 4, 4};
	std::cout << DD::equal(arr1.begin(), arr1.end(), arr2.begin()) << std::endl;
	std::cout << DD::mismatch(arr1.begin(), arr1.end(), arr2.begin(), arr2.end()).first - arr1.begin() << std::endl;
	*/
	int i = 5;
	//auto const& a = greater;
	//fun1(1, 4, 3, a);
	//func(1, 2, 3);
	//std::cout << DD::get_last_argument(1, 4, 3) << std::endl;
	std::cout << DD::max(1, 4, 7, 5, 3) << std::endl;
	return 0;
}