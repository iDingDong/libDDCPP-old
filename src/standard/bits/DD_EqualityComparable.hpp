//	DDCPP/standard/bits/DD_EqualityComparable.hpp
#ifndef DD_EQUALITY_COMPARABLE_HPP_INCLUDED_
#	define DD_EQUALITY_COMPARABLE_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename ObjectT1_, typename ObjectT2_ = ObjectT1_>
struct EqualityComparable {
	DD_ALIAS(Type1, ObjectT1_);
	DD_ALIAS(Type2, ObjectT2_);


	friend ValidityType operator ==(
		Type2 const& object_1_,
		Type1 const& object_2_
	) DD_NOEXCEPT_AS(static_cast<ValidityType>(object_2_ == object_1_)) {
		return object_2_ == object_1_;
	}


	friend ValidityType operator !=(
		Type1 const& object_1_,
		Type2 const& object_2_
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(object_1_ == object_2_)) {
		return !static_cast<ValidityType>(object_1_ == object_2_);
	}

	friend ValidityType operator !=(
		Type2 const& object_1_,
		Type1 const& object_2_
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(object_2_ == object_1_)) {
		return !static_cast<ValidityType>(object_2_ == object_1_);
	}


};



template <typename ObjectT_>
struct EqualityComparable<ObjectT_> {
	DD_ALIAS(Type, ObjectT_);


	friend ValidityType operator !=(
		Type const& object_1_,
		Type const& object_2_
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(object_1_ == object_2_)) {
		return !static_cast<ValidityType>(object_1_ == object_2_);
	}


};



DD_END_



#endif
