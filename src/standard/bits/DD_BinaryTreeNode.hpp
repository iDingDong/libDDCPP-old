//	DDCPP/standard/bits/DD_BinaryTreeNode.hpp
#ifndef DD_BINARY_TREE_NODE_HPP_INCLUDED_
#	define DD_BINARY_TREE_NODE_HPP_INCLUDED_ 1



#	include "DD_debugger_definitions.hpp"
#	include "DD_ValueTypeNested.hpp"



DD_DETAIL_BEGIN_
struct EmptyBinaryTreeNode {
	DD_ALIAS(ThisType, EmptyBinaryTreeNode);

	DD_ALIAS(NodePointerType, ThisType*);
	DD_ALIAS(NodeConstPointerType, ThisType const*);


	NodePointerType parent;
	NodePointerType left;
	NodePointerType right;


	ValidityType DD_CONSTEXPR has_parent() const DD_NOEXCEPT {
		return parent;
	}


	ValidityType DD_CONSTEXPR has_left() const DD_NOEXCEPT {
		return left;
	}


	ValidityType DD_CONSTEXPR has_right() const DD_NOEXCEPT {
		return right;
	}


	ValidityType DD_CONSTEXPR is_left() const DD_NOEXCEPT {
		DD_ASSERT(has_parent(), "Not a child: 'DD::EmptyBinaryTreeNode::is_left'");
		return this == parent->left;
	}


	ValidityType DD_CONSTEXPR is_right() const DD_NOEXCEPT {
		DD_ASSERT(has_parent(), "Not a child: 'DD::EmptyBinaryTreeNode::is_right'");
		return this == parent->right;
	}


	NodePointerType DD_CONSTEXPR get_brother() const DD_NOEXCEPT {
		DD_ASSERT(has_parent(), "No brother to get: 'DD::EmptyBinaryTreeNode::get_brother'");
		return is_left() ? parent->right : parent->left;
	}


	NodePointerType get_minimum() DD_NOEXCEPT {
		NodePointerType current_ = this;
		if (current_->has_left()) {
			current_ = current_->left;
		}
		return current_;
	}

	NodeConstPointerType DD_CONSTEXPR get_minimum() const DD_NOEXCEPT {
#	if __cplusplus >= 201402L
		NodeConstPointerType current_ = this;
		if (current_->has_left()) {
			current_ = current_->left;
		}
		return current_;
#	else
		return has_left() ? static_cast<NodeConstPointerType>(left)->get_minimum() : this;
#	endif
	}


	template <int workaround_>
	ProcessType left_rotate() DD_NOEXCEPT;

	ProcessType left_rotate() DD_NOEXCEPT {
		left_rotate<0>();
	}


	template <int workaround_>
	ProcessType right_rotate() DD_NOEXCEPT;

	ProcessType right_rotate() DD_NOEXCEPT {
		right_rotate<0>();
	}


};



template <int workaround_>
ProcessType EmptyBinaryTreeNode::left_rotate() DD_NOEXCEPT {
	NodePointerType temp_ = this->right;
	this->right = temp_->left;
	if (this->has_right()) {
		this->right->parent = this;
	}
	if (this->has_parent()) {
		if (this->is_left()) {
			this->parent->left = temp_;
		} else {
			this->parent->right = temp_;
		}
	}
	temp_->parent = this->parent;
	temp_->left = this;
	this->parent = temp_;
}



template <int workaround_>
ProcessType EmptyBinaryTreeNode::right_rotate() DD_NOEXCEPT {
	NodePointerType temp_ = this->left;
	this->left = temp_->right;
	if (this->has_left()) {
		this->left->parent = this;
	}
	if (this->has_parent()) {
		if (this->is_right()) {
			this->parent->right = temp_;
		} else {
			this->parent->left = temp_;
		}
	}
	temp_->parent = this->parent;
	temp_->right = this;
	this->parent = temp_;
}



template <typename ValueT_>
struct BinaryTreeNode : EmptyBinaryTreeNode {
	DD_ALIAS(ThisType, BinaryTreeNode<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	ValueType value;


};



struct EmptyRedBlackTreeNode {
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



struct RedBlackTreeNodeBase : EmptyBinaryTreeNode, EmptyRedBlackTreeNode {
};



template <typename ValueT_>
struct RedBlackTreeNode : RedBlackTreeNodeBase {
	DD_ALIAS(ThisType, RedBlackTreeNode<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


	ValueType value;


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::EmptyBinaryTreeNode;
using detail_::BinaryTreeNode;
using detail_::EmptyRedBlackTreeNode;
using detail_::RedBlackTreeNode;



DD_END_



#endif
