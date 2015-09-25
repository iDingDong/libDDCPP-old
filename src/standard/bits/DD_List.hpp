//	standard/bits/DD_List.hpp
#ifndef _DD_LIST_HPP
#	define _DD_LIST_HPP 1



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
template <typename _ValueT>
struct _ListBase {
	public:
	DD_ALIAS(ThisType, _List<_ValueT>);
	DD_ALIAS(ValueType, _ValueT);

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
	EmptyListNode _m_sentry;


	public:
	_ListBase() DD_NOEXCEPT : _m_sentry{address_of(_m_sentry), address_of(_m_sentry)} {
	}

	public:
	DD_DELETE_COPY_CONSTRUCTOR(_ListBase)

	public:
	DD_DELETE_MOVE_CONSTRUCTOR(_ListBase)

	public:
	_ListBase(NodePointer _begin, NodePointer _end) DD_NOEXCEPT : _m_sentry{_begin, _end} {
	}


#	if __cplusplus >= 201103L
	public:
	~_ListBase() = default;


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
		return static_cast<NodePointer>(address_of(_m_sentry));
	}

	public:
	NodeConstPointer get_sentry() const DD_NOEXCEPT {
		return static_cast<NodePointer>(address_of(_m_sentry));
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
	DD_DELETE_COPY_ASSIGNMENT(_ListBase)

	public:
	DD_DELETE_MOVE_ASSIGNMENT(_ListBase)


};



template <typename _ValueT, typename _AllocatorT, ValidityType _need_instance_c>
struct _List : _ListBase<_ValueT> {
	public:
	DD_ALIAS(SuperType, _List<_ValueT>);
	DD_ALIAS(ThisType, _List<_ValueT DD_COMMA _AllocatorT DD_COMMA _need_instance_c>);
	DD_ALIAS(ValueType, _ValueT);
	DD_ALIAS(Allocator, _AllocatorT);

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
	_List() = default;

#	endif
	public:
	_List(ThisType const& _origin) DD_NOEXCEPT_AS(append(_origin)) {
		try {
			append(_origin);
		} catch (...) {
			destruct();
			throw;
		}
	}

#	if __cplusplus >= 201103L
	public:
	_List(ThisType&& _origin) noexcept : SuperType(_origin._m_sentry->previous, _origin._m_sentry->next) {
		_origin._reset();
	}

#	endif

	public:
	~_List() DD_NOEXCEPT {
		_destruct();
	}


	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT {
		using DD::swap;
		swap(this->_m_sentry, _target._m_sentry);
	}


	public:
	template <typename _UndirectionalIteratorT_>
	ProcessType clone(
		_UndirectionalIteratorT_ __begin_,
		_UndirectionalIteratorT_ const& __end_
	) {
		for (Iterator _current(begin()); _current != end(); ++_current, ++__begin_) {
			if (__begin == __end) {
				erase_range(_current, end());
				return;
			}
			*_current = *__begin_;
		}
		append_range(__begin, __end_);
	}

	public:
	template <typename _UndirectionalRangeT_>
	ProcessType clone(_UndirectionalRangeT_ const& __origin_) {
		clone(DD_SPLIT_RANGE(__origin_));
	}


	public:
#	if __cplusplus >= 201103L
	template <typename _ValueT_>
	ProcessType push_front(_ValueT_&& __value_) {
		insert(begin(), forward<_ValueT_>(__value_));
	}
#	else
	template <typename _ValueT_>
	ProcessType push_front(_ValueT_ const& __value_) {
		insert(begin(), __value_);
	}
#	endif


	public:
#	if __cplusplus >= 201103L
	template <typename _ValueT_>
	ProcessType push_back(_ValueT_&& __value_) {
		insert(end(), forward<_ValueT_>(__value_));
	}
#	else
	template <typename _ValueT_>
	ProcessType push_back(_ValueT_ const& __value_) {
		insert(end(), __value_);
	}
#	endif


	public:
	template <typename _UndirectionalIteratorT_>
	ProcessType append_range(
		_UndirectionalIteratorT_ __begin_,
		_UndirectionalIteratorT_ const& __end_
	) {
		for (; __begin_ != __end_; ++__begin_) {
			push_back(*__begin_);
		}
	}

	public:
	template <typename _UndirectionalRangeT_>
	ProcessType append_range(_UndirectionalRangeT_ const& __range_) {
		append_range(DD_SPLIT_RANGE(__range_));
	}


	public:
	static ProcessType splice(
		NodePointer _position,
		NodePointer _begin,
		NodePointer _end
	) DD_NOEXCEPT {

	}


	public:
	static ProcessType transfer(Iterator const& _position, Iterator const& _new_node) DD_NOEXCEPT_AS(_transfer(_position.get_node() DD_COMMA _new_node.get_node())) {
		_transfer(_position.get_node(), _new_node.get_node());
	}

	private:
	static ProcessType _transfer(NodePointer _position, NodePointer _node) DD_NOEXCEPT_AS {
		_delink(_node);
		_enlink(_position, _node);
	}


#	if __cplusplus >= 201103L
	public:
	template <typename _ValueT_>
	static Iterator insert(Iterator const& _position, _ValueT_&& __value_) {
		return Iterator(_insert(_position.get_node(), forward<_ValueT_>(__value_)));
	}

	private:
	template <typename _ValueT_>
	static ProcessType _insert(NodePointer _position, _ValueT_&& __value_) {
		NodePointer _new_node = _create_node(forward<_ValueT_>(__value_));
		_enlink(_position, _new_node);
		return _new_node;
	}
#	else
	public:
	template <typename _ValueT_>
	static Iterator insert(Iterator const& _position, _ValueT_ const& __value_) {
		return Iterator(_insert(_position.get_node(), __value_));
	}

	private:
	template <typename _ValueT_>
	static NodePointer _insert(NodePointer _position, _ValueT_ const& __value_);
		NodePointer _new_node = _create_node(__value_);
		_enlink(_position, _new_node);
		return _new_node;
	}
#	endif


	private:
	static ProcessType _enlink(NodePointer _position, NodePointer _new_node) DD_NOEXCEPT {
		_new_node->previous = _position->previous;
		_new_node->previous->next = _new_node;
		_new_node->next = _position;
		_position->previous = _new_node;
	}

	private:
	static ProcessType _delink(NodePointer _node) {
		_node->previous->next = _node->next;
		_node->next->previous = _node->previous;
	}


	public:
	static Iterator erase(Iterator const& _position) DD_NOEXCEPT_AS(Iterator(_erase(_position.get_node()))) {
		return Iterator(_erase(_position.get_node()));
	}

	public:
	static NodePointer _erase(NodePointer _position) DD_NOEXCEPT {
		_position = _position->next;
		_delink(_position->previous);
		_destroy_node(_position);
		return _position;
	}


	public:
	static Iterator erase_range(
		Iterator _begin,
		Iterator const& _end
	) DD_NOEXCEPT_AS(Iterator(_erase_range(_begin.get_node() DD_COMMA _end.get_node()))) {
		return Iterator(_erase_range(_begin.get_node(), _end.get_node()));
	}

	private:
	static NodePointer _erase_range(
		NodePointer _begin,
		NodePointer _end
	) DD_NOEXCEPT_AS(erase(_begin)) {
		_begin->previous->next = _end->next;
		_end->next->previous = _begin->previous;
		for (; _begin != _end; _begin = _begin->next) {
			_destroy_node(_begin)
		}
		return _begin;
	}


	public:
	ProcessType clear() DD_NOEXCEPT {
		erase_range(begin(), end());
	}


	private:
	template <typename _ValueT_>
#	if __cplusplus >= 201103L
	static NodePointer _creat_node(_ValueT_&& __value_) {
		NodePointer _new_node = Allocator::Basic::allocate(sizeof(Node));
		Allocator::construct(_new_node->value, forward<_ValueT_>(__value_));
		return _new_node;
	}
#	else
	static NodePointer _creat_node(_ValueT_ const& __value_) {
		NodePointer _new_node = Allocator::Basic::allocate(sizeof(Node));
		Allocator::construct(_new_node->value, __value_);
		return _new_node;
	}
#	endif


	private:
	template <typename _PointerT_>
	static ProcessType _destroy_node(_PointerT_ const& _node) DD_NOEXCEPT {
		Allocator::destruct(_node->value);
		Allocator::Basic::deallocate(address_of(*_node), sizeof(Node));
	}


	private:
	ProcessType _destruct() DD_NOEXCEPT {
		for (Iterator _current = begin(); _current++ != end(); ) {
			_destroy_node(_current.get_node()->previous);
		}
	}


	public:
	ThisType& operator =(ThisType const& _origin) DD_NOEXCEPT {
		clone(_origin);
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& _origin) DD_NOEXCEPT {
		swap(_origin);
	}


#	endif
	public:
	template <typename _ValueT_>
#	if __cplusplus >= 201103L
	ThisType& operator <<(_ValueT_&& __value_) DD_NOEXCEPT_AS(push_back(forward<_ValueT_>(__value))) {
		push_back(forward<_ValueT_>(__value));
		return *this;
	}
#	else
	ThisType& operator <<(_ValueT_ const& __value_) DD_NOEXCEPT_AS(push_back(__value)) {
		push_back(__value);
		return *this;
	}
#	endif


};



DD_DETAIL_END



DD_BEGIN



DD_END



#endif
