//	DDCPP/standard/bits/DD_GreaterThan.hpp
#ifndef DD_GREATER_THAN_HPP_INCLUDED_
#	define DD_GREATER_THAN_HPP_INCLUDED_ 1



#	include "DD_LessThan.hpp"



DD_DETAIL_BEGIN_
template <typename LeftOperandT_ = void, typename RightOperandT_ = LeftOperandT_>
struct GreaterThan : BinaryFunctor<ValidityType, LeftOperandT_ const&, RightOperandT_ const&> {
	DD_ALIAS(SuperType, BinaryFunctor<ValidityType DD_COMMA LeftOperandT_ const& DD_COMMA RightOperandT_ const&>);
	DD_ALIAS(ThisType, GreaterThan<LeftOperandT_ DD_COMMA RightOperandT_>);

	DD_ALIAS(OriginalImplementation, TrueType);

	DD_INHERIT_TEMPLATE_ALIAS(ResultType);
	DD_INHERIT_TEMPLATE_ALIAS(FirstArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(SecondArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(FunctionType);


	static ResultType DD_UNCONSTRIANED_CONSTEXPR call(
		FirstArgumentType argument_1_,
		SecondArgumentType argument_2_
	) DD_NOEXCEPT_AS(
		static_cast<ResultType>(LessThan<RightOperandT_ DD_COMMA LeftOperandT_>()(argument_2_ DD_COMMA argument_1_))
	) {
		return LessThan<RightOperandT_, LeftOperandT_>()(argument_2_, argument_1_);
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
struct GreaterThan<void, void> {
	DD_ALIAS(ThisType, GreaterThan<void DD_COMMA void>);

	DD_ALIAS(OriginalImplementation, TrueType);


	template <typename LeftOperandT__, typename RightOperandT__>
	static typename GreaterThan<LeftOperandT__, RightOperandT__>::ResultType DD_UNCONSTRIANED_CONSTEXPR call(
		LeftOperandT__ const& argument_1_,
		RightOperandT__ const& argument_2_
	) DD_NOEXCEPT_AS(static_cast<typename GreaterThan<LeftOperandT__ DD_COMMA RightOperandT__>::ResultType>(
		GreaterThan<LeftOperandT__ DD_COMMA RightOperandT__>()(argument_1_ DD_COMMA argument_2_)
	)) {
		return GreaterThan<LeftOperandT__, RightOperandT__>()(argument_1_, argument_2_);
	}

	template <typename LeftOperandT__, typename RightOperandT__>
	typename GreaterThan<LeftOperandT__, RightOperandT__>::ResultType DD_UNCONSTRIANED_CONSTEXPR operator ()(
		LeftOperandT__ const& argument_1_,
		RightOperandT__ const& argument_2_
	) const DD_NOEXCEPT_AS(static_cast<typename GreaterThan<LeftOperandT__ DD_COMMA RightOperandT__>::ResultType>(
		call(argument_1_ DD_COMMA argument_2_)
	)) {
		return call(argument_1_, argument_2_);
	}


};



GreaterThan<void, void> DD_CONSTANT greater_than;



DD_DETAIL_END_



DD_BEGIN_
using detail_::GreaterThan;

using detail_::greater_than;



DD_END_



#endif
