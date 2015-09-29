//	DDCPP/standard/bits/DD_LessThanComparable.hpp
#ifndef DD_LESS_THAN_COMPARABLE_HPP_INCLUDED_
#	define DD_LESS_THAN_COMPARABLE_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename ObjectT1_, typename ObjectT2_ = ObjectT1_>
struct LessThanComparable {
	DD_ALIAS(Type1, ObjectT1_);
	DD_ALIAS(Type2, ObjectT2_);


	friend ValidityType operator <(
		Type2 const& object_1__,
		Type1 const& object_2__
	) DD_NOEXCEPT_AS(static_cast<ValidityType>(object_2__ > object_1__)) {
		return object_2__ > object_1__;
	}


	friend ValidityType operator <=(
		Type1 const& object_1__,
		Type2 const& object_2__
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(object_1__ > object_2__)) {
		return !static_cast<ValidityType>(object_1__ > object_2__);
	}

	friend ValidityType operator <=(
		Type2 const& object_1__,
		Type1 const& object_2__
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(object_2__ < object_1__)) {
		return !static_cast<ValidityType>(object_2__ < object_1__);
	}


	friend ValidityType operator >(
		Type2 const& object_1__,
		Type1 const& object_2__
	) DD_NOEXCEPT_AS(static_cast<ValidityType>(object_2__ < object_1__)) {
		return object_2__ < object_1__;
	}


	friend ValidityType operator >=(
		Type1 const& object_1__,
		Type2 const& object_2__
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(object_1__ < object_2__)) {
		return !static_cast<ValidityType>(object_1__ < object_2__);
	}

	friend ValidityType operator >=(
		Type2 const& object_1__,
		Type1 const& object_2__
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(object_2__ > object_1__)) {
		return !static_cast<ValidityType>(object_2__ > object_1__);
	}


};



template <typename ObjectT_>
struct LessThanComparable<ObjectT_> {
	DD_ALIAS(Type, ObjectT_);


	friend ValidityType operator <=(
		Type const& object_1_,
		Type const& object_2_
	) DD_NOEXCEPT_AS(!(object_1_ > object_2_)) {
		return !(object_1_ > object_2_);
	}


	friend ValidityType operator >(
		Type const& object_1_,
		Type const& object_2_
	) DD_NOEXCEPT_AS(static_cast<ValidityType>(object_2_ < object_1_)) {
		return object_2_ < object_1_;
	}


	friend ValidityType operator >=(
		Type const& object_1_,
		Type const& object_2_
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(object_1_ < object_2_)) {
		return !static_cast<ValidityType>(object_1_ < object_2_);
	}


};



DD_END_



#endif
