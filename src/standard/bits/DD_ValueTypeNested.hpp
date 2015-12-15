//	DDCPP/standard/bits/DD_ValueTypeNested.hpp
#ifndef DD_VALUE_TYPE_NESTED_HPP_INCLUDED_
#	define DD_VALUE_TYPE_NESTED_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



#	if DD_COMPAT_STL
#		define DD_VALUE_TYPE_NESTED_COMPAT_STL\
			DD_ALIAS(value_type, ValueType);\
			DD_ALIAS(reference, ReferenceType);\
			DD_ALIAS(const_reference, ConstReferenceType);\
			DD_ALIAS(pointer, PointerType);\
			DD_ALIAS(const_pointer, ConstPointerType);
#	else
#		define DD_VALUE_TYPE_NESTED_COMPAT_STL
#	endif

#	if __cplusplus >= 201103L
#		define DD_VALUE_TYPE_NESTED(...)\
			using ValueType = __VA_ARGS__;\
			using ValueConstType = ValueType const;\
			using ReferenceType = ValueType&;\
			using ConstReferenceType = ValueConstType&;\
			using PointerType = ValueType*;\
			using ConstPointerType = ValueConstType*;\
			DD_VALUE_TYPE_NESTED_COMPAT_STL
#	else
#		define DD_VALUE_TYPE_NESTED(ARG_ValueType_)\
			typedef ARG_ValueType_ ValueType;\
			typedef ValueType const ValueConstType;\
			typedef ValueType& ReferenceType;\
			typedef ValueConstType& ConstReferenceType;\
			typedef ValueType* PointerType;\
			typedef ValueConstType* ConstPointerType\
			DD_VALUE_TYPE_NESTED_COMPAT_STL
#	endif



#endif
