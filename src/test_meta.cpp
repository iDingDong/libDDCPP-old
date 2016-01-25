#include "test_meta.h"
#include "test_object.hpp"
#include "standard/DDMeta.hpp"
#include "standard/DDTrait.hpp"
#include "standard/DDHub.hpp"
#include "standard/bits/DD_TypeInfo.hpp"

struct Big {
	void* t[2];
};

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
			!DD::IsSame<DD::ReadOnlyCallType<void*>, void*>::value ||
			DD::IsSame<DD::ReadOnlyCallType<Big>, Big>::value
		) {
			throw "'DD::ReadOnlyCall' test failed.";
		}
	}
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
