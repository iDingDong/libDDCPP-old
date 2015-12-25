//	DDCPP/standard/bits/UndirectionalListIterator.hpp
#ifndef DD_UNDIRECTIONAL_ITERATOR_HPP_INCLUDED_
#	define DD_UNDIRECTIONAL_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_SpecificTypeNested.hpp"
#	include "DD_IteratorCatagory.hpp"
#	include "DD_EqualityComparable.hpp"
#	include "DD_fabricate.hpp"
#	include "DD_address_of.hpp"
#	include "DD_UndirectionalListNode.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct UndirectionalListIterator;



template <>
#	if __cplusplus >= 201103L
struct UndirectionalListIterator<void> : EqualityComparable<UndirectionalListIterator<void>> {
#	else
struct UndirectionalListIterator<void> : EqualityComparable<UndirectionalListIterator<void> > {
#	endif
	public:
	DD_ALIAS(ThisType, UndirectionalListIterator<void>);
	DD_ALIAS(ValueType, void);

	public:
	DD_ALIAS(ValueConstType, void);
	DD_ALIAS(ReferenceType, void);
	DD_ALIAS(ConstReferenceType, void);
	DD_ALIAS(PointerType, void);
	DD_ALIAS(ConstPointerType, void);

	public:
	DD_SPECIFIC_TYPE_NESTED(Node, UndirectionalListNode<ValueType>)

	public:
	DD_ALIAS(CatagoryType, UndirectionalIterator);


	private:
	NodePointerType m_pointer_ DD_IN_CLASS_INITIALIZE(NodePointerType());


#	if __cplusplus >= 201103L
	public:
	constexpr UndirectionalListIterator() = default;

	public:
	constexpr UndirectionalListIterator(ThisType const& origin_) = default;

	public:
	constexpr UndirectionalListIterator(ThisType&& origin_) = default;
#	else
	public:
	UndirectionalListIterator() throw() : m_pointer_() {
	};
#	endif

	public:
	DD_CONSTEXPR UndirectionalListIterator(NodePointerType pointer_) DD_NOEXCEPT : m_pointer_(pointer_) {
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


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const noexcept {
		return is_valid();
	}


#	endif
};



template <typename ValueT_>
#	if __cplusplus >= 201103L
struct UndirectionalListIterator : UndirectionalListIterator<void>, EqualityComparable<UndirectionalListIterator<ValueT_>> {
#	else
struct UndirectionalListIterator : UndirectionalListIterator<void>, EqualityComparable<UndirectionalListIterator<ValueT_> > {
#	endif
	public:
	DD_ALIAS(SuperType, UndirectionalListIterator<void>);
	DD_ALIAS(ThisType, UndirectionalListIterator<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_SPECIFIC_TYPE_NESTED(Node, ListNode<ValueType>)


#	if __cplusplus >= 201103L
	public:
	constexpr UndirectionalListIterator() = default;

	public:
	constexpr UndirectionalListIterator(ThisType const& origin_) = default;

	public:
	constexpr UndirectionalListIterator(ThisType&& origin_) = default;
#	else
	public:
	UndirectionalListIterator() throw() {
	}
#	endif

	public:
	explicit DD_CONSTEXPR UndirectionalListIterator(SuperType origin_) : SuperType(origin_) {
	}

	public:
	DD_CONSTEXPR UndirectionalListIterator(NodePointerType pointer_) DD_NOEXCEPT : SuperType(pointer_) {
	}


#	if __cplusplus >= 201103L
	public:
	~UndirectionalListIterator() = default;


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
inline ProcessType link_undirectional_list_(
	UndirectionalListIterator<ValueT_> iterator_1_,
	UndirectionalListIterator<ValueT_> iterator_2_
) DD_NOEXCEPT {
	::DD::detail_::link_undirectional_list_node_(iterator_1_.get_node_pointer(), interator_2_.get_node_pointer());
}


template <typename ValueT_>
inline ProcessType enlink_after_undirectional_list_(
	UndirectionalListIterator<ValueT_> position_,
	UndirectionalListIterator<ValueT_> node_
) DD_NOEXCEPT {
	::DD::detail_::enlink_after_undirectional_list_node_(position_.get_node_pointer(), node_.get_node_pointer());
}

template <typename ValueT_>
inline ProcessType enlink_after_undirectional_list_(
	UndirectionalListIterator<ValueT_> position_,
	UndirectionalListIterator<ValueT_> first_,
	UndirectionalListIterator<ValueT_> last_
) DD_NOEXCEPT {
	::DD::detail_::enlink_after_undirectional_list_node_(
		position_.get_node_pointer(),
		first_.get_node_pointer(),
		last_.get_node_pointer()
	);
}


template <typename ValueT_>
inline ProcessType delink_after_undirectional_list_(UndirectionalListIterator<ValueT_> position_) DD_NOEXCEPT {
	::DD::detail_::delink_after_undirectional_list_node_(position_.get_node_pointer());
}


template <typename ValueT_>
inline ProcessType delink_between_undirectional_list_(
	UndirectionalListIterator<ValueT_> head_,
	UndirectionalListIterator<ValueT_> tail_
) DD_NOEXCEPT {
	::DD::detail_::delink_between_undirectional_list_node_(position_.get_node_pointer());
}


template <typename ValueT_>
inline transfer_after_undirectional_list_(
	UndirectionalListIterator<ValueT_> from_after_,
	UndirectionalListIterator<ValueT_> to_after_
) DD_NOEXCEPT {
	::DD::detail_::transfer_after_undirectional_list_node_(from_after_.get_node_pointer(), to_after_.get_node_pointer());
}


template <typename ValueT_>
inline ProcessType splice_after_undirectional_list_(
	UndirectionalListIterator<ValueT_> position_,
	UndirectionalListIterator<ValueT_> head_,
	UndirectionalListIterator<ValueT_> tail_
) DD_NOEXCEPT {
	::DD::detail_::splice_after_undirectional_list_node_(
		position_.get_node_pointer(),
		head_.get_node_pointer(),
		tail_.get_node_pointer()
	);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::UndirectionalListIterator;



DD_END_



#endif
