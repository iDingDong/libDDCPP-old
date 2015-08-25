#include <iostream>
#include "standard/DDAlgorithm.hpp"
#include "test_meta.h"
#include "test_memory.h"
#include "test_algorithm.h"
#include "test_utility.h"
#include "test_math.h"

bool greater(int x, int y) {
	return y < x;
}

int main() {
	try {
#if 0
		test_memory();
#endif
#if 0
		test_algorithm();
#endif
#if 1
		test_meta();
		test_utility();
		test_math();
		{
			using DD::min;
			using DD::max;
			using DD::min_max;
			auto mm1 = min_max(1, 5, 3, 7, -2, 4);
			auto mm2 = min_max(1, 5, 3, 7, -2, 4, greater);
			if (min(1, 5, 3, 7, -2, 4) != -2 ||
				min(1, 5, 3, 7, -2, 4, greater) != 7 ||
				max(1, 5, 3, 7, -2, 4) != 7 ||
				max(1, 5, 3, 7, -2, 4, greater) != -2 ||
				mm1.first != -2 ||
				mm1.second != 7 ||
				mm2.first != 7 ||
				mm2.second != -2) {
				throw "DD::min/DD::max/DD::min_max test failed.";
			}
		}
#endif
		std::cout << "All tests successfully operated.";
	} catch (char const* prompt) {
		std::cout << prompt;
	}
	std::cout << std::endl;
	return 0;
}
