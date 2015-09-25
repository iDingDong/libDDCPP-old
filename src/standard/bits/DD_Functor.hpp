//	DDCPP/standard/bits/DD_Functor.hpp
#ifndef _DD_FUNCTOR_HPP_INCLUDED
#	define _DD_FUNCTOR_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
#	if __cplusplus >= 201103L
template <typename _ResultT, typename... _ArgumentsT>
struct Functor {
#	else
template <typename _ResultT>
struct Functor {
#	endif
	DD_ALIAS(ResultType, _ResultT);


};



template <typename _ResultT, typename _ArgumentT>
#	if __cplusplus >= 201103L
struct UnaryFunctor : Functor<_ResultT, _ArgumentT> {
#	else
struct UnaryFunctor : Functor<_ResultT> {
#	endif
	DD_ALIAS(ResultType, _ResultT);
	DD_ALIAS(ArgumentType, _ArgumentT);


};



template <typename _ResultT, typename _ArgumentT1, typename _ArgumentT2>
#	if __cplusplus >= 201103L
struct BinaryFunctor : Functor<_ResultT, _ArgumentT1, _ArgumentT2> {
#	else
struct BinaryFunctor : Functor<_ResultT> {
#	endif
	DD_ALIAS(ResultType, _ResultT);
	DD_ALIAS(FirstArgumentType, _ArgumentT1);
	DD_ALIAS(SecondArgumentType, _ArgumentT2);


};



_DD_END



#endif
