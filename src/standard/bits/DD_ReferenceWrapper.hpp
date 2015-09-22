//	DDCPP/standard/bits/DD_ReferenceWrapper.hpp
#ifndef _DD_REFERENCE_WRAPPER_HPP
#	define _DD_REFERENCE_WRAPPER_HPP 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ReferenceWrapper'.



#	endif
#	include <functional>

#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _ObjectT>
using ReferenceWrapper = std::reference_wrapper<_ObjectT>;



_DD_END



#endif
