#include "test_utility.h"
#define TEST_OBJECT_AUTO_PROMPT 0
#define DDCPP_DEBUG DD_ON
#include "test_object.hpp"
#include "standard/DDHub.hpp"

#include "standard/DDUtility.hpp"
#include "standard/DDArray.hpp"
#include "standard/DDVessel.hpp"
#include "standard/DDAlgorithm.hpp"

inline int func(int x, int y) {
	return x + y;
}

inline int overloaded(int x, int y) {
	return x + y;
}

inline int overloaded(int x, int y, int z) {
	return x + y + z;
}

class A {
	public:
	int func(int x, int y) const {
		return x - y;
	}

	public:
	int operator ()(int x, int y) const {
		return x * y;
	}

};
class B : public A {
};

void test_utility() {
	{
		DD::Pair<int, double> idp1(1, 3.3);
		DD::Pair<int, double> idp2(1, 4.1);
		if (idp1 > idp2) {
			throw "'DD::LessThanComparable' test failed.";
		}
	}
	{
		{
			DD::Variant<> variant_1((Test()));
			if (variant_1.get_type() != typeid(Test)) {
				throw "'DD::Variant' test failed.";
			}
			variant_1 = 2;
			if (variant_1.to<int>() != 2) {
				throw "'DD::Variant' test failed.";
			}
			variant_1 = Test();
			Test tst = variant_1.to<Test>();
			variant_1 = 3.3;
			if (variant_1.to<double>() < 3.0) {
				throw "'DD::Variant' test failed.";
			}
		}
		if (Test::count != 0) {
			throw "'DD::Variant' test failed.";
		}
	}
	{
		DD::Tuple<short, long> tuple_1(3, 2);
		DD::Tuple<short, short> tuple_2(3, 2);
		DD::Tuple<short, long, double> tuple_3(3, 2, 2.0);
		DD::Tuple<short> tuple_4(3);
		if (
			DD::get_value<0>(tuple_1) != 3 ||
			DD::get_value<1>(tuple_1) != 2
		) {
			throw "'DD::Tuple' test failed.";
		}
		if (
			&tuple_1.at<0>() != &DD::get_value<0>(tuple_1) ||
			&tuple_1.at<1>() != &DD::get_value<1>(tuple_1)
		) {
			throw "'DD::Tuple' test failed.";
		}
		if (
			DD::get_value<short>(tuple_1) != 3 ||
			DD::get_value<long>(tuple_1) != 2
		) {
			throw "'DD::Tuple' test failed.";
		}
		if (
			&tuple_1.get<short>() != &DD::get_value<short>(tuple_1) ||
			&tuple_1.get<long>() != &DD::get_value<long>(tuple_1)
		) {
			throw "'DD::Tuple' test failed.";
		}
		/*
		std::cout << (tuple_1 == tuple_3) << std::endl;
		if (
			!(tuple_1 == tuple_2) ||
			tuple_1 == tuple_3 ||
			tuple_1 == tuple_4
		) {
			throw "'DD::Tuple' test failed.";
		}
		*/
	}
	{
		using namespace ::DD::place_holder;
		auto testBinded_1 = DD::bind(func, _0_, 123);
		auto testBinded_2 = DD::bind(&A::func, _1_, 123, _0_);
		auto testBinded_3 = DD::bind(A(), 123, _0_);
		if (
			testBinded_1(111) != 111 + 123 ||
			testBinded_1(432) != 432 + 123 ||
			testBinded_2(100, A()) != 123 - 100 ||
			testBinded_2(200, A()) != 123 - 200 ||
			testBinded_3(222) != 123 * 222 ||
			testBinded_3(321) != 123 * 321
		) {
			throw "'DD::bind' test failed.";
		}
	}
	{
		DD::Function<int(int, int)> test_func_1 = func;
		if (
			test_func_1(123, 321) != 123 + 321 ||
			test_func_1(345, 432) != 345 + 432
		) {
			throw "'DD::Function' test failed.";
		}
		DD::Function<int(int, int)> test_func_2 = overloaded;
		DD::Function<int(int, int, int)> test_func_3 = overloaded;
		if (
			test_func_2(123, 234) != 123 + 234 ||
			test_func_3(123, 234, 345) != 123 + 234 + 345
		) {
			throw "'DD::Function' test failed.";
		}
		DD::Function<int(int, int)> test_func_4 = A();
		if (
			test_func_4(123, 234) != 123 * 234
		) {
			throw "'DD::Function' test failed.";
		}
		DD::Function<int(int, int)> test_func_5 = [](int x, int y) { return x - y; };
		if (
			test_func_5(123, 234) != 123 - 234
		) {
			throw "'DD::Function' test failed.";
		}
		DD::Function<int(int, int)> test_copy = test_func_1;
	}
	{
		DD::Vessel<int> ves = { 1, 3, 4, 5, 6, 7, 18, 15 };
		DD::Predicate<bool(int)> is_even = [](int a) { return a % 2 == 0; };
		DD::Predicate<bool(int)> is_exactly_divided_by_3 = [](int a) { return a % 3 == 0; };
		DD::Predicate<bool(int)> is_exactly_divided_by_6 = [](int a) { return a % 6 == 0; };

		if (
			DD::count_if(ves, is_even) != 3 ||
			DD::count_if(ves, is_even && is_exactly_divided_by_3) != DD::count_if(ves, is_exactly_divided_by_6)
		) {
			throw "'DD::Predicate' test failed.";
		}

	}
}
