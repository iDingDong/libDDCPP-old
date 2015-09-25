//	DDCPP/standard/bits/DD_BinaryTreeNode.hpp
#ifndef _DD_BINARY_TREE_NODE_HPP_INCLUDED
#	define _DD_BINARY_TREE_NODE_HPP_INCLUDED 1



#	include "DD_ValueTypeNested.hpp"



_DD_BEGIN
struct EmptyBinaryTreeNode {
	DD_ALIAS(ThisType, EmptyBinaryTreeNode);

	ThisType* parent;
	ThisType* left;
	ThisType* right;


};



template <typename _ValueT>
struct BinaryTreeNode : EmptyBinaryTreeNode, ValueTypeNested<_ValueT> {
	DD_ALIAS(ThisType, BinaryTree<_ValueT>);


	ValueType value;


};



_DD_END



#endif
