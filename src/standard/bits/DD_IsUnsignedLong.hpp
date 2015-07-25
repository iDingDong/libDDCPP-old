//	DDCPP/standard/bits/DD_IsUnsignedLong.hpp
#ifndef _DD_IS_UNSIGNED_LONG_HPP_INCLUDED
#	define _DD_IS_UNSIGNED_LONG_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsUnsignedLong : FalseType {
};



template <>
struct _IsUnsignedLong<unsigned long> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsUnsignedLong = AndType<detail::_IsUnsignedLong<RemoveCVType<_ObjectsT>>...>;
#	else
template <typename _ObjectT>
struct IsUnsignedLong : detail::_IsUnsignedLong<typename RemoveCV<_ObjectT>::Type> {
};
#	endif



DD_END



#endif
