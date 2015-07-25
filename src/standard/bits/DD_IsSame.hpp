//	DDCPP/standard/bits/ DD_IsSame.hpp
#ifndef _DD_IS_SAME_HPP_INCLUDED
#	define _DD_IS_SAME_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
struct _IsSame : TrueType {
};



template <typename _ObjectT1, typename _ObjectT2, typename... _ObjectsT>
struct _IsSame<_ObjectT1, _ObjectT2, _ObjectsT...> : AndType<_IsSame<_ObjectT1, _ObjectT2>, _IsSame<_ObjectT1, _ObjectsT...>> {
};



template <typename _ObjectT1, typename _ObjectT2>
struct _IsSame<_ObjectT1, _ObjectT2> : StdBoolConstant<std::is_same<_ObjectT1, _ObjectT2>> {
};
#	else
template <typename _ObjectT1, typename _ObjectT2>
struct _IsSame : FalseType {
};
#	endif



template <typename _ObjectT>
struct _IsSame<_ObjectT, _ObjectT> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsSame = detail::_IsSame<_ObjectsT...>;
#	else
template <typename _ObjectT1, typename _ObjectT2>
struct IsSame : detail::_IsSame<_ObjectT1, _ObjectT2> {
};
#	endif



DD_END



#endif
