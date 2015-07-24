//	standard/bits/DD_IsChar16.hpp
#ifndef _DD_IS_CHAR_16_HPP_INCLUDED
#	define _DD_IS_CHAR_16_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsChar16'.
#	endif



#	include "DD_And.hpp"
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsChar16 : FalseType {
};



template <>
struct _IsChar16<char16_t> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
template <typename... _ObjectsT>
using IsChar16 = AndType<detail::_IsChar16<RemoveCVType<_ObjectsT>>...>;



DD_END



#endif
