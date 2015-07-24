//	standard/bits/DD_IsUnsignedLongLong.hpp
#ifndef _DD_IS_UNSIGNED_LONG_LONG_HPP_INCLUDED
#	define _DD_IS_UNSIGNED_LONG_LONG_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsUnsignedLongLong'.
#	endif



#	if __cplusplus >= 201103L
#		include "DD_And.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsUnsignedLongLong : FalseType {
};



template <>
struct _IsUnsignedLongLong<unsigned long long> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
template <typename... _ObjectsT>
using IsUnsignedLongLong = AndType<detail::_IsUnsignedLongLong<RemoveCVType<_ObjectsT>>...>;



DD_END



#endif
