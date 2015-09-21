//	DDCPP/standard/bits/DD_EqualityComparable.hpp
#ifndef _DD_EQUALITY_COMPARABLE_HPP_INCLUDED
#	define _DD_EQUALITY_COMPARABLE_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _ObjectT1, typename _ObjectT2 = _ObjectT1>
struct EqualityComparable {
	DD_ALIAS(Type1, _ObjectT1)
	DD_ALIAS(Type2, _ObjectT2)


	friend ValidityType operator ==(
		Type2 const& _object_1,
		Type1 const& _object_2
	) DD_NOEXCEPT_AS(static_cast<ValidityType>(_object_2 == _object_1)) {
		return _object_2 == _object_1;
	}


	friend ValidityType operator !=(
		Type1 const& _object_1,
		Type2 const& _object_2
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(_object_1 == _object_2)) {
		return !static_cast<ValidityType>(_object_1 == _object_2);
	}

	friend ValidityType operator !=(
		Type2 const& _object_1,
		Type1 const& _object_2
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(_object_2 == _object_1)) {
		return !static_cast<ValidityType>(_object_2 == _object_1);
	}


};



template <typename _ObjectT>
struct EqualityComparable<_ObjectT> {
	DD_ALIAS(Type, _ObjectT)


	friend ValidityType operator !=(
		Type const& _object_1,
		Type const& _object_2
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(_object_1 == _object_2)) {
		return !static_cast<ValidityType>(_object_1 == _object_2);
	}


};



_DD_END



#endif
