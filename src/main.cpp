#include <iostream>

#define DDCPP_DEFAULT_WARNING 0

#include "standard/DDGlobal.hpp"

#include "standard/DDVessel.hpp"
#include "standard/DDList.hpp"
#include "standard/bits/DD_RedBlackTree.hpp"
#include "test_meta.h"
#include "test_memory.h"
#include "test_algorithm.h"
#include "test_utility.h"
#include "test_math.h"

int main() {
	try {
		test_meta();
		test_utility();
		test_memory();
		test_algorithm();
		test_math();
		std::cout << "All tests successfully operated.";
	} catch (char const* prompt) {
		std::cout << prompt;
	}
	std::cout << std::endl;
	return 0;
}
