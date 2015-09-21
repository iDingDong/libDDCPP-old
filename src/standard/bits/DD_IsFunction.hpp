//	DDCPP/standard/bits/DD_IsFunction.hpp
#ifndef _DD_IS_FUNCTION_HPP_INCLUDED
#	define _DD_IS_FUNCTION_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsFunction'.
#	endif



#	include <type_traits>
#	include "DD_And.hpp"



_DD_DETAIL_BEGIN
template <typename _ObjectT>
struct _IsFunction : StdIntegralConstant<std::is_function<_ObjectT>> {
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



_DD_DETAIL_END



_DD_BEGIN
template <typename... _ObjectsT>
using IsFunction = AndType<_detail::_IsFunction<_ObjectsT>...>;



_DD_END



#endif
