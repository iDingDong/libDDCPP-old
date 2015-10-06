//	DDCPP/standard/bits/DD_RedBlackTree.hpp
#ifndef DD_RED_BLACK_TREE_HPP_INCLUDED_
#	define DD_RED_BLACK_TREE_HPP_INCLUDED_ 1



#	include "DD_NeedInstance.hpp"
#	include "DD_ReadOnlyCall.hpp"
#	include "DD_LessThan.hpp"
#	include "DD_BinaryTreeNode.hpp"
#	include "DD_Allocator.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType& less_c_>
struct RedBlackTreeBase_ {
	protected:
	DD_ALIAS(ThisType, RedBlackTreeBase_<ValueT_ DD_COMMA less_c_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(LessPredicatorType, typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType&);
	static LessPredicatorType DD_CONSTANT less = less_c_;

	protected:
	DD_ALIAS(NodeType, RedBlackTreeNode<ValueT_>);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodePointerType, NodeType*);


	private:
	NodePointerType m_root_ DD_IN_CLASS_INITIALIZE(NodePointerType());


	protected:
#	if __cplusplus >= 201103L
	constexpr RedBlackTreeBase_() = default;
#	else
	RedBlackTreeBase_() throw() : m_root_() {
	}
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(RedBlackTreeBase_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(RedBlackTreeBase_)

	protected:
	DD_CONSTEXPR RedBlackTreeBase_(NodePointerType root_) DD_NOEXCEPT : m_root_(root_) {
	}


#	if __cplusplus >= 201103L
	protected:
	~RedBlackTreeBase_() = default;


#	endif
	protected:
	ProcessType insert_node_(NodePointerType new_node_) DD_NOEXCEPT;


	private:
	ProcessType insert_fix_up_(NodePointerType new_node_) DD_NOEXCEPT;


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(RedBlackTreeBase_)


};



template <typename ValueT_, typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType& less_c_>
ProcessType RedBlackTreeBase_<ValueT_, less_c_>::insert_node_(
	RedBlackTreeBase_<ValueT_, less_c_>::NodePointerType new_node_
) DD_NOEXCEPT {
	new_node_->left = NodePointerType();
	new_node_->right = NodePointerType();
	if (m_root_) {
		m_root_ = new_node_;
		new_node_->color = NodeType::black;
		new_node_->parent = NodePointerType();
	} else {
		new_node_->color = NodeType::red;
		new_node_->parent = m_root_;
		for (; ; ) {
			if (less(*new_node_, *new_node_->parent)) {
				if (new_node_->parent->left) {
					new_node_->parent = new_node_->parent->left;
				} else {
					new_node_->parent->left = new_node_;
					break;
				}
			} else if (less(*new_node_->parent, *new_node_)) {
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
}


template <typename ValueT_, typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType& less_c_>
ProcessType RedBlackTreeBase_<ValueT_, less_c_>::insert_fix_up_(
	RedBlackTreeBase_<ValueT_, less_c_>::NodePointerType new_node_
) DD_NOEXCEPT {
	while (new_node_->parent->color == NodeType::red) {
		if (is_left_child(new_node_->parent)) {
			NodePointerType temp_ = new_node_->parent->parent->right;
			if (temp_->color == NodeType::red) {
				new_node_->parent->color = NodeType::black;
				temp_->color = NodeType::black;
				temp_->parent = NodeType::red;
				new_node_ = temp_->parent;
			} else if (is_right_child(new_node_)) {
				new_node_ = new_node_->parent;
				left_rotate(new_node_);
			}
			new_node_->parent->color = NodeType::black;
			new_node_->parent->parent->color = NodeType::red;
			right_rotate(new_node_->parent->parent);
		} else {
			NodePointerType temp_ = new_node_->parent->parent->left;
			if (temp_->color == NodeType::red) {
				new_node_->parent->color = NodeType::black;
				temp_->color = NodeType::black;
				temp_->parent = NodeType::red;
				new_node_ = temp_->parent;
			} else if (is_left_child(new_node_)) {
				new_node_ = new_node_->parent;
				right_rotate(new_node_);
			}
			new_node_->parent->color = NodeType::black;
			new_node_->parent->parent->color = NodeType::red;
			left_rotate(new_node_->parent->parent);
		}
	}
	m_root_->color = NodeType::black;
}



template <
	typename ValueT_,
	typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType& less_c_,
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



template <typename ValueT_, typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType& less_c_, typename AllocatorT_>
struct RedBlackTree_<ValueT_, less_c_, AllocatorT_, true> {
};



template <
	typename ValueT_,
	typename LessThan<RedBlackTreeNode<ValueT_>>::FunctionType& less_c_ = LessThan<RedBlackTreeNode<ValueT_>>::call,
	typename AllocatorT_ = Allocator<ValueT_>
>
struct RedBlackTree : RedBlackTree_<ValueT_, less_c_, AllocatorT_, NeedInstance<AllocatorT_>::value> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::RedBlackTree;



DD_END_



#endif
