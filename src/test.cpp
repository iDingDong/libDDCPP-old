#include <iostream>

#include "standard/DDGlobal.hpp"
#include "standard/DDError.hpp"
#include "standard/DDTrait.hpp"
//#include "standard/DDMemory.hpp"
#include "standard/DDCompare.hpp"
#include "standard/DDUtility.hpp"
#include "standard/DDArray.hpp"
#include "standard/DDIterator.hpp"
#include "standard/DDAlgorithm.hpp"

class Test {
    public:
    Test() {}
    Test(Test const&) {}
    //Test(Test&&) {}
    Test& operator =(Test const&) { return *this; }
    //Test& operator =(Test&&) { return *this; }
};

struct BadIter {
    typedef float value_type;
    typedef int ValueType;
    int& operator *();
};

int main(int argc, char** argv) {
    DD::Direction a = DD::Direction::forward;
    std::cout << (a == DD::Direction::forward) << std::endl;
    
    
    DD::Pair<int, char> testPair1 = {3, 'e'};
    DD::Pair<int, char> testPair2 = {1, 'e'};
    std::cout << (testPair1 <= testPair2) << std::endl;
    
    DD::Array<int, 4> arr = {7, 4, 9, 1};
    //std::cout << &*arr.begin() - &*arr.rend() << std::endl;
    auto beg = arr.begin();
    auto end = arr.end();
    DD::insert_sort(beg, end);
    //DD::insert_sort(arr.rbegin(), arr.rend());
    std::cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << std::endl;
    
    //DD::ArrayIterator<int> aiter(&arr[0]);
    /*
    std::cout << *aiter << std::endl;
    std::cout << *(aiter + 1) << std::endl;
    std::cout << *aiter << std::endl;
    std::cout << (aiter == aiter) << std::endl;
    */
    //DD::Array<Test, 5> testArray;
    int* p;
    std::cout << DD::IsSame<typename DD::IteratorReference<int*>::Type, typename DD::IteratorReference<BadIter>::Type>::value << std::endl;
    Test testTest1;
    Test testTest2;
    //std::cout << noexcept(DD::swap(testTest1, testTest2)) << std::endl;
    
    return 0;
}