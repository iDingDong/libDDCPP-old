//	standard/bits/DD_List.hpp
#ifndef DD_LIST_HPP_
#	define DD_LIST_HPP_ 1



#	include "DD_IteratorNested.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_address_of.hpp"
#	include "DD_next.hpp"
#	include "DD_Range.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_InitializerList.hpp"
#	include "DD_ListNode.hpp"
#	include "DD_ListIterator.hpp"
#	include "DD_length_difference.hpp"



DD_DETAIL_BEGIN_
template <>
struct List_<void> {
	public:
	DD_ALIAS(ThisType, List_<void>);
	DD_ALIAS(ValueType, void);

	public:
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
	DD_ALIAS(NodeType, EmptyNode);
	DD_ALIAS(NodeConstType, NodeType const);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodeConstReferenceType, NodeConstType&);
	DD_ALIAS(NodePointerType, NodeType*);
	DD_ALIAS(NodeConstPointerType, NodeConstType*);


	public:
	DD_ALIAS(Iterator, ListIterator<void>);
	DD_ALIAS(ConstIterator, ListIterator<void>);
	DD_ITERATOR_NESTED


	private:
	NodeType m_sentry_;


	public:
	DD_CONSTEXPR List_() DD_NOEXCEPT : m_sentry_{ ::DD::address_of(m_sentry_), ::DD::address_of(m_sentry_) } {
	}

	public:
	DD_DELETE_COPY_CONSTRUCTOR(List_)

	public:
	DD_DELETE_MOVE_CONSTRUCTOR(List_)


	protected:
	Iterator sentry_() DD_NOEXCEPT {
		return Iterator(m_sentry_);
	}

	protected:
	ConstIterator DD_CONSTEXPR sentry_() const DD_NOEXCEPT {
		return Iterator(m_sentry_);
	}


	public:
	Iterator DD_CONSTEXPR begin() DD_NOEXCEPT {
		return ::DD::next(sentry_());
	}

	public:
	ConstIterator DD_CONSTEXPR begin() const DD_NOEXCEPT {
		return ::DD::next(sentry_());
	}


	public:
	Iterator DD_CONSTEXPR end() DD_NOEXCEPT {
		return sentry_();
	}

	public:
	ConstIterator DD_CONSTEXPR end() const DD_NOEXCEPT {
		return sentry_();
	}


	public:
	DD_RANGE_NESTED


	public:
	ReverseIterator DD_CONSTEXPR rbegin() DD_NOEXCEPT {
		return ReverseIterator(::DD::previous(sentry_()));
	}

	public:
	ConstReverseIterator DD_CONSTEXPR rbegin() const DD_NOEXCEPT {
		return ConstReverseIterator(::DD::previous(sentry_()));
	}


	public:
	ReverseIterator DD_CONSTEXPR rend() DD_NOEXCEPT {
		return ReverseIterator(sentry_());
	}

	public:
	ConstReverseIterator DD_CONSTEXPR rend() const DD_NOEXCEPT {
		return ConstReverseIterator(sentry_());
	}


	public:
	DD_REVERSE_RANGE_NESTED


	public:
	DD_DELETE_ALL_ASSIGNMENTS(List_)


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::List;



DD_END_



#endif
