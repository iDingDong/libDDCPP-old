//	DDCPP/standard/bits/DD_Ring.hpp
#ifndef DD_RING_HPP_INCLUDED_
#	define DD_RING_HPP_INCLUDED_ 1



#	include "DD_Tags.hpp"
#	include "DD_IteratorNested.hpp"
#	include "DD_IsTriviallyDestructible.hpp"
#	include "DD_Range.hpp"
#	include "DD_Allocateable.hpp"
#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"
#	include "DD_UniversalFreeAccessIterator.hpp"
#	include "DD_swap.hpp"



DD_DETAIL_BEGIN_
template <ValidityType can_trivially_operate_c_>
struct DestructRing_ {
	template <typename ValueT_>
	ProcessType destruct_ring_(
		ValueT_* storage_begin_,
		ValueT_* begin_,
		ValueT_* storage_end_,
		LengthType length_
	) DD_NOEXCEPT {
		right_offset_ = storage_end_ - begin_;
		if (right_offset_ < length_) {
			do {
				::DD::destruct(begin_);
			} while (++begin_ != storage_end_);
			length_ -= right_offset_;
			do {
				::DD::destruct(storage_begin_ + (--length_));
			} while (length_);
		} else {
			::DD::destruct(begin_, begin_ + length_);
		}
	}


};



template <>
struct DestructRing_<true> {
	template <typename ValueT_>
	ProcessType destruct_ring_(
		ValueT_* storage_begin_,
		ValueT_* begin_,
		ValueT_* storage_end_,
		LengthType length_
	) DD_NOEXCEPT {
	}


};



template <typename ValueT_>
struct Ring_ {
	public:
	DD_ALIAS(ThisType, Ring_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	protected:
	DD_ALIAS(LengthType, ::DD::LengthType);

	protected:
	DD_ALIAS(Iterator, UniversalFreeAccessIterator<ThisType>);
	DD_ALIAS(ConstIterator, UniversalFreeAccessIterator<ThisType, true>);
	DD_ITERATOR_NESTED


	protected:
	PointerType m_storage_begin_;
	PointerType m_begin_;
	PointerType m_storage_end_;
	LengthType m_length_;


	protected:
	DD_CONSTEXPR Ring_() DD_NOEXCEPT : m_storage_begin_(), m_begin_(), m_storage_end_(), m_length_() {
	}

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(Ring_)

	protected:
	Ring_(ThisType&& origin_) DD_NOEXCEPT :
		m_storage_begin_(origin_.m_storage_begin_),
		m_begin_(origin_.m_begin_),
		m_storage_end_(origin_.m_storage_end_),
		m_length_(origin_.m_length_)
	{
		origin_.m_storage_begin_ = PointerType();
		origin_.m_begin_ = PointerType();
		origin_.m_storage_end_ = PointerType();
		origin_.m_length_ = LengthType();
	}

	protected:
	Ring_(UnguardedTag tag_) DD_NOEXCEPT {
	}


	protected:
	~Ring_() DD_NOEXCEPT {
		destruct_();
	}


	protected:
	Iterator begin() DD_NOEXCEPT {
		return Iterator(*this, 0);
	}

	protected:
	ConstIterator DD_CONSTEXPR begin() const DD_NOEXCEPT {
		return ConstIterator(*this, 0);
	}


	protected:
	Iterator end() DD_NOEXCEPT {
		return Iterator(*this, m_length_);
	}

	protected:
	ConstIterator DD_CONSTEXPR end() const DD_NOEXCEPT {
		return ConstIterator(*this, m_length_);
	}


	protected:
	DD_RANGE_NESTED


	protected:
	ReversIterator rbegin() DD_NOEXCEPT {
		return ReversIterator(end() - 1);
	}

	protected:
	ConstReversIterator rbegin() DD_NOEXCEPT {
		return ConstReversIterator(end() - 1);
	}


	protected:
	ReversIterator rend() DD_NOEXCEPT {
		return ReversIterator(begin() - 1);
	}

	protected:
	ConstReversIterator rend() DD_NOEXCEPT {
		return ConstReversIterator(begin() - 1);
	}


	protected:
	DD_REVERSE_RANGE_NESTED


	public:
	LengthType DD_CONSTEXPR get_length() const DD_NOEXCEPT {
		return m_length_;
	}


	public:
	LengthType DD_CONSTEXPR get_capacity() const DD_NOEXCEPT {
		return m_storage_end_ - m_storage_begin_;
	}


	protected:
	LengthType DD_CONSTEXPR get_left_offset_() const DD_NOEXCEPT {
		return m_begin_ - m_storage_begin_;
	}


	protected:
	LengthType DD_CONSTEXPR get_right_offset_() const DD_NOEXCEPT {
		return m_storage_end_ - m_begin_;
	}


	public:
	ValidityType DD_CONSTEXPR is_empty() const DD_NOEXCEPT {
		return !get_length();
	}


	public:
	ValidityType DD_CONSTEXPR is_full() const DD_NOEXCEPT {
		return get_length() == get_capacity();
	}


	public:
	PointerType DD_CONSTEXPR get_pointer(LengthType index_) DD_NOEXCEPT {
		LengthType right_offset_ = get_right_offset_()
		return index_ < right_offset_ ? m_begin_ + index_ : m_storage_begin_ + index_ - right_offset_;
	}

	public:
	ConstPointerType DD_CONSTEXPR get_pointer(LengthType index_) const DD_NOEXCEPT {
		LengthType right_offset_ = get_right_offset_()
		return index_ < right_offset_ ? m_begin_ + index_ : m_storage_begin_ + index_ - right_offset_;
	}


	protected:
	ProcessType swap(ThisType& origin_) DD_NOEXCEPT {
		::DD::swap(m_storage_begin_, origin_.m_storage_begin_);
		::DD::swap(m_begin_, origin_.m_storage_end_);
		::DD::swap(m_storage_end_, origin_.m_storage_end_);
		::DD::swap(m_length_, origin_.m_length_);
	}


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	ProcessType unguarded_emplace_back() noexcept(noexcept(::DD::construct(
		::DD::fabricate<ThisType>().get_pointer(::DD::fabricate<ThisType>().get_length()),
		::DD::forward<ArgumentsT__>(arguments___)...)
	)) {
		::DD::construct(get_pointer(get_length()), ::DD::forward<ArgumentsT__>(arguments___)...);
		++m_length_;
	}

	public:
	template <typename ValueT__>
	ProcessType unguarded_push_back(ValueT__&& value___) noexcept(
		noexcept(::DD::fabricate<ThisType>().unguarded_emplace_back(forward<ValueT__>(value___)))
	) {
		unguarded_emplace_back(forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	ProcessType unguarded_push_back(ValueT__ const& value___) {
		::DD::construct(get_pointer(get_length()), value___);
		++m_length_;
	}
#	endif


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		DestructRing_<IsTriviallyDestructible<ValueType>::value>::destruct_ring_(
			m_storage_begin_, m_begin_, m_storage_end_, m_length_
		);
	}


	protected:
	DD_DELETE_COPY_ASSIGNMENT(Ring_)

#	if __cplusplus >= 201103L
	protected:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT {
		swap(origin_);
	}

#	endif

	public:
	ReferenceType operator [](LengthType index_) DD_NOEXCEPT {
		return *(get_pointer(index_));
	}

	public:
	ConstReferenceType operator [](LengthType index_) const DD_NOEXCEPT {
		return *(get_pointer(index_));
	}


};



#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
#	endif
struct Ring : Allocateable<AllocatorT_>, Ring_<ValueT_> {
	public:
	DD_ALIAS(AllocateAgent, Allocateable<AllocatorT_>);
	DD_ALIAS(SuperType, Ring_<ValueT_>);
	DD_ALIAS(ThisType, Ring<ValueT_, AllocatorT_>);
	DD_ALIAS(AllocatorType, AllocatorT_);

	public:
	DD_INHERIT_TEMPLATE_ALIAS(ValueType);
	DD_INHERIT_TEMPLATE_ALIAS(ValueConstType);
	DD_INHERIT_TEMPLATE_ALIAS(ReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(ConstReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(PointerType);
	DD_INHERIT_TEMPLATE_ALIAS(ConstPointerType);

	public:
	DD_ALIAS(Iterator, UniversalFreeAccessIterator<ThisType>);
	DD_ALIAS(ConstIterator, UniversalFreeAccessIterator<ThisType, true>);
	DD_ITERATOR_NESTED


#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR Ring() = default;

	public:
	DD_CONSTEXPR Ring(ThisType const& origin_) {
		clone_initialize_(origin_);
	}

	public:
	DD_CONSTEXPR Ring(ThisType&& origin_) = default;
#	else
	Ring() throw() {
	}
#	endif


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
