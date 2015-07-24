template <typename T>
struct Wrap {
    T t;
    
    void printA() {
        t.prtA();
    }
    
    void printB() {
        t.prtB();
    }
    
    
};

#include <iostream>
#include <iterator>
using std::cout;
using std::endl;

struct A {
    void prtA() {
        cout << "Hi!" << endl;
    }
};


struct B {
    int a;
};


struct BIter {
    
    BIter& operator ++() {
        cout << "Forward!" << endl;
        return *this;
    }
};


int main() {
    B b{1};
    Wrap<A> wa;
    wa.printA();
    //std::reverse_iterator<BIter> rbiter;
    return 0;
}