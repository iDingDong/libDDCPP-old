//	DDCPP/standard/bits/DD_ValueStorage.hpp
#ifndef DD_VALUE_STORAGE_HPP_INCLUDED_
#	define DD_VALUE_STORAGE_HPP_INCLUDED_ 1



#	include "DD_ValueTypeNested.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct ValueStorage {
	DD_ALIAS(ThisType, ValueStorage<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	ValueType value;


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::ValueStorage;



DD_END_



#endif
