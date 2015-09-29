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
template <typename ObjectT_>
#	if __cplusplus >= 201103L
using IsReference_ = OrType<IsLvalueReference<ObjectT_>, IsRvalueReference<ObjectT_>>;
#	else
struct IsReference_ : FalseType {
};



template <typename ObjectT_>
struct IsReference_<ObjectT_&> : TrueType {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsReference = AndType<detail_::IsReference_<ObjectsT_>...>;
#	else
template <typename ObjectT_>
struct IsReference : detail_::IsReference_<ObjectT_> {
};
#	endif



DD_END_



#endif
