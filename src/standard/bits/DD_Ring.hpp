//	DDCPP/standard/bits/DD_Ring.hpp
#ifndef DD_RING_HPP_INCLUDED_
#	define DD_RING_HPP_INCLUDED_ 1



#	include "DD_Tags.hpp"
#	include "DD_IteratorNested.hpp"
#	include "DD_IsTriviallyDestructible.hpp"
#	include "DD_Illogic.hpp"
#	include "DD_Range.hpp"
#	include "DD_Allocateable.hpp"
#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"
#	include "DD_UniversalFreeAccessIterator.hpp"
#	include "DD_max.hpp"
#	include "DD_swap.hpp"
#	include "DD_for_each.hpp"
#	include "DD_length_difference.hpp"
#	include "DD_copy_length.hpp"
#	include "DD_copy_construct_length.hpp"
#	include "DD_transconstruct.hpp"
#	if __cplusplus >= 201103L
#		include "DD_move_overlapped_backward.hpp"
#		include "DD_move_overlapped_forward.hpp"
#	else
#		include "DD_copy_overlapped_backward.hpp"
#		include "DD_copy_overlapped_forward.hpp"
#	endif



#	if !defined(DDCPP_RING_GROWTH_RATIO)
#		define DDCPP_RING_GROWTH_RATIO 2
#	endif



DD_DETAIL_BEGIN_
template <ValidityType can_trivially_operate_c_>
struct RingOperation_ {
	template <typename ValueT_>
	static ProcessType destruct_ring_(
		ValueT_* storage_begin_,
		ValueT_* begin_,
		ValueT_* storage_end_,
		LengthType length_
	) DD_NOEXCEPT {
		LengthType right_offset_ = storage_end_ - begin_;
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


	template <typename ValueT_>
	static ProcessType destruct_element_(
		ValueT_* storage_begin_,
		ValueT_* begin_,
		ValueT_* storage_end_,
		LengthType index_
	) DD_NOEXCEPT {
		LengthType right_offset_ = storage_end_ - begin_;
		if (index_ < right_offset_) {
			::DD::destruct(begin_ + index_);
		} else {
			::DD::destruct(storage_begin_ + index_ - right_offset_);
		}
	}


	template <typename ValueT_>
	static ProcessType destruct_element_(
		ValueT_* storage_begin_,
		ValueT_* begin_,
		ValueT_* storage_end_,
		LengthType begin_index_,
		LengthType end_index_
	) DD_NOEXCEPT {
		LengthType right_offset_ = storage_end_ - begin_;
		if (begin_index_ < right_offset_) {
			if (right_offset_ < end_index_) {
				::DD::destruct(begin_ + begin_index_, storage_end_);
				::DD::destruct(storage_begin_, storage_begin_ + end_index_ - right_offset_);
			} else {
				::DD::destruct(begin_ + begin_index_, begin_ + end_index_);
			}
		} else {
			storage_begin_ -= right_offset_;
			::DD::destruct(storage_begin_ + begin_index_, storage_begin_ + end_index_);
		}
	}


};



template <>
struct RingOperation_<true> {
	template <typename ValueT_>
	static ProcessType destruct_ring_(
		ValueT_* storage_begin_,
		ValueT_* begin_,
		ValueT_* storage_end_,
		LengthType length_
	) DD_NOEXCEPT {
	}


	template <typename ValueT_>
	static ProcessType destruct_element_(
		ValueT_* storage_begin_,
		ValueT_* begin_,
		ValueT_* storage_end_,
		LengthType index_
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
	DD_ALIAS(ConstIterator, UniversalFreeAccessIterator<ThisType DD_COMMA true>);
	DD_ITERATOR_NESTED

	protected:
	static ValidityType DD_CONSTANT is_trivially_destructible_ = IsTriviallyDestructible<ValueType>::value;


	protected:
	PointerType m_storage_begin_;
	PointerType m_begin_;
	PointerType m_storage_end_;
	LengthType m_length_;


	protected:
	template <typename ValueT__>
	friend struct Ring_;


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
		origin_.reset_();
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
	ReverseIterator rbegin() DD_NOEXCEPT {
		return ReverseIterator(end() - 1);
	}

	protected:
	ConstReverseIterator rbegin() const DD_NOEXCEPT {
		return ConstReverseIterator(end() - 1);
	}


	protected:
	ReverseIterator rend() DD_NOEXCEPT {
		return ReverseIterator(begin() - 1);
	}

	protected:
	ConstReverseIterator rend() const DD_NOEXCEPT {
		return ConstReverseIterator(begin() - 1);
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


	public:
	LengthType DD_CONSTEXPR get_free_space() const DD_NOEXCEPT {
		return get_capacity() - get_length();
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
	ValidityType DD_CONSTEXPR is_contigious() const DD_NOEXCEPT {
		return get_length() <= get_right_offset_();
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
		LengthType right_offset_ = get_right_offset_();
		return index_ < right_offset_ ? m_begin_ + index_ : m_storage_begin_ + index_ - right_offset_;
	}

	public:
	ConstPointerType DD_CONSTEXPR get_pointer(LengthType index_) const DD_NOEXCEPT {
		LengthType right_offset_ = get_right_offset_();
		return index_ < right_offset_ ? m_begin_ + index_ : m_storage_begin_ + index_ - right_offset_;
	}


	public:
	ReferenceType at(LengthType index_) {
		if (index_ >= get_length()) {
			throw Illogic("Out of range: 'DD::Ring::at'");
		}
		return *get_pointer(index_);
	}

	public:
	ConstReferenceType at(LengthType index_) const {
		if (index_ >= get_length()) {
			throw Illogic("Out of range: 'DD::Ring::at'");
		}
		return *get_pointer(index_);
	}


	protected:
	ProcessType reset_() DD_NOEXCEPT {
		m_storage_begin_ = PointerType();
		m_begin_ = PointerType();
		m_storage_end_ = PointerType();
		m_length_ = LengthType();
	}


	protected:
	ProcessType swap(ThisType& origin_) DD_NOEXCEPT {
		::DD::swap(m_storage_begin_, origin_.m_storage_begin_);
		::DD::swap(m_begin_, origin_.m_storage_end_);
		::DD::swap(m_storage_end_, origin_.m_storage_end_);
		::DD::swap(m_length_, origin_.m_length_);
	}


	protected:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_clone_without_circuit_(UndirectionalIteratorT__ begin___, LengthType length_) {
		if (get_length() < length_) {
			PointerType position_;
			::DD::mate(begin___, position_) = ::DD::copy_length(begin___, m_begin_, get_length());
			::DD::copy_construct_length(begin___, position_, length_ - get_length());
		} else {
			::DD::destruct(::DD::copy_length(begin___, m_begin_, length_).second, m_begin_ + get_length());
		}
		m_length_ = length_;
	}


	protected:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_clone(UndirectionalIteratorT__ begin___, LengthType length_) {
		LengthType origin_length_ = get_length();
		LengthType right_offset_ = get_right_offset_();
		if (origin_length_ < right_offset_) {
			if (origin_length_ < length_) {
				begin___ = ::DD::copy_length(begin___, m_begin_, origin_length_);
				if (right_offset_ < length_) {
					begin___ = ::DD::copy_construct_length(begin___, m_begin_ + origin_length_, right_offset_ - origin_length_);
					m_length_ = right_offset_;
					::DD::copy_construct_length(begin___, m_storage_begin_, length_ - right_offset_);
				} else {
					::DD::copy_construct_length(begin___, m_begin_ + origin_length_, length_ - origin_length_);
				}
			} else {
				::DD::destruct(::DD::copy_length(begin___, m_begin_, length_).second, m_begin_ + origin_length_);
			}
		} else if (right_offset_ < length_) {
			begin___ = ::DD::copy_length(begin___, m_begin_, right_offset_);
			length_ -= right_offset_;
			origin_length_ -= right_offset_;
			if (origin_length_ < length_) {
				PointerType position_;
				::DD::mate(begin___, position_) = ::DD::copy_length(begin___, m_storage_begin_, origin_length_);
				::DD::copy_construct_length(begin___, position_, length_ - origin_length_);
			} else {
				::DD::destruct(::DD::copy_length(begin___, m_storage_begin_, length_).second, m_storage_begin_ + origin_length_);
			}
		} else {
			::DD::destruct(::DD::copy_length(begin___, m_begin_, length_).second, m_storage_end_);
			::DD::destruct(m_storage_begin_, m_storage_begin_ + origin_length_ - right_offset_);
		}
		m_length_ = length_;
	}


	protected:
	ProcessType transfer_to_(PointerType new_storage_begin_) {
		LengthType right_offset_ = get_right_offset_();
		if (right_offset_ < get_length()) {
			PointerType new_end_ = ::DD::transconstruct(m_begin_, m_storage_end_, new_storage_begin_);
			try {
				::DD::transconstruct(
					m_storage_begin_,
					m_storage_begin_ + get_length() - right_offset_,
					new_end_
				);
			} catch (...) {
				::DD::destruct(new_storage_begin_, new_end_);
				throw;
			}
		} else {
			::DD::transconstruct(m_begin_, m_begin_ + get_length(), new_storage_begin_);
		}
		destruct_();
	}


	public:
	template <typename FunctionT__>
	ProcessType for_each(FunctionT__ function___) {
		LengthType right_offset_ = get_right_offset_();
		if (right_offset_ < get_length()) {
			return ::DD::for_each(
				m_storage_begin_,
				m_storage_begin_ + m_length_ - right_offset_,
				::DD::for_each(m_begin_, m_storage_end_, function___)
			);
		}
		return ::DD::for_each(m_begin_, m_begin_ + get_length(), function___);
	}

	public:
	template <typename FunctionT__>
	ProcessType for_each(LengthType begin_index_, LengthType end_index_, FunctionT__ function___) {
		LengthType right_offset_ = get_right_offset_();
		if (begin_index_ < right_offset_) {
			if (right_offset_ < end_index_) {
				return ::DD::for_each(
					m_storage_begin_,
					m_storage_begin_ + end_index_ - right_offset_,
					::DD::for_each(m_begin_ + begin_index_, m_storage_end_, function___)
				);
			} else {
				return ::DD::for_each(m_begin_ + begin_index_, m_begin_ + end_index_, function___);
			}
		}
		PointerType reference_frame_ = m_storage_begin_ - right_offset_;
		return ::DD::for_each(reference_frame_ + begin_index_, reference_frame_ + end_index_, function___);
	}


#	if __cplusplus >= 201103L
	protected:
	template <typename... ArgumentsT__>
	ProcessType unguarded_emplace_front_without_circuit_(ArgumentsT__&&... arguments___) noexcept(
		noexcept(::DD::construct(m_begin_ - 1, ::DD::forward<ArgumentsT__>(arguments___)...))
	) {
		::DD::construct(m_begin_ - 1, ::DD::forward<ArgumentsT__>(arguments___)...);
		--m_begin_;
		++m_length_;
	}


	public:
	template <typename... ArgumentsT__>
	ProcessType unguarded_emplace_front(ArgumentsT__&&... arguments___) noexcept(noexcept(::DD::construct(
		::DD::fabricate<ThisType>().get_pointer(::DD::fabricate<ThisType>().get_length()),
		::DD::forward<ArgumentsT__>(arguments___)...)
	)) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Ring::unguarded_emplace_front'");
		PointerType m_position_ = m_begin_ - 1;
		if (m_position_ < m_storage_begin_) {
			m_position_ = m_storage_end_ - 1;
		}
		::DD::construct(m_position_, ::DD::forward<ArgumentsT__>(arguments___)...);
		m_begin_ = m_position_;
		++m_length_;
	}


	public:
	template <typename ValueT__>
	ProcessType unguarded_push_front(ValueT__&& value___) noexcept(
		noexcept(::DD::fabricate<ThisType>().unguarded_emplace_front(::DD::forward<ValueT__>(value___)))
	) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Ring::unguarded_push_front'");
		unguarded_emplace_front(::DD::forward<ValueT__>(value___));
	}
#	else
	protected:
	template <typename ValueT__>
	ProcessType unguarded_push_front_without_circuit_(ValueT__ const& value___) {
		::DD::construct(m_begin_ - 1, value___);
		--m_begin_;
		++m_length_;
	}


	public:
	template <typename ValueT__>
	ProcessType unguarded_push_front(ValueT__ const& value___) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Ring::unguarded_push_front'");
		PointerType m_position_ = m_begin_ - 1;
		if (m_position_ < m_storage_begin_) {
			m_position_ = m_storage_end_ - 1;
		}
		::DD::construct(m_position_, value___);
		m_begin_ = m_position_;
		++m_length_;
	}
#	endif


#	if __cplusplus >= 201103L
	protected:
	template <typename... ArgumentsT__>
	ProcessType unguarded_emplace_back_without_circuit_(ArgumentsT__&&... arguments___) noexcept(
		noexcept(::DD::construct(m_begin_ + ::DD::fabricate<ThisType>().get_length(), ::DD::forward<ArgumentsT__>(arguments___)...))
	) {
		::DD::construct(m_begin_ + get_length(), ::DD::forward<ArgumentsT__>(arguments___)...);
		++m_length_;
	}


	public:
	template <typename... ArgumentsT__>
	ProcessType unguarded_emplace_back(ArgumentsT__&&... arguments___) noexcept(noexcept(::DD::construct(
		::DD::fabricate<ThisType>().get_pointer(::DD::fabricate<ThisType>().get_length()),
		::DD::forward<ArgumentsT__>(arguments___)...)
	)) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Ring::unguarded_emplace_back'");
		::DD::construct(get_pointer(get_length()), ::DD::forward<ArgumentsT__>(arguments___)...);
		++m_length_;
	}


	public:
	template <typename ValueT__>
	ProcessType unguarded_push_back(ValueT__&& value___) noexcept(
		noexcept(!::DD::fabricate<ThisType>().unguarded_emplace_back(forward<ValueT__>(value___)))
	) {
		DD_ASSERT(is_full(), "Out of range: 'DD::Ring::unguarded_push_back'");
		unguarded_emplace_back(forward<ValueT__>(value___));
	}
#	else
	protected:
	template <typename ValueT__>
	ProcessType unguarded_push_front_without_circuit_(ValueT__ const& value___) {
		::DD::construct(m_begin_ + get_length(), value___);
		++m_length_;
	}


	public:
	template <typename ValueT__>
	ProcessType unguarded_push_back(ValueT__ const& value___) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Ring::unguarded_push_back'");
		::DD::construct(get_pointer(get_length()), value___);
		++m_length_;
	}
#	endif


	private:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_concatenate_front_without_circuit_(
		UndirectionalIteratorT__ begin___,
		LengthType length_
	) DD_NOEXCEPT_AS(::DD::copy_construct_length(begin___, m_begin_ - length_, length_)) {
		::DD::copy_construct_length(begin___, m_begin_ - length_, length_);
		m_begin_ -= length_;
		m_begin_ -= length_;
	}


	public:
	template <typename ValueT__>
	ProcessType unguarded_concatenate_front(
		UniversalFreeAccessIterator<Ring_<ValueT__> const> begin___,
		LengthType length_
	) {
		LengthType left_offset_ = get_left_offset_();
		typename UniversalFreeAccessIterator<
			Ring_<ValueT__> const
		>::PointerType origin_begin_ = begin___.get_container().m_begin_;
		LengthType origin_right_offset_ = begin___.get_container().m_storage_end_ - origin_begin_;
		if (left_offset_ < length_) {
			if (origin_right_offset_ < length_) {
				if (left_offset_ < origin_right_offset_) {
					::DD::copy_construct_length(origin_begin_, m_storage_begin_, left_offset_);
					m_begin_ = m_storage_begin_;
					m_length_ += left_offset_;
					origin_right_offset_ -= left_offset_;
					::DD::copy_construct_length(origin_begin_ + left_offset_, m_storage_end_ - origin_right_offset_, origin_right_offset_);
					m_begin_ = m_storage_end_ - origin_right_offset_;
					m_length_ += origin_right_offset_;
					length_ -= (origin_right_offset_ + left_offset_);
					::DD::copy_construct_length(begin___.get_container().m_storage_begin_, m_begin_ - length_, length_);
					m_begin_ -= length_;
				} else {
					::DD::copy_construct_length(origin_begin_, m_begin_ - origin_right_offset_, origin_right_offset_);
					m_begin_ -= origin_right_offset_;
					m_length_ += origin_right_offset_;
					origin_begin_ = ::DD::copy_construct_length(
						begin___.get_container().m_storage_begin_, m_storage_begin_, left_offset_ - origin_right_offset_
					).first;
					m_begin_ = m_storage_begin_;
					m_length_ += (left_offset_ - origin_right_offset_);
					length_ -= left_offset_;
					::DD::copy_construct_length(origin_begin_, m_storage_end_ - length_, length_);
					m_begin_ = m_storage_end_ - length_;
				}
			} else {
				::DD::copy_construct_length(origin_begin_, m_storage_begin_, left_offset_);
				m_begin_ = m_storage_begin_;
				m_length_ += left_offset_;
				length_ -= left_offset_;
				::DD::copy_construct_length(origin_begin_ + left_offset_, m_storage_end_ - length_, length_);
				m_begin_ = m_storage_end_ - length_;
			}
		} else {
			if (origin_right_offset_ < length_) {
				::DD::copy_construct_length(origin_begin_, m_begin_ - origin_right_offset_, origin_right_offset_);
				m_begin_ -= origin_right_offset_;
				m_length_ += origin_right_offset_;
				origin_begin_ = begin___.get_container().m_storage_begin_;
				length_ -= origin_right_offset_;
			}
			::DD::copy_construct_length(origin_begin_, m_begin_ - length_, length_);
			m_begin_ -= length_;
		}
		m_length_ += length_;
	}

	public:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_concatenate_front(UndirectionalIteratorT__ begin___, LengthType length_) {
		LengthType left_offset_ = get_left_offset_();
		if (length_ < left_offset_) {
			unguarded_concatenate_front_without_circuit_(begin___, length_);
		} else {
			begin___ = ::DD::copy_construct_length(begin___, m_begin_ - left_offset_, left_offset_).first;
			m_length_ += left_offset_;
			length_ -= left_offset_;
			::DD::copy_construct_length(begin___, m_storage_end_ - length_, length_);
			m_length_ += length_;
		}
	}

	public:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_concatenate_front(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().unguarded_concatenate_front(
		begin___ DD_COMMA ::DD::length_difference(begin___ DD_COMMA end___)
	)) {
		unguarded_concatenate_front(begin___, ::DD::length_difference(begin___, end___));
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType unguarded_concatenate_front(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().unguarded_concatenate_front(DD_SPLIT_RANGE(range___))
	) {
		unguarded_concatenate_front(DD_SPLIT_RANGE(range___));
	}


	private:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_concatenate_back_without_circuit_(
		UndirectionalIteratorT__ begin___,
		LengthType length_
	) DD_NOEXCEPT_AS(::DD::copy_construct_length(begin___, m_begin_ - length_, length_)) {
		::DD::copy_construct_length(begin___, m_begin_ + get_length(), length_);
		m_length_ += length_;
	}


	public:
	template <typename ValueT__>
	ProcessType unguarded_concatenate_back(
		UniversalFreeAccessIterator<Ring_<ValueT__> const> begin___,
		LengthType length_
	) {
		LengthType right_offset_ = get_right_offset_();
		typename UniversalFreeAccessIterator<
			Ring_<ValueT__> const
		>::PointerType origin_begin_ = begin___.get_container().m_begin_;
		LengthType origin_right_offset_ = begin___.get_container().m_storage_end_ - origin_begin_;
		if (get_length() < right_offset_) {
			if (right_offset_ -= get_length() < length_) {
				if (origin_right_offset_ < length_) {
					if (right_offset_ < origin_right_offset_) {
						::DD::copy_construct_length(origin_begin_, m_begin_ + get_length(), right_offset_);
						m_length_ += right_offset_;
						origin_right_offset_ -= right_offset_;
						::DD::copy_construct_length(origin_begin_ + right_offset_, m_storage_begin_, origin_right_offset_);
						m_length_ += origin_right_offset_;
						length_ -= (origin_right_offset_ + right_offset_);
						::DD::copy_construct_length(
							begin___.get_container().m_storage_begin_, m_storage_begin_ + origin_right_offset_, length_
						);
					} else {
						::DD::copy_construct_length(origin_begin_, m_begin_ + get_length(), origin_right_offset_);
						m_length_ += origin_right_offset_;
						right_offset_ -= origin_right_offset_;
						origin_begin_ = ::DD::copy_construct_length(
							begin___.get_container().m_storage_begin_, m_begin_ + get_length(), right_offset_
						).first;
						m_length_ += right_offset_;
						length_ -= (origin_right_offset_ + right_offset_);
						::DD::copy_construct_length(origin_begin_, m_storage_begin_, length_);
					}
				} else {
					::DD::copy_construct_length(origin_begin_, m_begin_ + get_length(), right_offset_);
					m_length_ += right_offset_;
					length_ -= right_offset_;
					::DD::copy_construct_length(origin_begin_ + right_offset_, m_storage_begin_, length_);
				}
			} else {
				if (origin_right_offset_ < length_) {
					::DD::copy_construct_length(origin_begin_, m_begin_ + get_length(), origin_right_offset_);
					m_length_ += origin_right_offset_;
					length_ -= origin_right_offset_;
					::DD::copy_construct_length(begin___.get_container().m_storage_begin_, m_begin_ + get_length(), length_);
				} else {
					::DD::copy_construct_length(origin_begin_, m_begin_ + get_length(), length_);
				}
			}
		} else {
			if (origin_right_offset_ < length_) {
				PointerType position_ = ::DD::copy_construct_length(
					origin_begin_, m_storage_begin_ + get_length() - right_offset_, origin_right_offset_
				).second;
				m_length_ += origin_right_offset_;
				length_ -= origin_right_offset_;
				::DD::copy_construct_length(begin___.get_container().m_storage_begin_, position_, length_);
			} else {
				::DD::copy_construct_length(origin_begin_, m_storage_begin_ + get_length() - right_offset_, length_);
			}
		}
		m_length_ += length_;
	}

	public:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_concatenate_back(UndirectionalIteratorT__ begin___, LengthType length_) {
		LengthType right_offset_ = get_right_offset_();
		if (get_length() < right_offset_) {
			if (right_offset_ -= get_length() < length_) {
				begin___ = ::DD::copy_construct_length(begin___, m_begin_ + get_length(), right_offset_).first;
				m_length_ += right_offset_;
				length_ -= right_offset_;
				::DD::copy_construct_length(begin___, m_storage_begin_, length_);
				m_length_ += length_;
			} else {
				unguarded_concatenate_back_without_circuit_(begin___, length_);
			}
		} else {
			::DD::copy_construct_length(begin___, m_storage_begin_ + get_length() - right_offset_, length_);
			m_length_ += length_;
		}
	}

	public:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_concatenate_back(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().unguarded_concatenate_back(
		begin___ DD_COMMA ::DD::length_difference(begin___ DD_COMMA end___)
	)) {
		unguarded_concatenate_back(begin___, ::DD::length_difference(begin___, end___));
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType unguarded_concatenate_back(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().unguarded_concatenate_back(DD_SPLIT_RANGE(range___))
	) {
		unguarded_concatenate_back(DD_SPLIT_RANGE(range___));
	}


	public:
	ProcessType pop_front() DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Ring::pop_back'");
		::DD::destruct(m_begin_);
		if (++m_begin_ == m_storage_end_) {
			m_begin_ = m_storage_begin_;
		}
		--m_length_;
	}


	public:
	ProcessType pop_back() DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Ring::pop_back'");
		RingOperation_<is_trivially_destructible_>::destruct_element_(
			m_storage_begin_, m_begin_, m_storage_end_, --m_length_
		);
	}


	public:
	ProcessType trim_front(LengthType index_) DD_NOEXCEPT {
		DD_ASSERT(index_ <= get_length(), "Out of range: 'DD::Ring::trim_back'");
		LengthType right_offset_ = get_right_offset_();
		if (right_offset_ < index_) {
			::DD::destruct(m_begin_, m_storage_end_);
			m_begin_ = m_storage_begin_ + index_ - right_offset_;
			::DD::destruct(m_storage_begin_, m_begin_);
		} else {
			PointerType position_ = m_begin_ + index_;
			::DD::destruct(m_begin_, position_);
			m_begin_ = position_;
		}
		m_length_ -= index_;
	}


	public:
	ProcessType trim_back(LengthType index_) DD_NOEXCEPT {
		DD_ASSERT(index_ <= get_length(), "Out of range: 'DD::Ring::trim_back'");
		RingOperation_<is_trivially_destructible_>::destruct_element_(
			m_storage_begin_, m_begin_, m_storage_end_, index_, m_length_
		);
		m_length_ = index_;
	}


	public:
	ProcessType erase(LengthType index_) {
		DD_ASSERT(index_ < get_length(), "Out of range: 'DD::Ring::erase'");
		LengthType right_offset_ = get_right_offset_();
		if (index_ < right_offset_) {
			PointerType position_ = m_begin_ + index_;
#	if __cplusplus >= 201103L
			::DD::move_overlapped_backward(
#	else
			::DD::copy_overlapped_backward(
#	endif
				m_begin_,
				position_,
				position_ + 1
			);
			pop_front();
		} else {
			PointerType reference_frame_ = m_storage_begin_ - right_offset_;
#	if __cplusplus >= 201103L
			::DD::move_overlapped_forward(
#	else
			::DD::copy_overlapped_forward(
#	endif
				reference_frame_ + index_ + 1,
				reference_frame_ + get_length(),
				reference_frame_ + index_
			);
			::DD::destruct(reference_frame_ + --m_length_);
		}
	}


	public:
	static ProcessType erase(Iterator position_) {
		position_.get_container().erase(position_.get_index());
	}


	public:
	ProcessType erase_range(LengthType begin_index_, LengthType end_index_) {
		DD_ASSERT(begin_index_ <= end_index_, "Invalid range: 'DD::Ring::erase_range'");
		DD_ASSERT(
			(begin_index_ < get_length() && end_index_ <= get_length()) || begin_index_ == end_index_,
			"Out of range: 'DD::Ring::erase_range'"
		);
		LengthType right_offset_ = get_right_offset_();
		if (begin_index_ < right_offset_) {
			if (right_offset_ < end_index_) {
				{
					PointerType origin_begin_ = m_begin_;
					::DD::destruct(
						origin_begin_,
#	if __cplusplus >= 201103L
						m_begin_ = ::DD::move_overlapped_backward(m_begin_, m_begin_ + begin_index_, m_storage_end_)
#	else
						m_begin_ = ::DD::copy_overlapped_backward(m_begin_, m_begin_ + begin_index_, m_storage_end_)
#	endif
					);
				}
				{
					LengthType origin_length_ = get_length();
					m_length_ -= (right_offset_ - begin_index_);
					PointerType reference_frame_ = m_storage_begin_ - right_offset_;
					::DD::destruct(
#	if __cplusplus >= 201103L
						::DD::move_overlapped_forward(reference_frame_ + end_index_, reference_frame_ + origin_length_, m_storage_begin_),
#	else
						::DD::copy_overlapped_forward(reference_frame_ + end_index_, reference_frame_ + origin_length_, m_storage_begin_),
#	endif
						reference_frame_ + origin_length_
					);
					m_length_ -= (end_index_ - right_offset_);
				}
			} else {
				PointerType origin_begin_ = m_begin_;
				::DD::destruct(
					origin_begin_,
#	if __cplusplus >= 201103L
					m_begin_ = ::DD::move_overlapped_backward(m_begin_, m_begin_ + begin_index_, m_begin_ + end_index_)
#	else
					m_begin_ = ::DD::copy_overlapped_backward(m_begin_, m_begin_ + begin_index_, m_begin_ + end_index_)
#	endif
				);
				m_length_ -= (end_index_ - begin_index_);
			}
		} else {
			PointerType reference_frame_ = m_storage_begin_ - right_offset_;
			::DD::destruct(
#	if __cplusplus >= 201103L
				::DD::move_overlapped_forward(
#	else
				::DD::copy_overlapped_forward(
#	endif
					reference_frame_ + end_index_,
					reference_frame_ + get_length(),
					reference_frame_ + begin_index_
				),
				reference_frame_ + get_length()
			);
			m_length_ -= (end_index_ - begin_index_);
		}
	}


	public:
	static ProcessType erase_range(Iterator begin_, Iterator end_) {
		DD_ASSERT(
			::DD::address_of(begin_.get_container()) == ::DD::address_of(end.get_container()),
			"Invalid range: 'DD::Ring::erase_range'"
		);
		begin_.get_container().erase_range(begin_.get_index(), end_.get_index());
	}


	public:
	ProcessType clear() DD_NOEXCEPT {
		destruct_();
		m_begin_ = m_storage_begin_;
		m_length_ = 0;
	}


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		RingOperation_<is_trivially_destructible_>::destruct_ring_(
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
		DD_ASSERT(index_ < get_length(), "Out of range: 'DD::Ring::operator []'");
		return *(get_pointer(index_));
	}

	public:
	ConstReferenceType operator [](LengthType index_) const DD_NOEXCEPT {
		DD_ASSERT(index_ < get_length(), "Out of range: 'DD::Ring::operator []'");
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
	DD_ALIAS(ThisType, Ring<ValueT_ DD_COMMA AllocatorT_>);
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
	DD_ALIAS(ConstIterator, UniversalFreeAccessIterator<ThisType DD_COMMA true>);
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


	public:
	Iterator begin() DD_NOEXCEPT_AS(Iterator(::DD::fabricate<ThisType>().SuperType::begin())) {
		return Iterator(SuperType::begin());
	}

	public:
	ConstIterator begin() const DD_NOEXCEPT_AS(ConstIterator(::DD::fabricate<ThisType const>().SuperType::begin())) {
		return ConstIterator(SuperType::begin());
	}


	public:
	Iterator end() DD_NOEXCEPT_AS(Iterator(::DD::fabricate<ThisType>().SuperType::end())) {
		return Iterator(SuperType::end());
	}

	public:
	ConstIterator end() const DD_NOEXCEPT_AS(ConstIterator(::DD::fabricate<ThisType const>().SuperType::end())) {
		return ConstIterator(SuperType::end());
	}


	public:
	DD_RANGE_NESTED


	public:
	ReverseIterator rbegin() DD_NOEXCEPT_AS(ReverseIterator(::DD::fabricate<ThisType>().SuperType::rbegin())) {
		return ReverseIterator(SuperType::rbegin());
	}

	public:
	ConstReverseIterator rbegin() const DD_NOEXCEPT_AS(ConstReverseIterator(::DD::fabricate<ThisType const>().SuperType::rbegin())) {
		return ConstReverseIterator(SuperType::rbegin());
	}


	public:
	ReverseIterator rend() DD_NOEXCEPT_AS(ReverseIterator(::DD::fabricate<ThisType>().SuperType::rend())) {
		return ReverseIterator(SuperType::rend());
	}

	public:
	ConstReverseIterator rend() const DD_NOEXCEPT_AS(ConstReverseIterator(::DD::fabricate<ThisType const>().SuperType::rend())) {
		return ConstReverseIterator(SuperType::rend());
	}


	public:
	DD_REVERSE_RANGE_NESTED


	public:
	~Ring() {
		destruct_();
	}


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT_IF(
		noexcept(::DD::fabricate<ThisType>().swap(other_)) &&
		noexcept(::DD::swap(static_cast<AllocateAgent&>(::DD::fabricate<ThisType>()), static_cast<AllocateAgent&>(other_)))
	) {
		::DD::swap(static_cast<AllocateAgent&>(*this), static_cast<AllocateAgent&>(other_));
		try {
			SuperType::swap(other_);
		} catch (...) {
			::DD::swap(static_cast<AllocateAgent&>(*this), static_cast<AllocateAgent&>(other_));
			throw;
		}
	}


	private:
	template <typename UndirectionalIteratorT__>
	ProcessType clone_initialize_(UndirectionalIteratorT__ begin___, LengthType length_) {
		if (length_ > 0) {
			this->m_storage_begin_ = AllocateAgent::allocate(length_);
			try {
				::DD::copy_construct_length(this->m_storage_begin_, this->m_begin_);
			} catch (...) {
				AllocateAgent::deallocate(this->m_storage_begin_, length_);
			}
			this->m_storage_end_ = this->m_storage_begin_ + length_;
			this->m_begin_ = this->m_storage_begin_;
			this->m_length_ = length_;
		} else {
			this->reset_();
		}
	}

	private:
	template <typename UndirectionalIteratorT__>
	ProcessType clone_initialize_(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) {
		clone_initialize_(begin___, ::DD::length_difference(begin___, end___));
	}

	private:
	template <typename UndirectionalRangeT__>
	ProcessType clone_initialize_(UndirectionalRangeT__ const& range___) {
		clone_initialize_(DD_SPLIT_RANGE(range___));
	}


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType clone(UndirectionalIteratorT__ begin___, LengthType length_) {
		if (this->get_capacity() < length_) {
			stretch(length_);
			SuperType::unguarded_clone_without_circuit_(begin___, length_);
		} else {
			SuperType::unguarded_clone(begin___, length_);
		}
	}


	public:
	ProcessType stretch(LengthType new_capacity_) {
		DD_ASSERT(new_capacity_ >= this->get_length(), "New capacity is not enough for existing elements: 'DD::Ring::stretch'");
		PointerType new_storage_begin_ = AllocateAgent::allocate(new_capacity_);
		LengthType right_ = (new_capacity_ - this->get_length()) / 2;
		try {
			SuperType::transfer_to_(new_storage_begin_ + right_);
		} catch (...) {
			AllocateAgent::deallocate(new_storage_begin_, new_capacity_);
			throw;
		}
		destruct_();
		this->m_storage_begin_ = new_storage_begin_;
		this->m_begin_ = new_storage_begin_ + right_;
		this->m_storage_end_ = new_storage_begin_ + new_capacity_;
	}


	public:
	ProcessType stretch_left(LengthType left_) {
		LengthType new_capacity_ = this->get_length() + left_;
		PointerType new_storage_begin_ = AllocateAgent::allocate(new_capacity_);
		try {
			SuperType::transfer_to_(new_storage_begin_ + left_);
		} catch (...) {
			AllocateAgent::deallocate(new_storage_begin_, new_capacity_);
			throw;
		}
		destruct_();
		this->m_storage_begin_ = new_storage_begin_;
		this->m_begin_ = new_storage_begin_ + left_;
		this->m_storage_end_ = new_storage_begin_ + new_capacity_;
	}


	public:
	ProcessType stretch_right(LengthType right_) {
		stretch(this->get_length() + right_);
	}


	public:
	ProcessType stretch_ends(LengthType left_, LengthType right_) {
		LengthType new_capacity_ = this->get_length() + left_ + right_;
		PointerType new_storage_begin_ = AllocateAgent::allocate(new_capacity_);
		try {
			SuperType::transfer_to_(new_storage_begin_ + left_);
		} catch (...) {
			AllocateAgent::deallocate(new_storage_begin_, new_capacity_);
			throw;
		}
		destruct_();
		this->m_storage_begin_ = new_storage_begin_;
		this->m_begin_ = new_storage_begin_ + left_;
		this->m_storage_end_ = new_storage_begin_ + new_capacity_;
	}


	public:
	ProcessType reserve() {
		LengthType capacity_ = this->get_capacity();
		if (capacity_) {
			try {
				stretch(capacity_ * (DDCPP_RING_GROWTH_RATIO));
			} catch (AllocationFailure& exception_) {
				stretch(capacity_ + 1);
			}
		} else {
			stretch(1);
		}
	}

	public:
	ProcessType reserve(LengthType new_capacity_) {
		if (this->get_capacity() < new_capacity_) {
			stretch(new_capacity_);
		}
	}


	public:
	ProcessType reserve_left() {
		LengthType capacity_ = this->get_capacity();
		if (capacity_) {
			try {
				stretch_left(capacity_ * ((DDCPP_RING_GROWTH_RATIO) - 1));
			} catch (AllocationFailure& exception_) {
				stretch_left(1);
			}
		} else {
			stretch_left(1);
		}
	}

	public:
	ProcessType reserve_left(LengthType left_) {
		if (this->get_free_space() < left_) {
			stretch_left(left_);
		}
	}


	public:
	ProcessType reserve_right() {
		LengthType capacity_ = this->get_capacity();
		if (capacity_) {
			try {
				stretch_right(capacity_ * ((DDCPP_RING_GROWTH_RATIO) - 1));
			} catch (AllocationFailure& exception_) {
				stretch_right(1);
			}
		} else {
			stretch_right(1);
		}
	}

	public:
	ProcessType reserve_right(LengthType right_) {
		if (this->get_free_space() < right_) {
			stretch_right(right_);
		}
	}


	public:
	ProcessType shrink() {
		stretch(this->get_length());
	}

	public:
	ProcessType shrink(LengthType length_) {
		stretch(::DD::max(length_, this->get_length()));
	}


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	ProcessType emplace_front(ArgumentsT__&&... arguments___) {
		if (this->is_full()) {
			reserve_left();
			this->unguarded_emplace_front_without_circuit_(::DD::forward<ArgumentsT__>(arguments___)...);
		} else {
			this->unguarded_emplace_front(::DD::forward<ArgumentsT__>(arguments___)...);
		}
	}

	public:
	template <typename ValueT__>
	ProcessType push_front(ValueT__&& value___) {
		emplace_front(::DD::forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	ProcessType push_front(ValueT__ const& value___) {
		if (this->is_full()) {
			reserve_left();
			this->unguarded_push_front_without_circuit_(value___);
		} else {
			this->unguarded_push_front(value___);
		}
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	ProcessType emplace_back(ArgumentsT__&&... arguments___) {
		if (this->is_full()) {
			reserve_right();
			this->unguarded_emplace_back_without_circuit_(::DD::forward<ArgumentsT__>(arguments___)...);
		} else {
			this->unguarded_emplace_back(::DD::forward<ArgumentsT__>(arguments___)...);
		}
	}

	public:
	template <typename ValueT__>
	ProcessType push_back(ValueT__&& value___) {
		emplace_back(::DD::forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	ProcessType push_back(ValueT__ const& value___) {
		if (this->is_full()) {
			reserve_right();
			this->unguarded_push_back_without_circuit_(value___);
		} else {
			this->unguarded_push_back(value___);
		}
	}
#	endif


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType concatenate_front(UndirectionalIteratorT__ begin___, LengthType length_) {
		if (length_ > this->get_free_space()) {
			stretch_left(length_);
			this->unguarded_concatenate_front_without_circuit_(begin___, length_);
		} else {
			this->unguarded_concatenate_front(begin___, length_);
		}
	}

	public:
	template <typename UndirectionalIteratorT__>
	ProcessType concatenate_front(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().concatenate_front(begin___ DD_COMMA ::DD::length_difference(begin___ DD_COMMA end___))
	) {
		concatenate_front(begin___, ::DD::length_difference(begin___, end___));
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType concatenate_front(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().concatenate_front(DD_SPLIT_RANGE(range___))
	) {
		concatenate_front(DD_SPLIT_RANGE(range___));
	}


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType concatenate_back(UndirectionalIteratorT__ begin___, LengthType length_) {
		if (length_ > this->get_free_space()) {
			stretch_right(length_);
			this->unguarded_concatenate_back_without_circuit_(begin___, length_);
		} else {
			this->unguarded_concatenate_back(begin___, length_);
		}
	}

	public:
	template <typename UndirectionalIteratorT__>
	ProcessType concatenate_back(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().concatenate_back(begin___ DD_COMMA ::DD::length_difference(begin___ DD_COMMA end___))
	) {
		concatenate_back(begin___, ::DD::length_difference(begin___, end___));
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType concatenate_back(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().concatenate_back(DD_SPLIT_RANGE(range___))
	) {
		concatenate_back(DD_SPLIT_RANGE(range___));
	}


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		AllocateAgent::deallocate(this->m_storage_begin_, this->get_capacity());
	}


	public:
	ThisType& operator =(ThisType const& origin_) {
		clone(origin_);
		return *this;
	}

	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT {
		swap(origin_);
	}


	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ThisType& operator <<(ValueT__&& value___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().push_back(::DD::forward<ValueT__>(value___))
	) {
		push_back(::DD::forward<ValueT__>(value___));
		return *this;
	}
#	else
	ThisType& operator <<(ValueT__ const& value___) {
		push_back(value___);
		return *this;
	}
#	endif


	template <typename UndirectionalRangeT__>
	ThisType& operator +=(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().concatenate_back(range___)
	) {
		concatenate_back(range___);
		return *this;
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Ring;



DD_END_



#endif
