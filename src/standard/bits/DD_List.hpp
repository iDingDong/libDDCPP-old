//	DDCPP/standard/bits/DD_List.hpp
#ifndef _DD_LIST_HPP_INCLUDED
#	define _DD_LIST_HPP_INCLUDED 1



#	include "DD_CompatStlContainer.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_Allocator.hpp"
#	include "DD_release.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_InitializerList.hpp"
#	include "DD_container_definitions.hpp"
#	include "DD_ListNode.hpp"
#	include "DD_ListIterator.hpp"



_DD_DETAIL_BEGIN
template <typename _ValueT>
struct _ListBase {
	protected:
	DD_ALIAS(ThisType, _ListBase<_ValueT>)
	DD_ALIAS(ValueType, _ValueT)

	protected:
	DD_ALIAS(NodeType, ListNode<ValueType>)
	DD_ALIAS(NodeConstType, NodeType const)
	DD_ALIAS(NodeReferenceType, NodeType&)
	DD_ALIAS(NodeConstReferenceType, NodeConstType&)
	DD_ALIAS(NodePointerType, NodeType*)
	DD_ALIAS(NodeConstPointerType, NodeConstType*)

	protected:
	DD_CONTAINER_DECLARATIONS
	DD_ALIAS(LengthType, DD::LengthType)

	protected:
	DD_ALIAS(Iterator, ListIterator<NodeType>)
	DD_ALIAS(ReverseIterator, DD_MODIFY_TRAIT(IteratorReverse, Iterator));
	DD_ALIAS(ConstIterator, ListIterator<NodeConstType>)
	DD_ALIAS(ConstReverseIterator, DD_MODIFY_TRAIT(IteratorReverse, ConstIterator));


	protected:
#	if __cplusplus >= 201103L
	NodePointerType _m_first = NodePointerType();
	NodePointerType _m_last = NodePointerType();
#	else
	NodePointerType _m_first;
	NodePointerType _m_last;
#	endif


#	if __cplusplus >= 201103L
	public:
	constexpr _ListBase() = default;
#	else
	public:
	_ListBase() throw() : _m_begin(), _m_end();
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(_ListBase)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(_ListBase)

	protected:
	DD_CONSTEXPR _ListBase(NodePointerType _first, NodePointerType _last) DD_NOEXCEPT : _m_first(_first), _m_last(_last) {
	}


	public:
	~_ListBase() DD_NOEXCEPT {
	};


	public:
	Iterator begin() DD_NOEXCEPT {
		return Iterator(_m_first);
	}


	public:
	Iterator end() DD_NOEXCEPT {
		return Iterator();
	}


	public:
	ReverseIterator rbegin() DD_NOEXCEPT {
		return ReverseIterator(_m_last);
	}


	public:
	ReverseIterator rend() DD_NOEXCEPT {
		return ReverseIterator();
	}


	public:
	ConstIterator cbegin() const DD_NOEXCEPT {
		return ConstIterator(_m_first);
	}


	public:
	ConstIterator cend() const DD_NOEXCEPT {
		return ConstIterator();
	}


	public:
	ConstReverseIterator crbegin() const DD_NOEXCEPT {
		return ConstReverseIterator(_m_last);
	}


	public:
	ConstReverseIterator crend() const DD_NOEXCEPT {
		return ConstReverseIterator();
	}


};



_DD_DETAIL_END



_DD_BEGIN
template <typename _ValueT, typename _AllocatorT = Allocator<ListNode>>
struct List : _detail::_ListBase<_ValueT> {
};



template <typename _ValueT, ValidityType _manage_pool_c>
struct List<_ValueT, Allocator<ListNode, _manage_pool_c>> : _detail::_ListBase<_ValueT> {
	public:
	DD_ALIAS(BaseType, _detail::_ListBase<_ValueT>)
	DD_ALIAS(ThisType, List<_ValueT DD_COMMA Allocator<ListNode DD_COMMA _manage_pool_c>>)
	DD_ALIAS(ValueType, _ValueT)
	DD_ALIAS(AllocatorType, Allocator<ListNode DD_COMMA _manage_pool_c>)

	private:
	using BaseType::_m_first;
	using BaseType::_m_last;

	public:
	DD_ALIAS(NodeType, typename BaseType::NodeType)
	DD_ALIAS(NodeConstType, typename BaseType::NodeConstType)
	DD_ALIAS(NodeReferenceType, typename BaseType::NodeReferenceType)
	DD_ALIAS(NodeConstReferenceType, typename BaseType::NodeConstReferenceType)
	DD_ALIAS(NodePointerType, typename BaseType::NodePointerType)
	DD_ALIAS(NodeConstPointerType, typename BaseType::NodeConstPointerType)

	public:
	DD_CONTAINER_DECLARATIONS
	DD_ALIAS(LengthType, DD::LengthType)

	public:
	DD_ALIAS(Iterator, ListIterator<NodeType>)


#	if __cplusplus >= 201103L
	public:
	constexpr List() = default;

	public:
	constexpr List(ThisType&& _origin) noexcept : BaseType(release(_origin._m_first), release(_origin._m_last)) {
	}

	public:
	template <typename... _ArgumentsT_>
	List(LengthType _length, _ArgumentsT_&&... __argumnets_) noexcept(false) {
		throw false;
	}
#	else
	public:
	List() throw() : BaseType() {
	}
#	endif


	public:
	~List() DD_NOEXCEPT {
		_m_last = _m_first->next;
		AllocatorType::destroy()
	}


	public:
	template <typename... _ArgumentsT_>
	ProcessType emplace_front(_ArgumentsT_&&... __arguments_) {
		NodePointerType _temp = _create_node(NodePointerType(), _m_first, forward<_ArgumentsT_>(__arguments_)...);
		if (_m_first) {
			_m_first->previous = _temp;
		}
		_m_first = _temp;
	}


	public:
	template <typename... _ArgumentsT_>
	ProcessType emplace_back(_ArgumentsT_&&... __arguments_) {
		NodePointerType _temp = _create_node(_m_last, NodePointerType(), forward<_ArgumentsT_>(__arguments_)...);
		if (_m_last) {
			_m_last->next = _temp;
		}
		_m_last = _temp;
	}


	private:
	template <typename... _ArgumentsT_>
	NodePointerType _create_node(NodePointerType _previous, NodePointerType _next, _ArgumentsT_&&... __arguments_) {
		NodePointerType _temp = AllocatorType::allocate();
		try {
			AllocatorType::construct(_temp, NodeType{_previous, _next, ValueType(forward<_ArgumentsT_>(__arguments_)...)});
		} catch (...) {
			AllocatorType::deallocate(_temp, 1);
			throw;
		}
		return _temp;
	}


};



_DD_END



#endif
