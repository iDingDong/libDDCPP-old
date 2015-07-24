//	standard/bits/DD_Functor.hpp
#ifndef _DD_FUNCTOR_HPP_INCLUDED
#	define _DD_FUNCTOR_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ResultT, typename _ArgumentT>
struct UnaryFunctor {
	DD_ALIAS(ResultType, _ResultT)
	DD_ALIAS(ArgumentType, _ArgumentT)
	
	
};



template <typename _ResultT, typename _ArgumentT1, typename _ArgumentT2>
struct BinaryFunctor {
	DD_ALIAS(ResultType, _ResultT)
	DD_ALIAS(FirstArgumentType, _ArgumentT1)
	DD_ALIAS(SecondArgumentType, _ArgumentT2)
	
	
};



#	if __cplusplus >= 201103L
template <typename _ResultT, typename... _ArgumentsT>
struct Functor {
	DD_ALIAS(ResultType, _ResultT)
	
	
};



template <typename _ResultT, typename _ArgumentT>
struct Functor<_ResultT, _ArgumentT> : UnaryFunctor<_ResultT, _ArgumentT> {
	DD_ALIAS(ResultType, _ResultT)
	DD_ALIAS(ArgumentType, _ArgumentT)
	
	
};



template <typename _ResultT, typename _ArgumentT1, typename _ArgumentT2>
struct Functor<_ResultT, _ArgumentT1, _ArgumentT2> : BinaryFunctor<_ResultT, _ArgumentT1, _ArgumentT2> {
	DD_ALIAS(ResultType, _ResultT)
	DD_ALIAS(FirstArgumentType, _ArgumentT1)
	DD_ALIAS(SecondArgumentType, _ArgumentT2)
	
	
};



#	endif
DD_END



#endif
