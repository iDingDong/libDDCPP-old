#include "test_container.h"
#include "test_object.hpp"
#include "test_algorithm.h"

#include "standard/DDHub.hpp"
#include "standard/bits/DD_HashTable.hpp"
#include "standard/DDArray.hpp"
#include "standard/DDVessel.hpp"
#include "standard/DDList.hpp"
#include "standard/DDRing.hpp"
#include "standard/DDUtility.hpp"

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
				ves.get_length() != 3 ||
				Test::count != 3
			) {
				DD_PRINT "'Test::count' : ", Test::count, "\nExpected to be : ", 3, DD::end_line;
				throw "'DD::Vessel' test failed.";
			}

			ves.push_back(Test());
			if (
				ves.get_length() != 4 ||
				Test::count != 4
			) {
				throw "'DD::Vessel' test failed.";
			}

			ves.insert(ves.begin(), Test());
			if (
				ves.get_length() != 5 ||
				Test::count != 5
			) {
				throw "'DD::Vessel' test failed.";
			}

			ves.insert(ves.begin() + 1, Test());
			if (
				ves.get_length() != 6 ||
				Test::count != 6
			) {
				throw "'DD::Vessel' test failed.";
			}

			ves.erase(ves.begin());
			if (
				ves.get_length() != 5 ||
				Test::count != 5
			) {
				throw "'DD::Vessel' test failed.";
			}

			auto another_ves = ves;
			if (
				another_ves.get_length() != 5 ||
				Test::count != 10
			) {
				throw "'DD::Vessel' test failed.";
			}
			DD::swap(another_ves, ves);

			DD::Vessel<DD::Variant<>> variant_ves = { 1, "haha", 1.0, Test() };
			if (
				variant_ves.get_length() != 4 ||
				variant_ves[0].get_type() != typeid(1) ||
				variant_ves[1].get_type() != typeid(DD::DecayType<decltype("haha")>) ||
				variant_ves[2].get_type() != typeid(1.0) ||
				variant_ves[3].get_type() != typeid(Test)
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
			DD::swap(lst_1, lst_4);
			if (
				lst_4.get_length() != 3 ||
				Test::count != 8
			) {
				throw "'DD::List' test failed.";
			}

			lst_1.splice(lst_1.end(), lst_4.begin(), lst_4.end());
			if (
				lst_1.get_length() != 4 ||
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
	{
		{
			DD::Array<int, 5> arr_1 = { 1, 7, -12, 33, 5 };
			DD::Ring<int> ring_1;
			for (auto i : arr_1) {
				ring_1.push_back(i);
			}
			if (!DD::equal(ring_1, arr_1)) {
				throw "'DD::Ring' test failed.";
			}

			DD::Array<int, 6> arr_2 = { -222, 1, 7, -12, 33, 5 };
			ring_1.push_front(arr_2[0]);
			if (!DD::equal(ring_1, arr_2)) {
				throw "'DD::Ring' test failed.";
			}
		}
		{
			DD::Ring<Test> ring_1;
			ring_1.push_back(Test());
			if (
				ring_1.get_length() != 1 ||
				Test::count != 1
			) {
				throw "'DD::Ring' test failed.";
			}
			ring_1.push_front(Test());
			if (
				ring_1.get_length() != 2 ||
				Test::count != 2
			) {
				throw "'DD::Ring' test failed.";
			}
		}
		if (
			Test::count != 0
		) {
			throw "'DD::List' test failed.";
		}
	}
	{
		{
			DD::UndirectionalList<Test> ulst_1 = { Test(), Test() };
			if (
				Test::count != 2
			) {
				throw "'DD::UndirectionalList' test failed.";
			}
			ulst_1.push_front(Test());
			if (
				Test::count != 3
			) {
				throw "'DD::UndirectionalList' test failed.";
			}
			ulst_1.pop_front();
			if (
				Test::count != 2
			) {
				throw "'DD::UndirectionalList' test failed.";
			}
		}
		if (
			Test::count != 0
		) {
			throw "'DD::UndirectionalList' test failed.";
		}
	}
	{
		{
			DD::Vessel<int> ves;
			DD::List<int> lst;
			DD::Ring<int> ring;
			ves.push_back(1);
			lst.push_back(1);
			ring.push_back(1);
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.push_front(2);
			lst.push_front(2);
			ring.push_front(2);
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.push_back(3);
			lst.push_back(3);
			ring.push_back(3);
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.push_front(4);
			lst.push_front(4);
			ring.push_front(4);
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.push_back(5);
			lst.push_back(5);
			ring.push_back(5);
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.push_front(6);
			lst.push_front(6);
			ring.push_front(6);
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.push_back(7);
			lst.push_back(7);
			ring.push_back(7);
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.push_front(8);
			lst.push_front(8);
			ring.push_front(8);
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.pop_back();
			lst.pop_back();
			ring.pop_back();
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.pop_front();
			lst.pop_front();
			ring.pop_front();
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.pop_back();
			lst.pop_back();
			ring.pop_back();
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.pop_front();
			lst.pop_front();
			ring.pop_front();
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.erase(::DD::next(ves.begin()));
			lst.erase(::DD::next(lst.begin()));
			ring.erase(::DD::next(ring.begin()));
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves << 9 << 10;
			lst << 9 << 10;
			ring << 9 << 10;
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves.erase_range(::DD::next(ves.begin()), ::DD::next(ves.begin(), 3));
			lst.erase_range(::DD::next(lst.begin()), ::DD::next(lst.begin(), 3));
			ring.erase_range(::DD::next(ring.begin()), ::DD::next(ring.begin(), 3));
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves += ves;
			lst += lst;
			ring += ring;
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
			ves += ves;
			lst += lst;
			ring += ring;
			if (
				!DD::equal(ves, lst) ||
				!DD::equal(lst, ring) ||
				!DD::equal(ring, ves)
			) {
				throw "Container test failed.";
			}
		}
	}
}
