//	DDCPP/standard/bits/DD_IsFunction.hpp
#ifndef DD_IS_FUNCTION_HPP_INCLUDED_
#	define DD_IS_FUNCTION_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsFunction'.
#	endif



#	include <type_traits>
#	include "DD_And.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct IsFunction_ : StdIntegralConstant<std::is_function<ObjectT_>> {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...)> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...)> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...) const> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...) volatile> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...) const volatile> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...) const> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...) volatile> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...) const volatile> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...)&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...) const&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...) volatile&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...) const volatile&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...)&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...) const&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...) volatile&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...) const volatile&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...)&&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...) const&&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...) volatile&&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_...) const volatile&&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...)&&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...) const&&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...) volatile&&> : TrueType {
};



template <typename ResultT_, typename... ArgumentsT_>
struct IsFunction_<ResultT_(ArgumentsT_... ...) const volatile&&> : TrueType {
};



template <typename... ObjectsT_>
struct IsFunction : AndType<IsFunction_<ObjectsT_>...> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsFunction;



DD_END_



#endif
