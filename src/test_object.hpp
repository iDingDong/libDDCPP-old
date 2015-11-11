#ifndef TEST_OBJECT_HPP_
#	define TEST_OBJECT_HPP_ 1



#	include <iostream>



#	ifndef TEST_OBJECT_AUTO_PROMPT
#		define TEST_OBJECT_AUTO_PROMPT 0
#	endif



template <int workaround = 0>
struct TestImpl {
	static std::size_t count;
	static std::size_t history_count;
	std::size_t const id;

	TestImpl() throw() : id(history_count++) {
		++count;
#	if TEST_OBJECT_AUTO_PROMPT
		std::cout << "\nTest object " << id << " constructed(default). ";
#	endif
		auto_prompt();
	}

	TestImpl(TestImpl const&) throw() : id(history_count++) {
		++count;
#	if TEST_OBJECT_AUTO_PROMPT
		std::cout << "\nTest object " << id << " constructed(copy). ";
#	endif
		auto_prompt();
	}

#	if __cplusplus >= 201103L
	TestImpl(TestImpl&&) throw() : id(history_count++) {
		++count;
#	if TEST_OBJECT_AUTO_PROMPT
		std::cout << "\nTest object " << id << " constructed(move). ";
#	endif
		auto_prompt();
	}

#	endif

	~TestImpl() throw() {
		--count;
#	if TEST_OBJECT_AUTO_PROMPT
		std::cout << "\nTest object " << id << " destructed. ";
#	endif
		auto_prompt();
	}

	void auto_prompt() throw() {
#	if TEST_OBJECT_AUTO_PROMPT
		std::cout << count << " test objects.\n" << std::endl;
#	endif
	}


	TestImpl& operator =(TestImpl const&) throw() {
#	if TEST_OBJECT_AUTO_PROMPT
		std::cout << "\nTest object " << id << " copied. ";
#	endif
		return *this;
	}

#	if __cplusplus >= 201103L
	TestImpl& operator =(TestImpl&&) throw() {
#		if TEST_OBJECT_AUTO_PROMPT
		std::cout << "\nTest object " << id << " copied. ";
#		endif
		return *this;
	}

#	endif

};


template <int workaround>
std::size_t TestImpl<workaround>::count = 0;
template <int workaround>
std::size_t TestImpl<workaround>::history_count = 0;


typedef TestImpl<> Test;



#endif
