//	DDCPP/standard/bits/DD_IsReference.hpp
#ifndef _DD_IS_REFERENCE_HPP_INCLUDED
#	define _DD_IS_REFERENCE_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_Or.hpp"
#		include "DD_IsLvalueReference.hpp"
#		include "DD_IsRvalueReference.hpp"
#	else
#		include "DD_IntegralConstant.hpp"
#	endif



DD_DETAIL_BEGIN
template <typename _ObjectT>
#	if __cplusplus >= 201103L
using _IsReference = OrType<IsLvalueReference<_ObjectT>, IsRvalueReference<_ObjectT>>;
#	else
struct _IsReference : FalseType {
};



template <typename _ObjectT>
struct _IsReference<_ObjectT&> : TrueType {
};
#	endif



DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsReference = AndType<_detail::_IsReference<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct IsReference : _detail::_IsReference<_ObjectT> {
};
#	endif



DD_END



#endif
