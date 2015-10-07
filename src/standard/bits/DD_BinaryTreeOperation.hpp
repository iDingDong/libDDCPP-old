//	DDCPP/standard/bits/DD_BinarySearchTree.hpp
#ifndef DD_BINARY_SEARCH_TREE_HPP_INCLUDED_



#	include "DD_BinaryTreeNode.hpp"



DD_DETAIL_BEGIN_
template <int workaround_>
struct BinaryTreeOperation_ {
	static ValidityType DD_CONSTEXPR has_root(EmptyBinaryTreeNode* node_) DD_NOEXCEPT {
		return node_->parent;
	}


	static ValidityType DD_CONSTEXPR has_left(EmptyBinaryTreeNode* node_) DD_NOEXCEPT {
		return node_->left;
	}


	static ValidityType DD_CONSTEXPR has_right(EmptyBinaryTreeNode* node_) DD_NOEXCEPT {
		return node_->right;
	}


	static ValidityType DD_CONSTEXPR is_root(EmptyBinaryTreeNode* node_) DD_NOEXCEPT {
		return !has_root(node_);
	}


	static ValidityType is_left_child(EmptyBinaryTreeNode* node_) DD_NOEXCEPT {
		DD_ASSERT(!is_root(node_), "Failed to judge a non-child node: 'DD::is_left_child'");
		return node_ == node_->parent->left;
	}


	static ValidityType is_right_child(EmptyBinaryTreeNode* node_) DD_NOEXCEPT {
		DD_ASSERT(!is_root(node_), "Failed to judge a non-child node: 'DD::is_right_child'");
		return node_ == node_->parent->right;
	}


	static EmptyBinaryTreeNode* minimum_node(EmptyBinaryTreeNode* root_) DD_NOEXCEPT {
		DD_ASSERT(root_, "Failed to find minimum node in an empty binary (sub-)tree: 'DD::minimum_binary_tree_node'");
		while (root_->right) {
			root_ = root_->right;
		}
		return root_;
	}


	static ProcessType left_rotate(EmptyBinaryTreeNode* root_) DD_NOEXCEPT;


	static ProcessType right_rotate(EmptyBinaryTreeNode* root_) DD_NOEXCEPT;


};



template <int workaround_>
ProcessType BinaryTreeOperation_<workaround_>::left_rotate(EmptyBinaryTreeNode* root_) DD_NOEXCEPT {
	EmptyBinaryTreeNode* temp_ = root_->right;
	root_->right = temp_->left;
	if (root_->right) {
		root_->right->parent = root_;
	}
	if (!is_root(root_)) {
		if (is_left_child(root_)) {
			root_->parent->left = temp_;
		} else {
			root_->parent->right = temp_;
		}
	}
	temp_->parent = root_->parent;
	temp_->left = root_;
	root_->parent = temp_;
}


template <int workaround_>
ProcessType BinaryTreeOperation_<workaround_>::right_rotate(EmptyBinaryTreeNode* root_) DD_NOEXCEPT {
	EmptyBinaryTreeNode* temp_ = root_->left;
	root_->left = temp_->right;
	if (root_->left) {
		root_->left->parent = root_;
	}
	if (root_->parent) {
		if (is_right_child(root_)) {
			root_->parent->right = temp_;
		} else {
			root_->parent->left = temp_;
		}
	}
	temp_->parent = root_->parent;
	temp_->right = root_;
	root_->parent = temp_;
}



DD_ALIAS(BinaryTreeOperation, BinaryTreeOperation_<0>);



template <int workaround_>
struct BinarySearchTree



static ProcessType insert_node(EmptyBinaryTreeNode* root_, EmptyBinaryTreeNode* new_node) DD_NOEXCEPT;



template <int workaround_>
ProcessType BinaryTreeOperation_<workaround_>::insert_node(EmptyBinayrTreeNode*) DD_NOEXCEPT {

}


DD_DETAIL_END_
