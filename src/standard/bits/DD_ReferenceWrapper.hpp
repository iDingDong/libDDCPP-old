//	DDCPP/standard/bits/DD_ReferenceWrapper.hpp
#ifndef DD_REFERENCE_WRAPPER_HPP_
#	define DD_REFERENCE_WRAPPER_HPP_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ReferenceWrapper'.



#	endif
#	include <functional>

#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename ObjectT_>
using ReferenceWrapper = std::reference_wrapper<ObjectT_>;



DD_END_



#endif
