#include <iostream>
#include <thread>

using std::cout;
using std::endl;

int thread_1_main() {
	cout << "1 Hello!" << endl;
	cout << "1 Hello!" << endl;
	cout << "1 Hello!" << endl;
	cout << "1 Hello!" << endl;
	cout << "1 Hello!" << endl;
	cout << "1 Hello!" << endl;
	cout << "1 Hello!" << endl;
	cout << "1 Hello!" << endl;
	cout << "1 Hello!" << endl;
	cout << "1 Hello!" << endl;
	return 0;
}

int thread_2_main() {
	cout << "2 Hello!" << endl;
	cout << "2 Hello!" << endl;
	cout << "2 Hello!" << endl;
	cout << "2 Hello!" << endl;
	cout << "2 Hello!" << endl;
	cout << "2 Hello!" << endl;
	cout << "2 Hello!" << endl;
	cout << "2 Hello!" << endl;
	cout << "2 Hello!" << endl;
	cout << "2 Hello!" << endl;
	return 0;
}



int main() {
	std::thread thr1(thread_1_main);
	std::thread thr2(thread_2_main);
	thr1.detach();
	thr2.detach();
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	cout << "main Hello!" << endl;
	return 0;
}