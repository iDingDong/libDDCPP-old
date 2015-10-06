//	DDCPP/standard/bits/DD_LessThan.hpp
#ifndef DD_LESS_THAN_HPP_INCLUDED_
#	define DD_LESS_THAN_HPP_INCLUDED_ 1



#	include "DD_ReadOnlyCall.hpp"
#	include "DD_Functor.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT1_, typename ValueT2_ = ValueT1_>
struct LessThan : BinaryFunctor<ValidityType, DD_MODIFY_TRAIT(ReadOnlyCall, ValueT1_), DD_MODIFY_TRAIT(ReadOnlyCall, ValueT2_)> {
	DD_ALIAS(ThisType, LessThan<ValueT1_ DD_COMMA ValueT2_>);
	DD_ALIAS(
		SuperType,
		BinaryFunctor<ValidityType DD_COMMA DD_MODIFY_TRAIT(ReadOnlyCall, ValueT1_) DD_COMMA DD_MODIFY_TRAIT(ReadOnlyCall, ValueT2_)>
	);

	DD_INHERIT_TEMPLATE_ALIAS(ResultType);
	DD_INHERIT_TEMPLATE_ALIAS(FirstArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(SecondArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(FunctionType);


	static ResultType call(FirstArgumentType value_1_, SecondArgumentType value_2_) DD_NOEXCEPT_AS(
		static_cast<ResultType>(value_1_ < value_2_)
	) {
		return value_1_ < value_2_;
	}


	ResultType operator()(FirstArgumentType value_1_, SecondArgumentType value_2_) DD_NOEXCEPT_AS(
		static_cast<ResultType>(call(value_1_, value_2_))
	) {
		return call(value_1_, value_2_);
	}


};



DD_DETAIL_END_



#endif
