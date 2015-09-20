//	DDCPP/standard/bits/DD_ListIterator.hpp
#ifndef _DD_LIST_ITERATOR_HPP_INCLUDED
#	define _DD_LIST_ITERATOR_HPP_INCLUDED 1



#	include "DD_address_of.hpp"
#	include "DD_iterator_definitions.hpp"
#	include "DD_IteratorCatagory.hpp"



DD_BEGIN
template <typename _NodeT>
struct ListIterator {
	public:
	DD_ALIAS(ThisType, ListIterator<_NodeT>)
	DD_ALIAS(NodeType, _NodeT)

	public:
	DD_ALIAS(NodeConstType, NodeType const)
	DD_ALIAS(NodeReferenceType, NodeType&)
	DD_ALIAS(NodeConstReferenceType, NodeConstType&)
	DD_ALIAS(NodePointerType, NodeType*)
	DD_ALIAS(NodeConstPointerType, NodeConstType*)

	public:
	DD_ALIAS(ValueType, typename NodeType::ValueType)

	public:
	DD_ITERATOR_DECLARATIONS
	DD_ALIAS(CatagoryType, BidirectionalIterator)


	private:
#	if __cplusplus >= 201103L
	NodePointerType _m_pointer = NodePointerType();
#	else
	NodePointerType _m_pointer;
#	endif


#	if __cplusplus >= 201103L
	public:
	constexpr ListIterator() = default;

	public:
	constexpr ListIterator(ThisType const& _origin) = default;

	public:
	constexpr ListIterator(ThisType&& _origin) = default;
#	else
	public:
	ListIterator() throw() : _m_pointer() {
	};
#	endif

	public:
	DD_CONSTEXPR ListIterator(NodePointerType _pointer) DD_NOEXCEPT : _m_pointer(_pointer) {
	}


	public:
	ProcessType swap_target(ThisType& _target) DD_NOEXCEPT {
		//assert(_m_pointer && _target)
		NodePointerType _temp = _m_pointer->previous;
		if (_temp) {
			_temp->next = _target._m_pointer;
		}
		_temp = _m_pointer->next;
		if (_temp) {
			_temp->previous = _target._m_pointer;
		}
		_temp = _target._m_pointer->previous;
		_target._m_pointer->previous = _m_pointer->previous;
		_m_pointer->previous = _temp;
		if (_temp) {
			_temp->next = _m_pointer;
		}
		_temp = _target._m_pointer->next;
		_target._m_pointer->next = _m_pointer->next;
		_m_pointer->next = _temp;
		if (_temp) {
			_temp->previous = _m_pointer;
		}
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return address_of(this->_m_pointer->value);
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& _origin) = default;

	public:
	ThisType& operator =(ThisType&& _origin) = default;


#	endif
	public:
	ThisType& operator ++() DD_NOEXCEPT {
		this->_m_pointer = this->_m_pointer->next;
		return *this;
	}

	public:
	ThisType operator ++(int) DD_NOEXCEPT {
		return ThisType(release(this->_m_pointer, this->m_pointer->next));
	}


	public:
	ThisType& operator --() DD_NOEXCEPT {
		this->_m_pointer = this->_m_pointer->previous;
		return *this;
	}

	public:
	ThisType operator --(int) DD_NOEXCEPT {
		return ThisType(release(this->_m_pointer, this->m_pointer->previous));
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return this->_m_pointer->value;
	}


	public:
	ReferenceType operator ->() const DD_NOEXCEPT {
		return this->get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const noexcept {
		return this->_m_pointer;
	}


#	endif
};



template <typename _NodeT>
inline ProcessType swap_target(ListIterator<_NodeT>& _list_iterator_1, ListIterator<_NodeT>& _list_iterator_2) DD_NOEXCEPT {
	_list_iterator_1.swap_target(_list_iterator_2);
}



DD_END



#endif
