//	DDCPP/standard/bits/DD_Functor.hpp
#ifndef DD_FUNCTOR_HPP_INCLUDED_
#	define DD_FUNCTOR_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ResultT_, typename... ArgumentsT_>
struct Functor {
#	else
template <typename ResultT_>
struct Functor {
#	endif
	DD_ALIAS(ResultType, ResultT_);


};



template <typename ResultT_, typename ArgumentT_>
#	if __cplusplus >= 201103L
struct UnaryFunctor : Functor<ResultT_, ArgumentT_> {
#	else
struct UnaryFunctor : Functor<ResultT_> {
#	endif
	DD_ALIAS(ResultType, ResultT_);
	DD_ALIAS(ArgumentType, ArgumentT_);


};



template <typename ResultT_, typename ArgumentT1_, typename ArgumentT2_>
#	if __cplusplus >= 201103L
struct BinaryFunctor : Functor<ResultT_, ArgumentT1_, ArgumentT2_> {
#	else
struct BinaryFunctor : Functor<ResultT_> {
#	endif
	DD_ALIAS(ResultType, ResultT_);
	DD_ALIAS(FirstArgumentType, ArgumentT1_);
	DD_ALIAS(SecondArgumentType, ArgumentT2_);

#	if __cplusplus >= 201103L
	using FunctionType = ResultT_(ArgumentT1_, ArgumentT2_);
#	else
	typedef ResultT_ FunctionType(ArgumentT1_, ArgumentT2_);
#	endif


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Functor;
using detail_::UnaryFunctor;
using detail_::BinaryFunctor;



DD_END_



#endif
