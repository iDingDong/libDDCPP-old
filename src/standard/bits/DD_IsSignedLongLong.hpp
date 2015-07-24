//	standard/bits/DD_IsSignedLongLong.hpp
#ifndef _DD_IS_SIGNED_LONG_LONG_HPP_INCLUDED
#	define _DD_IS_SIGNED_LONG_LONG_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsLongLong'.
#	endif



#	include "DD_And.hpp"
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsSignedLongLong : FalseType {
};



template <>
struct _IsSignedLongLong<signed long long> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
template <typename... _ObjectsT>
using IsSignedLongLong = AndType<detail::_IsSignedLongLong<RemoveCVType<_ObjectsT>>...>;



DD_END



#endif
