#include "test_memory.h"
#include "test_object.hpp"

#include "standard/DDMemory.hpp"



void test_memory() {
	{
		{
			DD::ParasiticPointer<Test> ip_0(new DD::Parasitifer<Test>());
			if (
				ip_0.get_reference_count() != 1 ||
				ip_0->count != 1
			) {
				throw "'DD::ParasiticPointer' test failed.";
			}
			{
				auto ip_1 = DD::make_parasitic<Test>();
				ip_0 = ip_1;
				if (
					ip_0.get_reference_count() != 2 ||
					ip_0->count != 1
				) {
					throw "'DD::ParasiticPointer' test failed.";
				}
			}
			if (
				ip_0.get_reference_count() != 1 ||
				ip_0->count != 1
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
			DD::UniquePointer<Test[]> sp_1(new Test[3]);
			if (Test::count != 3) {
				throw "'DD::UniquePointer' test failed.";
			}
		}
		if (Test::count != 0) {
			throw "'DD::UniquePointer' test failed.";
		}
	}
}
