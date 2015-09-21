//	DDCPP/standard/bits/DD_ListNode.hpp
#ifndef _DD_LIST_NODE_HPP_INCLUDED
#	define _DD_LIST_NODE_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
template <typename _ValueT>
struct ListNode {
	DD_ALIAS(ThisType, ListNode<_ValueT>)
	DD_ALIAS(ValueType, _ValueT)

	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(ConstReferenceType, ValueType const&)
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ConstPointerType, ValueType*)


	ThisType* previous;
	ThisType* next;
	ValueType value;


};



_DD_END



#endif
