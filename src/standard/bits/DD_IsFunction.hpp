//	DDCPP/standard/bits/DD_IsFunction.hpp
#ifndef _DD_IS_FUNCTION_HPP_INCLUDED
#	define _DD_IS_FUNCTION_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsFunction'.
#	endif



#	include <type_traits>
#	include "DD_And.hpp"



DD_DETAIL_BEGIN
template <typename _ObjectT>
#	if __cplusplus >= 201103L
struct _IsFunction : StdIntegralConstant<std::is_function<_ObjectT>> {
#	else
struct _IsFunction : FalseType {
#	endif
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...)> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...)> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...) const> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...) volatile> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...) const volatile> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...) const> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...) volatile> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...) const volatile> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...)&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...) const&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...) volatile&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...) const volatile&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...)&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...) const&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...) volatile&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...) const volatile&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...)&&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...) const&&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...) volatile&&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT...) const volatile&&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...)&&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...) const&&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...) volatile&&> : TrueType {
};



template <typename _ResultT, typename... _ArgumentsT>
struct _IsFunction<_ResultT(_ArgumentsT... ...) const volatile&&> : TrueType {
};



DD_DETAIL_END



DD_BEGIN
template <typename... _ObjectsT>
using IsFunction = AndType<detail::_IsFunction<_ObjectsT>...>;



DD_END



#endif
