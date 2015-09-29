//	DDCPP/standard/bits/DD_Pair.hpp
#ifndef DD_PAIR_HPP_INCLUDED_
#	define DD_PAIR_HPP_INCLUDED_



//#	include "DD_relationship_operators.hpp"
//#	if __cplusplus >= 201103L
//#		include "DD_forward.hpp"
//#	endif
#	include "DD_Comparable.hpp"
#	include "DD_swap.hpp"
#	include "DD_dereference.hpp"



DD_BEGIN_
template <typename ValueT1_, typename ValueT2_ = ValueT1_>
struct Pair : Comparable<Pair<ValueT1_, ValueT2_>> {
	public:
	DD_ALIAS(ThisType, Pair<ValueT1_ DD_COMMA ValueT2_>);
	DD_ALIAS(FirstValueType, ValueT1_);
	DD_ALIAS(SecondValueType, ValueT2_);


	public:
	FirstValueType first;
	SecondValueType second;


#	if __cplusplus >= 201103L
	public:
	constexpr Pair() = default;

	public:
	constexpr Pair(ThisType const& origin_) = default;

	public:
	constexpr Pair(ThisType&& origin_) = default;

	public:
	template <typename ValueT1__, typename ValueT2__>
	DD_CONSTEXPR Pair(
		ValueT1__&& value_1___,
		ValueT2__&& value_2___
	) DD_NOEXCEPT_IF(noexcept(FirstValueType(value_1___)) && noexcept(SecondValueType(value_2___))) : first(value_1___), second(value_2___) {
	}
#	else
	public:
	Pair() {
	}

	public:
	template <typename ValueT1__, typename ValueT2__>
	Pair(ValueT1__ const& value_1___, ValueT2_ const& value_2___) : first(value_1___), second(value_2___) {
	}
#	endif


	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT_AS(swap(first, target_.first) DD_COMMA swap(second, target_.second)) {
		using DD::swap;
		swap(first, target_.first);
		swap(second, target_.second);
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



template <typename ValueT_>
struct Pair<ValueT_> : Comparable<Pair<ValueT_>> {
	public:
	DD_ALIAS(ThisType, Pair<ValueT_>);
	DD_ALIAS(ValueType, ValueT_);

	DD_ALIAS(FirstValueType, ValueType);
	DD_ALIAS(SecondValueType, ValueType);


	public:
	FirstValueType first;
	SecondValueType second;


#	if __cplusplus >= 201103L
	public:
	constexpr Pair() = default;

	public:
	constexpr Pair(ThisType const& origin_) = default;

	public:
	constexpr Pair(ThisType&& origin_) = default;

	public:
	template <typename ValueT1__, typename ValueT2__>
	constexpr Pair(
		ValueT1__&& value_1___,
		ValueT2__&& value_2___
	) noexcept(noexcept(FirstValueType(value_1___)) && noexcept(SecondValueType(value_2___))) : first(value_1___), second(value_2___) {
	}
#	else
	public:
	Pair() {
	}

	public:
	template <typename ValueT1__, typename ValueT2__>
	Pair(ValueT1__ const& value_1___, ValueT2_ const& value_2___) : first(value_1___), second(value_2___) {
	}
#	endif


	public:
	ProcessType swap() DD_NOEXCEPT_AS(DD::swap(first, second)) {
		using DD::swap;
		swap(first, second);
	}

	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT_AS(DD::swap(first, target_.first)) {
		using DD::swap;
		swap(first, target_.first);
		swap(second, target_.second);
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



template <typename ValueT_>
inline ProcessType swap(Pair<ValueT_, ValueT_>& pair_) DD_NOEXCEPT_AS(pair_.swap()) {
	pair_.swap();
}



template <typename PointerT1_, typename PointerT2_>
inline Pair<DD_MODIFY_TRAIT(IteratorReference, PointerT1_), DD_MODIFY_TRAIT(IteratorReference, PointerT2_)> dereference(
	Pair<PointerT1_, PointerT2_> pair_
) noexcept(noexcept(Pair<DD_MODIFY_TRAIT(IteratorReference, PointerT1_), DD_MODIFY_TRAIT(IteratorReference, PointerT2_)>{dereference(pair_.first), dereference(pair_.second)})) {
	return Pair<DD_MODIFY_TRAIT(IteratorReference, PointerT1_), DD_MODIFY_TRAIT(IteratorReference, PointerT2_)>{dereference(pair_.first), dereference(pair_.second)};
}




template <typename ValueT1_, typename ValueT2_>
inline ValidityType DD_CONSTEXPR operator ==(
	Pair<ValueT1_, ValueT2_> const& pair_1_,
	Pair<ValueT1_, ValueT2_> const& pair_2_
) DD_NOEXCEPT_IF(noexcept(pair_1_.first == pair_2_.first) && noexcept(pair_1_.second == pair_2_.second)) {
	return pair_1_.first == pair_2_.first && pair_1_.second == pair_2_.second;
}



template <typename ValueT1_, typename ValueT2_>
inline ValidityType DD_CONSTEXPR operator <(
	Pair<ValueT1_, ValueT2_> const& pair_1_,
	Pair<ValueT1_, ValueT2_> const& pair_2_
) DD_NOEXCEPT_IF(noexcept(pair_1_.first < pair_2_.first) && noexcept(pair_1_.second < pair_2_.second)) {
	return pair_1_.first < pair_2_.first || (pair_1_.first == pair_2_.first && pair_1_.second < pair_2_.second);
}



DD_END_



#endif
