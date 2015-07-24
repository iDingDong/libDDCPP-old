#include <deque>
#include <thread>
struct Prime {
	using Result = unsigned long;
	
	static std::deque<Result> primes;
	static Result end;
	
	static void process(Result n) noexcept {
		auto origin_size = primes.size();
		auto last = primes.back();
		auto last_square = last * last;
		for (auto current = end; current < last_square; current += 2) {
			bool isPrime = true;
			for (std::size_t i = 0; i < origin_size; ++i) {
				if (current % primes[i] == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				primes.emplace_back(current);
				if (primes.size() >= n) {
					return;
				}
			}
		}
		end = last_square + 2;
	}
	
	static Result nth_prime(Result n) noexcept {
		while (primes.size() < n) {
			process(n);
		}
		return primes.at(n - 1);
	}
	
	
};

std::deque<Prime::Result> Prime::primes = {2, 3};
Prime::Result Prime::end = 5;

#include <cstdio>
#include <conio.h>
void monitor_main() {
	for (std::size_t size; ; ) {
		size = Prime::primes.size();
		std::printf("%u: %lu\n", size, Prime::primes[size - 1]);
		sleep(1);
	}
}


int main() {
	//for (int i = 1; i < 30; ++i)
	std::thread monitor(monitor_main);
	monitor.detach();
	std::printf("%d: %lu\n", 4263116, Prime::nth_prime(4263116));
	return 0;
}