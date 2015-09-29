#include "test_memory.h"
#include "test_object.hpp"
#include <iostream>
#include <thread>
#include <mutex>

#include "standard/DDMemory.hpp"



std::mutex g_mutex;
//DD::ParasiticPointer<Test> g_ip(DD::construct_tag);


/*
void th1_main() {
	while (true) {
		std::cout << "out: " << g_ip.get_reference_count() << std::endl;
		{
			//std::lock_guard<std::mutex> lock(g_mutex);
			auto ip_0 = g_ip;
			std::cout << "in: " << g_ip.get_reference_count() << std::endl;
		}
		std::cout << "end: " << g_ip.get_reference_count() << std::endl;
	}
}
*/


void test_memory() {
	{
		{
			DD::ParasiticPointer<Test> ip_0(DD::construct_tag);
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
}
