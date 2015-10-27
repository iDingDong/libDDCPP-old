//	DDCPP/standard/bits/DD_ArithmeticTrait.hpp
#ifndef DD_ARITHMETIC_TRAIT_HPP_INCLUDED_
#	define DD_ARITHMETIC_TRAIT_HPP_INCLUDED_



#	include "DD_Trait.hpp"
#	include "DD_ArithmeticLimit.hpp"



DD_DETAIL_BEGIN_
template <typename ArithmeticT_>
struct ArithmeticTrait : Trait<ArithmeticT_> {
	DD_ALIAS(Type, ArithmeticT_);

	static Type DD_CONSTEXPR digits = ArithmeticLimit<Type>::digits;
	static Type DD_CONSTEXPR min = ArithmeticLimit<Type>::min;
	static Type DD_CONSTEXPR max = ArithmeticLimit<Type>::max;


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::ArithmeticTrait;



DD_END_



#endif
