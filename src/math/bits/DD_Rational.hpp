//	DDCPP/math/bits/DD_Rational.hpp
#ifndef DD_RATIONAL_HPP_INCLUDED_
#	define DD_RATIONAL_HPP_INCLUDED_ 1



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



#	define DD_RATIONAL_BEGIN DD_BEGIN_ namespace rational {
#	define DD_RATIONAL_END } DD_END_



DD_RATIONAL_BEGIN
struct Default : DefaultTag {
	DD_ALIAS(NumeratorType, unsigned);
	DD_ALIAS(Denominator, int);


};



struct DefaultAccurate : DefaultTag {
	DD_ALIAS(NumeratorType, int);
	DD_ALIAS(Denominator, unsigned);


};



struct DefaultChar : Default {
	DD_ALIAS(NumeratorType, unsigned char);
	DD_ALIAS(Denominator, signed char);


};



struct DefaultCharAccurate : DefaultAccurate {
	DD_ALIAS(NumeratorType, signed char);
	DD_ALIAS(Denominator, unsigned char);


};



struct DefaultShort : Default {
	DD_ALIAS(NumeratorType, unsigned short);
	DD_ALIAS(Denominator, short);


};



struct DefaultShortAccurate : DefaultAccurate {
	DD_ALIAS(NumeratorType, short);
	DD_ALIAS(Denominator, unsigned short);


};



struct DefaultLong : Default {
	DD_ALIAS(NumeratorType, unsigned long);
	DD_ALIAS(Denominator, long);


};



struct DefaultLongAccurate : DefaultAccurate {
	DD_ALIAS(NumeratorType, long);
	DD_ALIAS(Denominator, unsigned long);


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



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201402L
template <typename NumeratorT_, typename DenominatorT_>
Pair<NumeratorT_, DenominatorT_> constexpr normalize_(
	Pair<NumeratorT_, DenominatorT_> const& pair_
) noexcept(
	noexcept(greatest_common_divisor<CommonType<NumeratorT_, DenominatorT_>>(pair_.first, pair_.second)) &&
	noexcept(Pair<NumeratorT_, DenominatorT_>(
		pair_.first / fabricate<Pair<NumeratorT_, DenominatorT_>>(), pair_.second / fabricate<Pair<NumeratorT_, DenominatorT_>>()
	))
) {
	auto temp__ = greatest_common_divisor<CommonType<NumeratorT_, DenominatorT_>>(pair_.first, pair_.second);
	return Pair<NumeratorT_, DenominatorT_>(pair_.first / temp__, pair_.second / temp__);
}
#	else
template <typename NumeratorT_, typename DenominatorT_>
Pair<NumeratorT_, DenominatorT_> constexpr normalize_(
	Pair<NumeratorT_, DenominatorT_> const& pair_,
	CommonType<NumeratorT_, DenominatorT_> workaround__ = CommonType<NumeratorT_, DenominatorT_>()
) noexcept(noexcept(
	workaround__ = greatest_common_divisor<CommonType<NumeratorT_, DenominatorT_>>(pair_.first, pair_.second),
	Pair<NumeratorT_, DenominatorT_>(pair_.first / workaround__, pair_.second / workaround__)
)) {
	return
		workaround__ = greatest_common_divisor<CommonType<NumeratorT_, DenominatorT_>>(pair_.first, pair_.second),
		Pair<NumeratorT_, DenominatorT_>(pair_.first / workaround__, pair_.second / workaround__)
	;
}
#	endif



template <typename NumeratorT_, typename DenominatorT_, ValidityType is_divided_by_unsigned_c_ = IsUnsigned<DenominatorT_>::value>
struct Rational_ :
	Addable<Rational_<NumeratorT_, DenominatorT_, is_divided_by_unsigned_c_>>,
	Subtractable<Rational_<NumeratorT_, DenominatorT_, is_divided_by_unsigned_c_>>,
	Multipliable<Rational_<NumeratorT_, DenominatorT_, is_divided_by_unsigned_c_>>,
	Dividable<Rational_<NumeratorT_, DenominatorT_, is_divided_by_unsigned_c_>>,
	Comparable<Rational_<NumeratorT_, DenominatorT_, is_divided_by_unsigned_c_>>
{
	public:
	DD_ALIAS(ThisType, Rational_<NumeratorT_ DD_COMMA DenominatorT_ DD_COMMA is_divided_by_unsigned_c_>);
	DD_ALIAS(NumeratorType, NumeratorT_);
	DD_ALIAS(DenominatorType, DenominatorT_);

	public:
	DD_ALIAS(ValueType, Pair<NumeratorType DD_COMMA DenominatorType>);


	private:
	ValueType m_value_ DD_IN_CLASS_INITIALIZE(ValueType(NumeratorType() DD_COMMA DenominatorType(1)));


#	if __cplusplus >= 201103L
	public:
	constexpr Rational_() = default;

	public:
	constexpr Rational_(ThisType const& origin_) = default;

	public:
	constexpr Rational_(ThisType&& origin_) = default;
#	else
	public:
	Rational_() : m_numerator_(), m_value_(NumeratorType(), DenominatorType(1)) {
	}
#	endif

	public:
	DD_CONSTEXPR Rational_(ValueType const& value_) : m_value_(value_) {
	}

#	if __cplusplus >= 201103L
	public:
	constexpr Rational_(ValueType value_) noexcept(noexcept(ValueType(move(value_)))) : m_value_(move(value_)) {
	};

	public:
	template <typename NumeratorT__, typename DenominatorT__>
	constexpr Rational_(NumeratorT__&& numerator___, DenominatorT__&& denominator___) noexcept(
		noexcept(Rational_(ValueType(forward<NumeratorT__>(numerator___) DD_COMMA forward<DenominatorT__>(denominator___))))
	) : Rational_(ValueType(forward<NumeratorT__>(numerator___), forward<DenominatorT__>(denominator___))) {
	}
#	else
	public:
	Rational_(ValueType const& value_) : m_value_(value_) {
	}

	public:
	template <typename NumeratorT__, typename DenominatorT__>
	Rational_ (NumeratorT__ const& numerator__, DenominatorT__ const& denominator___) : m_value_(numerator__, denominator___) {
	}
#	endif

#	if __cplusplus >= 201103L
	public:
	~Rational_() = default;


#	endif
	public:



};



template <typename NumeratorT_, typename DenominatorT_>
struct Rational_<NumeratorT_, DenominatorT_, true> :
	Addable<Rational_<NumeratorT_, DenominatorT_, true>>,
	Subtractable<Rational_<NumeratorT_, DenominatorT_, true>>,
	Multipliable<Rational_<NumeratorT_, DenominatorT_, true>>,
	Dividable<Rational_<NumeratorT_, DenominatorT_, true>>,
	Comparable<Rational_<NumeratorT_, DenominatorT_, true>>
{
	public:


};



DD_DETAIL_END_



DD_BEGIN_
template <typename NumeratorT_, typename DenominatorT_ = NumeratorT_>
#	if __cplusplus >= 201103L
using Rational = detail_::Rational_<NumeratorT_, DenominatorT_>;
#	else
struct Rational : detail_::Rational_<NumeratorT_, DenominatorT_> {
};
#	endif



DD_END_



#endif
