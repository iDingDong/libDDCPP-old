//	DDCPP/standard/bits/DD_IntegeralConstant.hpp
#ifndef DD_INTERGRAL_CONSTANT_HPP_INCLUDED_
#	define DD_INTERGRAL_CONSTANT_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, ValueT_ value_c_>
struct IntegralConstant {
	DD_ALIAS(Type, IntegralConstant<ValueT_ DD_COMMA value_c_>);
	DD_ALIAS(ValueType, ValueT_);
	static ValueType DD_CONSTANT value = value_c_;

#	if __cplusplus >= 201103L
	constexpr operator ValueType() const noexcept(true) {
		return value;
	}


#	endif
};



template <bool value_c_>
struct BoolConstant : IntegralConstant<bool, value_c_> {
};



template <SizeType size_c_>
struct SizeConstant : IntegralConstant<SizeType, size_c_> {
};



template <DifferenceType difference_c_>
struct DifferenceConstant : IntegralConstant<DifferenceType, difference_c_> {
};



template <typename IntegralT_>
struct StdIntegralConstant : IntegralConstant<typename IntegralT_::value_type, IntegralT_::value> {
};



template <typename IntegralT_>
struct StdBoolConstant : BoolConstant<IntegralT_::value> {
};



DD_ALIAS(TrueType, BoolConstant<true>);
DD_ALIAS(FalseType, BoolConstant<false>);



DD_DETAIL_END_



DD_BEGIN_
using detail_::IntegralConstant;
using detail_::BoolConstant;
using detail_::SizeConstant;
using detail_::DifferenceConstant;
using detail_::StdIntegralConstant;
using detail_::StdBoolConstant;
using detail_::TrueType;
using detail_::FalseType;



DD_END_



#endif
