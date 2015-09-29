//	DDCPP/standard/bits/DD_IsFloat.hpp
#ifndef DD_IS_FLOAT_HPP_INCLUDED_
#	define DD_IS_FLOAT_HPP_INCLUDED_



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsFloat_ : FalseType {
};



template <>
struct IsFloat_<float> : TrueType {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
using IsFloat = AndType<detail_::IsFloat_<RemoveCVType<ObjectsT_>>...>;
#	else
template <typename ObjectT_>
struct IsFloat : detail_::IsFloat_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_END_



#endif
