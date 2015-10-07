//	DDCPP/standard/bits/DD_BinaryTreeNode.hpp
#ifndef DD_BINARY_TREE_NODE_HPP_INCLUDED_
#	define DD_BINARY_TREE_NODE_HPP_INCLUDED_ 1



#	include "DD_ValueTypeNested.hpp"



DD_DETAIL_BEGIN_
struct EmptyBinaryTreeNode {
	DD_ALIAS(ThisType, EmptyBinaryTreeNode);


	ThisType* parent;
	ThisType* left;
	ThisType* right;


};



template <typename ValueT_>
struct BinaryTreeNode : EmptyBinaryTreeNode {
	DD_ALIAS(ThisType, BinaryTreeNode<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	ValueType value;


};



struct EmptyRedBlackTreeNode : EmptyBinaryTreeNode {
	DD_ALIAS(ThisType, EmptyRedBlackTreeNode);


#	if __cplusplus >= 201103L
	enum Color : CheckType {
		red = true,
		black = false
	};
#	else
	typedef CheckType Color;
	static Color const red = true;
	static Color const black = false;
#	endif


	Color color;


};



template <typename ValueT_>
struct RedBlackTreeNode : EmptyRedBlackTreeNode {
	DD_ALIAS(ThisType, RedBlackTreeNode<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	ValueType value;


};



template <typename BinaryTreeNodeT_>
inline ValidityType DD_CONSTEXPR has_root(BinaryTreeNodeT_* node_) DD_NOEXCEPT {
	return node_->parent;
}


template <typename BinaryTreeNodeT_>
inline ValidityType DD_CONSTEXPR has_left(BinaryTreeNodeT_* node_) DD_NOEXCEPT {
	return node_->left;
}


template <typename BinaryTreeNodeT_>
inline ValidityType DD_CONSTEXPR has_right(BinaryTreeNodeT_* node_) DD_NOEXCEPT {
	return node_->right;
}


template <typename BinaryTreeNodeT_>
inline ValidityType DD_CONSTEXPR is_root(BinaryTreeNodeT_* node_) DD_NOEXCEPT {
	return !has_root(node_);
}


template <typename BinaryTreeNodeT_>
inline ValidityType is_left_child(BinaryTreeNodeT_* node_) DD_NOEXCEPT {
	DD_ASSERT(!is_root(node_), "Failed to judge a non-child node: 'DD::is_left_child'");
	return node_ == node_->parent->left;
}


template <typename BinaryTreeNodeT_>
inline ValidityType is_right_child(BinaryTreeNodeT_* node_) DD_NOEXCEPT {
	DD_ASSERT(!is_root(node_), "Failed to judge a non-child node: 'DD::is_right_child'");
	return node_ == node_->parent->right;
}


template <typename BinaryTreeNodeT_>
inline BinaryTreeNodeT_* minimum_binary_tree_node(BinaryTreeNodeT_* root_) DD_NOEXCEPT {
	DD_ASSERT(root_, "Failed to find minimum node in an empty binary (sub-)tree: 'DD::minimum_binary_tree_node'");
	if (root_->right) {
		root_ = root_->right;
	}
	return root_;
}


template <typename BinaryTreeNodeT_>
ProcessType left_rotate(BinaryTreeNodeT_* root_) DD_NOEXCEPT {
	BinaryTreeNodeT_* temp_ = root_->right;
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


template <typename BinaryTreeNodeT_>
ProcessType right_rotate(BinaryTreeNodeT_* root_) DD_NOEXCEPT {
	BinaryTreeNodeT_* temp_ = root_->left;
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



DD_DETAIL_END_



DD_BEGIN_
using detail_::EmptyBinaryTreeNode;
using detail_::BinaryTreeNode;
using detail_::EmptyRedBlackTreeNode;
using detail_::RedBlackTreeNode;
using detail_::is_left_child;
using detail_::is_right_child;
using detail_::left_rotate;
using detail_::right_rotate;



DD_END_



#endif
