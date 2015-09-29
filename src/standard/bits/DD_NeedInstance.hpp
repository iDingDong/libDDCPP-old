//	DDCPP/standard/bits/DD_NeedInstance.hpp
#ifndef DD_NEED_INSTANCE_HPP_INCLUDED_
#	define DD_NEED_INSTANCE_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN_
DD_NESTED_TYPE_TRAIT(GetNeedInstance_, NeedInstance, FalseType)



template <typename ObjectT_>
struct NeedInstance_ : BoolConstant<DD_MODIFY_TRAIT(GetNeedInstance_, ObjectT_)::value> {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >=201103L
template <typename... ObjectsT_>
using NeedInstance = AndType<detail_::NeedInstance_<ObjectsT_>...>;
#	else
template <typename ObjectT_>
struct NeedInstance : detail_::NeedInstance_<ObjectT_> {
};
#	endif



DD_END_



#endif
