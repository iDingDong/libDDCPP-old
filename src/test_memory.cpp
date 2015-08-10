#include "test_memory.h"
#define TEST_OBJECT_AUTO_PROMPT 1
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
#if 0 
	{
		DD::ParasiticPointer<Test> ip_0(DD::construct_tag);
		{
			std::cout << "Into block." << std::endl;
			auto ip_1 = DD::make_parasitic<Test>();
			ip_0 = ip_1;
			std::cout << "End of block." << std::endl;
		}
		std::cout << "Out of block." << std::endl;
		std::cout << "End Sign." << std::endl;
	}
#endif
#if 0
	{
		std::thread th1(th1_main);
		th1.detach();
		for (unsigned n = 10; n; -- n) {
			std::cout << "main out: " << g_ip.get_reference_count() << std::endl;
			{
				//std::lock_guard<std::mutex> lock(g_mutex);
				auto ip_0 = g_ip;
				std::cout << "main in: " << g_ip.get_reference_count() << std::endl;
			}
			std::cout << "main end: " << g_ip.get_reference_count() << std::endl;
		}
	}
#endif
}
