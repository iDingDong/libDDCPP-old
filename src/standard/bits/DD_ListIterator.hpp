//	DDCPP/standard/bits/DD_ListIterator.hpp
#ifndef DD_LIST_ITERATOR_HPP_INCLUDED_
#	define DD_LIST_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_SpecificTypeNested.hpp"
#	include "DD_IteratorCatagory.hpp"
#	include "DD_EqualityComparable.hpp"
#	include "DD_fabricate.hpp"
#	include "DD_address_of.hpp"
#	include "DD_previous.hpp"
#	include "DD_ListNode.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct ListIterator;



template <>
#	if __cplusplus >= 201103L
struct ListIterator<void> : EqualityComparable<ListIterator<void>> {
#	else
struct ListIterator<void> : EqualityComparable<ListIterator<void> > {
#	endif
	public:
	DD_ALIAS(ThisType, ListIterator<void>);
	DD_ALIAS(ValueType, void);

	public:
	DD_ALIAS(ValueConstType, void);
	DD_ALIAS(ReferenceType, void);
	DD_ALIAS(ConstReferenceType, void);
	DD_ALIAS(PointerType, void);
	DD_ALIAS(ConstPointerType, void);

	public:
	DD_SPECIFIC_TYPE_NESTED(Node, ListNode<ValueType>)

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
	NodePointerType DD_CONSTEXPR get_node_pointer() const DD_NOEXCEPT {
		return m_pointer_;
	}


	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT {
		return get_node_pointer();
	}


	public:
	ValidityType DD_CONSTEXPR equal(ThisType const& other_) const DD_NOEXCEPT {
		return get_node_pointer() == other_.get_node_pointer();
	}


	public:
	ProcessType swap_target(ThisType const& other_) const DD_NOEXCEPT {
		DD_ASSERT(is_valid() && other_.is_valid(), "'DD::ListIterator::swap_target': Invalid iterator dereferenced");
		::DD::detail_::swap_list_node_(get_node_pointer(), other_.get_node_pointer());
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
	public:
	ThisType& operator ++() DD_NOEXCEPT {
		m_pointer_ = m_pointer_->next;
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
		m_pointer_ = m_pointer_->previous;
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
#	if __cplusplus >= 201103L
struct ListIterator : ListIterator<void>, EqualityComparable<ListIterator<ValueT_>> {
#	else
struct ListIterator : ListIterator<void>, EqualityComparable<ListIterator<ValueT_> > {
#	endif
	public:
	DD_ALIAS(SuperType, ListIterator<void>);
	DD_ALIAS(ThisType, ListIterator<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_SPECIFIC_TYPE_NESTED(Node, ListNode<ValueType>)


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
	explicit DD_CONSTEXPR ListIterator(SuperType origin_) : SuperType(origin_) {
	}

	public:
	DD_CONSTEXPR ListIterator(NodePointerType pointer_) DD_NOEXCEPT : SuperType(pointer_) {
	}


#	if __cplusplus >= 201103L
	public:
	~ListIterator() = default;


#	endif
	public:
	NodePointerType DD_CONSTEXPR get_node_pointer() const DD_NOEXCEPT_AS(
		static_cast<NodePointerType>(::DD::fabricate<ThisType const>().SuperType::get_node_pointer())
	) {
		return static_cast<NodePointerType>(SuperType::get_node_pointer());
	}


	public:
	PointerType DD_CONSTEXPR unguarded_get_pointer() const DD_NOEXCEPT_AS(
		static_cast<PointerType>(::DD::address_of(::DD::fabricate<ThisType const>().get_node_pointer()->value))
	) {
		return ::DD::address_of(get_node_pointer()->value);
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT_AS(static_cast<PointerType>(
		::DD::fabricate<ThisType const>().is_valid() ? ::DD::fabricate<ThisType const>().unguarded_get_pointer() : PointerType()
	)) {
		return is_valid() ? unguarded_get_pointer() : PointerType();
	}


	public:
	ValidityType DD_CONSTEXPR equal(ThisType const& other_) const DD_NOEXCEPT {
		return SuperType::equal(other_);
	}


	public:
	ValidityType DD_CONSTEXPR is_valid() const DD_NOEXCEPT {
		return SuperType::is_valid();
	}


	public:
	ProcessType swap_target(ThisType const& other_) const DD_NOEXCEPT {
		return SuperType::swap_target(other_);
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
	ThisType& operator ++() DD_NOEXCEPT {
		++static_cast<SuperType&>(*this);
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
		--static_cast<SuperType&>(*this);
		return *this;
	}

	public:
	ThisType operator --(int) DD_NOEXCEPT {
		ThisType result_(*this);
		--*this;
		return result_;
	}


	public:
	ReferenceType DD_CONSTEXPR operator *() const DD_NOEXCEPT {
		return *unguarded_get_pointer();
	}


	public:
	PointerType DD_CONSTEXPR operator ->() const DD_NOEXCEPT {
		return get_pointer();
	}


};



template <typename ValueT_>
inline ProcessType link_list_node_(ListIterator<ValueT_> iterator_1_, ListIterator<ValueT_> iterator_2_) DD_NOEXCEPT {
	::DD::detail_::link_list_node_(iterator_1_.get_node_pointer(), iterator_2_.get_node_pointer());
}


template <typename ValueT_>
inline ProcessType enlink_list_node_(ListIterator<ValueT_> position_, ListIterator<ValueT_> new_node_) DD_NOEXCEPT {
	::DD::detail_::enlink_list_node_(position_.get_node_pointer(), new_node_.get_node_pointer());
}

template <typename ValueT_>
inline ProcessType enlink_list_node_(ListIterator<ValueT_> position_, ListIterator<ValueT_> first_, ListIterator<ValueT_> last_) DD_NOEXCEPT {
	::DD::detail_::enlink_list_node_(position_.get_node_pointer(), first_.get_node_pointer(), last_.get_node_pointer());
}


template <typename ValueT_>
inline ProcessType delink_list_node_(ListIterator<ValueT_> node_) DD_NOEXCEPT {
	::DD::detail_::delink_list_node_(node_.get_node_pointer());
}

template <typename ValueT_>
inline ProcessType delink_list_node_(ListIterator<ValueT_> first_, ListIterator<ValueT_> last_) DD_NOEXCEPT {
	::DD::detail_::delink_list_node_(first_.get_node_pointer(), last_.get_node_pointer());
}


template <typename ValueT_>
inline ProcessType unguarded_splice_list_node_(
	ListIterator<ValueT_> position_,
	ListIterator<ValueT_> begin_,
	ListIterator<ValueT_> end_
) DD_NOEXCEPT {
	::DD::detail_::splice_list_node_(position_.get_node_pointer(), begin_.get_node_pointer(), ::DD::previous(end_).get_node_pointer());
}


template <typename ValueT_>
inline ProcessType splice_list_node_(ListIterator<ValueT_> position_, ListIterator<ValueT_> begin_, ListIterator<ValueT_> end_) DD_NOEXCEPT {
	if (begin_ != end_) {
		unguarded_splice_list_node_(position_, begin_, end_);
	}
}


template <typename ValueT_>
inline ListIterator<ValueT_> move_range(
	ListIterator<ValueT_> begin_,
	ListIterator<ValueT_> end_,
	ListIterator<ValueT_> result_begin_
) DD_NOEXCEPT_IF(noexcept(begin_ != end_) && noexcept((++begin_).swap_target(++result_begin_))) {
	for (; begin_ != end_; ++begin_, ++result_begin_) {
		begin_.swap_target(result_begin_);
	}
	return result_begin_;
}


template <typename ValueT_>
#	if __cplusplus >= 201103L
inline Pair<ListIterator<ValueT_>> move_range(
#	else
inline Pair<ListIterator<ValueT_> > move_range(
#	endif
	ListIterator<ValueT_> begin_,
	ListIterator<ValueT_> end_,
	ListIterator<ValueT_> result_begin_,
	ListIterator<ValueT_> result_end_
) DD_NOEXCEPT_IF(noexcept(begin_ != end_) && noexcept(result_begin_ != result_end_) && noexcept((++begin_).swap_target(++result_begin_))) {
	for (; begin_ != end_ && result_begin_ != result_end_; ++begin_, ++result_begin_) {
		begin_.swap_target(result_begin_);
	}
#	if __cplusplus >= 201103L
	return Pair<ListIterator<ValueT_>>(begin_, result_begin_);
#	else
	return Pair<ListIterator<ValueT_> >(begin_, result_begin_);
#	endif
}


template <typename ValueT_>
inline ProcessType transfer(
	ListIterator<ValueT_> from_,
	ListIterator<ValueT_> to_
) DD_NOEXCEPT_AS(::DD::detail_::transfer_list_node_(from_.get_node_pointer() DD_COMMA to_.get_node_pointer())) {
	::DD::detail_::transfer_list_node_(from_.get_node_pointer(), to_.get_node_pointer());
}


template <typename ValueT_>
inline ProcessType transfer_forward(
	ListIterator<ValueT_> from_,
	ListIterator<ValueT_> to_
) DD_NOEXCEPT_AS(::DD::detail_::transfer(from_ DD_COMMA to_)) {
	::DD::detail_::transfer(from_, to_);
}


template <typename ValueT_>
inline ProcessType transfer_backward(
	ListIterator<ValueT_> from_,
	ListIterator<ValueT_> to_
) DD_NOEXCEPT_AS(::DD::detail_::transfer(from_ DD_COMMA to_)) {
	::DD::detail_::transfer(from_, to_);
}


template <typename ValueT_>
ProcessType inplace_merge(
	ListIterator<ValueT_> begin_,
	ListIterator<ValueT_> middle_,
	ListIterator<ValueT_> end_
) {
	while (middle_ != end_ && begin_ != middle_) {
		if (*middle_ < *begin_) {
			::DD::detail_::transfer(middle_++, begin_);
		} else {
			++begin_;
		}
	}
}

template <typename ValueT_, typename BinaryPredicateT_>
ProcessType inplace_merge(
	ListIterator<ValueT_> begin_,
	ListIterator<ValueT_> middle_,
	ListIterator<ValueT_> end_,
	BinaryPredicateT_ less__
) {
	while (middle_ != end_ && begin_ != middle_) {
		if (less__(*middle_, *begin_)) {
			::DD::detail_::transfer(middle_++, begin_);
		} else {
			++begin_;
		}
	}
}


template <typename ValueT_>
inline ValidityType DD_CONSTEXPR operator ==(
	ListIterator<ValueT_> const& iterator_1_,
	ListIterator<ValueT_> const& iterator_2_
) DD_NOEXCEPT_AS(static_cast<ValidityType>(iterator_1_.equal(iterator_2_))) {
	return iterator_1_.equal(iterator_2_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::ListIterator;

using detail_::move_range;
using detail_::transfer;
using detail_::inplace_merge;



DD_END_



#endif
