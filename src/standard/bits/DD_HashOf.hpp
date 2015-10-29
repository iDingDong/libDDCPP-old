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
DD_ALIAS(HashType, SizeType);



template <LengthType length_c_>
struct Hash_;



template <>
struct Hash_<1> {
	template <typename ValueT__>
	static DD_UNCONSTRIANED_CONSTEXPR HashType hash(ValueT__ const& value___) DD_NOEXCEPT {
		HashType result_ = HashType();
		reinterpret_cast<ValueT__&>(result_) = value___;
		return result_;
	}


};



template <LengthType length_c_>
struct Hash_ {
	template <typename ValueT__>
	static DD_UNCONSTRIANED_CONSTEXPR HashType hash(ValueT__ const& value___) DD_NOEXCEPT {
		HashType result_ = HashType();
		for (int i = 0; i < length_c_ - 1; ++i) {
			result_ = result_ * DDCPP_HASH_STEP + reinterpret_cast<HashType*>(address_of(value___))[i];
		}
		return result_ * DDCPP_HASH_STEP + Hash_<1>::hash(reinterpret_cast<char(&)[sizeof(ValueT__) % sizeof(HashType)]>(
			reinterpret_cast<HashType*>(address_of(value___))[length_c_ - 1]
		));
	}


};



template <typename ValueT_>
struct HashOf : UnaryFunctor<HashType, ValueT_ const&> {
	DD_ALIAS(ValueType, ValueT_);


	static DD_CONSTEXPR HashType call(ValueType const& value_) DD_NOEXCEPT_AS(
		Hash_<(sizeof(ValueType) + 1) / sizeof(HashType)>::hash(value_)
	) {
		return Hash_<(sizeof(ValueType) + 1) / sizeof(HashType)>::hash(value_);
	}


	HashType DD_CONSTEXPR operator ()(ValueType const& value_) DD_NOEXCEPT_AS(call(value_)) {
		return call(value_);
	}


};



DD_DETAIL_END_



#endif
