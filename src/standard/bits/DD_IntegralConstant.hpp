//	DDCPP/standard/bits/DD_IntegeralConstant.hpp
#ifndef _DD_INTERGRAL_CONSTANT_HPP_INCLUDED
#	define _DD_INTERGRAL_CONSTANT_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _ValueT, _ValueT _value_c>
struct IntegralConstant {
	DD_ALIAS(ValueType, _ValueT)
	static ValueType DD_CONSTANT value = _value_c;

#	if __cplusplus >= 201103L
	using Type = IntegralConstant<_ValueT, _value_c>;


	constexpr operator ValueType() const noexcept(true) {
		return value;
	}
#	else
	typedef IntegralConstant<_ValueT, _value_c> Type;
#	endif


};



#	if __cplusplus >= 201103L
template <bool _value_c>
using BoolConstant = IntegralConstant<bool, _value_c>;

template <SizeType _size_c>
using SizeConstant = IntegralConstant<SizeType, _size_c>;

template <DifferenceType _difference_c>
using DifferenceConstant = IntegralConstant<DifferenceType, _difference_c>;

template <typename _IntegralT>
using StdIntegralConstant = IntegralConstant<typename _IntegralT::value_type, _IntegralT::value>;
template <typename _IntegralT>
using StdBoolConstant = BoolConstant<_IntegralT::value>;
#	else
template <bool _value_c>
struct BoolConstant : IntegralConstant<bool, _value_c> {
};



template <SizeType _size_c>
struct SizeConstant : IntegralConstant<SizeType, _size_c> {
};



template <DifferenceType _difference_c>
struct DifferenceConstant : IntegralConstant<DifferenceType, _difference_c> {
};



template <typename _IntegralT>
struct StdIntegralConstant : IntegralConstant<typename _IntegralT::value_type, _IntegralT::value> {
};
#	endif



DD_ALIAS(TrueType, BoolConstant<true>)
DD_ALIAS(FalseType, BoolConstant<false>)



_DD_END



#endif
