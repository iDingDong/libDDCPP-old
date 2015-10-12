//	standard/bits/DD_List.hpp
#ifndef DD_LIST_HPP_
#	define DD_LIST_HPP_ 1



#	include "DD_IteratorNested.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_address_of.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_InitializerList.hpp"
#	include "DD_container_definitions.hpp"
#	include "DD_ListNode.hpp"
#	include "DD_ListIterator.hpp"
#	include "DD_length_difference.hpp"



DD_DETAIL_BEGIN_
struct ListBase_ {
	protected:
	DD_ALIAS(ThisType, ListBase_);

	protected:
	DD_ALIAS(EmptyNode, EmptyListNode);
	DD_ALIAS(EmptyNodeConst, EmptyNode const);
	DD_ALIAS(EmptyNodeReference, EmptyNode&);
	DD_ALIAS(EmptyNodeConstReference, EmptyNodeConst&);
	DD_ALIAS(EmptyNodePointer, EmptyNode*);
	DD_ALIAS(EmptyNodeConstPointer, EmptyNodeConst*);

	protected:
	DD_ALIAS(NodeType, EmptyNode);
	DD_ALIAS(NodeConstType, NodeType const);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodeConstReferenceType, NodeConstType&);
	DD_ALIAS(NodePointerType, NodeType*);
	DD_ALIAS(NodeConstPointerType, NodeConstType*);


	private:
	NodeType m_sentry_;


	protected:
	DD_CONSTEXPR ListBase_() DD_NOEXCEPT : m_sentry_{address_of(m_sentry_), address_of(m_sentry_)} {
	}

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(ListBase_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(ListBase_)

	protected:
	DD_CONSTEXPR ListBase_(NodePointerType begin_, NodePointerType end_) DD_NOEXCEPT : m_sentry_{begin_, end_} {
	}


	protected:


};



template <typename ValueT_>
struct List_ : ListBase_ {
	protected:
	DD_ALIAS(SuperType, ListBase_);
	DD_ALIAS(ThisType, List_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	protected:
	DD_INHERIT_ALIAS(EmptyNode);
	DD_INHERIT_ALIAS(EmptyNodeConst);
	DD_INHERIT_ALIAS(EmptyNodeReference);
	DD_INHERIT_ALIAS(EmptyNodeConstReference);
	DD_INHERIT_ALIAS(EmptyNodePointer);
	DD_INHERIT_ALIAS(EmptyNodeConstPointer);

	protected:
	DD_ALIAS(NodeType, ListNode<ValueType>);
	DD_ALIAS(NodeConstType, NodeType const);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodeConstReferenceType, NodeConstType&);
	DD_ALIAS(NodePointerType, NodeType*);
	DD_ALIAS(NodeConstPointerType, NodeConstType*);

	protected:
	DD_ALIAS(LengthType, DD::LengthType);

	protected:
	DD_ALIAS(Iterator, ListIterator<NodeType>);
	DD_ALIAS(ConstIterator, ListIterator<NodeConstType>);
	DD_ITERATOR_NESTED


	public:
#	if __cplusplus >= 201103L
	constexpr List_() = default;
#	else
	List_ throw() {
	}
#	endif

	public:
	DD_DELETE_COPY_CONSTRUCTOR(List_)

	public:
	DD_DELETE_MOVE_CONSTRUCTOR(List_)

	public:
	DD_CONSTEXPR List_(NodePointerType begin_, NodePointerType end_) DD_NOEXCEPT : ListBase_(begin_, end_) {
	}


#	if __cplusplus >= 201103L
	public:
	~List_() = default;


#	endif
	public:
	LengthType length() DD_NOEXCEPT {
		return length_difference(begin(), end());
	}


	public:
	ValidityType is_empty() DD_NOEXCEPT {
		return begin() == end();
	}


	public:
	NodePointerType get_sentry() DD_NOEXCEPT {
		return static_cast<NodePointerType>(address_of(m_sentry_));
	}

	public:
	NodeConstPointerType get_sentry() const DD_NOEXCEPT {
		return static_cast<NodePointerType>(address_of(m_sentry_));
	}


	public:
	Iterator begin() DD_NOEXCEPT_AS(Iterator(get_sentry()->next)) {
		return Iterator(get_sentry()->next);
	}

	public:
	ConstIterator begin() const DD_NOEXCEPT_AS(ConstIterator(get_sentry()->next)) {
		return ConstIterator(get_sentry()->next);
	}


	public:
	Iterator end() DD_NOEXCEPT_AS(Iterator(get_sentry())) {
		return Iterator(get_sentry());
	}

	public:
	ConstIterator end() const DD_NOEXCEPT_AS(ConstIterator(get_sentry())) {
		return Iterator(get_sentry());
	}


	public:
	DD_DELETE_COPY_ASSIGNMENT(List_)

	public:
	DD_DELETE_MOVE_ASSIGNMENT(List_)


};



template <typename ValueT_, typename AllocatorT_, ValidityType need_instance_c_>
struct List : List_<ValueT_> {
	public:
	DD_ALIAS(SuperType, List_<ValueT_>);
	DD_ALIAS(ThisType, List<ValueT_ DD_COMMA AllocatorT_ DD_COMMA need_instance_c_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(Allocator, AllocatorT_);

	private:
	DD_ALIAS(EmptyNode, EmptyListNode);
	DD_ALIAS(EmptyNodeConst, EmptyNode const);
	DD_ALIAS(EmptyNodeReference, EmptyNode&);
	DD_ALIAS(EmptyNodeConstReference, EmptyNodeConst&);
	DD_ALIAS(EmptyNodePointer, EmptyNode*);
	DD_ALIAS(EmptyNodeConstPointer, EmptyNodeConst*);

	public:
	DD_INHERIT_TEMPLATE_ALIAS(NodeType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeConstType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeConstReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(NodePointerType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeConstPointerType);

	public:
	DD_ALIAS(LengthType, DD::LengthType);

	public:
	DD_INHERIT_TEMPLATE_ALIAS(Iterator);
	DD_INHERIT_TEMPLATE_ALIAS(ConstIterator);
	DD_INHERIT_TEMPLATE_ALIAS(ReverseIterator);
	DD_INHERIT_TEMPLATE_ALIAS(ConstReverseIterator);


#	if __cplusplus >= 201103L
	public:
	List() = default;

#	endif
	public:
	List(ThisType const& origin_) DD_NOEXCEPT_AS(append(origin_)) {
		try {
			append(origin_);
		} catch (...) {
			destruct_();
			throw;
		}
	}

#	if __cplusplus >= 201103L
	public:
	List(ThisType&& origin_) noexcept : SuperType(origin_.m_sentry_->previous, origin_.m_sentry_->next) {
		origin_.reset_();
	}

#	endif

	public:
	~List() DD_NOEXCEPT {
		destruct_();
	}


	public:
	ProcessType swap(ThisType& target_) DD_NOEXCEPT {
		using DD::swap;
		swap(this->m_sentry_, target_.m_sentry_);
	}


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType clone(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ const& end___
	) {
		for (Iterator current_(this->begin()); current_ != this->end(); ++current_, ++begin___) {
			if (begin___ == end___) {
				erase_range(current_, this->end());
				return;
			}
			*current_ = *begin___;
		}
		append_range(begin___, end___);
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType clone(UndirectionalRangeT__ const& origin___) {
		clone(DD_SPLIT_RANGE(origin___));
	}


	public:
#	if __cplusplus >= 201103L
	template <typename ValueT__>
	ProcessType push_front(ValueT__&& value___) {
		insert(this->begin(), forward<ValueT__>(value___));
	}
#	else
	template <typename ValueT__>
	ProcessType push_front(ValueT__ const& value___) {
		insert(this->begin(), value___);
	}
#	endif


	public:
#	if __cplusplus >= 201103L
	template <typename ValueT__>
	ProcessType push_back(ValueT__&& value___) {
		insert(this->end(), forward<ValueT__>(value___));
	}
#	else
	template <typename ValueT__>
	ProcessType push_back(ValueT__ const& value___) {
		insert(this->end(), value___);
	}
#	endif


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType append_range(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ const& end___
	) {
		for (; begin___ != end___; ++begin___) {
			push_back(*begin___);
		}
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType append_range(UndirectionalRangeT__ const& range___) {
		append_range(DD_SPLIT_RANGE(range___));
	}


	public:
	static ProcessType splice(
		NodePointerType position_,
		NodePointerType begin_,
		NodePointerType end_
	) DD_NOEXCEPT {
		NodePointerType front_ = position_->previous;
		position_->previous = end_->previous;
		position_->previous->next = position_;
		begin_->previous->next = end_;
		end_->previous = begin_->previous;
		front_->next = begin_;
		begin_->previous_ = front_;
	}


	public:
	static ProcessType transfer(Iterator const& position_, Iterator const& new_node_) DD_NOEXCEPT_AS(transfer_(position_.get_node() DD_COMMA new_node_.get_node())) {
		transfer_(position_.get_node(), new_node_.get_node());
	}

	private:
	static ProcessType transfer_(NodePointerType position_, NodePointerType node_) DD_NOEXCEPT_AS(
		delink_(node_) DD_COMMA enlink(position_ DD_COMMA node_)
	) {
		delink_(node_);
		enlink_(position_, node_);
	}


#	if __cplusplus >= 201103L
	public:
	template <typename ValueT__>
	static Iterator insert(Iterator const& position_, ValueT__&& value___) {
		return Iterator(insert_(position_.get_node(), forward<ValueT__>(value___)));
	}

	private:
	template <typename ValueT__>
	static ProcessType insert_(NodePointerType position_, ValueT__&& value___) {
		NodePointerType new_node_ = create_node_(forward<ValueT__>(value___));
		enlink_(position_, new_node_);
		return new_node_;
	}
#	else
	public:
	template <typename ValueT__>
	static Iterator insert(Iterator const& position_, ValueT__ const& value___) {
		return Iterator(insert_(position_.get_node(), value___));
	}

	private:
	template <typename ValueT__>
	static NodePointerType insert_(NodePointerType position_, ValueT__ const& value___);
		NodePointerType new_node_ = create_node_(value___);
		enlink_(position_, new_node_);
		return new_node_;
	}
#	endif


	private:
	static ProcessType enlink_(NodePointerType position_, NodePointerType new_node_) DD_NOEXCEPT {
		new_node_->previous = position_->previous;
		new_node_->previous->next = new_node_;
		new_node_->next = position_;
		position_->previous = new_node_;
	}

	private:
	static ProcessType delink_(NodePointerType node_) {
		node_->previous->next = node_->next;
		node_->next->previous = node_->previous;
	}


	public:
	static Iterator erase(Iterator const& position_) DD_NOEXCEPT_AS(Iterator(erase_(position_.get_node()))) {
		return Iterator(erase_(position_.get_node()));
	}

	public:
	static NodePointerType erase_(NodePointerType position_) DD_NOEXCEPT {
		position_ = position_->next;
		delink_(position_->previous);
		destroy_node_(position_);
		return position_;
	}


	public:
	static Iterator erase_range(
		Iterator begin_,
		Iterator const& end_
	) DD_NOEXCEPT_AS(Iterator(erase_range_(begin_.get_node() DD_COMMA end_.get_node()))) {
		return Iterator(erase_range_(begin_.get_node(), end_.get_node()));
	}

	private:
	static NodePointerType erase_range_(
		NodePointerType begin_,
		NodePointerType end_
	) DD_NOEXCEPT_AS(erase(begin_)) {
		begin_->previous->next = end_->next;
		end_->next->previous = begin_->previous;
		for (; begin_ != end_; begin_ = begin_->next) {
			destroy_node_(begin_);
		}
		return begin_;
	}


	public:
	ProcessType clear() DD_NOEXCEPT {
		erase_range(this->begin(), this->end());
	}


	private:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	static NodePointerType creat_node_(ValueT__&& value___) {
		NodePointerType new_node_ = Allocator::Basic::allocate(sizeof(NodeType));
		Allocator::construct(new_node_->value, forward<ValueT__>(value___));
		return new_node_;
	}
#	else
	static NodePointerType creat_node_(ValueT__ const& value___) {
		NodePointerType new_node_ = Allocator::Basic::allocate(sizeof(NodeType));
		Allocator::construct(new_node_->value, value___);
		return new_node_;
	}
#	endif


	private:
	template <typename PointerT__>
	static ProcessType destroy_node_(PointerT__ const& node_) DD_NOEXCEPT {
		Allocator::destruct(node_->value);
		Allocator::Basic::deallocate(address_of(*node_), sizeof(NodeType));
	}


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		for (Iterator current_ = this->begin(); current_++ != this->end(); ) {
			destroy_node_(current_.get_node()->previous);
		}
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT {
		clone(origin_);
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT {
		swap(origin_);
	}


#	endif
	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ThisType& operator <<(ValueT__&& value___) DD_NOEXCEPT_AS(push_back(forward<ValueT__>(value___))) {
		push_back(forward<ValueT__>(value___));
		return *this;
	}
#	else
	ThisType& operator <<(ValueT__ const& value___) DD_NOEXCEPT_AS(push_back(value___)) {
		push_back(value___);
		return *this;
	}
#	endif


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::List;



DD_END_



#endif
