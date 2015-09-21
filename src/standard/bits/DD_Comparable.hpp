//	DDCPP/standard/bits/DD_Comparable.hpp
#ifndef _DD_COMPARABLE_HPP_INCLUDED
#	define _DD_COMPARABLE_HPP_INCLUDED 1



#	include "DD_EqualityComparable.hpp"
#	include "DD_LessThanComparable.hpp"



_DD_BEGIN
template <typename _ObjectT1, typename _ObjectT2 = _ObjectT1>
struct Comparable : EqualityComparable<_ObjectT1, _ObjectT2>, LessThanComparable<_ObjectT1, _ObjectT2> {
};



_DD_END



#endif
