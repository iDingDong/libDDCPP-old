//	DDCPP/standard/bits/DD_generate.hpp
#ifndef _DD_GENERATE_HPP_INCLUDED
#	define _DD_GENERATE_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _UndirectionalIteratorT, typename _Generator>
ProcessType generate(
	_UndirectionalIteratorT __begin,
	_UndirectionalIteratorT const& __end,
	_Generator const& __generator
) DD_NOEXCEPT_AS(*++__begin = __generator() DD_COMMA __begin != __end) {
	for (; __begin != __end; ++__begin) {
		*__begin = __generator();
	}
}



DD_END



#endif
