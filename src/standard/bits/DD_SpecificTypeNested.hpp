//	DDCPP/standard/bits/DD_SpecificTypeNested.hpp
#ifndef DD_SPECIFIC_TYPE_NESTED_HPP_INCLUDED_
#	define DD_SPECIFIC_TYPE_NESTED_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



#	if __cplusplus >= 201103L
#		define DD_SPECIFIC_TYPE_NESTED(ARG_Name_, ...)\
			using ARG_Name_##Type = __VA_ARGS__;\
			using ARG_Name_##ConstType = ARG_Name_##Type const;\
			using ARG_Name_##ReferenceType = ARG_Name_##Type&;\
			using ARG_Name_##ConstReferenceType = ARG_Name_##ConstType&;\
			using ARG_Name_##PointerType = ARG_Name_##Type*;\
			using ARG_Name_##ConstPointerType = ARG_Name_##ConstType*;
#	else
#		define DD_SPECIFIC_TYPE_NESTED(ARG_Name_, ARG_Type_)\
			typedef ARG_Type_ ARG_Name_##Type;\
			typedef ARG_Name_##Type const ARG_Name_##ConstType;\
			typedef ARG_Name_##Type& ARG_Name_##ReferenceType;\
			typedef ARG_Name_##ConstType& ARG_Name_##ConstReferenceType;\
			typedef ARG_Name_##Type* ARG_Name_##PointerType;\
			typedef ARG_Name_##ConstType* ARG_Name_##ConstPointerType;
#	endif



#endif
