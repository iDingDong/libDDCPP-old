#include <utility>
#include <deque>
#include <memory>
#include <algorithm>
struct Prime {
	using Result = unsigned long;
	
	static std::deque<std::pair<Result const, Result>> primes;
	static Result end;
	
	static void process() {
		auto last_square = primes.back().first * primes.back().first;
		std::unique_ptr<bool[]> temp(new bool[last_square - end + 1]);
		std::fill(&temp[0], &temp[last_square - end + 1], true);
		auto ptr = &temp[-end];
		for (auto i = primes.size(); i--; ) {
			for (; primes[i].second <= last_square; primes[i].second += primes[i].first) {
				ptr[primes[i].second] = false;
			}
		}
		for (std::size_t i = end; i < last_square; ++i) {
			if (ptr[i]) {
				primes.emplace_back(std::pair<Result const, Result>{i, i * 2});
			}
		}
		end = last_square + 1;
	}
	
	static Result nth_prime(Result n) {
		while (primes.size() < n) {
			process();
		}
		return primes.at(n - 1).first;
	}
	
};

std::deque<std::pair<Prime::Result const, Prime::Result>> Prime::primes = {{2, 2 * 2}};
Prime::Result Prime::end = 2 + 1;


#include <cstdio>
int main() {
	for (int i = 1; i <= 400; ++i)
	//int i = 500;
	std::printf("%d: %lu\n", i, Prime::nth_prime(i));
	return 0;
}