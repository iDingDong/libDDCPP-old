//	DDCPP/standard/bits/DD_NeedInstance.hpp
#ifndef _DD_NEED_INSTANCE_HPP_INCLUDED
#	define _DD_NEED_INSTANCE_HPP_INCLUDED 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



_DD_DETAIL_BEGIN
DD_NESTED_TYPE_TRAIT(_GetNeedInstance, NeedInstance, FalseType)



template <typename _ObjectT>
struct _NeedInstance : BoolConstant<DD_MODIFY_TRAIT(_GetNeedInstance, _ObjectT)::value> {
};



_DD_DETAIL_END



_DD_BEGIN
#	if __cplusplus >=201103L
template <typename... _ObjectsT>
using NeedInstance = AndType<_detail::_NeedInstance<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct NeedInstance : _detail::_NeedInstance<_ObjectT> {
};
#	endif



_DD_END



#endif
