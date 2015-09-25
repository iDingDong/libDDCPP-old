//	standard/bits/DD_ListNode.hpp
#ifndef _DD_LIST_NODE_HPP
#	define _DD_LIST_NODE_HPP 1



#	include "DD_ValueTypeNested.hpp"



DD_BEGIN
struct EmptyListNode {
	DD_ALIAS(ThisType, EmptyListNode)


	ThisType* previous;
	ThisType* next;


};



template <typename _ValueT>
struct ListNode : EmptyListNode {
	DD_ALIAS(ThisType, ListNode<_ValueT>)
	DD_ALIAS(ValueType, _ValueT)

	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(ConstReferenceType, ValueType const&)
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ConstPointerType, ValueType*)


	ValueType value;


};



DD_END



#endif
