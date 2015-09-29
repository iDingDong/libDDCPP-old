//	DDCPP/standard/bits/DD_ListIterator.hpp
#ifndef DD_LIST_ITERATOR_HPP_INCLUDED_
#	define DD_LIST_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_address_of.hpp"
#	include "DD_iterator_definitions.hpp"
#	include "DD_IteratorCatagory.hpp"



DD_BEGIN_
template <typename NodeT_>
struct ListIterator {
	public:
	DD_ALIAS(ThisType, ListIterator<NodeT_>);
	DD_ALIAS(NodeType, NodeT_);

	public:
	DD_ALIAS(NodeConstType, NodeType const);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodeConstReferenceType, NodeConstType&);
	DD_ALIAS(NodePointerType, NodeType*);
	DD_ALIAS(NodeConstPointerType, NodeConstType*);

	public:
	DD_ALIAS(ValueType, typename NodeType::ValueType);

	public:
	DD_ITERATOR_DECLARATIONS
	DD_ALIAS(CatagoryType, BidirectionalIterator);


	private:
#	if __cplusplus >= 201103L
	NodePointerType m_pointer_ = NodePointerType();
#	else
	NodePointerType m_pointer_;
#	endif


#	if __cplusplus >= 201103L
	public:
	constexpr ListIterator() = default;

	public:
	constexpr ListIterator(ThisType const& origin_) = default;

	public:
	constexpr ListIterator(ThisType&& origin_) = default;
#	else
	public:
	ListIterator() throw() : m_pointer_() {
	};
#	endif

	public:
	DD_CONSTEXPR ListIterator(NodePointerType pointer_) DD_NOEXCEPT : m_pointer_(pointer_) {
	}


	public:
	ProcessType swap_target(ThisType& target_) DD_NOEXCEPT {
		//assert(m_pointer_ && target_)
		NodePointerType temp_ = m_pointer_->previous;
		if (temp_) {
			temp_->next = target_.m_pointer_;
		}
		temp_ = m_pointer_->next;
		if (temp_) {
			temp_->previous = target_.m_pointer_;
		}
		temp_ = target_.m_pointer_->previous;
		target_.m_pointer_->previous = m_pointer_->previous;
		m_pointer_->previous = temp_;
		if (temp_) {
			temp_->next = m_pointer_;
		}
		temp_ = target_.m_pointer_->next;
		target_.m_pointer_->next = m_pointer_->next;
		m_pointer_->next = temp_;
		if (temp_) {
			temp_->previous = m_pointer_;
		}
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return address_of(this->m_pointer_->value);
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
	public:
	ThisType& operator ++() DD_NOEXCEPT {
		this->m_pointer_ = this->m_pointer_->next;
		return *this;
	}

	public:
	ThisType operator ++(int) DD_NOEXCEPT {
		return ThisType(release(this->m_pointer_, this->m_pointer->next));
	}


	public:
	ThisType& operator --() DD_NOEXCEPT {
		this->m_pointer_ = this->m_pointer_->previous;
		return *this;
	}

	public:
	ThisType operator --(int) DD_NOEXCEPT {
		return ThisType(release(this->m_pointer_, this->m_pointer->previous));
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return this->m_pointer_->value;
	}


	public:
	ReferenceType operator ->() const DD_NOEXCEPT {
		return this->get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const noexcept {
		return this->m_pointer_;
	}


#	endif
};



template <typename NodeT_>
inline ProcessType swap_target(ListIterator<NodeT_>& list_iterator_1_, ListIterator<NodeT_>& list_iterator_2_) DD_NOEXCEPT {
	list_iterator_1_.swap_target(list_iterator_2_);
}



DD_END_



#endif
