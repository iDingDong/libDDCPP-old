//	DDCPP/standard/bits/DD_ErrorCode.hpp
#ifndef DD_ERROR_CODE_HPP_INCLUDED_
#	define DD_ERROR_CODE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ErrorCode'.



#	endif
#	include <system_error>

#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
using ErrorCode = std::error_code;



DD_DETAIL_END_



DD_BEGIN_
using detail_::ErrorCode;



DD_END_



#endif
