//	DDCPP/standard/bits/DD_have_uncaught_exception.hpp
#ifndef DD_HAVE_UNCAUGHT_EXCEPTION_HPP_INCLUDED_
#	define DD_HAVE_UNCAUGHT_EXCEPTION_HPP_INCLUDED_ 1



#	if __cplusplus <= 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::have_uncaught_exception'.



#	endif
#	include <exception>

#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
inline ValidityType have_uncaught_exception() noexcept {
	return std::uncaught_exception();
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::have_uncaught_exception;



DD_END_



#endif
