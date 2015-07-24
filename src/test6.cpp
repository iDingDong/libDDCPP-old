#include <vector>
#include <iostream>
int main() {
	std::vector<int> a = {1, 2, 3};
	for (int i = 0; i < 20; ++i) {
		a.push_back(2);
		std::cout << a.size() << ' ' << a.capacity() << std::endl;
	}
	std::cout << a.capacity() << std::endl;
};