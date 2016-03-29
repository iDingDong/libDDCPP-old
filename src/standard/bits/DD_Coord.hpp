//	DDCPP/standard/bits/DD_Coord.hpp
#ifndef DD_COORD_HPP_INCLUDED_
#	define DD_COORD_HPP_INCLUDED_ 1



#	include <standard/bits/DD_ValueTypeNested.hpp>



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct Coord {
	DD_ALIAS(ThisType, Coord<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	ValueType x;
	ValueType y;


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Coord;



DD_END_



#endif
