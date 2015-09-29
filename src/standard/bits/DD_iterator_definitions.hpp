//	DDCPP/standard/bits/DD_list_definitions,hpp
#ifndef DD_LIST_DEFINITIONS_HPP_INCLUDED_
#	define DD_LIST_DEFINITIONS_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



#	define DD_ITERATOR_DECLARATIONS\
		DD_ALIAS(ConstValueType, ValueType const);\
		DD_ALIAS(ReferenceType, ValueType&);\
		DD_ALIAS(ConstReferenceType, ConstValueType&);\
		DD_ALIAS(PointerType, ValueType*);\
		DD_ALIAS(ConstPointerType, ConstValueType*);\



#endif
