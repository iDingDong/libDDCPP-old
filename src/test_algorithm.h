#ifndef TEST_ALGORITHM_H_INCLUDED_
#	define TEST_ALGORITHM_H_INCLUDED_ 1



#	include "standard/bits/DD_print.hpp"



template <typename ContainerT>
inline void print_container(ContainerT const& container) {
	for (auto& element : container) {
		DD_PRINT element, ", ";
	}
	DD_PRINT DD::end_line;
}


void test_algorithm();



#endif
