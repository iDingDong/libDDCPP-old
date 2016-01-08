//	DDCPP/standard/bits/DD_EqualTo.hpp
#ifndef DD_EQUAL_TO_HPP_INCLUDED_
#	define DD_EQUAL_TO_HPP_INCLUDED_ 1



#	include "DD_IntegralConstant.hpp"
#	include "DD_Functor.hpp"



DD_DETAIL_BEGIN_
template <typename LeftOperandT_ = void, typename RightOperandT_ = LeftOperandT_>
struct EqualTo : BinaryFunctor<ValidityType, LeftOperandT_ const&, RightOperandT_ const&> {
	DD_ALIAS(SuperType, BinaryFunctor<ValidityType DD_COMMA LeftOperandT_ const& DD_COMMA RightOperandT_ const&>);
	DD_ALIAS(ThisType, EqualTo<LeftOperandT_ DD_COMMA RightOperandT_>);

	DD_ALIAS(OriginalImplementation, TrueType);

	DD_INHERIT_TEMPLATE_ALIAS(ResultType);
	DD_INHERIT_TEMPLATE_ALIAS(FirstArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(SecondArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(FunctionType);


	static ResultType DD_UNCONSTRIANED_CONSTEXPR call(
		FirstArgumentType argument_1_,
		SecondArgumentType argument_2_
	) DD_NOEXCEPT_AS(
		static_cast<ResultType>(argument_1_ == argument_2_)
	) {
		return argument_1_ == argument_2_;
	}


	ResultType DD_UNCONSTRIANED_CONSTEXPR operator ()(
		FirstArgumentType argument_1_,
		SecondArgumentType argument_2_
	) DD_NOEXCEPT_AS(
		static_cast<ResultType>(call(argument_1_ DD_COMMA argument_2_))
	) {
		return call(argument_1_, argument_2_);
	}


};



template <>
struct EqualTo<void, void> {
	DD_ALIAS(ThisType, EqualTo<void DD_COMMA void>);

	DD_ALIAS(OriginalImplementation, TrueType);


	template <typename LeftOperandT__, typename RightOperandT__>
	static typename EqualTo<LeftOperandT__, RightOperandT__>::ResultType DD_UNCONSTRIANED_CONSTEXPR call(
		LeftOperandT__ const& argument_1_,
		RightOperandT__ const& argument_2_
	) DD_NOEXCEPT_AS(static_cast<typename EqualTo<LeftOperandT__ DD_COMMA RightOperandT__>::ResultType>(
		EqualTo<LeftOperandT__ DD_COMMA RightOperandT__>()(argument_1_ DD_COMMA argument_2_)
	)) {
		return EqualTo<LeftOperandT__, RightOperandT__>()(argument_1_, argument_2_);
	}

	template <typename LeftOperandT__, typename RightOperandT__>
	typename EqualTo<LeftOperandT__, RightOperandT__>::ResultType DD_UNCONSTRIANED_CONSTEXPR operator ()(
		LeftOperandT__ const& argument_1_,
		RightOperandT__ const& argument_2_
	) const DD_NOEXCEPT_AS(static_cast<typename EqualTo<LeftOperandT__ DD_COMMA RightOperandT__>::ResultType>(
		call(argument_1_ DD_COMMA argument_2_)
	)) {
		return call(argument_1_, argument_2_);
	}


};



EqualTo<void, void> DD_CONSTANT equal_to;



DD_DETAIL_END_



DD_BEGIN_
using detail_::EqualTo;

using detail_::equal_to;



DD_END_



#endif
