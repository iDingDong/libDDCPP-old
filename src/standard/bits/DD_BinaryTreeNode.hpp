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
