#include "test_utility.h"
#define TEST_OBJECT_AUTO_PROMPT 0
#define DDCPP_DEBUG DD_ON
#include "test_object.hpp"
#include <iostream>
#include "standard/DDUtility.hpp"

class A {
};
class B : public A {
};

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
			if (variant_1.get_type() != typeid(Test)) {
				throw "DD::Variant test failed.";
			}
			variant_1 = 2;
			if (variant_1.to<int>() != 2) {
				throw "DD::Variant test failed.";
			}
			variant_1 = Test();
			Test tst = variant_1.to<Test>();
			variant_1 = 3.3;
			if (variant_1.to<double>() < 3.0) {
				throw "DD::Variant test failed.";
			}
		}
		if (Test::count != 0) {
			throw "DD::Variant test failed.";
		}
	}
}
