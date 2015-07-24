#include <cstdio>
using std::printf;

//#include "standard/DDMemory.hpp"
//#include "standard/DDUtility.hpp"
#include "standard/DDTrait.hpp"


struct Test {
	Test() { ++count; printf("\nTest constructed(default). "); printCount(); }
	Test(Test const&) { ++count; printf("\nTest constructed(copy). "); printCount(); }
	Test(Test&& origin) { origin.valid = false; ++count; printf("\nTest constructed(move). "); printCount(); }
	
	~Test() { --count; printf("\nTest destructed. "); printCount(); }
	
	Test& operator =(Test const& origin) { valid = origin.valid; printf("\nTest copied.\n"); return *this; };
	Test& operator =(Test&& origin) { valid = origin.valid; origin.valid = false; printf("\nTest moved.\n"); return *this; }
	
	void show() { if (valid) printf("Alive.\n"); else printf("Dead.\n"); }
	static void printCount() { printf("%d Tests in memory.\n", count); }
	
	bool valid = true;
	static int count;
};

int Test::count = 0;
/*
DD::UniquePointer<Test> func() {
	DD::UniquePointer<Test> temp(new Test());
	return temp;
}
*/
void _fun(Test&) {
	printf("Lvalue ref.\n");
}

void _fun(Test&&) {
	printf("Rvalue ref.\n");
}
/*
template <typename T>
void fun(T&& param) {
	_fun(DD::forward<T>(param));
}
*/
Test func() {
	Test tst;
	tst.show();
	return tst;
}

int main() {
	//DD::UniquePointer<Test> uptr1(new Test);
	//auto uptr2 = func();
	//DD::UniquePointer<Test[]> uptr3(new Test[10]);
	
	//DD::Tuple<Test> tuple1;
	//auto tuple2 = DD::move(tuple1);
	
	//Test tst;
	
	
	/*
	fun(tst);
	fun(Test());
	
	tst.printCount();
	DD::Tuple<Test> tuple3(tst);
	tst.show();
	printf("End of main. \n");
	*/
	Test tst;
	tst = func();
	
	//DD::Tuple<Test, int> tuple4(tst, 1);
	//printf("The int is %d\n", DD::get_value<1>(tuple4));
	//printf("The int is %d\n", DD::get_value<int>(tuple4));
	
	return 0;
}