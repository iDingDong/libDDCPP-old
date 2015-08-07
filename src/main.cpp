#include <iostream>
#include "standard/DDAlgorithm.hpp"
#include "test_memory.h"
#include "test_algorithm.h"

bool greater(int x, int y) {
	return y < x;
}

int main() {
#if 1
	test_memory();
#endif
#if 0 
	test_algorithm();
#endif
#if 0
	using DD::min;
	using DD::max;
	using DD::min_max;
	std::cout << min(1, 5, 3, 7, -2, 4) << std::endl;
	std::cout << min(1, 5, 3, 7, -2, 4, greater) << std::endl;
	std::cout << max(1, 5, 3, 7, -2, 4) << std::endl;
	std::cout << max(1, 5, 3, 7, -2, 4, greater) << std::endl;
	auto mm1 = min_max(1, 5, 3, 7, -2, 4);
	std::cout << mm1.first << ", " << mm1.second << std::endl;
	auto mm2 = min_max(1, 5, 3, 7, -2, 4, greater);
	std::cout << mm2.first << ", " << mm2.second << std::endl;
	return 0;
#endif
}
