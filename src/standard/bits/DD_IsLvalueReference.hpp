//	DDCPP/standard/bits/DD_IsLvalueReference.hpp
#ifndef _DD_IS_LVALUE_REFERENCE_HPP_INCLUDED
#	define _DD_IS_LVALUE_REFERENCE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsLvalueReference'.
#	endif



#	include <type_traits>

#	include "DD_And.hpp"



_DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsLvalueReference : StdBoolConstant<std::is_lvalue_reference<_ObjectT>> {
};



template <typename _ObjectT>
struct _IsLvalueReference<_ObjectT&> : TrueType {
};



_DD_DETAIL_END



_DD_BEGIN
template <typename... _ObjectsT>
using IsLvalueReference = AndType<_detail::_IsLvalueReference<_ObjectsT>...>;



_DD_END



#endif
