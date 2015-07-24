#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex m;	

void th1_main() {
	while (true) {
		std::lock_guard<std::mutex> locker(::m);
		std::cout << "Th1 signal\n" << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}


int main() {
	std::thread th1(th1_main);
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "Main request...\n" << std::flush;
	::m.lock();
	std::cout << "Main request done.\nMain signal\n" << std::flush;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "Main out...\n" << std::flush;
	::m.unlock();
	std::cout << "Main out done.\n" << std::flush;
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	std::cout << "Terminate...\n" << std::flush;
	::m.lock();
	std::cout << "Terminate done.\n" << std::flush;
	::m.unlock();
	return 0;
}