//	DDCPP/standard/bits/DD_GreaterThan.hpp
#ifndef DD_GREATER_THAN_HPP_INCLUDED_
#	define DD_GREATER_THAN_HPP_INCLUDED_ 1



#	include "DD_IntegralConstant.hpp"
#	include "DD_ReadOnlyCall.hpp"
#	include "DD_Functor.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT1_, typename ValueT2_ = ValueT1_>
struct GreaterThan : BinaryFunctor<ValidityType, DD_MODIFY_TRAIT(ReadOnlyCall, ValueT1_), DD_MODIFY_TRAIT(ReadOnlyCall, ValueT2_)> {
	DD_ALIAS(ThisType, GreaterThan<ValueT1_ DD_COMMA ValueT2_>);
	DD_ALIAS(
		SuperType,
		BinaryFunctor<ValidityType DD_COMMA DD_MODIFY_TRAIT(ReadOnlyCall, ValueT1_) DD_COMMA DD_MODIFY_TRAIT(ReadOnlyCall, ValueT2_)>
	);

	DD_ALIAS(Default, TrueType);

	DD_INHERIT_TEMPLATE_ALIAS(ResultType);
	DD_INHERIT_TEMPLATE_ALIAS(FirstArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(SecondArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(FunctionType);


	static ResultType call(FirstArgumentType value_1_, SecondArgumentType value_2_) DD_NOEXCEPT_AS(ResultType(value_1_ < value_2_)) {
		return value_2_ < value_1_;
	}


	ResultType operator ()(FirstArgumentType value_1_, SecondArgumentType value_2_) DD_NOEXCEPT_AS(ResultType(call(value_1_, value_2_))) {
		return call(value_1_, value_2_);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::GreaterThan;



DD_END_



#endif

