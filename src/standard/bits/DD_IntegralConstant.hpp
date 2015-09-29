//	DDCPP/standard/bits/DD_IntegeralConstant.hpp
#ifndef DD_INTERGRAL_CONSTANT_HPP_INCLUDED_
#	define DD_INTERGRAL_CONSTANT_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename ValueT_, ValueT_ value_c_>
struct IntegralConstant {
	DD_ALIAS(ValueType, ValueT_);
	static ValueType DD_CONSTANT value = value_c_;

#	if __cplusplus >= 201103L
	using Type = IntegralConstant<ValueT_, value_c_>;


	constexpr operator ValueType() const noexcept(true) {
		return value;
	}
#	else
	typedef IntegralConstant<ValueT_, value_c_> Type;
#	endif


};



#	if __cplusplus >= 201103L
template <bool value_c_>
using BoolConstant = IntegralConstant<bool, value_c_>;

template <SizeType size_c_>
using SizeConstant = IntegralConstant<SizeType, size_c_>;

template <DifferenceType difference_c_>
using DifferenceConstant = IntegralConstant<DifferenceType, difference_c_>;

template <typename IntegralT_>
using StdIntegralConstant = IntegralConstant<typename IntegralT_::value_type, IntegralT_::value>;
template <typename IntegralT_>
using StdBoolConstant = BoolConstant<IntegralT_::value>;
#	else
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
#	endif



DD_ALIAS(TrueType, BoolConstant<true>);
DD_ALIAS(FalseType, BoolConstant<false>);



DD_END_



#endif
