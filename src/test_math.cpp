#include "test_math.h"

#include <iostream>

#include "math/DDArithmetics.hpp"
#include "math/DDMatrix.hpp"

void test_math() {
	{
		if (
			DD::square_root<int>(4) != 2 ||
			DD::square_root<int>(15) != 3
		) {
			throw "DD::square_root test failed.";
		}
	}
}
