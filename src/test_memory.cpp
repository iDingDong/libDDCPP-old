#include "test_memory.h"
#include "test_object.hpp"

#include "standard/DDMemory.hpp"


struct DefaultIntrusiveTest : DD::Intrusive<> {
	static DD::LengthType count;
	DefaultIntrusiveTest() { ++count; }
	DefaultIntrusiveTest(DefaultIntrusiveTest const&) { ++count; }
	~DefaultIntrusiveTest() { --count; }
};

DD::LengthType DefaultIntrusiveTest::count = 0;

struct IntrusiveTest {
	DD::LengthType ref_count;
	static DD::LengthType count;
	IntrusiveTest() : ref_count(0) { ++count; }
	IntrusiveTest(IntrusiveTest const&) : ref_count(0) { ++count; }
	~IntrusiveTest() { --count; }
};

void refer_intrusived(IntrusiveTest* ptr) {
	++ptr->ref_count;
}

void release_intrusived(IntrusiveTest* ptr) {
	--ptr->ref_count;
}

DD::LengthType get_intrusived_reference_count(IntrusiveTest* ptr) {
	return ptr->ref_count;
}

void destroy_intrusived(IntrusiveTest* ptr) {
	delete ptr;
}

DD::LengthType IntrusiveTest::count = 0;

void test_memory() {
	{
		{
			DD::ParasiticPointer<Test> pp_0(new DD::Parasitifer<Test>());
			if (
				pp_0.get_reference_count() != 1 ||
				pp_0->count != 1
			) {
				throw "'DD::ParasiticPointer' test failed.";
			}
			{
				auto pp_1 = DD::make_parasitic<Test>();
				pp_0 = pp_1;
				if (
					pp_0.get_reference_count() != 2 ||
					pp_0->count != 1
				) {
					throw "'DD::ParasiticPointer' test failed.";
				}
			}
			if (
				pp_0.get_reference_count() != 1 ||
				pp_0->count != 1
			) {
				throw "'DD::ParasiticPointer' test failed.";
			}
		}
		if (Test::count != 0) {
			throw "'DD::ParasiticPointer' test failed.";
		}
	}
	{
		{
			DD::UniquePointer<Test> up_0 = DD::make_unique<Test>();
			if (Test::count != 1) {
				throw "'DD::UniquePointer' test failed.";
			}
			DD::UniquePointer<Test[]> up_1(new Test[3]);
			if (Test::count != 4) {
				throw "'DD::UniquePointer' test failed.";
			}
		}
		if (Test::count != 0) {
			throw "'DD::UniquePointer' test failed.";
		}
	}
	{
		{
			DD::IntrusivePointer<IntrusiveTest> ip_0 = new IntrusiveTest();
			if (
				ip_0.get_reference_count() != 1 ||
				IntrusiveTest::count != 1
			) {
				throw "'DD::IntrusivePointer' test failed.";
			}
			{
				DD::IntrusivePointer<IntrusiveTest> ip_1 = new IntrusiveTest();
				if (
					ip_0.get_reference_count() != 1 ||
					IntrusiveTest::count != 2
				) {
					throw "'DD::IntrusivePointer' test failed.";
				}

				ip_0 = ip_1;
				if (
					ip_0.get_reference_count() != 2 ||
					ip_0.get_reference_count() != 2 ||
					IntrusiveTest::count != 1
				) {
					throw "'DD::IntrusivePointer' test failed.";
				}
			}
			if (
				ip_0.get_reference_count() != 1 ||
				IntrusiveTest::count != 1
			) {
				throw "'DD::IntrusivePointer' test failed.";
			}
		}
		if (IntrusiveTest::count != 0) {
			throw "'DD::IntrusivePointer' test failed.";
		}

		{
			DD::IntrusivePointer<DefaultIntrusiveTest> ip_0 = new DefaultIntrusiveTest();
			if (
				ip_0.get_reference_count() != 1 ||
				DefaultIntrusiveTest::count != 1
			) {
				throw "'DD::IntrusivePointer' test failed.";
			}
			{
				DD::IntrusivePointer<DefaultIntrusiveTest> ip_1 = new DefaultIntrusiveTest();
				if (
					ip_0.get_reference_count() != 1 ||
					DefaultIntrusiveTest::count != 2
				) {
					throw "'DD::IntrusivePointer' test failed.";
				}

				ip_0 = ip_1;
				if (
					ip_0.get_reference_count() != 2 ||
					ip_0.get_reference_count() != 2 ||
					DefaultIntrusiveTest::count != 1
				) {
					throw "'DD::IntrusivePointer' test failed.";
				}
			}
			if (
				ip_0.get_reference_count() != 1 ||
				DefaultIntrusiveTest::count != 1
			) {
				throw "'DD::IntrusivePointer' test failed.";
			}
		}
		if (DefaultIntrusiveTest::count != 0) {
			throw "'DD::IntrusivePointer' test failed.";
		}

		{
			DD::IntrusivePointer<IntrusiveTest> ip_0 = new IntrusiveTest();
			if (
				ip_0.get_reference_count() != 1 ||
				IntrusiveTest::count != 1
			) {
				throw "'DD::IntrusivePointer' test failed.";
			}
			{
				DD::IntrusivePointer<IntrusiveTest> ip_1 = new IntrusiveTest();
				if (
					ip_0.get_reference_count() != 1 ||
					IntrusiveTest::count != 2
				) {
					throw "'DD::IntrusivePointer' test failed.";
				}

				ip_0 = ip_1;
				if (
					ip_0.get_reference_count() != 2 ||
					ip_0.get_reference_count() != 2 ||
					IntrusiveTest::count != 1
				) {
					throw "'DD::IntrusivePointer' test failed.";
				}
			}
			if (
				ip_0.get_reference_count() != 1 ||
				IntrusiveTest::count != 1
			) {
				throw "'DD::IntrusivePointer' test failed.";
			}
		}
		if (IntrusiveTest::count != 0) {
			throw "'DD::IntrusivePointer' test failed.";
		}

		{
			DD::IntrusivePointer<DD::Parasitifer<Test> > ip_0 = DD::make_parasitic<Test>().get_parasitifer_pointer();
			if (
				ip_0.get_reference_count() != 1 ||
				Test::count != 1
			) {
				throw "'DD::IntrusivePointer' test failed.";
			}
			{
				DD::IntrusivePointer<DD::Parasitifer<Test> > ip_1 = DD::make_parasitic<Test>().get_parasitifer_pointer();
				if (
					ip_0.get_reference_count() != 1 ||
					Test::count != 2
				) {
					throw "'DD::IntrusivePointer' test failed.";
				}

				ip_0 = ip_1;
				if (
					ip_0.get_reference_count() != 2 ||
					ip_0.get_reference_count() != 2 ||
					Test::count != 1
				) {
					throw "'DD::IntrusivePointer' test failed.";
				}
			}
			if (
				ip_0.get_reference_count() != 1 ||
				Test::count != 1
			) {
				throw "'DD::IntrusivePointer' test failed.";
			}
		}
		if (Test::count != 0) {
			throw "'DD::IntrusivePointer' test failed.";
		}
	}
}
