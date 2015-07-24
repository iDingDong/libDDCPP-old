#include <iostream>

template <typename T>
struct A {
    A() : m() {}
    T m;
    template <typename T_>
    A& operator =(T_&& new_m) noexcept(noexcept(m = new_m)) {
        m = new_m;
        return *this;
    }
};


int main() {
    A<int> a1;
    A<int> a2;
    std::cout << a1.m << std::endl;
    a1 = 2;
    a2 = a1;
    std::cout << a2.m;
    return 0;
}