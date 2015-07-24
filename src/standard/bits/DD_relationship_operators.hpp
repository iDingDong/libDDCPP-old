//	standard/bits/DD_relationship_operators.hpp
#ifndef _DD_RELATIONSHIP_OPERATORS_HPP_INCLUDED
#	define _DD_RELATIONSHIP_OPERATORS_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
template <typename _ObjectT>
ValidityType DD_CONSTEXPR operator !=(_ObjectT const& __object_1, _ObjectT const& __object_2) DD_NOEXCEPT_AS(__object_1 == __object_2) {
	return !(__object_1 == __object_2);
}


template <typename _ObjectT>
ValidityType DD_CONSTEXPR operator <=(_ObjectT const& __object_1, _ObjectT const& __object_2) DD_NOEXCEPT_AS(__object_1 < __object_2) {
	return !(__object_2 < __object_1);
}


template <typename _ObjectT>
ValidityType DD_CONSTEXPR operator >(_ObjectT const& __object_1, _ObjectT const& __object_2) DD_NOEXCEPT_AS(__object_1 < __object_2) {
	return __object_2 < __object_1;
}


template <typename _ObjectT>
ValidityType DD_CONSTEXPR operator >=(_ObjectT const& __object_1, _ObjectT const& __object_2) DD_NOEXCEPT_AS(__object_1 < __object_2) {
	return !(__object_1 < __object_2);
}



DD_END



#endif
