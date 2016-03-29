#include "test_concurrency.h"

#include "standard/DDHub.hpp"
#include "concurrency/DDThread.hpp"
#include "concurrency/DDMutex.hpp"

struct TestThreadsPublic {
	static int test_int;
};

int TestThreadsPublic::test_int = 0;

void test_thread() {
	TestThreadsPublic::test_int = 3;
}

void test_concurrency() {
	{
		DD::Thread thread_1(test_thread);
		thread_1.join();
		if (TestThreadsPublic::test_int != 3) {
			throw "'DD::Thread' test failed.";
		}
		TestThreadsPublic::test_int = 0;
	}
}
