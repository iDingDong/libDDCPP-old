//	DDCPP/standard/bits/DD_IsChar32.hpp
#ifndef _DD_IS_CHAR_32_HPP_INCLUDED
#	define _DD_IS_CHAR_32_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsChar32'.
#	endif



#	include "DD_And.hpp"
#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsChar32 : FalseType {
};



template <>
struct _IsChar32<char32_t> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
template <typename... _ObjectsT>
using IsChar32 = AndType<detail::_IsChar32<RemoveCVType<_ObjectsT>>...>;



DD_END



#endif
