//	DDCPP/standard/bits/DD_ListIterator.hpp
#ifndef DD_LIST_ITERATOR_HPP_INCLUDED_
#	define DD_LIST_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_address_of.hpp"
#	include "DD_IteratorCatagory.hpp"
#	include "DD_ListIterator.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct ListIterator;



template <>
struct ListIterator<void> {
	public:
	DD_ALIAS(ThisType, ListIterator<NodeT_>);
	DD_ALIAS(ValueType, void);
	DD_ALIAS(ValueConstType, void);
	DD_ALIAS(ReferenceType, void);
	DD_ALIAS(ConstReferenceType, void);
	DD_ALIAS(PointerType, void);
	DD_ALIAS(ConstPointerType, void);

	public:
	DD_ALIAS(NodeType, ListNode<void>);
	DD_ALIAS(NodeConstType, NodeType const);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodeConstReferenceType, NodeConstType&);
	DD_ALIAS(NodePointerType, NodeType*);
	DD_ALIAS(NodeConstPointerType, NodeConstType*);

	public:
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
	ValidityType DD_CONSTEXP is_valid() const DD_NOEXCEPT {
		return m_pointer_;
	}


	protected:
	ProcessType swap_target(ThisType const& other_) const DD_NOEXCEPT {
		DD_ASSERT(m_pointer_ && other_.m_pointer, "'DD::ListIterator::swap_target': Invalid argument");
		NodePointerType temp_ = m_pointer_->previous;
		if (temp_) {
			temp_->next = other_.m_pointer_;
		}
		temp_ = m_pointer_->next;
		if (temp_) {
			temp_->previous = other_.m_pointer_;
		}
		temp_ = other_.m_pointer_->previous;
		other_.m_pointer_->previous = m_pointer_->previous;
		m_pointer_->previous = temp_;
		if (temp_) {
			temp_->next = m_pointer_;
		}
		temp_ = other_.m_pointer_->next;
		other_.m_pointer_->next = m_pointer_->next;
		m_pointer_->next = temp_;
		if (temp_) {
			temp_->previous = m_pointer_;
		}
	}


#	if __cplusplus >= 201103L
	protected:
	ThisType& operator =(ThisType const& origin_) = default;

	protected:
	ThisType& operator =(ThisType&& origin_) = default;
#	else
	protected:
	ThisType& operator =(ThisType const& origin_) throw() {
		m_pointer_ = origin_.m_pointer;
		return *this;
	}
#	endif


	public:
	ThisType& operator ++() DD_NOEXCEPT {
		this->m_pointer_ = this->m_pointer_->next;
		return *this;
	}

	public:
	ThisType operator ++(int) DD_NOEXCEPT {
		ThisType result_(*this);
		++*this;
		return result_;
	}


	public:
	ThisType& operator --() DD_NOEXCEPT {
		this->m_pointer_ = this->m_pointer_->previous;
		return *this;
	}

	public:
	ThisType operator --(int) DD_NOEXCEPT {
		ThisType result_(*this);
		--*this;
		return result_;
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const noexcept {
		return is_valid();
	}


#	endif
};




template <typename ValueT_>
struct ListIterator : ListIterator<void> {
	public:
	DD_ALIAS(SuperType, ListIterator<void>);
	DD_ALIAS(ThisType, ListIterator<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(NodeType, ListNode<ValueT_>);
	DD_ALIAS(NodeConstType, NodeType const);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodeConstReferenceType, NodeConstType&);
	DD_ALIAS(NodePointerType, NodeType*);
	DD_ALIAS(NodeConstPointerType, NodeConstType*);


#	if __cplusplus >= 201103L
	public:
	constexpr ListIterator() = default;

	public:
	constexpr ListIterator(ThisType const& origin_) = default;

	public:
	constexpr ListIterator(ThisType&& origin_) = default;
#	else
	public:
	ListIterator() throw() {
	}
#	endif

	public:
	DD_CONSTEXPR ListIterator(NodePointerType pointer_) DD_NOEXCEPT : SuperType(pointer_) {
	}


#	if __cplusplus >= 201103L
	public:
	~ListIterator() = default;


#	endif
	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return m_pointer_;
	}


	public:
	ProcessType swap_target(ThisType const& other_) const DD_NOEXCEPT {
		return static_cast<SuperType const&>(*this).swap_target(other_);
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;
#	else
	public:
	ThisType& operator =(ThisType const& origin_) throw() {
		static_cast<SuperType&>(*this) = origin_;
	}
#	endif

	public:
	ReferenceType DD_CONSTEXPR operator *() const DD_NOEXCEPT {
		return get_pointer()->value;
	}


	public:
	PointerType DD_CONSTEXPR operator ->() const DD_NOEXCEPT {
		return ::DD::address_of(**this);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::ListIterator;



DD_END_



#endif
