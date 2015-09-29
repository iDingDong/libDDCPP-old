//	standard/bits/DD_List.hpp
#ifndef DD_LIST_HPP_
#	define DD_LIST_HPP_ 1



#	include "DD_CompatStlContainer.hpp"
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



DD_DETAIL_BEGIN
template <typename ValueT_>
struct ListBase_ {
	public:
	DD_ALIAS(ThisType, List_<ValueT_>);
	DD_ALIAS(ValueType, ValueT_);

	private:
	DD_ALIAS(EmptyNode, EmptyListNode);
	DD_ALIAS(EmptyNodeConst, EmptyNode const);
	DD_ALIAS(EmptyNodeReference, EmptyNode&);
	DD_ALIAS(EmptyNodeConstReference, EmptyNodeConst&);
	DD_ALIAS(EmptyNodePointer, EmptyNode*);
	DD_ALIAS(EmptyNodeConstPointer, EmptyNodeConst*);

	public:
	DD_ALIAS(Node, ListNode<ValueType>);
	DD_ALIAS(NodeConst, Node const);
	DD_ALIAS(NodeReference, Node&);
	DD_ALIAS(NodeConstReference, NodeConst&);
	DD_ALIAS(NodePointer, Node*);
	DD_ALIAS(NodeConstPointer, NodeConst*);

	public:
	DD_CONTAINER_DECLARATIONS
	DD_ALIAS(LengthType, DD::LengthType);

	public:
	DD_ALIAS(Iterator, ListIterator<NodeType>);
	DD_ALIAS(ReverseIterator, DD_MODIFY_TRAIT(IteratorReverse, Iterator));
	DD_ALIAS(ConstIterator, ListIterator<NodeConstType>);
	DD_ALIAS(ConstReverseIterator, DD_MODIFY_TRAIT(IteratorReverse, ConstIterator));


	private:
	EmptyListNode m_sentry_;


	public:
	ListBase_() DD_NOEXCEPT : m_sentry_{address_of(m_sentry_), address_of(m_sentry_)} {
	}

	public:
	DD_DELETE_COPY_CONSTRUCTOR(ListBase_)

	public:
	DD_DELETE_MOVE_CONSTRUCTOR(ListBase_)

	public:
	ListBase_(NodePointer begin_, NodePointer end_) DD_NOEXCEPT : m_sentry_{begin_, end_} {
	}


#	if __cplusplus >= 201103L
	public:
	~ListBase_() = default;


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
	NodePointer get_sentry() DD_NOEXCEPT {
		return static_cast<NodePointer>(address_of(m_sentry_));
	}

	public:
	NodeConstPointer get_sentry() const DD_NOEXCEPT {
		return static_cast<NodePointer>(address_of(m_sentry_));
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
	DD_DELETE_COPY_ASSIGNMENT(ListBase_)

	public:
	DD_DELETE_MOVE_ASSIGNMENT(ListBase_)


};



template <typename ValueT_, typename AllocatorT_, ValidityType need_instance_c_>
struct List_ : ListBase_<ValueT_> {
	public:
	DD_ALIAS(SuperType, List_<ValueT_>);
	DD_ALIAS(ThisType, List_<ValueT_ DD_COMMA AllocatorT_ DD_COMMA need_instance_c_>);
	DD_ALIAS(ValueType, ValueT_);
	DD_ALIAS(Allocator, AllocatorT_);

	private:
	DD_ALIAS(EmptyNode, EmptyListNode);
	DD_ALIAS(EmptyNodeConst, EmptyNode const);
	DD_ALIAS(EmptyNodeReference, EmptyNode&);
	DD_ALIAS(EmptyNodeConstReference, EmptyNodeConst&);
	DD_ALIAS(EmptyNodePointer, EmptyNode*);
	DD_ALIAS(EmptyNodeConstPointer, EmptyNodeConst*);

	public:
	DD_ALIAS(Node, ListNode<ValueType>);
	DD_ALIAS(NodeConst, Node const);
	DD_ALIAS(NodeReference, Node&);
	DD_ALIAS(NodeConstReference, NodeConst&);
	DD_ALIAS(NodePointer, Node*);
	DD_ALIAS(NodeConstPointer, NodeConst*);

	public:
	DD_CONTAINER_DECLARATIONS
	DD_ALIAS(LengthType, DD::LengthType);

	public:
	DD_ALIAS(Iterator, ListIterator<NodeType>);
	DD_ALIAS(ReverseIterator, DD_MODIFY_TRAIT(IteratorReverse, Iterator));
	DD_ALIAS(ConstIterator, ListIterator<NodeConstType>);
	DD_ALIAS(ConstReverseIterator, DD_MODIFY_TRAIT(IteratorReverse, ConstIterator));


#	if __cplusplus >= 201103L
	public:
	List_() = default;

#	endif
	public:
	List_(ThisType const& origin_) DD_NOEXCEPT_AS(append(origin_)) {
		try {
			append(origin_);
		} catch (...) {
			destruct();
			throw;
		}
	}

#	if __cplusplus >= 201103L
	public:
	List_(ThisType&& origin_) noexcept : SuperType(origin_.m_sentry_->previous, origin_.m_sentry_->next) {
		origin_.reset_();
	}

#	endif

	public:
	~List_() DD_NOEXCEPT {
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
		for (Iterator current_(begin()); current_ != end(); ++current_, ++begin___) {
			if (begin__ == end__) {
				erase_range(current_, end());
				return;
			}
			*current_ = *begin___;
		}
		append_range(begin__, end___);
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
		insert(begin(), forward<ValueT__>(value___));
	}
#	else
	template <typename ValueT__>
	ProcessType push_front(ValueT__ const& value___) {
		insert(begin(), value___);
	}
#	endif


	public:
#	if __cplusplus >= 201103L
	template <typename ValueT__>
	ProcessType push_back(ValueT__&& value___) {
		insert(end(), forward<ValueT__>(value___));
	}
#	else
	template <typename ValueT__>
	ProcessType push_back(ValueT__ const& value___) {
		insert(end(), value___);
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
		NodePointer position_,
		NodePointer begin_,
		NodePointer end_
	) DD_NOEXCEPT {

	}


	public:
	static ProcessType transfer(Iterator const& position_, Iterator const& new_node_) DD_NOEXCEPT_AS(transfer_(position_.get_node() DD_COMMA new_node_.get_node())) {
		transfer_(position_.get_node(), new_node_.get_node());
	}

	private:
	static ProcessType transfer_(NodePointer position_, NodePointer node_) DD_NOEXCEPT_AS {
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
	static ProcessType insert_(NodePointer position_, ValueT__&& value___) {
		NodePointer new_node_ = create_node_(forward<ValueT__>(value___));
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
	static NodePointer insert_(NodePointer position_, ValueT__ const& value___);
		NodePointer new_node_ = create_node_(value___);
		enlink_(position_, new_node_);
		return new_node_;
	}
#	endif


	private:
	static ProcessType enlink_(NodePointer position_, NodePointer new_node_) DD_NOEXCEPT {
		new_node_->previous = position_->previous;
		new_node_->previous->next = new_node_;
		new_node_->next = position_;
		position_->previous = new_node_;
	}

	private:
	static ProcessType delink_(NodePointer node_) {
		node_->previous->next = node_->next;
		node_->next->previous = node_->previous;
	}


	public:
	static Iterator erase(Iterator const& position_) DD_NOEXCEPT_AS(Iterator(erase_(position_.get_node()))) {
		return Iterator(erase_(position_.get_node()));
	}

	public:
	static NodePointer erase_(NodePointer position_) DD_NOEXCEPT {
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
	static NodePointer erase_range_(
		NodePointer begin_,
		NodePointer end_
	) DD_NOEXCEPT_AS(erase(begin_)) {
		begin_->previous->next = end_->next;
		end_->next->previous = begin_->previous;
		for (; begin_ != end_; begin_ = begin_->next) {
			destroy_node_(begin_)
		}
		return begin_;
	}


	public:
	ProcessType clear() DD_NOEXCEPT {
		erase_range(begin(), end());
	}


	private:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	static NodePointer creat_node_(ValueT__&& value___) {
		NodePointer new_node_ = Allocator::Basic::allocate(sizeof(Node));
		Allocator::construct(new_node_->value, forward<ValueT__>(value___));
		return new_node_;
	}
#	else
	static NodePointer creat_node_(ValueT__ const& value___) {
		NodePointer new_node_ = Allocator::Basic::allocate(sizeof(Node));
		Allocator::construct(new_node_->value, value___);
		return new_node_;
	}
#	endif


	private:
	template <typename PointerT__>
	static ProcessType destroy_node_(PointerT__ const& node_) DD_NOEXCEPT {
		Allocator::destruct(node_->value);
		Allocator::Basic::deallocate(address_of(*node_), sizeof(Node));
	}


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		for (Iterator current_ = begin(); current_++ != end(); ) {
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
	ThisType& operator <<(ValueT__&& value___) DD_NOEXCEPT_AS(push_back(forward<ValueT__>(value__))) {
		push_back(forward<ValueT__>(value__));
		return *this;
	}
#	else
	ThisType& operator <<(ValueT__ const& value___) DD_NOEXCEPT_AS(push_back(value__)) {
		push_back(value__);
		return *this;
	}
#	endif


};



DD_DETAIL_END



DD_BEGIN



DD_END



#endif
