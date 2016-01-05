//	DDCPP/standard/bits/DD_ValueTypeNested.hpp
#ifndef DD_VALUE_TYPE_NESTED_HPP_INCLUDED_
#	define DD_VALUE_TYPE_NESTED_HPP_INCLUDED_ 1



#	include "DD_AddConst.hpp"
#	include "DD_AddLvalueReference.hpp"
#	include "DD_AddPointer.hpp"



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
			using ValueConstType = AddConstType<ValueType>;\
			using ReferenceType = AddLvalueReferenceType<ValueType>;\
			using ConstReferenceType = AddLvalueReferenceType<ValueConstType>;\
			using PointerType = AddPointerType<ValueType>;\
			using ConstPointerType = AddPointerType<ValueConstType>;\
			DD_VALUE_TYPE_NESTED_COMPAT_STL
#	else
#		define DD_VALUE_TYPE_NESTED(ARG_ValueType_)\
			typedef ARG_ValueType_ ValueType;\
			typedef typename AddConst<ValueType>::Type ValueConstType;\
			typedef typename AddLvalueReference<ValueType>::Type ReferenceType;\
			typedef typename AddLvalueReference<ValueConstType>::Type ConstReferenceType;\
			typedef typename AddPointer<ValueType>::Type PointerType;\
			typedef typename AddPointer<ValueConstType>::Type ConstPointerType\
			DD_VALUE_TYPE_NESTED_COMPAT_STL
#	endif



#endif
