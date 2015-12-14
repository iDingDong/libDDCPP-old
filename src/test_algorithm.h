#ifndef TEST_ALGORITHM_H_INCLUDED_
#	define TEST_ALGORITHM_H_INCLUDED_ 1



#	include "standard/DDIterator.hpp"
#	include "standard/DDUtility.hpp"
#	include "standard/DDHub.hpp"



template <typename ContainerT>
inline void print_container(ContainerT const& container) {
	for (typename DD::Iterator<ContainerT>::Type it(DD::begin(container)); it != DD::end(container); ++it) {
		DD_PRINT *it, ", ";
	}
	DD_PRINT DD::end_line;
}


void test_algorithm();



#endif
