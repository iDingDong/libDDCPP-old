//	standard/bits/DD_ListNode.hpp
#ifndef DD_LIST_NODE_HPP_
#	define DD_LIST_NODE_HPP_ 1



#	include "DD_ValueTypeNested.hpp"



DD_BEGIN
struct EmptyListNode {
	DD_ALIAS(ThisType, EmptyListNode)


	ThisType* previous;
	ThisType* next;


};



template <typename ValueT_>
struct ListNode : EmptyListNode {
	DD_ALIAS(ThisType, ListNode<ValueT_>)
	DD_ALIAS(ValueType, ValueT_)

	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(ConstReferenceType, ValueType const&)
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ConstPointerType, ValueType*)


	ValueType value;


};



DD_END



#endif
