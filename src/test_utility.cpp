#include "test_utility.h"
#define TEST_OBJECT_AUTO_PROMPT 0
#include "test_object.hpp"
#include <iostream>
#include "standard/DDUtility.hpp"

void test_utility() {
	{
		DD::Pair<int, double> idp1(1, 3.3);
		DD::Pair<int, double> idp2(1, 4.1);
		if (idp1 > idp2) {
			throw "DD::LessThanComparable test failed.";
		}
	}
	{
		{
			DD::Variant variant_1((Test()));
			variant_1 = 2;
			if (variant_1.to<int>() != 2) {
				throw "DD::Variant test failed.";
			}
			variant_1 = Test();
		}
		if (Test::count != 0) {
			throw "DD::Variant test failed.";
		}
	}
}
