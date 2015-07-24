#include "test_memory.h"
#define TEST_OBJECT_AUTO_PROMPT 1
#include "test_object.hpp"
#include <iostream>

#include "standard/DDMemory.hpp"



void test_memory() {
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
