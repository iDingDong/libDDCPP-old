//	DDCPP/standard/bits/DD_SpecificTypeNested.hpp
#ifndef DD_SPECIFIC_TYPE_NESTED_HPP_INCLUDED_
#	define DD_SPECIFIC_TYPE_NESTED_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



#	if __cplusplus >= 201103L
#		define DD_SPECIFIC_TYPE_NESTED(ARG_Name_, ...)\
			DD_ALIAS(ARG_Name_##Type, __VA_ARGS__);\
			DD_ALIAS(ARG_Name_##ConstType, ARG_Name_##Type const);\
			DD_ALIAS(ARG_Name_##ReferenceType, ARG_Name_##Type&);\
			DD_ALIAS(ARG_Name_##ConstReferenceType, ARG_Name_##ConstType&);\
			DD_ALIAS(ARG_Name_##PointerType, ARG_Name_##Type*);\
			DD_ALIAS(ARG_Name_##ConstPointerType, ARG_Name_##ConstType*);
#	else
#		define DD_SPECIFIC_TYPE_NESTED(ARG_Name_, ARG_Type_)\
			DD_ALIAS(ARG_Name_##Type, ARG_Type_);\
			DD_ALIAS(ARG_Name_##ConstType, ARG_Name_##Type const);\
			DD_ALIAS(ARG_Name_##ReferenceType, ARG_Name_##Type&);\
			DD_ALIAS(ARG_Name_##ConstReferenceType, ARG_Name_##ConstType&);\
			DD_ALIAS(ARG_Name_##PointerType, ARG_Name_##Type*);\
			DD_ALIAS(ARG_Name_##ConstPointerType, ARG_Name_##ConstType*);
#	endif



#endif
