//	DDCPP/standard/bits/DD_LessThanComparable.hpp
#ifndef _DD_LESS_THAN_COMPARABLE_HPP_INCLUDED
#	define _DD_LESS_THAN_COMPARABLE_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ObjectT1, typename _ObjectT2 = _ObjectT1>
struct LessThanComparable {
	public:
	DD_ALIAS(Type1, _ObjectT1)
	DD_ALIAS(Type2, _ObjectT2)
	
	
	public:
	friend ValidityType operator <(
		Type2 const& __object_1,
		Type1 const& __object_2
	) DD_NOEXCEPT_AS(static_cast<ValidityType>(__object_2 > __object_1)) {
		return __object_2 > __object_1;
	}
	
	
	public:
	friend ValidityType operator <=(
		Type1 const& __object_1,
		Type2 const& __object_2
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(__object_1 > __object_2)) {
		return !static_cast<ValidityType>(__object_1 > __object_2);
	}
	
	public:
	friend ValidityType operator <=(
		Type2 const& __object_1,
		Type1 const& __object_2
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(__object_2 < __object_1)) {
		return !static_cast<ValidityType>(__object_2 < __object_1);
	}
	
	
	public:
	friend ValidityType operator >(
		Type2 const& __object_1,
		Type1 const& __object_2
	) DD_NOEXCEPT_AS(static_cast<ValidityType>(__object_2 < __object_1)) {
		return __object_2 < __object_1;
	}
	
	
	public:
	friend ValidityType operator >=(
		Type1 const& __object_1,
		Type2 const& __object_2
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(__object_1 < __object_2)) {
		return !static_cast<ValidityType>(__object_1 < __object_2);
	}
	
	public:
	friend ValidityType operator >=(
		Type2 const& __object_1,
		Type1 const& __object_2
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(__object_2 > __object_1)) {
		return !static_cast<ValidityType>(__object_2 > __object_1);
	}
	
	
};



template <typename _ObjectT>
struct LessThanComparable<_ObjectT> {
	public:
	DD_ALIAS(Type, _ObjectT)
	
	
	public:
	friend ValidityType operator <=(
		Type const& _object_1,
		Type const& _object_2
	) DD_NOEXCEPT_AS(!(_object_1 > _object_2)) {
		return !(_object_1 > _object_2);
	}
	
	
	public:
	friend ValidityType operator >(
		Type const& _object_1,
		Type const& _object_2
	) DD_NOEXCEPT_AS(static_cast<ValidityType>(_object_2 < _object_1)) {
		return _object_2 < _object_1;
	}
	
	
	public:
	public:
	friend ValidityType operator >=(
		Type const& _object_1,
		Type const& _object_2
	) DD_NOEXCEPT_AS(!static_cast<ValidityType>(_object_1 < _object_2)) {
		return !static_cast<ValidityType>(_object_1 < _object_2);
	} 
	
	
};



DD_END



#endif
