//	DDCPP/standard/bits/DD_Function.hpp
#ifndef _DD_FUNCTION_HPP_INCLUDED
#	define _DD_FUNCTION_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Function'.



#	endif
#	include <functional>

#	include "DD_Functor.hpp"




_DD_BEGIN
template <typename _FunctionT>
struct Function {
	static_assert(false, "Only non-variable-argument functions are accepted by 'DD::Function'.");


};



template <typename _ResultT, typename... _ArgumentsT>
struct Function<_ResultT(_ArgumentsT...)> : Functor<_ResultT, _ArgumentsT...>, std::function<_ResultT(_ArgumentsT...)> {
};



_DD_END



#endif
