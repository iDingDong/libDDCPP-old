//	DDCPP/standard/bits/DD_size_distance.hpp
#ifndef _DD_SIZE_DISTANCE_HPP_INCLUDED
#	define _DD_SIZE_DISTANCE_HPP_INCLUDED 1



#	include "DD_get_pointer.hpp"



_DD_BEGIN
template <typename _PointerT1, typename _PointerT2>
inline SizeType DD_CONSTEXPR size_distance(
	_PointerT1 const& __begin,
	_PointerT2 const& __end
) DD_NOEXCEPT_IF(noexcept(get_pointer(__begin)) && noexcept(get_pointer(__end))) {
	return reinterpret_cast<char const*>(get_pointer(__end)) - reinterpret_cast<char const*>(get_pointer(__begin));
}



_DD_END



#endif
