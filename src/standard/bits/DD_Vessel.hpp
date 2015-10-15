//	DDCPP/standard/bits/DD_Vessel.hpp
#ifndef DD_VESSEL_HPP_INCLUDED_
#	define DD_VESSEL_HPP_INCLUDED_ 1



#	include "DD_Tags.hpp"
#	include "DD_NeedInstance.hpp"
#	include "DD_fabricate.hpp"
#	include "DD_IteratorNested.hpp"
#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	endif
#	include "DD_length_difference.hpp"
#	include "DD_release.hpp"
#	include "DD_AccessDenied.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_Range.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_InitializerList.hpp"
#	include "DD_get_pointer.hpp"
#	include "DD_transconstruct.hpp"
#	include "DD_copy.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct VesselBase_ {
	public:
	DD_ALIAS(ThisType, VesselBase_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(SizeType, DD::SizeType);
	DD_ALIAS(LengthType, DD::LengthType);

	public:
	DD_ALIAS(Iterator, PointerType);
	DD_ALIAS(ConstIterator, ConstPointerType);
	DD_ITERATOR_NESTED


	protected:
	PointerType m_begin_ DD_IN_CLASS_INITIALIZE(PointerType());
	PointerType m_end_ DD_IN_CLASS_INITIALIZE(PointerType());
	PointerType m_storage_end_ DD_IN_CLASS_INITIALIZE(PointerType());


	protected:
	DD_CONSTEXPR VesselBase_() DD_NOEXCEPT : m_begin_(), m_end_(), m_storage_end_() {
	}

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(VesselBase_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(VesselBase_)

	protected:
	DD_CONSTEXPR VesselBase_(UnguardedTag tag_) DD_NOEXCEPT {
	}

	protected:
	DD_CONSTEXPR VesselBase_(UnguardedTag tag_, PointerType begin_) DD_NOEXCEPT : m_begin_(begin_) {
	}

#	if __cplusplus >= 201103L
	protected:
	constexpr VesselBase_(
		PointerType begin_,
		LengthType length_
	) noexcept : VesselBase_(begin_, length_, length_) {
	}

	protected:
	constexpr VesselBase_(
		PointerType begin_,
		LengthType length_,
		LengthType capacity_
	) noexcept : VesselBase_(begin_, begin_ + length_, begin_ + capacity_) {
	}

	protected:
	constexpr VesselBase_(
		PointerType begin_,
		PointerType end_
	) noexcept : VesselBase_(begin_, end_, end_) {
	}
#	else
	protected:
	VesselBase_(
		PointerType begin_,
		LengthType length_
	) throw() : m_begin_(begin_), m_end_(m_begin_ + length_), m_storage_end_(m_end_) {
	}

	protected:
	VesselBase_(
		PointerType begin_,
		LengthType length_,
		LengthType capacity_
	) throw() : m_begin_(begin_), m_end_(m_begin_ + length_), m_storage_end_(m_begin_ + capacity_) {
	}

	protected:
	VesselBase_(
		PointerType begin_,
		PointerType end_
	) throw() : m_begin_(begin_), m_end_(end_), m_storage_end_(m_end_) {
	}
#	endif

	protected:
	DD_CONSTEXPR VesselBase_(
		PointerType begin_,
		PointerType end_,
		PointerType storage_end_
	) DD_NOEXCEPT : m_begin_(begin_), m_end_(end_), m_storage_end_(storage_end_) {
	}


	protected:
#	if __cplusplus >= 201103L
	~VesselBase_() = default;
#	else
	~VesselBase_() throw() {
	}
#	endif


	public:
	Iterator begin() DD_NOEXCEPT {
		return Iterator(m_begin_);
	}

	public:
	ConstIterator begin() const DD_NOEXCEPT {
		return Iterator(m_begin_);
	}


	public:
	Iterator end() DD_NOEXCEPT {
		return Iterator(m_begin_);
	}

	public:
	ConstIterator end() const DD_NOEXCEPT {
		return Iterator(m_begin_);
	}


	public:
	DD_RANGE_NESTED


	public:
	ReverseIterator rbegin() DD_NOEXCEPT {
		return ReverseIterator(m_end_ - 1);
	}

	public:
	ConstReverseIterator rbegin() const DD_NOEXCEPT {
		return ReverseIterator(m_end_ - 1);
	}


	public:
	ReverseIterator rend() DD_NOEXCEPT {
		return ReverseIterator(begin() - 1);
	}

	public:
	ConstReverseIterator rend() const DD_NOEXCEPT {
		return ReverseIterator(begin() - 1);
	}


	public:
	DD_REVERSE_RANGE_NESTED


	public:
	Iterator storage_end() DD_NOEXCEPT {
		return m_storage_end_;
	}

	public:
	ConstIterator storage_end() const DD_NOEXCEPT {
		return m_storage_end_;
	}


	public:
	ConstIterator storage_cend() const DD_NOEXCEPT {
		return m_storage_end_;
	}


	public:
	LengthType get_length() const DD_NOEXCEPT {
		return length_difference(begin(), end());
	}


	public:
	LengthType get_capacity() const DD_NOEXCEPT {
		return length_difference(begin(), storage_end());
	}


	public:
	ValidityType is_empty() const DD_NOEXCEPT {
		return begin() == end();
	}


	public:
	ValidityType is_full() const DD_NOEXCEPT {
		return end() == storage_end();
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return begin() < storage_cend();
	}


	public:
	ReferenceType front() DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Vessel::front' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return *begin();
	}

	public:
	ConstReferenceType front() const DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Vessel::front' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return *begin();
	}


	public:
	ReferenceType back() DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Vessel::back' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return end()[-1];
	}

	public:
	ConstReferenceType back() const DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Vessel::back' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return end()[-1];
	}


	public:
	ReferenceType at(LengthType index_) DD_NOEXCEPT {
		Iterator temp_ = begin() + index_;
		if (temp_ >= end()) {
			throw AccessDenied("'DD::Vessel::at' in " __FILE__ " at " DD_TO_STRING(__LINE__));
		}
		return *temp_;
	}

	public:
	ConstReferenceType at(LengthType index_) const DD_NOEXCEPT {
		ConstIterator temp_ = begin() + index_;
		if (temp_ >= end()) {
			throw AccessDenied("'DD::Vessel::at' in " __FILE__ " at " DD_TO_STRING(__LINE__));
		}
		return *temp_;
	}


	public:
	DD_DELETE_ALL_ASSIGNMENTS(VesselBase_)


	public:
	ReferenceType operator [](LengthType index_) DD_NOEXCEPT {
		return begin()[index_];
	}

	public:
	ConstReferenceType operator [](LengthType index_) const DD_NOEXCEPT {
		return begin()[index_];
	}


};



template <typename ValueT_, typename AllocatorT_, ValidityType need_instance_c_>
struct Vessel_ : VesselBase_<ValueT_> {
	public:
	DD_ALIAS(SuperType, VesselBase_<ValueT_>);
	DD_ALIAS(ThisType, Vessel_<ValueT_ DD_COMMA AllocatorT_ DD_COMMA need_instance_c_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(AllocatorType, AllocatorT_);

	public:
	DD_ALIAS(SizeType, DD::SizeType);
	DD_ALIAS(LengthType, DD::LengthType);

	public:
	DD_ALIAS(Iterator, PointerType);
	DD_ALIAS(ConstIterator, ConstPointerType);
	DD_ITERATOR_NESTED


	public:
#	if __cplusplus >= 201103L
	constexpr Vessel_() = default;
#	else
	Vessel_() throw() {
	}
#	endif

	public:
	Vessel_(ThisType const& origin_) : SuperType(unguarded_tag, AllocatorType::allocate(origin_.get_length())) {
		try {
			this->m_end_ = copy(origin_, this->begin());
		} catch (...) {
			AllocatorType::deallocate(this->m_begin_, this->get_length());
			throw;
		}
	}

#	if __cplusplus >= 201103L
	public:
	constexpr Vessel_(ThisType&& origin_) DD_NOEXCEPT : SuperType(
		release(origin_.m_begin_),
		release(origin_.m_end_),
		release(origin_.m_storage_end_)
	) {
	}

#	endif

	public:
	~Vessel_() DD_NOEXCEPT {
		destruct_();
	}


	public:
	ProcessType stretch(LengthType new_capacity_) {
		PointerType temp_begin_ = AllocatorType::allocate(new_capacity_);
		PointerType temp_end_;
		try {
			temp_end_ = transconstruct(this->m_begin_, this->m_end_, temp_begin_);
		} catch (...) {
			AllocatorType::deallocate(temp_begin_, new_capacity_);
		}
		destruct_();
		this->m_begin_ = temp_begin_;
		this->m_end_ = temp_end_;
		this->m_storage_end_ = temp_begin_ + new_capacity_;
	}


	public:
	ProcessType reserve() noexcept(noexcept(ThisType().reserve(LengthType()))) {
		LengthType capacity_ = this->get_capacity();
		if (capacity_) {
			try {
				stretch(capacity_ * 2);
			} catch (AllocationFailure& error_) {
				stretch(capacity_ + 1);
			}
		} else {
			stretch(1);
		}
	}


	public:
	ProcessType reserve(LengthType new_capacity_) noexcept(noexcept(ThisType().stretch())) {
		if (new_capacity_ > this->get_length()) {
			stretch(new_capacity_);
		}
	}


	public:
	static ProcessType transfer(Iterator from_, Iterator to_) {
#	if __cplusplus >= 201103L
		ValueType temp_(move(*from_));
		move(ReverseIterator(from_ - 1), ReverseIterator(to_), ReverseIterator(from_));
		*to_ = move(temp_);
#	else
		ValueType temp_ = *from_;
		copy(ReverseIterator(from_ - 1), ReverseIterator(to_), ReverseIterator(from_));
		*to_ = temp_;
#	endif
	}


	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ProcessType push_back(ValueT__&& value___) {
		if (this->is_full()) {
			reserve();
		}
		AllocatorType::construct(this->m_end_, forward<ValueT__>(value___));
		++this->m_end_;
	}
#	else
	ProcessType push_back(ValueT__ const& value___) {
		if (this->is_full()) {
			reserve();
		}
		AllocatorType::construct(this->m_end_, value___);
		++this->m_end_;
	}
#	endif


	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ProcessType insert(Iterator position_, ValueT__&& value__) {
#	else
	ProcessType insert(Iterator position_, ValueT__ const& value__) {
#	endif
		if (this->is_full()) {
			reserve();
		}
#	if __cplusplus >= 201103L
		push_back(forward<ValueT__>(value__));
#	else
		push_back(value__);
#	endif
		transfer(this->end(), position_);
	}


	public:
	ProcessType clear() DD_NOEXCEPT {
		destruct_();
		this->m_begin_ = PointerType();
		this->m_end_ = PointerType();
		this->m_storage_end_ = PointerType();
	}


	public:
	ProcessType shrink() DD_NOEXCEPT_AS(fabricate<ThisType>().stretch(fabricate<ThisType>().get_length())) {
		stretch(this->get_length());
	}


	private:
	ProcessType destruct_() const DD_NOEXCEPT {
		AllocatorType::destruct(this->m_begin_, this->m_end_);
		AllocatorType::deallocate(this->m_begin_, this->get_capacity());
	}


};



template <typename ValueT_, typename AllocatorT_>
struct Vessel_<ValueT_, AllocatorT_, true> : VesselBase_<ValueT_> {
};



template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
struct Vessel : detail_::Vessel_<ValueT_, AllocatorT_, NeedInstance<AllocatorT_>::value> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Vessel;



DD_END_



#endif
