#include "test_container.h"
#include "test_object.hpp"

#include "standard/DDHub.hpp"
#include "standard/DDArray.hpp"
#include "standard/DDVessel.hpp"
#include "standard/DDList.hpp"

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
			DD::Vessel<Test> ves(DD::batch_tag, 3, Test());
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

			auto another_ves = ves;
			if (
				Test::count != 10
			) {
				throw "'DD::Vessel' test failed.";
			}
			DD::swap(another_ves, ves);
		}
		if (
			Test::count != 0
		) {
			throw "'DD::Vessel' test failed.";
		}
	}
	{
		{
			DD::List<Test> lst_1{ Test(), Test() };
			lst_1.push_back(Test());
			if (
				lst_1.get_length() != 3 ||
				Test::count != 3
			) {
				throw "'DD::List' test failed.";
			}

			DD::List<Test> lst_2(DD::batch_tag, 3);
			if (
				lst_2.get_length() != 3 ||
				Test::count != 6
			) {
				throw "'DD::List' test failed.";
			}

			DD::List<Test> lst_3(DD::Vessel<Test>(DD::batch_tag, 4));
			if (
				lst_3.get_length() != 4 ||
				Test::count != 10
			) {
				throw "'DD::List' test failed.";
			}

			lst_2.erase(DD::next(lst_2.begin()));
			if (
				lst_2.get_length() != 2 ||
				Test::count != 9
			) {
				throw "'DD::List' test failed.";
			}

			lst_3.erase_range(DD::next(lst_3.begin()), DD::previous(lst_3.end()));
			if (
				lst_3.get_length() != 2 ||
				Test::count != 7
			) {
				throw "'DD::List' test failed.";
			}

			DD::List<Test> lst_4 = lst_1;
			if (
				lst_4.get_length() != 3 ||
				Test::count != 10
			) {
				throw "'DD::List' test failed.";
			}
			lst_4 = lst_3;
			if (
				lst_4.get_length() != 2 ||
				Test::count != 9
			) {
				throw "'DD::List' test failed.";
			}
			lst_4 = DD::Vessel<Test>(DD::batch_tag, 1);
			if (
				lst_4.get_length() != 1 ||
				Test::count != 8
			) {
				throw "'DD::List' test failed.";
			}
		}
		if (
			Test::count != 0
		) {
			throw "'DD::List' test failed.";
		}
	}
}
