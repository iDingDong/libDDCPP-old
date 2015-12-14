#define DDCPP_DEFAULT_WARNING 0

#include "standard/DDGlobal.hpp"

#include "standard/DDIterator.hpp"

#include "standard/DDHub.hpp"
#include "test_meta.h"
#include "test_memory.h"
#include "test_algorithm.h"
#include "test_container.h"
#include "test_utility.h"
#include "test_math.h"

int main() {
	try {
		DD_PRINT DD::version, '\n', DD::end_line;
		test_meta();
		test_utility();
		test_memory();
		test_algorithm();
		test_container();
		test_math();
		DD_PRINT "All tests successfully operated.";
	} catch (char const* prompt) {
		DD_PRINT prompt;
	} catch (DD::Exception& error_) {
		DD_PRINT error_.get_prompt();
	}
	DD_PRINT DD::end_line;
	return 0;
}
