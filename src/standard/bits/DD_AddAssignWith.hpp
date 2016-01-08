//	DDCPP/standard/bits/DD_AddAssignWith.hpp
#ifndef DD_ADD_ASSIGN_WITH_HPP_INCLUDED_
#	define DD_ADD_ASSIGN_WITH_HPP_INCLUDED_ 1



#	include "DD_AddConst.hpp"
#	include "DD_AddLvalueReference.hpp"
#	include "DD_Functor.hpp"



DD_DETAIL_BEGIN_
template <typename LeftOperandT_ = void, typename RightOperandT_ = LeftOperandT_>
struct AddAssignWith : BinaryFunctor<
	DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT_),
	DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT_),
	DD_MODIFY_TRAIT(AddLvalueReference, DD_MODIFY_TRAIT(AddConst, RightOperandT_))
> {
	DD_ALIAS(SuperType, BinaryFunctor<
		DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT_) DD_COMMA
		DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT_) DD_COMMA
		DD_MODIFY_TRAIT(AddLvalueReference, DD_MODIFY_TRAIT(AddConst, RightOperandT_))
	>);
	DD_ALIAS(ThisType, AddAssignWith<LeftOperandT_ DD_COMMA RightOperandT_>);
	DD_INHERIT_TEMPLATE_ALIAS(ResultType);
	DD_INHERIT_TEMPLATE_ALIAS(FirstArgumentType);
	DD_INHERIT_TEMPLATE_ALIAS(SecondArgumentType);


	static ResultType call(
		FirstArgumentType first_argument_,
		SecondArgumentType second_argument_
	) DD_NOEXCEPT_AS(static_cast<ResultType>(first_argument_ += second_argument_)) {
		return first_argument_ += second_argument_;
	}


	ResultType operator ()(
		FirstArgumentType first_argument_,
		SecondArgumentType second_argument_
	) const DD_NOEXCEPT_AS(static_cast<ResultType>(call(first_argument_ DD_COMMA second_argument_))) {
		return call(first_argument_, second_argument_);
	}


};



template <>
struct AddAssignWith<void, void> {
	DD_ALIAS(ThisType, AddAssignWith<void DD_COMMA void>);


	template <typename LeftOperandT__, typename RightOperandT__>
	static DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT__) call(
		DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT__) first_argument_,
		DD_MODIFY_TRAIT(AddLvalueReference, DD_MODIFY_TRAIT(AddConst, RightOperandT__)) second_argument_
	) DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT__)>(
		AddAssignWith<LeftOperandT__, RightOperandT__>()(first_argument_, second_argument_)
	)) {
		return AddAssignWith<LeftOperandT__, RightOperandT__>()(first_argument_, second_argument_);
	}


	template <typename LeftOperandT__, typename RightOperandT__>
	DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT__) operator()(
		DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT__) first_argument_,
		DD_MODIFY_TRAIT(AddLvalueReference, DD_MODIFY_TRAIT(AddConst, RightOperandT__)) second_argument_
	) const DD_NOEXCEPT_AS(static_cast<DD_MODIFY_TRAIT(AddLvalueReference, LeftOperandT__)>(
		call(first_argument_ DD_COMMA second_argument_)
	)) {
		return call(first_argument_ DD_COMMA second_argument_);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::AddAssignWith;



DD_END_



#endif
