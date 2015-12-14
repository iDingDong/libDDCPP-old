//	DDCPP/standard/bits/DD_BinarySearchTree.hpp
#ifndef DD_BINARY_SEARCH_TREE_HPP_INCLUDED_
#	define DD_BINARY_SEARCH_TREE_HPP_INCLUDED_ 1



#	include "DD_Value.hpp"
#	include "DD_Illogic.hpp"
#	include "DD_logical_not_of.hpp"
#	include "DD_BinaryTreeNode.hpp"
#	include "DD_LessThan.hpp"



DD_DETAIL_BEGIN_
inline ProcessType transplant_binary_tree_(
	EmptyBinaryTreeNode** root_,
	EmptyBinaryTreeNode* old_root_,
	EmptyBinaryTreeNode* new_root_
) DD_NOEXCEPT {
	if (!old_root_->has_parent()) {
		*root_ = new_root_;
	} else if (old_root_->is_left()) {
		old_root_->parent->left = new_root_;
	} else {
		old_root_->parent->right = new_root_;
	}
	if (new_root_) {
		new_root_->parent = old_root_->parent;
	}
}


template <int workaround>
inline ProcessType detach_node_(EmptyBinaryTreeNode** root_, EmptyBinaryTreeNode* node_) DD_NOEXCEPT {
	if (node_->has_left()) {
		transplant_binary_tree_(root_, node_, node_->right);
	} else if (node_->has_right()) {
		transplant_binary_tree_(root_, node_, node_->left);
	} else {
		EmptyBinaryTreeNode* temp_ = node_->right->get_minimum();
		if (temp_ != node_->right) {
			transplant_binary_tree_(root_, temp_, temp_->right);
			temp_->right = node_->right;
			temp_->right->parent = temp_;
		}
		transplant_binary_tree_(root_, node_, temp_);
		temp_->left = node_->left;
		temp_->left->parent = temp_;
	}
}

inline ProcessType detach_node_(EmptyBinaryTreeNode** root_, EmptyBinaryTreeNode* node_) DD_NOEXCEPT {
	detach_node_<0>(root_, node_);
}


template <typename NodeT_, typename LessThan<NodeT_>::FunctionType& less_c_>
ProcessType insert_binary_search_tree_node_as_sub_(NodeT_* root_, NodeT_* new_node_) DD_NOEXCEPT {
	new_node_->parent = root_;
	for (; ; ) {
		if (less_c_(*new_node_, *new_node_->parent)) {
			if (new_node_->parent->left) {
				new_node_->parent = new_node_->parent->left;
			} else {
				new_node_->parent->left = new_node_;
				break;
			}
		} else if (less_c_(*new_node_->parent, *new_node_)) {
			if (new_node_->parent->right) {
				new_node_->parent = new_node_->parent->right;
			} else {
				new_node_->parent->right = new_node_;
				break;
			}
		} else {
			throw Illogic("Repeat element found in a search tree.");
		}
	}
}


template <typename NodeT_, typename LessThan<NodeT_>::FunctionType& less_c_>
inline ProcessType insert_binary_search_tree_node_(NodeT_** root_, NodeT_* new_node_) DD_NOEXCEPT {
	if (*root_) {
		insert_binary_search_tree_node_as_sub_<NodeT_, less_c_>(*root_, new_node_);
	} else {
		*root_ = new_node_;
	}
}

template <typename NodeT_>
inline ProcessType insert_binary_search_tree_node_(NodeT_** root_, NodeT_* new_node_) DD_NOEXCEPT {
	insert_binary_search_tree_node_<NodeT_, LessThan<NodeT_>::call>(root_, new_node_);
}



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
