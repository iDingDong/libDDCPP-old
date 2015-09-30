//	DDCPP/standard/bits/DD_IteratorNested.hpp
#ifndef DD_ITERATOR_NESTED_HPP_INCLUDED_
#	define DD_ITERATOR_NESTED_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



#	if DD_COMPAT_STL
#		define DD_ITERATOR_NESTED_COMPAT_STL_
#	else
#		define DD_ITERATOR_NESTED_COMPAT_STL_\
			DD_ALIAS(iterator, Iterator);\
			DD_ALIAS(const_iterator, ConstIterator);\
			DD_ALIAS(reverse_iterator, ReverseIterator);\
			DD_ALIAS(const_reverse_iterator, ConstReverseIterator);
#	endif

#	define DD_ITERATOR_NESTED\
		DD_ALIAS(ReverseIterator, DD_MODIFY_TRAIT(IteratorReverse, Iterator));\
		DD_ALIAS(ConstReverseIterator, DD_MODIFY_TRAIT(IteratorReverse, ConstIterator));\
		DD_ITERATOR_NESTED_COMPAT_STL_



#endif
