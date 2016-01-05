//	DDCPP/standard/bits/DD_SpecificTypeNested.hpp
#ifndef DD_SPECIFIC_TYPE_NESTED_HPP_INCLUDED_
#	define DD_SPECIFIC_TYPE_NESTED_HPP_INCLUDED_ 1



#	include "DD_AddConst.hpp"
#	include "DD_AddLvalueReference.hpp"
#	include "DD_AddPointer.hpp"



#	if __cplusplus >= 201103L
#		define DD_SPECIFIC_TYPE_NESTED(ARG_Name_, ...)\
			using ARG_Name_##Type = __VA_ARGS__;\
			using ARG_Name_##ConstType = AddConstType<ARG_Name_##Type>;\
			using ARG_Name_##ReferenceType = AddLvalueReferenceType<ARG_Name_##Type>;\
			using ARG_Name_##ConstReferenceType = AddLvalueReferenceType<ARG_Name_##ConstType>;\
			using ARG_Name_##PointerType = AddPointerType<ARG_Name_##Type>;\
			using ARG_Name_##ConstPointerType = AddPointerType<ARG_Name_##ConstType>;
#	else
#		define DD_SPECIFIC_TYPE_NESTED(ARG_Name_, ARG_Type_)\
			typedef ARG_Type_ ARG_Name_##Type;\
			typedef typename AddConst<ARG_Name_##Type>::Type ARG_Name_##ConstType;\
			typedef typename AddLvalueReferenceType<ARG_Name_##Type>::Type ARG_Name_##ReferenceType;\
			typedef typename AddLvalueReferenceType<ARG_Name_##ConstType>::Type ARG_Name_##ConstReferenceType;\
			typedef typename AddPointer<ARG_Name_##Type>::Type ARG_Name_##PointerType;\
			typedef typename AddPointer<ARG_Name_##ConstType>::Type ARG_Name_##ConstPointerType;
#	endif



#endif
