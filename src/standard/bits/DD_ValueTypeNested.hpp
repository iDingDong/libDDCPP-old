//	DDCPP/standard/bits/DD_ValueTypeNested.hpp
#ifndef _DD_VALUE_TYPE_NESTED_HPP_INCLUDED
#	define _DD_VALUE_TYPE_NESTED_HPP_INCLUDED 1



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
			using ReferenceType = ValueType&;\
			using ConstReferenceType = ValueType const&;\
			using PointerType = ValueType*;\
			using ConstPointerType = ValueType const*;\
			DD_VALUE_TYPE_NESTED_COMPAT_STL
#	else
#		define DD_VALUE_TYPE_NESTED(_ARG_ValueType)\
			typedef _ARG_ValueType ValueType;\
			typedef ValueType& ReferenceType;\
			typedef ValueType const& ConstReferenceType;\
			typedef ValueType* PointerType;\
			typedef ValueType const* ConstPointerType;\
			DD_VALUE_TYPE_NESTED_COMPAT_STL
#	endif



#endif
