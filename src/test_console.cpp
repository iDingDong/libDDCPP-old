#include "test_console.h"

#include <thread>
#include <chrono>

#include "console/DDConsole.hpp"

void test_console() {
	using namespace DD::console;
	using namespace std::chrono_literals;
	clear_screen();
	std::this_thread::sleep_for(1s);
	put_at('a', 3, Coord{ 3, 1 });
	std::this_thread::sleep_for(1s);
	set_cursor_position(Coord{ 2, 2 });
	std::this_thread::sleep_for(1s);


	write("Hahahaha");
	set_cursor_position(Coord{ 0, 20 });
}
