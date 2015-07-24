//	standard/bits/DD_CompatStlContainer.hpp
#ifndef _DD_COMPAT_STL_CONTAINER_HPP_INCLUDED
#	define _DD_COMPAT_STL_CONTAINER_HPP_INCLUDED 1



#	include "DD_compatibility_definitions.hpp"



#	if DDCPP_COMPAT_STL
#		define DD_COMPAT_STL_CONTAINER\
			DD_ALIAS(value_type, ValueType)\
			DD_ALIAS(reference, ReferenceType)\
			DD_ALIAS(const_reference, ConstReferenceType)\
			DD_ALIAS(pointer, PointerType)\
			DD_ALIAS(const_pointer, ConstPointerType)\
			DD_ALIAS(iterator, Iterator)\
			DD_ALIAS(revese_iterator, ReverseIterator)\
			DD_ALIAS(const_iterator, ConstIterator)\
			DD_ALIAS(const_reverse_iterator, ConstReverseIterator)
#		define DD_COMPAT_STL_UNDIRECTIONAL_CONTAINER\
			DD_ALIAS(value_type, ValueType)\
			DD_ALIAS(reference, ReferenceType)\
			DD_ALIAS(const_reference, ConstReferenceType)\
			DD_ALIAS(pointer, PointerType)\
			DD_ALIAS(const_pointer, ConstPointerType)\
			DD_ALIAS(iterator, Iterator)\
			DD_ALIAS(const_iterator, ConstIterator)
#	else
#		define DD_COMPAT_STL_CONTAINER
#		define DD_COMPAT_STL_UNDIRECTIONAL_CONTAINER
#	endif



#endif
