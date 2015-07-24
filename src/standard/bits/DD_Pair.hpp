//	standard/bits/DD_Pair.hpp
#ifndef _DD_PAIR_HPP_INCLUDED
#	define _DD_PAIR_HPP_INCLUDED



#	include "DD_relationship_operators.hpp"
#	include "DD_swap.hpp"
#	include "DD_dereference.hpp"



DD_BEGIN
template <typename _ValueT1, typename _ValueT2 = _ValueT1>
struct Pair {
	public:
#	if __cplusplus >= 201103L
	using ThisType = Pair<_ValueT1, _ValueT2>;
#	else
	typedef Pair<_ValueT1, _ValueT2> ThisType;
#	endif
	DD_ALIAS(FirstValueType, _ValueT1)
	DD_ALIAS(SecondValueType, _ValueT2)
	
	
	public:
	FirstValueType first;
	SecondValueType second;
	
	
	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT_IF(
		noexcept(DD::swap(first, _target.first)) && noexcept(DD::swap(second, _target.second))
	) {
		using DD::swap;
		swap(this->first, _target.first);
		swap(this->second, _target.second);
	}
	
	
};



template <typename _ValueT>
struct Pair<_ValueT, _ValueT> {
	public:
#	if __cplusplus >= 201103L
	using ThisType = Pair<_ValueT, _ValueT>;
#	else
	typedef Pair<_ValueT, _ValueT> ThisType;
#	endif
	DD_ALIAS(ValueType, _ValueT)
	
	DD_ALIAS(FirstValueType, ValueType)
	DD_ALIAS(SecondValueType, ValueType)
	
	
	public:
	FirstValueType first;
	SecondValueType second;
	
	
	public:
	ProcessType swap() DD_NOEXCEPT_AS(DD::swap(first, second)) {
		using DD::swap;
		swap(this->first, this->second);
	}
	
	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT_AS(DD::swap(first, _target.first)) {
		using DD::swap;
		swap(this->first, _target.first);
		swap(this->second, _target.second);
	}
	
	
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
