//	DDCPP/standard/bits/DD_relationship_operators.hpp
#ifndef DD_RELATIONSHIP_OPERATORS_HPP_INCLUDED_
#	define DD_RELATIONSHIP_OPERATORS_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



#	define DD_RELATIONSHIP_OPERATORS_BEGIN_ DD_BEGIN_ namespace relationship_operators {
#	define DD_RELATIONSHIP_OPERATORS_END_ } DD_END_



DD_RELATIONSHIP_OPERATORS_BEGIN_
template <typename ObjectT_>
ValidityType DD_CONSTEXPR operator !=(ObjectT_ const& object_1__, ObjectT_ const& object_2__) DD_NOEXCEPT_AS(object_1__ == object_2__) {
	return !(object_1__ == object_2__);
}


template <typename ObjectT_>
ValidityType DD_CONSTEXPR operator <=(ObjectT_ const& object_1__, ObjectT_ const& object_2__) DD_NOEXCEPT_AS(object_1__ < object_2__) {
	return !(object_2__ < object_1__);
}


template <typename ObjectT_>
ValidityType DD_CONSTEXPR operator >(ObjectT_ const& object_1__, ObjectT_ const& object_2__) DD_NOEXCEPT_AS(object_1__ < object_2__) {
	return object_2__ < object_1__;
}


template <typename ObjectT_>
ValidityType DD_CONSTEXPR operator >=(ObjectT_ const& object_1__, ObjectT_ const& object_2__) DD_NOEXCEPT_AS(object_1__ < object_2__) {
	return !(object_1__ < object_2__);
}



DD_RELATIONSHIP_OPERATORS_END_



#	undef DD_RELATIONSHIP_OPERATORS_BEGIN_
#	undef DD_RELATIONSHIP_OPERATORS_END_



#endif
