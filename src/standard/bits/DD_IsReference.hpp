//	DDCPP/standard/bits/DD_IsReference.hpp
#ifndef DD_IS_REFERENCE_HPP_INCLUDED_
#	define DD_IS_REFERENCE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_Or.hpp"
#		include "DD_IsLvalueReference.hpp"
#		include "DD_IsRvalueReference.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsReference : AndType<IsReference<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsReference<ObjectT_> : OrType<IsLvalueReference<ObjectT_>, IsRvalueReference<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsReference : FalseType {
};



template <typename ObjectT_>
struct IsReference<ObjectT_&> : TrueType {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsReference;



DD_END_



#endif
