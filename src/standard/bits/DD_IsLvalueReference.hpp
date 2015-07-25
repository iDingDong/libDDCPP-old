//	DDCPP/standard/bits/DD_IsLvalueReference.hpp
#ifndef _DD_IS_LVALUE_REFERENCE_HPP_INCLUDED
#	define _DD_IS_LVALUE_REFERENCE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsLvalueReference'.
#	endif



#	include <type_traits>

#	include "DD_And.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsLvalueReference : StdBoolConstant<std::is_lvalue_reference<_ObjectT>> {
};



template <typename _ObjectT>
struct _IsLvalueReference<_ObjectT&> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
template <typename... _ObjectsT>
using IsLvalueReference = AndType<detail::_IsLvalueReference<_ObjectsT>...>;



DD_END



#endif
