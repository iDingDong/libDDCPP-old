//	DDCPP/standard/bits/DD_CompatStlIterator.hpp
#ifndef _DD_COMPAT_STL_ITERATOR_HPP_INCLUDED
#	define _DD_COMPAT_STL_ITERATOR_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"
#	include "DD_compatibility_definitions.hpp"



#	if DDCPP_COMPAT_STL
#		define DD_COMPAT_STL_ITERATOR\
			DD_ALIAS(value_type, ValueType);\
			DD_ALIAS(reference, ReferenceType);\
			DD_ALIAS(pointer, PointerType);\
			DD_ALIAS(difference_type, DifferenceType);
#	else
#		define DD_COMPAT_STL_ITERATOR
#	endif



#endif
