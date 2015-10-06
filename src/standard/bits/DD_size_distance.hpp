//	DDCPP/standard/bits/DD_size_distance.hpp
#ifndef DD_SIZE_DISTANCE_HPP_INCLUDED_
#	define DD_SIZE_DISTANCE_HPP_INCLUDED_ 1



#	include "DD_get_pointer.hpp"



DD_DETAIL_BEGIN_
template <typename PointerT1_, typename PointerT2_>
inline SizeType DD_CONSTEXPR size_distance(
	PointerT1_ const& begin__,
	PointerT2_ const& end__
) DD_NOEXCEPT_IF(noexcept(get_pointer(begin__)) && noexcept(get_pointer(end__))) {
	return reinterpret_cast<char const*>(get_pointer(end__)) - reinterpret_cast<char const*>(get_pointer(begin__));
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::size_distance;



DD_END_



#endif
