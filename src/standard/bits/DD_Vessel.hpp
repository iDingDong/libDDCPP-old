//	DDCPP/standard/bits/DD_Vessel.hpp
#ifndef DD_VESSEL_HPP_INCLUDED_
#	define DD_VESSEL_HPP_INCLUDED_ 1



#	include "DD_NeedInstance.hpp"
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
#	if __cplusplus >= 201103L
	constexpr VesselBase_() = default;
#	else
	VesselBase_() throw() : m_begin_(), m_end_(), m_storage_end_() {
	}
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(VesselBase_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(VesselBase_)

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
	DD_ALIAS(ThisType, Vessel_<ValueT_ DD_COMMA AllocatorT_ DD_COMMA need_instance_c_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(AllocatorType, AllocatorT_);

	public:
	DD_ALIAS(SizeType, DD::SizeType);
	DD_ALIAS(LengthType, DD::LengthType);


	public:
#	if __cplusplus >= 201103L
	constexpr Vessel_() = default;
#	else
	Vessel_() throw() {
	}
#	endif


	public:
	ProcessType stretch(LengthType new_capacity_) {
		PointerType temp_begin_ = AllocatorType::allocate(new_capacity_);
		PointerType temp_end_ = transconstruct(this->m_begin_, this->m_end_, temp_begin_);
		destruct();
		this->m_begin_ = temp_begin_;
		this->m_end_ = temp_end_;
		this->m_storage_end_ = temp_begin_ + new_capacity_;
	}


	public:
	ProcessType reserve() noexcept(noexcept(ThisType().reserve(LengthType()))) {
		LengthType capacity_ = this->get_capacity();
		if (capacity_) {
			reserve(capacity_ * 2);
		} else {
			reserve(1);
		}
	}


	public:
	ProcessType reserve(LengthType new_capacity_) noexcept(noexcept(ThisType().stretch())) {
		if (new_capacity_ > this->get_length()) {
			stretch(new_capacity_);
		}
	}


	private:
	ProcessType destruct() const DD_NOEXCEPT {
		AllocatorType::destruct(this->begin(), this->end());
		AllocatorType::deallocate(this->begin(), this->get_capacity());
	}


};



template <typename ValueT_, typename AllocatorT_>
struct Vessel_<ValueT_, AllocatorT_, true> : VesselBase_<ValueT_> {
};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
using Vessel = detail_::Vessel_<ValueT_, AllocatorT_, NeedInstance<AllocatorT_>::value>;
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
struct Vessel : detail_::Vessel_<ValueT_, AllocatorT_, NeedInstance<AllocatorT_>::value> {
};
#	endif



DD_END_



#endif
