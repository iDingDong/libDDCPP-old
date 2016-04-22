//	DDCPP/standard/bits/DD_UndirectionalLinkedRing.hpp
#ifndef DD_UNDIRECTIONAL_LINKED_RING_HPP_INCLUDED_
#	ifndef DD_UNDIRECTIONAL_LINKED_RING_HPP_INCLUDED_ 1



#	include "DD_UndirectionalListIterator.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct UndirectionalLinkedRing_;



template <>
struct UndirectionalLinkedRing_<void> {
	protected:
	DD_ALIAS(ThisType, UndirectionalLinkedRing<ValueT_, AllocatorT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	protected:
	DD_ALIAS(Iterator, UndirectionalListIterator<ValueT_>);
	DD_ALIAS(ConstIterator, UndirectionalListIterator<const ValueT_>);

	protected:
	Iterator m_begin_;


#	if __cplusplus >= 201103L
	protected:
	constexpr UndirectionalLinkedRing_() = default;

#	endif
	protected:
	DD_DELETE_COPY_CONSTRUCTOR(UndirectionalLinkedRing_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(UndirectionalLinkedRing_)


	protected:
	Iterator begin() DD_NOEXCEPT {
		return m_begin_;
	}

	protected:
	ConstIterator begin() const DD_NOEXCEPT {
		return m_begin_;
	}


	public:
	ValidityType DD_CONSTEXPR is_nonempty() const DD_NOEXCEPT {
		return begin();
	}


	public:
	ValidityType DD_CONSTEXPR is_empty() const DD_NOEXCEPT {
		return !is_nonempty();
	}


	public:
	LengthType DD_CONSTEXPR count_element() const DD_NOEXCEPT {
		LengthType result = 0U;
		if (is_nonempty()) {
			Iterator begin_(::DD::next(begin()));
			while (begin_ != begin()) {
				++begin_;
				++result_;
			}
			return result_;
		}
		return result;
	}


	protected:
	static ProcessType link_(Iterator iterator_1_, Iterator iterator_2_) DD_NOEXCEPT {
		::DD::detail_::link_undirectional_list_(iterator_1_, iterator_2_);
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
	static ProcessType delink_after_(Iterator position_) DD_NOEXCEPT {
		::DD::detail_::delink_after_undirectional_list_(position_);
	}

	protected:
	static ProcessType delink_between_(Iterator head_, Iterator tail_) DD_NOEXCEPT {
		::DD::detail_::delink_between_undirectional_list_(head_, tail_);
	}


	protected:
	static ProcessType transfer_after(Iterator from_after_, Iterator to_after_) DD_NOEXCEPT {
		::DD::detail_::transfer_after_undirectional_list_(from_after_, to_after_);
	}


	protected:
	static ProcessType unguarded_splice_after(Iterator position_, Iterator head_, Iterator last_) DD_NOEXCEPT {
		::DD::detail_::splice_after_undirectional_list_(position_, head_, last_);
	}


	protected:
	static ProcessType splice_after(Iterator position_, Iterator head_, Iterator last_) DD_NOEXCEPT {
		if (head_ != last_) {
			unguarded_splice_after(position_, head_, last_);
		}
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(UndirectionalLinkedRing_)


};



template <typename ValueT_, typename AllocatorT_>
struct UndirectionalLinkedRing : Allocateable<AllocatorT_>, UndirectionalLinkedRing_<ValueT_> {
	public:
	DD_ALIAS(AllocateAgent, Allocateable<AllocatorT_>);
	DD_ALIAS(SuperType, UndirectionalLinkedRing_<ValueT_>);
	DD_ALIAS(ThisType, UndirectionalLinkedRing<ValueT_, AllocatorT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(AllocatorType, AllocatorT_);


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
