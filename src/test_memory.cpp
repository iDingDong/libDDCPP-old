#include "test_memory.h"
#include "test_object.hpp"

#include "standard/DDMemory.hpp"



void test_memory() {
	{
		/*{
			DD::StrictParasiticPointer<Test> ip_0(new DD::StrictParasitifer<Test>());
			if (
				ip_0.get_reference_count() != 1 ||
				ip_0->count != 1
			) {
				throw "'DD::StrictParasiticPointer' test failed.";
			}
			{
				auto ip_1 = DD::make_strict_parasitic<Test>();
				ip_0 = ip_1;
				if (
					ip_0.get_reference_count() != 2 ||
					ip_0->count != 1
				) {
					throw "'DD::StrictParasiticPointer' test failed.";
				}
			}
			if (
				ip_0.get_reference_count() != 1 ||
				ip_0->count != 1
			) {
				throw "'DD::StrictParasiticPointer' test failed.";
			}
		}
		if (Test::count != 0) {
			throw "'DD::StrictParasiticPointer' test failed.";
		}*/
	}
	{
		{
			DD::UniquePointer<Test[]> sp_1(new Test[3]);
		}
		if (Test::count != 0) {
			throw "'DD::StrictPointer' test failed.";
		}
	}
}
