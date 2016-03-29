//	DDCPP/math/bits/DD_Rational.hpp
#ifndef DD_RATIONAL_HPP_INCLUDED_
#	define DD_RATIONAL_HPP_INCLUDED_ 1



#	include <standard/bits/DD_SpecificTypeNested.hpp>
#	include <standard/bits/DD_fabricate.hpp>
#	include <standard/bits/DD_Pair.hpp>

#	include "DD_absolute.hpp"
#	include "DD_lowest_common_multiple.hpp"



DD_DETAIL_BEGIN_
template <typename NumberT_ = int, ValidityType auto_reduce_fraction_c_ = true>
struct Rational :
#	if __cplusplus >= 201103L
	Comparable<Rational<NumberT_>>
#	else
	Comparable<Rational<NumberT_> >
#	endif
{
	public:
	DD_ALIAS(ThisType, Rational<NumberT_ DD_COMMA auto_reduce_fraction_c_>);
	DD_SPECIFIC_TYPE_NESTED(NumberType, NumberT_);

	public:
	DD_VALUE_TYPE_NESTED(Pair<NumberType>);


	private:
	ValueType m_value_ = ValueType(0, 1);


#	if __cplusplus >= 201103L
	public:
	constexpr Rational() = default;

	public:
	constexpr Rational(ThisType const& origin_) = default;

	public:
	constexpr Rational(ThisType&& origin_) = default;

	public:
	template <typename NumeratorT__, typename DenominatorT__>
	constexpr Rational(NumeratorT__&& numerator___, DenominatorT__&& denominator___) noexcept(
		noexcept(ValueType(::DD::forward<NumeratorT__>(numerator___), ::DD::forward<DenominatorT__>(denominator___)))
	) : m_value_(::DD::forward<NumeratorT__>(numerator___), ::DD::forward<DenominatorT__>(denominator___)) {
	}

	public:
	template <typename NumberT__>
	constexpr Rational(NumberT__&& value___) noexcept(
		noexcept(ThisType(::DD::forward<NumberT__>(value___), 1))
	) : ThisType(::DD::forward<NumberT__>(value___), 1) {
	}
#	else
	public:
	Rational() m_value_(0, 1) {
	}

	public:
	template <typename NumberT__>
	Rational(NumberT__ const& value___) : m_value_(value___, 1) {
	}

	public:
	template <typename NumeratorT__, typename DenominatorT__>
	Rational(
		NumeratorT__ const& numerator___, DenominatorT__ const& denominator___
	) : m_value_(numerator___, denominator___) {
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	~Rational() = default;


#	endif
	public:
	NumberReferenceType get_numerator() DD_NOEXCEPT {
		return m_value_.first;
	}

	public:
	NumberConstReferenceType DD_CONSTEXPR get_numerator() const DD_NOEXCEPT {
		return m_value_.first;
	}


	public:
	NumberType& get_denominator() DD_NOEXCEPT {
		return m_value_.second;
	}

	public:
	NumberConstReferenceType DD_CONSTEXPR get_denominator() const DD_NOEXCEPT {
		return m_value_.second;
	}

	public:
	NumberType DD_UNCONSTRIANED_CONSTEXPR get_fraction_reduction_divisor() const DD_NOEXCEPT_AS(NumberType(
		::DD::greatest_common_divisor(
			::DD::absolute(::DD::fabricate<ThisType>().get_numerator()),
			::DD::absolute(::DD::fabricate<ThisType>().get_denominator())
		)
	) {
		return ::DD::greatest_common_divisor(::DD::absolute(get_numerator()), ::DD::absolute(get_denominator()));
	}


	public:
	ThisType DD_UNCONSTRIANED_CONSTEXPR get_reduced(NumberType const& divisor_) const DD_NOEXCEPT_AS(ThisType(
		::DD::fabricate<ThisType>().get_numerator() / divisor_ DD_COMMA
		::DD::fabricate<ThisType>().get_denominator() / divisor_
	)) {
		return ThisType(get_numerator() / divisor_, get_denominator() / divisor_);
	}

#	if __cplusplus >= 201103L
	public:
	ThisType get_reduced(NumberType const& divisor_) && DD_NOEXCEPT_IF(
		noexcept(::DD::fabricate<ThisType>().reduce(divisor_)) &&
		noexcept(ThisType(::DD::move(::DD::fabricate<ThisType>())))
	) {
		reduce(divisor_);
		return ThisType(::DD::move(*this));
	}

#	endif

	public:
	ThisType DD_UNCONSTRIANED_CONSTEXPR get_lowest_term() const DD_NOEXCEPT_AS(ThisType(
		::DD::fabricate<ThisType>().get_reduced(::DD::fabricate<ThisType>().get_fraction_reduction_divisor())
	)) {
		return get_reduced(get_fraction_reduction_divisor());
	}

#	if __cplusplus >= 201103L
	public:
	ThisType get_lowest_term() && DD_NOEXCEPT_IF(
		noexcept(::DD::fabricate<ThisType>().reduce_fraction()) &&
		noexcept(ThisType(::DD::move(::DD::fabricate<ThisType>())))
	) {
		reduce_fraction();
		return ThisType(::DD::move(*this));
	}

#	endif

	public:
	ProcessType reduce(NumberType const& divisor_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().get_numerator() /= divisor_
	) {
		get_numerator() /= divisor_;
		get_denominator() /= divisor_;
	}


	public:
	ProcessType reduce_fraction() DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().reduce(::DD::fabricate<ThisType>().get_fraction_reduction_divisor())
	) {
		reduce(get_fraction_reduction_divisor());
	}


	//public:
	//static ProcessType add_with(ThisType& rational_1__, ThisType const& rational_2__) DD_NOEXCEPT_AS() {
		//rational_1__.get_numerator()
	//}


	public:
	template <typename IteratorT__>
	IteratorT__ unguarded_write_to_string(IteratorT__ begin___) const DD_NOEXCEPT {
		begin___ = ::DD::unguarded_write_to_string(get_numerator(), begin___);
		*begin___ = DD_MODIFY_TRAIT(IteratorValue, IteratorT__)('/');
		return ::DD::unguarded_write_to_string(get_denominator(), begin___ + 1);
	}


	public:
	template <typename IteratorT__>
	IteratorT__ write_to_string(IteratorT__ begin___, IteratorT__ end___) const DD_NOEXCEPT {
		begin___ = ::DD::write_to_string(get_numerator(), begin___, end___);
		if (begin__ != end__) {
			*begin___ = DD_MODIFY_TRAIT(IteratorValue, IteratorT__)('/');
			return ::DD::write_to_string(get_denominator(), begin___ + 1, end___);
		}
		return end___;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;
#	else
	public:
	template <typename ValueT__>
	ThisType& operator =(ValueT__ origin_) {

	}
#	endif


	public:
	ThisType operator -() const DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT_AS(ThisType(
		-::DD::fabricate<ThisType>().get_numerator() DD_COMMA ::DD::fabricate<ThisType>().get_denominator()
	)) {
		return ThisType(-get_numerator(), get_denominator());
	}

#	if __cplusplus >= 201103L
#	endif


};



template <typename NumberT_>
struct Rational<NumberT_, true> : private Rational<NumberT_, false> {
	public:
	DD_ALIAS(SuperType, Rational<NumberT_ DD_COMMA false>)
	DD_ALIAS(ThisType, Rational<NumberT_ DD_COMMA true>);
	DD_SPECIFIC_TYPE_NESTED(NumberType, NumberT_);


#	if __cplusplus >= 201103L
    public:
	constexpr Rational() = default;

	public:
	constexpr Rational(ThisType const& origin_) = default;

	public:
	constexpr Rational(ThisType&& origin_) = default;

	public:
	constexpr Rational(SuperType const& origin_) noexcept(
		noexcept(SuperType(origin_.get_lowest_term()))
	) : SuperType(origin_.get_lowest_term()) {
	}

	public:
	constexpr Rational(SuperType&& origin_) noexcept(
		noexcept(SuperType(::DD::move(origin_).get_lowest_term()))
	) : SuperType(::DD::move(origin_).get_lowest_term()) {
	}

	public:
	template <typename NumeratorT__, typename DenominatorT__>
	constexpr Rational(NumeratorT__&& numerator___, DenominatorT__&& denominator___) noexcept(noexcept(
		ThisType(SuperType(::DD::forward<NumeratorT__>(numerator___), ::DD::forward<DenominatorT__>(denominator___)))
	)) : ThisType(SuperType(::DD::forward<NumeratorT__>(numerator___), ::DD::forward<DenominatorT__>(denominator___))) {
	}
#	else
	public:
	Rational() {
	}
#	endif


	public:
	NumberConstReferenceType DD_CONSTEXPR get_numerator() const DD_NOEXCEPT {
		return SuperType::get_numerator();
	}


	public:
	NumberConstReferenceType DD_CONSTEXPR get_denominator() const DD_NOEXCEPT {
		return SuperType::get_denominator();
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;

	public:
	ThisType& operator =(ThisType& origin_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>() = static_cast<ThisType const&>(origin_)
	) {
		*this = static_cast<ThisType const&>(origin_);
	}

	public:
	template <typename ValueT__>
	ThisType& operator =(ValueT__&& value___) noexcept(
		noexcept((::DD::fabricate<SuperType>() = ::DD::forward<ValueT__>(value___)).reduce_fraction())
	) {
		static_cast<SuperType&>(*this) = ::DD::forward<ValueT__>(value___);
		reduce_fraction();
	}

#	endif
	public:
	ThisType& operator =(SuperType const& origin_) {
		static_cast<SuperType&>(*this) = origin_;
		reduce_fraction();
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Rational;



DD_END_



#endif
