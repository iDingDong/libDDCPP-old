//	DDCPP/math/bits/DD_Rational.hpp
#ifndef _DD_RATIONAL_HPP_INCLUDED
#	define _DD_RATIONAL_HPP_INCLUDED 1



#	include "../../standard/bits/DD_Tags.hpp"
#	include "../../standard/bits/DD_IsUnsigned.hpp"
#	if __cplusplus >= 201103L
#		include "../../standard/bits/DD_IsBaseOf.hpp"
#		include "../../standard/bits/DD_Common.hpp"
#		include "../../standard/bits/DD_move.hpp"
#		include "../../standard/bits/DD_forward.hpp"
#	else
#		include "../../standard/bits/DD_NestedTypeCheck.hpp"
#	endif
#	include "../../standard/bits/DD_BinaryOperators.hpp"
#	include "../../standard/bits/DD_Comparable.hpp"
#	include "../../standard/bits/DD_Pair.hpp"
#	include "DD_greatest_common_divisor.hpp"



#	define DD_RATIONAL_BEGIN DD_BEGIN namespace rational {
#	define DD_RATIONAL_END } DD_END



DD_RATIONAL_BEGIN
struct Default : DefaultTag {
	DD_ALIAS(NumeratorType, unsigned)
	DD_ALIAS(Denominator, int)
	
	
};



struct DefaultAccurate : DefaultTag {
	DD_ALIAS(NumeratorType, int)
	DD_ALIAS(Denominator, unsigned)
	
	
};



struct DefaultChar : Default {
	DD_ALIAS(NumeratorType, unsigned char)
	DD_ALIAS(Denominator, signed char)
	
	
};



struct DefaultCharAccurate : DefaultAccurate {
	DD_ALIAS(NumeratorType, signed char)
	DD_ALIAS(Denominator, unsigned char)
	
	
};



struct DefaultShort : Default {
	DD_ALIAS(NumeratorType, unsigned short)
	DD_ALIAS(Denominator, short)
	
	
};



struct DefaultShortAccurate : DefaultAccurate {
	DD_ALIAS(NumeratorType, short)
	DD_ALIAS(Denominator, unsigned short)
	
	
};



struct DefaultLong : Default {
	DD_ALIAS(NumeratorType, unsigned long)
	DD_ALIAS(Denominator, long)
	
	
};



struct DefaultLongAccurate : DefaultAccurate {
	DD_ALIAS(NumeratorType, long)
	DD_ALIAS(Denominator, unsigned long)
	
	
};



#	if __cplusplus >= 201103L
struct DefaultLongLong : Default {
	using NumeratorType = unsigned long long;
	using Denominator = long long;
	
	
};



struct DefaultLongLongAccurate : DefaultAccurate {
	using NumeratorType = long long;
	using Denominator = unsigned long long;
	
	
};



#	endif
DD_RATIONAL_END



#	undef DD_RATIONAL_BEGIN
#	undef DD_RATIONAL_END



DD_DETAIL_BEGIN
#	if __cplusplus >= 201402L
template <typename _NumeratorT, typename _DenominatorT>
Pair<_NumeratorT, _DenominatorT> constexpr _normalize(
	Pair<_NumeratorT, _DenominatorT> const& _pair
) noexcept(
	noexcept(greatest_common_divisor<CommonType<_NumeratorT, _DenominatorT>>(_pair.first, _pair.second)) &&
	noexcept(Pair<_NumeratorT, _DenominatorT>(_pair.first / __temp, _pair.second / __temp))
) {
	auto __temp = greatest_common_divisor<CommonType<_NumeratorT, _DenominatorT>>(_pair.first, _pair.second);
	return Pair<_NumeratorT, _DenominatorT>(_pair.first / __temp, _pair.second / __temp)
}
#	else
template <typename _NumeratorT, typename _DenominatorT>
Pair<_NumeratorT, _DenominatorT> constexpr _normalize(
	Pair<_NumeratorT, _DenominatorT> const& _pair,
	CommonType<_NumeratorT, _DenominatorT> __workaround = CommonType<_NumeratorT, _DenominatorT>()
) noexcept(noexcept(
	__workaround = greatest_common_divisor<CommonType<_NumeratorT, _DenominatorT>>(_pair.first, _pair.second),
	Pair<_NumeratorT, _DenominatorT>(_pair.first / __workaround, _pair.second / __workaround)
)) {
	return
		__workaround = greatest_common_divisor<CommonType<_NumeratorT, _DenominatorT>>(_pair.first, _pair.second),
		Pair<_NumeratorT, _DenominatorT>(_pair.first / __workaround, _pair.second / __workaround)
	;
}
#	endif



template <typename _NumeratorT, typename _DenominatorT, ValidityType _is_divided_by_unsigned_c = IsUnsigned<_DenominatorT>::value>
struct _Rational :
	Addable<_Rational<_NumeratorT, _DenominatorT, _is_divided_by_unsigned_c>>,
	Subtractable<_Rational<_NumeratorT, _DenominatorT, _is_divided_by_unsigned_c>>,
	Multipliable<_Rational<_NumeratorT, _DenominatorT, _is_divided_by_unsigned_c>>,
	Dividable<_Rational<_NumeratorT, _DenominatorT, _is_divided_by_unsigned_c>>,
	Comparable<_Rational<_NumeratorT, _DenominatorT, _is_divided_by_unsigned_c>>
{
	public:
	DD_ALIAS(ThisType, _Rational<_NumeratorT DD_COMMA _DenominatorT DD_COMMA _is_divided_by_unsigned_c>)
	DD_ALIAS(NumeratorType, _NumeratorT)
	DD_ALIAS(DenominatorType, _DenominatorT)
	
	public:
	DD_ALIAS(ValueType, Pair<NumeratorType DD_COMMA DenominatorType>)
	
	
	private:
	ValueType _m_value DD_IN_CLASS_INITIALIZE(ValueType(NumeratorType() DD_COMMA DenominatorType(1)));
	
	
#	if __cplusplus >= 201103L
	public:
	constexpr _Rational() = default;
	
	public:
	constexpr _Rational(ThisType const& _origin) = default;
	
	public:
	constexpr _Rational(ThisType&& _origin) = default;
#	else
	public:
	_Rational() : _m_numerator(), _m_value(NumeratorType(), DenominatorType(1)) {
	}
#	endif
	
	public:
	DD_CONSTEXPR _Rational(ValueType const& _value) : _m_value(_value) {
	}
	
#	if __cplusplus >= 201103L
	public:
	constexpr _Rational(ValueType _value) noexcept(noexcept(ValueType(move(_value)))) : _m_value(move(_value)) {
	};
	
	public:
	template <typename _NumeratorT_, typename _DenominatorT_>
	constexpr _Rational(_NumeratorT_&& __numerator_, _DenominatorT_&& __denominator_) noexcept(
		noexcept(_Rational(ValueType(forward<_NumeratorT_>(__numerator_) DD_COMMA forward<_DenominatorT_>(__denominator_))))
	) : _Rational(ValueType(forward<_NumeratorT_>(__numerator_), forward<_DenominatorT_>(__denominator_))) {
	}
#	else
	public:
	_Rational(ValueType const& _value) : _m_value(_value) {
	}
	
	public:
	template <typename _NumeratorT_, typename _DenominatorT_>
	_Rational (_NumeratorT_ const& __numerator, _DenominatorT_ const& __denominator_) : _m_value(__numerator, __denominator_) {
	}
#	endif
	
#	if __cplusplus >= 201103L
	public:
	~_Rational() = default;
	
	
#	endif
	public:
	
	
	
};



template <typename _NumeratorT, typename _DenominatorT>
struct _Rational<_NumeratorT, _DenominatorT, true> :
	Addable<_Rational<_NumeratorT, _DenominatorT, true>>,
	Subtractable<_Rational<_NumeratorT, _DenominatorT, true>>,
	Multipliable<_Rational<_NumeratorT, _DenominatorT, true>>,
	Dividable<_Rational<_NumeratorT, _DenominatorT, true>>,
	Comparable<_Rational<_NumeratorT, _DenominatorT, true>>
{
	public:
	
	
};



DD_DETAIL_END



DD_BEGIN
template <typename _NumeratorT, typename _DenominatorT = _NumeratorT>
#	if __cplusplus >= 201103L
using Rational = _detail::_Rational<_NumeratorT, _DenominatorT>;
#	else
struct Rational : _detail::_Rational<_NumeratorT, _DenominatorT> {
};
#	endif



DD_END



#endif
