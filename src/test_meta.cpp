#include "test_meta.h"
#include "standard/DDMeta.hpp"
#include "standard/DDTrait.hpp"

struct TestPositive {
	struct Positive;
	void positive();
};

struct TestNegative {
	struct Negative;
};

DD_NESTED_TYPE_CHECK(HasTypePositive, Positive)
DD_NESTED_TYPE_TRAIT(GetTypePositive, Positive, TestNegative::Negative)
DD_MEMBER_FUNCTION_CHECK(HasFunctionPositive, positive, void, )

void test_meta() {
	{
		if (
			!HasTypePositive<TestPositive>::value ||
			HasTypePositive<TestNegative>::value
		) {
			throw "'DD_NESTED_TYPE_CHECK' test failed.";
		}
		if (
			!DD::IsSame<typename GetTypePositive<TestPositive>::Type, TestPositive::Positive>::value ||
			DD::IsSame<typename GetTypePositive<TestNegative>::Type, TestPositive::Positive>::value ||
			!DD::IsSame<typename GetTypePositive<TestNegative>::Type, TestNegative::Negative>::value
		) {
			throw "'DD_NESTED_TYPE_TRAIT' test failed.";
		}
		if (
			!HasFunctionPositive<TestPositive>::value ||
			HasFunctionPositive<TestNegative>::value
		) {
			throw "'DD_MEMBER_FUNCTION_CHECK' test failed.";
		}
	}
}
