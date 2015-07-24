#include <iostream>
#include "standard/bits/DD_IsBaseOf.hpp"

class Base {};
class Derived : public Base {};
class PrivatelyDerived : private Base {};
class NonDerived {};

template <typename T>
struct Tst {
	static bool const value = false;
};

template <>
struct Tst<Base> {
	static bool const value = true;
};

int main() {
	std::cout << DD::IsBaseOf<Base, Base>::value << '\n'
		<< DD::IsBaseOf<Base, Derived>::value << '\n'
		<< DD::IsBaseOf<Base, PrivatelyDerived>::value << '\n'
		<< DD::IsBaseOf<Base, NonDerived>::value << std::endl;
	
	std::cout << '\n'
		<< Tst<Base>::value << '\n'
		<< Tst<Derived>::value << std::endl;
	
	return 0;
}