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



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsFloat : AndType<IsFloat<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsFloat<ObjectT_> : IsFloat_<RemoveCVType<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct IsFloat : IsFloat_<typename RemoveCV<ObjectT_>::Type> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsFloat;



DD_END_



#endif
