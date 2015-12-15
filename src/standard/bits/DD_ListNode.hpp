//	standard/bits/DD_ListNode.hpp
#ifndef DD_LIST_NODE_HPP_
#	define DD_LIST_NODE_HPP_ 1



#	include "DD_ValueTypeNested.hpp"
#	include "DD_swap.hpp"



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
	DD_ALIAS(ThisType, ListNode<void>);


	ThisType* previous;
	ThisType* next;


};



template <typename ValueT_>
struct ListNode : ListNode<void>, ValueStorage<ValueT_> {
	DD_ALIAS(ThisType, ListNode<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


};



inline ProcessType link_list_node_(ListNode<void>* node_1_, ListNode<void>* node_2_) DD_NOEXCEPT {
	node_1_->next = node_2_;
	node_2_->previous = node_1_;
}


inline ProcessType enlink_list_node_(ListNode<void>* position_, ListNode<void>* node_) DD_NOEXCEPT {
	node_->previous = position_->previous;
	node_->next = position_;
	position_->previous->next = node_;
	position_->previous = node_;
}

inline ProcessType enlink_list_node_(ListNode<void>* position_, ListNode<void>* first_, ListNode<void>* last_) DD_NOEXCEPT {
	first_->previous = position_->previous;
	last_->next = position_;
	position_->previous->next = first_;
	position_->previous = last_;
}


inline ProcessType delink_list_node_(ListNode<void>* node_) DD_NOEXCEPT {
	node_->previous->next = node_->next;
	node_->next->previous = node_->previous;
}

inline ProcessType delink_list_node_(ListNode<void>* first_, ListNode<void>* last_) DD_NOEXCEPT {
	first_->previous->next = last_->next;
	last_->next->previous = first_->previous;
}


inline ProcessType swap_list_node_(ListNode<void>* node_1_, ListNode<void>* node_2_) DD_NOEXCEPT {
	::DD::swap(node_1_->previous, node_2_->previous);
	::DD::swap(node_1_->next, node_2_->next);
	node_1_->previous->next = node_1_;
	node_1_->next->previous = node_1_;
	node_2_->previous->next = node_2_;
	node_2_->next->previous = node_2_;
}

inline ProcessType swap_list_node_(
	ListNode<void>* first_1_,
	ListNode<void>* last_1_,
	ListNode<void>* first_2_,
	ListNode<void>* last_2_
) DD_NOEXCEPT {
	::DD::swap(first_1_->previous, first_2_->previous);
	::DD::swap(last_1_->next, last_2_->next);
	first_1_->previous->next = first_1_;
	last_1_->next->previous = last_1_;
	first_2_->previous->next = first_2_;
	last_2_->next->previous = last_2_;
}


inline ProcessType transfer_list_node_(ListNode<void>* from_, ListNode<void>* to_) DD_NOEXCEPT {
	delink_list_node_(from_);
	enlink_list_node_(to_, from_);
}


inline ProcessType splice_list_node_(
	ListNode<void>* position_,
	ListNode<void>* first_,
	ListNode<void>* last_
) DD_NOEXCEPT {
	delink_list_node_(first_, last_);
	enlink_list_node_(position_, first_, last_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::ValueStorage;
using detail_::ListNode;



DD_END_



#endif
