//	DDCPP/standard/bits/DD_HashOf.hpp
#ifndef DD_HASH_OF_HPP_INCLUDED_
#	define DD_HASH_OF_HPP_INCLUDED_ 1



#	include <cstring>

#	include "DD_address_of.hpp"
#	include "DD_Functor.hpp"



#	if !defined(DDCPP_HASH_STEP)
#		define DDCPP_HASH_STEP 131
#	endif



DD_DETAIL_BEGIN_
DD_ALIAS(HashValueType, SizeType);



template <LengthType length_c_>
struct Hash_;



template <>
struct Hash_<1> {
	template <typename ValueT__>
	static DD_UNCONSTRIANED_CONSTEXPR HashValueType hash(ValueT__ const& value___) DD_NOEXCEPT {
		HashValueType result_ = HashValueType();
		reinterpret_cast<ValueT__&>(result_) = value___;
		return result_;
	}


};



template <LengthType length_c_>
struct Hash_ {
	template <typename ValueT__>
	static DD_UNCONSTRIANED_CONSTEXPR HashValueType hash(ValueT__ const& value___) DD_NOEXCEPT {
		HashValueType result_ = HashValueType();
		for (int i = 0; i < length_c_ - 1; ++i) {
			result_ = result_ * DDCPP_HASH_STEP + reinterpret_cast<HashValueType*>(address_of(value___))[i];
		}
		return result_ * DDCPP_HASH_STEP + Hash_<1>::hash(reinterpret_cast<char(&)[sizeof(ValueT__) % sizeof(HashValueType)]>(
			reinterpret_cast<HashValueType*>(address_of(value___))[length_c_ - 1]
		));
	}


};



template <typename ValueT_>
struct HashOf : UnaryFunctor<HashValueType, ValueT_ const&> {
	DD_ALIAS(ValueType, ValueT_);


	static DD_CONSTEXPR HashValueType call(ValueType const& value_) DD_NOEXCEPT_AS(
		Hash_<(sizeof(ValueType) + 1) / sizeof(HashValueType)>::hash(value_)
	) {
		return Hash_<(sizeof(ValueType) + 1) / sizeof(HashValueType)>::hash(value_);
	}


	HashValueType DD_CONSTEXPR operator ()(ValueType const& value_) DD_NOEXCEPT_AS(call(value_)) {
		return call(value_);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::HashValueType;
using detail_::HashOf;



DD_END_



#endif
