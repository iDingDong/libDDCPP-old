//	DDCPP/standard/bits/DD_Pair.hpp
#ifndef DD_PAIR_HPP_INCLUDED_
#	define DD_PAIR_HPP_INCLUDED_



//#	include "DD_relationship_operators.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_Comparable.hpp"
#	include "DD_swap.hpp"
#	include "DD_dereference.hpp"



DD_BEGIN_
template <typename ValueT1_, typename ValueT2_ = ValueT1_>
#	if __cplusplus >= 201103L
struct Pair : Comparable<Pair<ValueT1_, ValueT2_>> {
#	else
struct Pair : Comparable<Pair<ValueT1_, ValueT2_> > {
#	endif
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
#	else
	public:
	Pair() {
	}
#	endif

	public:
	template <typename ValueT1__, typename ValueT2__>
	Pair(Pair<ValueT1__, ValueT2__> const& origin_) DD_NOEXCEPT_IF(
		noexcept(FirstValueType(origin_.first)) && noexcept(SecondValueType(origin_.second))
	) : first(origin_.first), second(origin_.second) {
	}

#	if __cplusplus >= 201103L
	public:
	template <typename ValueT1__, typename ValueT2__>
	Pair(Pair<ValueT1__, ValueT2__>&& origin_) DD_NOEXCEPT_IF(
		noexcept(FirstValueType(::DD::move(origin_.first))) && noexcept(SecondValueType(::DD::move(origin_.second)))
	) : first(::DD::move(origin_.first)), second(::DD::move(origin_.second)) {
	}

	public:
	template <typename ValueT1__, typename ValueT2__>
	DD_CONSTEXPR Pair(ValueT1__&& value_1___, ValueT2__&& value_2___) noexcept(
		noexcept(FirstValueType(forward<ValueT1__>(value_1___))) && noexcept(SecondValueType(forward<ValueT2__>(value_2___)))
	) : first(forward<ValueT1__>(value_1___)), second(forward<ValueT2__>(value_2___)) {
	}
#	else
	public:
	template <typename ValueT1__, typename ValueT2__>
	Pair(ValueT1__ const& value_1___, ValueT2_ const& value_2___) : first(value_1___), second(value_2___) {
	}
#	endif

	public:
	ProcessType swap() DD_NOEXCEPT_AS(
		::DD::swap(fabricate<ThisType>().first DD_COMMA fabricate<ThisType>().second)
	) {
		::DD::swap(first, second);
	}

	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT_AS(
		::DD::swap(fabricate<ThisType>().first DD_COMMA target_.first) DD_COMMA
		::DD::swap(fabricate<ThisType>().second DD_COMMA target_.second)
	) {
		::DD::swap(first, target_.first);
		::DD::swap(second, target_.second);
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;

#	endif
	public:
	template <typename ValueT1__, typename ValueT2__>
	ThisType& operator =(Pair<ValueT1__, ValueT2__> const& origin_) DD_NOEXCEPT_IF(
		noexcept(fabricate<ThisType>().first = origin_.first) &&
		noexcept(fabricate<ThisType>().second = origin_.second)
	) {
		first = origin_.first;
		second = origin_.second;
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	template <typename ValueT1__, typename ValueT2__>
	ThisType& operator =(Pair<ValueT1__, ValueT2__>&& origin_) noexcept(
		noexcept(fabricate<ThisType>().first = ::DD::move(origin_.first)) &&
		noexcept(fabricate<ThisType>().second = ::DD::move(origin_.second))
	) {
		first = ::DD::move(origin_.first);
		second = ::DD::move(origin_.second);
		return *this;
	}

#	endif

};



template <typename ValueT1_, typename ValueT2_>
inline Pair<ValueT1_&, ValueT2_&> DD_CONSTEXPR mate(ValueT1_& value_1__, ValueT2_& value_2__) DD_NOEXCEPT_AS(
	Pair<ValueT1_& DD_COMMA ValueT2_&>(value_1__ DD_COMMA value_2__)
) {
	return Pair<ValueT1_&, ValueT2_&>(value_1__, value_2__);
}



template <typename ValueT_>
inline ProcessType swap(Pair<ValueT_, ValueT_>& pair_) DD_NOEXCEPT_AS(pair_.swap()) {
	pair_.swap();
}



template <typename PointerT1_, typename PointerT2_>
inline Pair<DD_MODIFY_TRAIT(IteratorReference, PointerT1_), DD_MODIFY_TRAIT(IteratorReference, PointerT2_)> dereference(
	Pair<PointerT1_, PointerT2_> pair_
) DD_NOEXCEPT_AS(Pair<
	DD_MODIFY_TRAIT(IteratorReference, PointerT1_) DD_COMMA
	DD_MODIFY_TRAIT(IteratorReference, PointerT2_)
>(dereference(pair_.first) DD_COMMA dereference(pair_.second))) {
	return Pair<
		DD_MODIFY_TRAIT(IteratorReference, PointerT1_),
		DD_MODIFY_TRAIT(IteratorReference, PointerT2_)
	>(dereference(pair_.first), dereference(pair_.second));
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
