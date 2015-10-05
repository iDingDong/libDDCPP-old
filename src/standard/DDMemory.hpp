//	DDCPP/standard/DDMemory.hpp
#ifndef DDMEMORY_HPP_INCLUDED_
#	define DDMEMORY_HPP_INCLUDED_ 1



#	include "bits/DD_size_distance.hpp"
#	include "bits/DD_Deleter.hpp"
#	include "bits/DD_Pool.hpp"
#	if __cplusplus >= 201103L
#		include "bits/DD_make_unique.hpp"
#		include "bits/DD_make_strict_parasitic.hpp"
#	else
#		include "bits/DD_UniquePointer.hpp"
#		include "bits/DD_StrictParasiticPointer.hpp"
#	endif



#endif
