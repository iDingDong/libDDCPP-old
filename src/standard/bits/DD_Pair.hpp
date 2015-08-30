//	DDCPP/standard/bits/DD_Pair.hpp
#ifndef _DD_PAIR_HPP_INCLUDED
#	define _DD_PAIR_HPP_INCLUDED



//#	include "DD_relationship_operators.hpp"
//#	if __cplusplus >= 201103L
//#		include "DD_forward.hpp"
//#	endif
#	include "DD_EqualityComparable.hpp"
#	include "DD_LessThanComparable.hpp"
#	include "DD_swap.hpp"
#	include "DD_dereference.hpp"



DD_BEGIN
template <typename _ValueT1, typename _ValueT2 = _ValueT1>
struct Pair : LessThanComparable<Pair<_ValueT1, _ValueT2>>, EqualityComparable<Pair<_ValueT1, _ValueT2>> {
	public:
	DD_ALIAS(ThisType, Pair<_ValueT1 DD_COMMA _ValueT2>)
	DD_ALIAS(FirstValueType, _ValueT1)
	DD_ALIAS(SecondValueType, _ValueT2)
	
	
	public:
	FirstValueType first;
	SecondValueType second;
	
	
#	if __cplusplus >= 201103L
	public:
	constexpr Pair() = default;
	
	public:
	constexpr Pair(ThisType const& _origin) = default;
	
	public:
	constexpr Pair(ThisType&& _origin) = default;
	
	public:
	template <typename _ValueT1_, typename _ValueT2_>
	DD_CONSTEXPR Pair(
		_ValueT1_&& __value_1_,
		_ValueT2_&& __value_2_
	) DD_NOEXCEPT_IF(noexcept(FirstValueType(__value_1_)) && noexcept(SecondValueType(__value_2_))) : first(__value_1_), second(__value_2_) {
	}
#	else
	public:
	Pair() {
	}
	
	public:
	template <typename _ValueT1_, typename _ValueT2_>
	Pair(_ValueT1_ const& __value_1_, _ValueT2 const& __value_2_) : first(__value_1_), second(__value_2_) {
	}
#	endif
	
	
	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT_AS(swap(first, _target.first) DD_COMMA swap(second, _target.second)) {
		using DD::swap;
		swap(first, _target.first);
		swap(second, _target.second);
	}
	
	
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& _origin) = default;
	
	public:
	ThisType& operator =(ThisType&& _origin) = default;
	
	
#	endif
};



template <typename _ValueT>
struct Pair<_ValueT, _ValueT> : LessThanComparable<Pair<_ValueT, _ValueT>>, EqualityComparable<Pair<_ValueT, _ValueT>> {
	public:
	DD_ALIAS(ThisType, Pair<_ValueT DD_COMMA _ValueT>)
	DD_ALIAS(ValueType, _ValueT)
	
	DD_ALIAS(FirstValueType, ValueType)
	DD_ALIAS(SecondValueType, ValueType)
	
	
	public:
	FirstValueType first;
	SecondValueType second;
	
	
#	if __cplusplus >= 201103L
	public:
	constexpr Pair() = default;
	
	public:
	constexpr Pair(ThisType const& _origin) = default;
	
	public:
	constexpr Pair(ThisType&& _origin) = default;
	
	public:
	template <typename _ValueT1_, typename _ValueT2_>
	constexpr Pair(
		_ValueT1_&& __value_1_,
		_ValueT2_&& __value_2_
	) noexcept(noexcept(FirstValueType(__value_1_)) && noexcept(SecondValueType(__value_2_))) : first(__value_1_), second(__value_2_) {
	}
#	else
	public:
	Pair() {
	}
	
	public:
	template <typename _ValueT1_, typename _ValueT2_>
	Pair(_ValueT1_ const& __value_1_, _ValueT2 const& __value_2_) : first(__value_1_), second(__value_2_) {
	}
#	endif
	
	
	public:
	ProcessType swap() DD_NOEXCEPT_AS(DD::swap(first, second)) {
		using DD::swap;
		swap(first, second);
	}
	
	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT_AS(DD::swap(first, _target.first)) {
		using DD::swap;
		swap(first, _target.first);
		swap(second, _target.second);
	}
	
	
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& _origin) = default;
	
	public:
	ThisType& operator =(ThisType&& _origin) = default;
	
	
#	endif
};



template <typename _ValueT>
inline ProcessType swap(Pair<_ValueT, _ValueT>& _pair) DD_NOEXCEPT_AS(_pair.swap()) {
	_pair.swap();
}



template <typename _PointerT1, typename _PointerT2>
inline Pair<DD_MODIFY_TRAIT(IteratorReference, _PointerT1), DD_MODIFY_TRAIT(IteratorReference, _PointerT2)> dereference(
	Pair<_PointerT1, _PointerT2> _pair
) noexcept(noexcept(Pair<DD_MODIFY_TRAIT(IteratorReference, _PointerT1), DD_MODIFY_TRAIT(IteratorReference, _PointerT2)>{dereference(_pair.first), dereference(_pair.second)})) {
	return Pair<DD_MODIFY_TRAIT(IteratorReference, _PointerT1), DD_MODIFY_TRAIT(IteratorReference, _PointerT2)>{dereference(_pair.first), dereference(_pair.second)};
}
	



template <typename _ValueT1, typename _ValueT2>
inline ValidityType DD_CONSTEXPR operator ==(
	Pair<_ValueT1, _ValueT2> const& _pair_1,
	Pair<_ValueT1, _ValueT2> const& _pair_2
) DD_NOEXCEPT_IF(noexcept(_pair_1.first == _pair_2.first) && noexcept(_pair_1.second == _pair_2.second)) {
	return _pair_1.first == _pair_2.first && _pair_1.second == _pair_2.second;
}



template <typename _ValueT1, typename _ValueT2>
inline ValidityType DD_CONSTEXPR operator <(
	Pair<_ValueT1, _ValueT2> const& _pair_1,
	Pair<_ValueT1, _ValueT2> const& _pair_2
) DD_NOEXCEPT_IF(noexcept(_pair_1.first < _pair_2.first) && noexcept(_pair_1.second < _pair_2.second)) {
	return _pair_1.first < _pair_2.first || (_pair_1.first == _pair_2.first && _pair_1.second < _pair_2.second);
}



DD_END



#endif
