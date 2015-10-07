//	DDCPP/standard/bits/DD_logical_not_of.hpp
#ifndef DD_LOGICAL_NOT_OF_HPP_INCLUDED_
#	define DD_LOGICAL_NOT_OF_HPP_INCLUDED_



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
inline ValidityType DD_CONSTEXPR logical_not_of(ObjectT_ const& object__) DD_NOEXCEPT_AS(static_cast<ValidityType>(object__)) {
	return !static_cast<ValidityType>(object__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::logical_not_of;



DD_END_



#endif
