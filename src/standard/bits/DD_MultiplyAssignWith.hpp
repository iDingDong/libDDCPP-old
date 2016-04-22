//	DDCPP/standard/bits/DD_MultiplyAssignWith.hpp
#ifndef DD_MULTIPLY_ASSIGN_WITH_HPP_INCLUDED_
#	define DD_MULTIPLY_ASSIGN_WITH_HPP_INCLUDED_ 1



#	include "DD_IntegralConstant.hpp"
#	include "DD_Functor.hpp"



DD_DETAIL_BEGIN_
template <typename LeftOperandT_ = void, typename RightOperandT_ = LeftOperandT_>
struct MultiplyAssignWith : BinaryFunctor<LeftOperandT_&, LeftOperandT_&, RightOperandT_ const&> {
	DD_ALIAS(SuperType, BinaryFunctor<LeftOperandT_& DD_COMMA LeftOperandT_& DD_COMMA RightOperandT_ const&>);
	DD_ALIAS(ThisType, MultiplyAssignWith<LeftOperandT_ DD_COMMA RightOperandT_>);
	DD_INHERIT_TEMPLATE_ALIAS(ResultType);
	DD_INHERIT_TEMPLATE_ALIAS(FirstArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(SecondArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(FunctionType);


	DD_ALIAS(OriginalImplementation, TrueType);


	static ResultType DD_UNCONSTRIANED_CONSTEXPR call(
		FirstArgumentType argument_1_,
		SecondArgumentType argument_2_
	) DD_NOEXCEPT_AS(static_cast<ResultType>(argument_1_ += argument_2_)) {
		return argument_1_ *= argument_2_;
	}


	ResultType DD_UNCONSTRIANED_CONSTEXPR operator ()(
		FirstArgumentType argument_1_,
		SecondArgumentType argument_2_
	) const DD_NOEXCEPT_AS(static_cast<ResultType>(call(argument_1_ DD_COMMA argument_2_))) {
		return call(argument_1_, argument_2_);
	}


};



template <>
struct MultiplyAssignWith<void, void> {
	DD_ALIAS(ThisType, MultiplyAssignWith<void DD_COMMA void>);

	DD_ALIAS(OriginalImplementation, TrueType);


	template <typename LeftOperandT__, typename RightOperandT__>
	static typename MultiplyAssignWith<LeftOperandT__, RightOperandT__>::ResultType DD_UNCONSTRIANED_CONSTEXPR call(
		LeftOperandT__& argument_1_,
		RightOperandT__ const& argument_2_
	) DD_NOEXCEPT_AS(static_cast<typename MultiplyAssignWith<LeftOperandT__ DD_COMMA RightOperandT__>::ResultType>(
		MultiplyAssignWith<LeftOperandT__ DD_COMMA RightOperandT__>()(argument_1_ DD_COMMA argument_2_)
	)) {
		return MultiplyAssignWith<LeftOperandT__, RightOperandT__>()(argument_1_, argument_2_);
	}


	template <typename LeftOperandT__, typename RightOperandT__>
	typename MultiplyAssignWith<LeftOperandT__, RightOperandT__>::ResultType DD_UNCONSTRIANED_CONSTEXPR operator ()(
		LeftOperandT__& argument_1_,
		RightOperandT__ const& argument_2_
	) const DD_NOEXCEPT_AS(static_cast<typename MultiplyAssignWith<LeftOperandT__ DD_COMMA RightOperandT__>::ResultType>(
		call(argument_1_ DD_COMMA argument_2_)
	)) {
		return call(argument_1_, argument_2_);
	}


};



MultiplyAssignWith<void, void> DD_CONSTANT multiply_assign_with;



DD_DETAIL_END_



DD_BEGIN_
using detail_::MultiplyAssignWith;

using detail_::multiply_assign_with;



DD_END_



#endif
