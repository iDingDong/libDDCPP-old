//	DDCPP/standard/bits/DD_Comparable.hpp
#ifndef DD_COMPARABLE_HPP_INCLUDED_
#	define DD_COMPARABLE_HPP_INCLUDED_ 1



#	include "DD_EqualityComparable.hpp"
#	include "DD_LessThanComparable.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT1_, typename ObjectT2_ = ObjectT1_>
struct Comparable : EqualityComparable<ObjectT1_, ObjectT2_>, LessThanComparable<ObjectT1_, ObjectT2_> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Comparable;



DD_END_



#endif
