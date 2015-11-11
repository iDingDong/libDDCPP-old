#include "test_container.h"
#include "test_object.hpp"

#include "standard/DDArray.hpp"
#include "standard/DDVessel.hpp"

#include "standard/DDAlgorithm.hpp"

void test_container() {
	{
		DD::Array<int, 5> arr = { 1, 3, 5, 2, 4 };
		DD::Vessel<int> ves = { 1, 3, 5, 2, 4 };
		if (
			!DD::equal(arr, ves)
		) {
			throw "'DD::Vessel' test failed.";
		}
		{
			DD::Vessel<Test> ves(3, Test());
			if (
				Test::count != 3
			) {
				throw "'DD::Vessel' test failed.";
			}

			ves.push_back(Test());
			if (
				Test::count != 4
			) {
				throw "'DD::Vessel' test failed.";
			}

			ves.insert(ves.begin(), Test());
			if (
				Test::count != 5
			) {
				throw "'DD::Vessel' test failed.";
			}

			ves.insert(ves.begin() + 1, Test());
			if (
				Test::count != 6
			) {
				throw "'DD::Vessel' test failed.";
			}

			ves.erase(ves.begin());
			if (
				Test::count != 5
			) {
				throw "'DD::Vessel' test failed.";
			}

		}
		if (
			Test::count != 0
		) {
			throw "'DD::Vessel' test failed.";
		}
	}
}
