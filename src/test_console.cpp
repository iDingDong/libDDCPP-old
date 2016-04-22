#include "test_console.h"

#include "standard/DDHub.hpp"
#include "console/DDConsole.hpp"
//#include "console/bits/DD_console_Buffer.hpp"

void test_console() {
	using namespace DD::console;
	try {
		clear_screen();
		put_at('a', 3, Coord{ 1, 1 });
		set_cursor_position(Coord{ 5, 1 });

		write("test");

		put(Pixel{ 'c', Color::cyan() }, Coord{ 0, 0 });

		clear_screen();

		//Buffer buffer(5, 3);
		//buffer.draw_at(Pixel{ 'y', Color::yellow() }, Coord{ 1, 3 });
	} catch (ConsoleFailure err) {
		set_cursor_position(Coord{ 0, 1 });
		DD_PRINT err.get_prompt(), "\n", err.get_code(), ::DD::end_line;
	}

	set_cursor_position(Coord{ 0, 10 });
}
