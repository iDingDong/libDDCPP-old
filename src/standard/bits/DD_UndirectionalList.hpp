//	DDCPP/standard/bits/DD_UndirectionalList.hpp
#ifndef DD_UNDIRECTIONAL_LIST_HPP_INCLUDED_
#	define DD_UNDIRECTIONAL_LIST_HPP_INCLUDED_ 1



#	include "DD_Allocator.hpp"
#	include "DD_UndirectionalListIterator.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct UndirectionalList_;



template <>
struct UndirectionalList_<void> {
	protected:
	DD_ALIAS(ThisType, UndirectionalList_<void>);
	DD_ALIAS(ValueType, void);

	protected:
	DD_ALIAS(ValueConstType, void);
	DD_ALIAS(ReferenceType, void);
	DD_ALIAS(ConstReferenceType, void);
	DD_ALIAS(PointerType, void);
	DD_ALIAS(ConstPointerType, void);

	protected:
	DD_ALIAS(Iterator, UndirectionalListIterator<void>);
	DD_ALIAS(ConstIterator, UndirectionalListIterator<void>);
	DD_ITERATOR_NESTED

	protected:
	DD_SPECIFIC_TYPE_NESTED(Node, UndirectionalListNode<ValueType>);


	protected:
	NodeType m_sentry_;


	protected:
	DD_CONSTEXPR UndirectionalList_() DD_NOEXCEPT : m_sentry_{ ::DD::address_of(m_sentry_) } {
	}

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(UndirectionalList_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(UndirectionalList_)


	protected:
	UndirectionalList_(UnguardedTag tag_) DD_NOEXCEPT {
	}


	protected:
	Iterator sentry_() DD_NOEXCEPT {
		return Iterator(::DD::address_of(m_sentry_));
	}

	protected:
	ConstIterator DD_UNCONSTRIANED_CONSTEXPR sentry_() const DD_NOEXCEPT {
		return ConstIterator(const_cast<NodePointerType>(::DD::address_of(m_sentry_)));
	}


	protected:
	Iterator begin() DD_NOEXCEPT {
		return ::DD::next(sentry_());
	}

	protected:
	ConstIterator DD_UNCONSTRIANED_CONSTEXPR begin() const DD_NOEXCEPT {
		return ::DD::next(sentry_());
	}


	protected:
	Iterator end() DD_NOEXCEPT {
		return sentry_();
	}

	protected:
	ConstIterator DD_UNCONSTRIANED_CONSTEXPR end() const DD_NOEXCEPT {
		return sentry_();
	}


	public:
	LengthType get_length() const DD_NOEXCEPT {
		return ::DD::length_difference(begin(), end());
	}


	public:
	ValidityType DD_CONSTEXPR is_empty() const DD_NOEXCEPT {
		return begin() == end();
	}


	public:
	ValidityType check_length(LengthType maximum_) {
		LengthType result_ = LengthType();
		for (Iterator current_ = begin(); result_ < maximum_ && current_ != end(); ++current_) {
			++result_;
		}
		return result_;
	}


	protected:
	ProcessType reset_() DD_NOEXCEPT {
		link_(sentry_(), sentry_());
	}


	protected:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		::DD::swap(m_sentry_, other_.m_sentry_);
		Iterator current_(sentry_())
		while (::DD::next(current_) != other_.sentry_()) {
			++current_;
		}
		link_(current_++, sentry_());
		while (::DD::next(current_) != sentry_()) {
			++current_;
		}
		link_(current_, other_.sentry_());
	}


	protected:
	static ProcessType link_(Iterator iterator_1_, Iterator iterator_2_) DD_NOEXCEPT {
		::DD::detail_::link_list_(iterator_1_, iterator_2_);
	}


	protected:
	static Iterator enlink_after_(Iterator position_, Iterator node_) DD_NOEXCEPT {
		::DD::detail_::enlink_after_undirectional_list_(position_, node_);
		return node_;
	}

	protected:
	static ProcessType enlink_after_(Iterator position_, Iterator first_, Iterator last_) DD_NOEXCEPT {
		::DD::detail_::enlink_after_undirectional_list_(position_, first_, last_);
	}


	protected:
	static ProcessType delink_after(Iterator position_) DD_NOEXCEPT {
		::DD::detail_::delink_after_undirectional_list_(position_);
	}

	protected:
	static ProcessType delink_between_(Iterator head_, Iterator tail_) DD_NOEXCEPT {
		::DD::detail_::delink_between_undirectional_list_node_(first_, last_);
	}


	protected:
	static ProcessType unguarded_splice_after(Iterator position_, Iterator head_, Iterator last_) DD_NOEXCEPT {
		::DD::detail_::splice_list_(position_, head_, last_);
	}


	protected:
	static ProcessType splice_after(Iterator position_, Iterator head_, Iterator last_) DD_NOEXCEPT {
		if (head_ != last_) {
			unguarded_splice(position_, head_, last_);
		}
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(UndirectionalList_)


};



template <typename ValueT_>
struct UndirectionalList_ : UndirectionalList_<void> {
	protected:
	DD_ALIAS(SuperType, UndirectionalList_<void>);
	DD_ALIAS(ThisType, UndirectionalList_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	protected:
	DD_SPECIFIC_TYPE_NESTED(Node, ListNode<ValueType>);


	protected:
	DD_INHERIT_ALIAS(SizeType);
	DD_INHERIT_ALIAS(LengthType);


	protected:
	DD_ALIAS(Iterator, ListIterator<ValueType>);
	DD_ALIAS(ConstIterator, ListIterator<ValueConstType>);
	DD_ITERATOR_NESTED


	protected:
#	if __cplusplus >= 201103L
	constexpr UndirectionalList_() = default;
#	else
	UndirectionalList_() throw() {
	}
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(UndirectionalList_);

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(UndirectionalList_);

	protected:
	DD_CONSTEXPR UndirectionalList_(UnguardedTag tag_) DD_NOEXCEPT : SuperType(tag_) {
	}


	protected:
	Iterator DD_CONSTEXPR begin() DD_NOEXCEPT {
		return Iterator(SuperType::begin());
	}

	protected:
	ConstIterator DD_CONSTEXPR begin() const DD_NOEXCEPT {
		return ConstIterator(SuperType::begin());
	}


	protected:
	Iterator DD_CONSTEXPR end() DD_NOEXCEPT {
		return Iterator(SuperType::end());
	}

	protected:
	ConstIterator DD_CONSTEXPR end() const DD_NOEXCEPT {
		return ConstIterator(SuperType::end());
	}


	protected:
	DD_RANGE_NESTED


	protected:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		SuperType::swap(other_);
	}


	protected:
	static ProcessType unguarded_splice_after(Iterator position_, Iterator head_, Iterator last_) DD_NOEXCEPT {
		SuperType::unguarded_splice_after(position_, head_, last_);
	}


	protected:
	static ProcessType splice_after(Iterator position_, Iterator head_, Iterator last_) DD_NOEXCEPT {
		SuperType::splice_after(position_, head_, last_);
	}

	protected:
	DD_DELETE_ALL_ASSIGNMENTS(UndirectionalList_);


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
