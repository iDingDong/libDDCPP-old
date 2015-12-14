//	DDCPP/standard/bits/DD_RedBlackTree.hpp
#ifndef DD_RED_BLACK_TREE_HPP_INCLUDED_
#	define DD_RED_BLACK_TREE_HPP_INCLUDED_ 1



#	include "DD_NeedInstance.hpp"
#	include "DD_ReadOnlyCall.hpp"
#	include "DD_LessThan.hpp"
#	include "DD_BinarySearchTree.hpp"
#	include "DD_Allocator.hpp"



DD_DETAIL_BEGIN_
struct RedBlackTreeBase__ {
	protected:
	DD_ALIAS(ThisType, RedBlackTreeBase__);

	protected:
	DD_ALIAS(NodeType, RedBlackTreeNodeBase);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodePointerType, NodeType*);


	private:
	NodePointerType m_root_ DD_IN_CLASS_INITIALIZE(NodePointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr RedBlackTreeBase__() = default;
#	else
	RedBlackTreeBase__() throw() : m_root_() {
	}
#	endif


	public:
	DD_CONSTEXPR RedBlackTreeBase__(NodePointerType root_) DD_NOEXCEPT : m_root_(root_) {
	}


	public:
	ValidityType DD_CONSTEXPR is_empty() const DD_NOEXCEPT {
		return logical_not_of(m_root_);
	}


	private:
	template <int workaround_>
	ProcessType detach_node_(NodePointerType node_) DD_NOEXCEPT;

	protected:
	ProcessType detach_node_(NodePointerType node_) DD_NOEXCEPT {
		detach_node_<0>(node_);
	}


	private:
	template <int workaround_>
	ProcessType detach_fix_up_(NodePointerType node_, ValidityType left_removed_) DD_NOEXCEPT;

	private:
	ProcessType detach_fix_up_(NodePointerType node_, ValidityType left_removed_) DD_NOEXCEPT {
		detach_fix_up_<0>(node_, left_removed_);
	}


};



template <int workaround_>
ProcessType RedBlackTreeBase__::detach_node_(RedBlackTreeBase__::NodePointerType node_) DD_NOEXCEPT {
	NodePointerType temp_ = node_;
	NodeType::Color original_color_ = temp_->color;
	if (!node_->has_left()) {
		NodePointerType to_fix_ = node_->parent;
		transplant_binary_tree_(&m_root_, node_, node_->right);
		if (node_->color == NodeType::black) {
			detach_fix_up_(to_fix_, node_->right->is_left());
		}
	} else if (!node_->has_right()) {
		NodePointerType to_fix_ = node_->parent;
		transplant_binary_tree_(&m_root_, node_, node_->left);
		if (node_->color == NodeType::black) {
			detach_fix_up_(to_fix_, node_->left->is_left());
		}
	} else {
		temp_ = node_->right->get_minimum();
		NodeType::Color original_color_ = temp_->color;
		temp_->color = node_->color;
		NodePointerType to_fix_ = temp_->parent == node_ ? node_->parent : temp_->parent;
		if (temp_ != node_->right) {
			transplant_binary_tree_(&m_root_, temp_, temp_->right);
			temp_->right = node_->right;
			temp_->right->parent = temp_;
		}
		transplant_binary_tree_(&m_root_, node_, temp_);
		temp_->left = node_->left;
		temp_->left->parent = temp_;
	}
	if (original_color_ == NodeType::black) {
		//detach_fix_up_();
	}
}



template <int workaround_>
ProcessType RedBlackTreeBase__::detach_fix_up_(RedBlackTreeBase__::NodePointerType node_, ValidityType left_removed_) DD_NOEXCEPT {

}



template <typename NodeT_, typename LessThan<NodeT_>::FunctionType& less_c_>
struct RedBlackTreeBase_ : RedBlackTreeBase__ {
	protected:
	DD_ALIAS(ThisType, RedBlackTreeBase_<NodeT_ DD_COMMA less_c_>);
	DD_ALIAS(SuperType, RedBlackTreeBase__);
	DD_ALIAS(LessPredicateType, typename LessThan<NodeT_>::FunctionType&);
	static LessPredicateType DD_CONSTANT less = less_c_;

	protected:
	DD_ALIAS(NodeType, NodeT_);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodePointerType, NodeType*);


	protected:
	DD_DELETE_COPY_CONSTRUCTOR(RedBlackTreeBase_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(RedBlackTreeBase_)

	protected:
	DD_CONSTEXPR RedBlackTreeBase_(NodePointerType root_) DD_NOEXCEPT : SuperType(root_) {
	}


#	if __cplusplus >= 201103L
	protected:
	~RedBlackTreeBase_() = default;


#	endif
	private:
	ProcessType insert_fix_up_(NodePointerType new_node_) DD_NOEXCEPT;


	protected:
	ProcessType insert_node_(NodePointerType new_node_) DD_NOEXCEPT {
		if (is_empty()) {
			new_node_->color = NodeType::black;
		} else {
			new_node_->color = NodeType::red;
			insert_binary_search_tree_node_as_sub_(this->m_root_, new_node_);
			insert_fix_up_(new_node_);
		}
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(RedBlackTreeBase_)


};



template <typename NodeT_, typename LessThan<NodeT_>::FunctionType& less_c_>
ProcessType RedBlackTreeBase_<NodeT_, less_c_>::insert_fix_up_(
	typename RedBlackTreeBase_<NodeT_, less_c_>::NodePointerType new_node_
) DD_NOEXCEPT {
	while (new_node_->parent->color == NodeType::red) {
		if (is_left_child(new_node_->parent)) {
			if (new_node_->parent->parent->right->color == NodeType::red) {
				new_node_->parent->color = NodeType::black;
				new_node_->parent->parent->right->color = NodeType::black;
				new_node_->parent->parent = NodeType::red;
				new_node_ = new_node_->parent->parent;
			} else if (is_right_child(new_node_)) {
				new_node_ = new_node_->parent;
				left_rotate(new_node_);
				if (!new_node_->parent->has_parent()) {
					this->m_root_ = new_node_->parent;
				}
			}
			new_node_->parent->color = NodeType::black;
			new_node_->parent->parent->color = NodeType::red;
			NodePointerType current_ = new_node_->parent->parent;
			right_rotate(current_);
			if (!current_->parent->has_parent()) {
				this->m_root_ = current_->parent;
			}
		} else {
			if (new_node_->parent->parent->left->color == NodeType::red) {
				new_node_->parent->color = NodeType::black;
				new_node_->parent->parent->left->color = NodeType::black;
				new_node_->parent->parent = NodeType::red;
				new_node_ = new_node_->parent->parent;
			} else if (is_left_child(new_node_)) {
				new_node_ = new_node_->parent;
				right_rotate(new_node_);
				if (!new_node_->parent->has_parent()) {
					this->m_root_ = new_node_->parent;
				}
			}
			new_node_->parent->color = NodeType::black;
			new_node_->parent->parent->color = NodeType::red;
			NodePointerType current_ = new_node_->parent->parent;
			left_rotate(current_);
			if (!current_->parent->has_parent()) {
				this->m_root_ = current_->parent;
			}
		}
	}
	m_root_->color = NodeType::black;
}



template <
	typename ValueT_,
#	if __cplusplus >= 201103L
	typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType& less_c_,
#	else
	typename LessThan<RedBlackTreeNode<ValueT_> >::FunctionType& less_c_,
#	endif
	typename AllocatorT_,
	ValidityType need_instance_c_
>
struct RedBlackTree_ : RedBlackTreeBase_<ValueT_, less_c_> {
	public:
	DD_ALIAS(ThisType, RedBlackTree_<ValueT_ DD_COMMA less_c_ DD_COMMA AllocatorT_ DD_COMMA need_instance_c_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(AllocatorType, AllocatorT_);

	private:
	DD_ALIAS(SuperType, RedBlackTreeBase_<ValueT_ DD_COMMA less_c_>);

	public:
	DD_INHERIT_TEMPLATE_ALIAS(NodeType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(NodePointerType);


	public:
#	if __cplusplus >= 201103L
	constexpr RedBlackTree_() = default;
#	else
	RedBlackTree_() throw() {
	}
#	endif

	public:
#	if __cplusplus >= 201103L
	constexpr RedBlackTree_(ThisType const& origin_) {
#	else
	RedBlackTree_(ThisType const& origin_) {
#	endif
	}

#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR RedBlackTree_(ThisType&& origin_)  {
	}

#	endif

	public:



};



#	if __cplusplus >= 201103L
template <typename ValueT_, typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType& less_c_, typename AllocatorT_>
#	else
template <typename ValueT_, typename LessThan<RedBlackTreeNode<ValueT_> >::FunctionType& less_c_, typename AllocatorT_>
#	endif
struct RedBlackTree_<ValueT_, less_c_, AllocatorT_, true> {
};



template <
	typename ValueT_,
#	if __cplusplus >= 201103L
	typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType& less_c_ = LessThan<RedBlackTreeNode<ValueT_>>::call,
#	else
	typename LessThan<RedBlackTreeNode<ValueT_> >::FunctionType& less_c_ = LessThan<RedBlackTreeNode<ValueT_> >::call,
#	endif
	typename AllocatorT_ = Allocator<ValueT_>
>
struct RedBlackTree : RedBlackTree_<ValueT_, less_c_, AllocatorT_, NeedInstance<AllocatorT_>::value> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::RedBlackTree;



DD_END_



#endif
