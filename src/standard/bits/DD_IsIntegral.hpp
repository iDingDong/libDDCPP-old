//	DDCPP/standard/bits/DD_IsIntegral.hpp
#ifndef _DD_IS_INTEGRAL_HPP_INCLUDED
#	define _DD_IS_INTEGRAL_HPP_INCLUDED 1



#	if __cplusplus > 201103L
#		include <type_traits>
#	endif

#	include "DD_IsBool.hpp"

#	include "DD_IsCharactor.hpp"

#	include "DD_IsUnsignedShort.hpp"
#	include "DD_IsSignedShort.hpp"
#	include "DD_IsUnsignedInt.hpp"
#	include "DD_IsSignedInt.hpp"
#	include "DD_IsUnsignedLong.hpp"
#	include "DD_IsSignedLong.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsUnsignedLongLong.hpp"
#		include "DD_IsSignedLongLong.hpp"
#	endif



#	if __cplusplus >= 201103L
DD_DETAIL_BEGIN
template <typename _ObjectT>
using _IsIntegral = OrType<
	IsBool<_ObjectT>,
	IsCharactor<_ObjectT>,
	IsUnsignedShort<_ObjectT>,
	IsSignedShort<_ObjectT>,
	IsUnsignedInt<_ObjectT>,
	IsSignedInt<_ObjectT>,
	IsUnsignedLong<_ObjectT>,
	IsSignedLong<_ObjectT>,
	IsUnsignedLongLong<_ObjectT>,
	IsSignedLongLong<_ObjectT>,
	StdBoolConstant<std::is_integral<_ObjectT>>
>;



DD_DETAIL_END



#	endif
DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsIntegral = AndType<detail::_IsIntegral<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct IsIntegral : BoolConstant<
	IsBool<_ObjectT>::value ||
	IsCharactor<_ObjectT>::value ||
	IsUnsignedShort<_ObjectT>::value ||
	IsSignedShort<_ObjectT>::value ||
	IsUnsignedInt<_ObjectT>::value ||
	IsSignedInt<_ObjectT>::value ||
	IsUnsignedLong<_ObjectT>::value ||
	IsSignedLong<_ObjectT>::value
> {
};
#	endif



DD_END



#endif
