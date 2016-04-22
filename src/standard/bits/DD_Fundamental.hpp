//	DDCPP/standard/bits/DD_Fundamental.hpp
#ifndef DD_FUNDAMENTAL_HPP_INCLUDED_
#	define DD_FUNDAMENTAL_HPP_INCLUDED_ 1



#	include "DD_BuildInType.hpp"
#	include "DD_ValueTypeNested.hpp"
#	include "DD_IsArithmetic.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, ValidityType is_arithmetic_c_>
struct Fundamental_ {
	public:
	DD_ALIAS(ThisType, Fundamental_<ValueT_, is_arithmetic_c_>);
	DD_VALUE_TYPE_NESTED(ValueT_);


	private:
	ValueType m_value_ DD_IN_CLASS_INITIALIZE(ValueType());


#	if __cplusplus >= 201103L
	public:
	constexpr Fundamental_() = default;

	public:
	constexpr Fundamental_(ThisType const& origin_) = default;

	public:
	constexpr Fundamental_(ThisType& origin_) = default;
#	else
	public:
	Fundamental_() throw() : m_value_() {
	}
#	endif

	public:
	Fundamental_(ValueType value_) DD_NOEXCEPT {
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
	public:
	ThisType& operator ++() {
		++m_value_;
		return *this;
	}


	public:
	ThisType& operator --() {
		--m_value_;
		return *this;
	}


	public:
	ThisType& operator +=(ThisType const& other_) {
		m_value_ += other_;
	}


	public:
	ThisType& operator -=(ThisType const& other_) {
		m_value_ -= other_;
	}


	public:
	ThisType& operator *=(ThisType const& other_) {
		m_value_ *= other_;
	}


	public:
	ThisType& operator /=(ThisType const& other_) {
		m_value_ /= other_;
	}


	public:
	ThisType operator -() {
		return ThisType(-m_value_);
	}


	public:
	DD_CONSTEXPR operator ValueType() const DD_NOEXCEPT {
		return m_value_;
	}


};



template <typename ValueT_>
struct Fundamental : Fundamental_<ValueT_, IsArithmetic<ValueT_>::value> {
};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
