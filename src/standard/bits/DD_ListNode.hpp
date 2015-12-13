//	standard/bits/DD_ListNode.hpp
#ifndef DD_LIST_NODE_HPP_
#	define DD_LIST_NODE_HPP_ 1



#	include "DD_ValueTypeNested.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct ValueStorage {
	DD_ALIAS(ThisType, ValueStorage<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	ValueType value;


};



template <typename ValueT_>
struct ListNode;



template <>
struct ListNode<void> {
	DD_ALIAS(ThisType, EmptyListNode);


	ThisType* previous;
	ThisType* next;


};



template <typename ValueT_>
struct ListNode : ListNode<void>, ValueStorage<ValueT_> {
	DD_ALIAS(ThisType, ListNode<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::ValueStorage;
using detail_::ListNode;



DD_END_



#endif
