//	DDCPP/standard/bits/DD_UndirectionalListNode.hpp
#ifndef DD_UNDIRECTIONAL_LIST_NODE_HPP_INCLUDED_
#	define DD_UNDIRECTIONAL_LIST_NODE_HPP_INCLUDED_ 1



#	include "DD_ValueStorage.hpp"
#	include "DD_swap.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct UndirectionalListNode;



template <>
struct UndirectionalListNode<void> {
	DD_ALIAS(ThisType, UndirectionalListNode<void>);


	ThisType* next;


};



template <typename ValueT_>
struct UndirectionalListNode : UndirectionalListNode<void>, ValueStorage<ValueT_> {
	DD_ALIAS(ThisType, UndirectionalListNode<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


};



inline ProcessType link_undirectional_list_node_(
	UndirectionalListNode<void>* node_1_,
	UndirectionalListNode<void>* node_2_
) DD_NOEXCEPT {
	node_1_->next = node_2_;
}


inline ProcessType enlink_after_undirectional_list_node_(
	UndirectionalListNode<void>* position_,
	UndirectionalListNode<void>* node_
) DD_NOEXCEPT {
	link_undirectional_list_node_(node_, position_->next);
	link_undirectional_list_node_(position_, node_);
}

inline ProcessType enlink_after_undirectional_list_node_(
	UndirectionalListNode<void>* position_,
	UndirectionalListNode<void>* first_,
	UndirectionalListNode<void>* last_
) DD_NOEXCEPT {
	link_undirectional_list_node_(last_, position_->next);
	link_undirectional_list_node_(position_, first_);
}


inline ProcessType delink_after_undirectional_list_node_(
	UndirectionalListNode<void>* position_
) DD_NOEXCEPT {
	link_undirectional_list_node_(position_, position_->next->next);
}


inline ProcessType delink_between_undirectional_list_node_(
	UndirectionalListNode<void>* head_,
	UndirectionalListNode<void>* tail_
) DD_NOEXCEPT {
	link_undirectional_list_node_(head_, tail_);
}


inline ProcessType transfer_after_undirectional_list_node_(
	UndirectionalListNode<void>* from_after_,
	UndirectionalListNode<void>* to_after_
) DD_NOEXCEPT {
	UndirectionalListNode<void>* node_ = from_after_->next;
	delink_after_undirectional_list_node_(from_after_);
	enlink_after_undirectional_list_node_(to_after_, node_);
}


inline ProcessType splice_after_undirectional_list_node_(
	UndirectionalListNode<void>* position_,
	UndirectionalListNode<void>* head_,
	UndirectionalListNode<void>* last_
) DD_NOEXCEPT {
	UndirectionalListNode<void>* first_ = head_->next;
	delink_between_undirectional_list_node_(head_, last_->last);
	enlink_after_undirectional_list_node_(position_, first_, last_);
}


inline ProcessType swap_after_undirectional_list_node_(
	UndirectionalListNode<void>* node_1_,
	UndirectionalListNode<void>* node_2_
) DD_NOEXCEPT {
	::DD::swap(node_1_->next, node_2_->next);
	::DD::swap(node_1_->next->next, node_2_->next->next);
}

inline ProcessType swap_after_undirectional_list_node_(
	UndirectionalListNode<void>* head_1_,
	UndirectionalListNode<void>* last_1_,
	UndirectionalListNode<void>* head_2_,
	UndirectionalListNode<void>* last_2_
) DD_NOEXCEPT {
	::DD::swap(head_1_->next, head_2_->next);
	::DD::swap(last_1_->next, last_2_->next);
}



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
