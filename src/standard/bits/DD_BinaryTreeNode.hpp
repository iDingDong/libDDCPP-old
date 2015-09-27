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
struct BinaryTreeNode : EmptyBinaryTreeNode {
	DD_ALIAS(ThisType, BinaryTree<_ValueT>);
	DD_VALUE_TYPE_NESTED(_ValueT)


	ValueType value;


};



struct EmptyRedBlackTreeNode : EmptyBinaryTreeNode {
	DD_ALIAS(ThisType, EmptyRedBlackTreeNode);


#	if __cplusplus >= 201103L
	enum Color : CheckType {
		red = true;
		black = false;
	};
#	else
	typedef CheckType Color;
	static Color const red = true;
	static Color const black = false;
#	endif


	Color color;


};



template <typename _ValueT>
struct RedBlackTreeNode : EmptyRedBlackTreeNode {
	DD_ALIAS(ThisType, RedBlackTreeNode<_ValueT>);
	DD_VALUE_TYPE_NESTED(_ValueT)


	ValueType value;


};



_DD_END



#endif
