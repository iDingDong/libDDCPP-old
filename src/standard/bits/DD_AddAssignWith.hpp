//	DDCPP/standard/bits/DD_AddAssignWith.hpp
#ifndef DD_ADD_ASSIGN_WITH_HPP_INCLUDED_
#	define DD_ADD_ASSIGN_WITH_HPP_INCLUDED_ 1



#	include "DD_IntegralConstant.hpp"
#	include "DD_Functor.hpp"



DD_DETAIL_BEGIN_
template <typename LeftOperandT_ = void, typename RightOperandT_ = LeftOperandT_>
struct AddAssignWith : BinaryFunctor<LeftOperandT_&, LeftOperandT_&, RightOperandT_ const&> {
	DD_ALIAS(SuperType, BinaryFunctor<LeftOperandT_& DD_COMMA LeftOperandT_& DD_COMMA RightOperandT_ const&>);
	DD_ALIAS(ThisType, AddAssignWith<LeftOperandT_ DD_COMMA RightOperandT_>);
	DD_INHERIT_TEMPLATE_ALIAS(ResultType);
	DD_INHERIT_TEMPLATE_ALIAS(FirstArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(SecondArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(FunctionType);


	DD_ALIAS(OriginalImplementation, TrueType);


	static ResultType DD_UNCONSTRIANED_CONSTEXPR call(
		FirstArgumentType argument_1_,
		SecondArgumentType argument_2_
	) DD_NOEXCEPT_AS(static_cast<ResultType>(argument_1_ += argument_2_)) {
		return argument_1_ += argument_2_;
	}


	ResultType DD_UNCONSTRIANED_CONSTEXPR operator ()(
		FirstArgumentType argument_1_,
		SecondArgumentType argument_2_
	) const DD_NOEXCEPT_AS(static_cast<ResultType>(call(argument_1_ DD_COMMA argument_2_))) {
		return call(argument_1_, argument_2_);
	}


};



template <>
struct AddAssignWith<void, void> {
	DD_ALIAS(ThisType, AddAssignWith<void DD_COMMA void>);

	DD_ALIAS(OriginalImplementation, TrueType);


	template <typename LeftOperandT__, typename RightOperandT__>
	static typename AddAssignWith<LeftOperandT__, RightOperandT__>::ResultType DD_UNCONSTRIANED_CONSTEXPR call(
		LeftOperandT__& argument_1_,
		RightOperandT__ const& argument_2_
	) DD_NOEXCEPT_AS(static_cast<typename AddAssignWith<LeftOperandT__ DD_COMMA RightOperandT__>::ResultType>(
		AddAssignWith<LeftOperandT__ DD_COMMA RightOperandT__>()(argument_1_ DD_COMMA argument_2_)
	)) {
		return AddAssignWith<LeftOperandT__, RightOperandT__>()(argument_1_, argument_2_);
	}


	template <typename LeftOperandT__, typename RightOperandT__>
	typename AddAssignWith<LeftOperandT__, RightOperandT__>::ResultType DD_UNCONSTRIANED_CONSTEXPR operator ()(
		LeftOperandT__& argument_1_,
		RightOperandT__ const& argument_2_
	) const DD_NOEXCEPT_AS(static_cast<typename AddAssignWith<LeftOperandT__ DD_COMMA RightOperandT__>::ResultType>(
		call(argument_1_ DD_COMMA argument_2_)
	)) {
		return call(argument_1_, argument_2_);
	}


};



AddAssignWith<void, void> DD_CONSTANT add_assign_with;



DD_DETAIL_END_



DD_BEGIN_
using detail_::AddAssignWith;

using detail_::add_assign_with;



DD_END_



#endif
