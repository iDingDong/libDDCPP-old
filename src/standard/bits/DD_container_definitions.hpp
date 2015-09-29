//	DDCPP/standard/bits/DD_container_definitions.hpp
#ifndef DD_CONTAINER_DEFINITIONS_HPP_INCLUDED_
#	define DD_CONTAINER_DEFINITIONS_HPP_INCLUDED_ 1



#	include "DD_CompatStlContainer.hpp"



#	define DD_CONTAINER_DECLARATIONS\
		DD_ALIAS(ConstValueType, ValueType const);\
		DD_ALIAS(ReferenceType, ValueType&);\
		DD_ALIAS(ConstReferenceType, ConstValueType&);\
		DD_ALIAS(PointerType, ValueType*);\
		DD_ALIAS(ConstPointerType, ConstValueType*);\



#endif
