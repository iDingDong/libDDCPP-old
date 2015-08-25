//	DDCPP/standard/bits/DD_IsUnsignedShort.hpp
#ifndef _DD_IS_UNSIGNED_SHORT_HPP_INCLUDED
#	define _DD_IS_UNSIGNED_SHORT_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsUnsignedShort : FalseType {
};



template <>
struct _IsUnsignedShort<unsigned short> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsUnsignedShort = AndType<_detail::_IsUnsignedShort<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsUnsignedShort : _detail::_IsUnsignedShort<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
