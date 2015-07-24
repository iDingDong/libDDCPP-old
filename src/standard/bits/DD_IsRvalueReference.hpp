//	standard/bits/DD_IsRvalueReference.hpp
#ifndef _DD_IS_RVALUE_REFERENCE_HPP_INCLUDED
#	define _DD_IS_RVALUE_REFERENCE_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsRvalueReference'.
#	endif



#	include <type_traits>

#	include "DD_And.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsRvalueReference : StdBoolConstant<std::is_rvalue_reference<_ObjectT>> {
};



template <typename _ObjectT>
struct _IsRvalueReference<_ObjectT&&> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
template <typename... _ObjectsT>
using IsRvalueReference = AndType<detail::_IsRvalueReference<_ObjectsT>...>;



DD_END



#endif
