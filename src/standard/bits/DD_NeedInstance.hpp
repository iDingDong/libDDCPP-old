//	DDCPP/standard/bits/DD_NeedInstance.hpp
#ifndef DD_NEED_INSTANCE_HPP_INCLUDED_
#	define DD_NEED_INSTANCE_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus >= 201103L
#		include "DD_Not.hpp"
#		include "DD_IsEmpty.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
DD_NESTED_TYPE_TRAIT(GetNeedInstance_, NeedInstance, NotType<IsEmpty<MACRO_ObjectT_>>)



template <typename... ObjectsT_>
struct NeedInstance : AndType<NeedInstance<ObjectsT_>...> {
};



template <typename ObjectT_>
struct NeedInstance<ObjectT_> : BoolConstant<GetNeedInstance_<ObjectT_>::Type::value> {
};
#	else
DD_NESTED_TYPE_TRAIT(GetNeedInstance_, NeedInstance, FalseType)



template <typename ObjectT_>
struct NeedInstance : BoolConstant<GetNeedInstance_<ObjectT_>::Type::value> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::NeedInstance;



DD_END_



#endif
