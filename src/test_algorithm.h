#ifndef _TEST_ALGORITHM_H_INCLUDED
#	define _TEST_ALGORITHM_H_INCLUDED 1



#	include <iostream>



template <typename ContainerT>
inline void print_container(ContainerT const& container) {
	for (auto& element : container) {
		std::cout << element << ", ";
	}
	std::cout << std::endl;
}


void test_algorithm();



#endif 
