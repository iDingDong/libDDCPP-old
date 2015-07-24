//	standard/bits/DD_IsFloat.hpp
#ifndef _DD_IS_FLOAT_HPP_INCLUDED
#	define _DD_IS_FLOAT_HPP_INCLUDED



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsFloat : FalseType {
};



template <>
struct _IsFloat<float> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsFloat = AndType<detail::_IsFloat<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsFloat : detail::_IsFloat<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
