//	DDCPP/standard/bits/DD_Vessel.hpp
#ifndef DD_VESSEL_HPP_INCLUDED_
#	define DD_VESSEL_HPP_INCLUDED_ 1



#	include "DD_debugger_definitions.hpp"
#	include "DD_Tags.hpp"
#	include "DD_NeedInstance.hpp"
#	include "DD_fabricate.hpp"
#	include "DD_IteratorNested.hpp"
#	include "DD_length_difference.hpp"
#	include "DD_release.hpp"
#	include "DD_AccessDenied.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_InitializerList.hpp"
#	include "DD_get_pointer.hpp"
#	include "DD_check_bound.hpp"
#	include "DD_transconstruct.hpp"
#	include "DD_transfer.hpp"
#	if __cplusplus >= 201103L
#		include "DD_copy.hpp"
#	endif
#	include "DD_copy_construct.hpp"



#	if !defined(DDCPP_VESSEL_GROWTH_RATIO)
#		define DDCPP_VESSEL_GROWTH_RATIO 2
#	endif



DD_DETAIL_BEGIN_
DD_STATIC_ASSERT(DDCPP_VESSEL_GROWTH_RATIO > 1, "'DDCPP_VESSEL_GROWTH_RATIO' should be defined greater than 1");



struct RangeTag {
} DD_CONSTANT range_tag;



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
		return Iterator(m_end_);
	}

	public:
	ConstIterator end() const DD_NOEXCEPT {
		return Iterator(m_end_);
	}


	public:
	DD_RANGE_NESTED


	public:
	ReverseIterator rbegin() DD_NOEXCEPT {
		return ReverseIterator(end() - 1);
	}

	public:
	ConstReverseIterator rbegin() const DD_NOEXCEPT {
		return ReverseIterator(end() - 1);
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
	ConstIterator cstorage_end() const DD_NOEXCEPT {
		return m_storage_end_;
	}


	public:
	PointerType data() DD_NOEXCEPT {
		return m_begin_;
	}

	public:
	ConstPointerType DD_CONSTEXPR data() const DD_NOEXCEPT {
		return m_begin_;
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
		return begin() < cstorage_end();
	}


	public:
	ReferenceType front() DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Vessel::front'");
		return *begin();
	}

	public:
	ConstReferenceType front() const DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Vessel::front'");
		return *begin();
	}


	public:
	ReferenceType back() DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Vessel::back'");
		return *(end() - 1);
	}

	public:
	ConstReferenceType back() const DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Out of range: 'DD::Vessel::back'");
		return *(end() - 1);
	}


	public:
	ReferenceType at(LengthType index_) DD_NOEXCEPT {
		Iterator temp_ = begin() + index_;
		if (check_bound(*this, temp_)) {
			return *temp_;
		}
		throw AccessDenied("Out of range: 'DD::Vessel::at'");
	}

	public:
	ConstReferenceType at(LengthType index_) const DD_NOEXCEPT {
		ConstIterator temp_ = begin() + index_;
		if (check_bound(*this, temp_)) {
			return *temp_;
		}
		throw AccessDenied("Out of range: 'DD::Vessel::at'");
	}


	public:
	DD_DELETE_ALL_ASSIGNMENTS(VesselBase_)


	public:
	ReferenceType operator [](LengthType index_) DD_NOEXCEPT {
		DD_ASSERT(check_bound(*this, begin() + index_), "Out of range: 'DD::Vessel::operator []'");
		return *(begin() + index_);
	}

	public:
	ConstReferenceType operator [](LengthType index_) const DD_NOEXCEPT {
		DD_ASSERT(check_bound(*this, begin() + index_), "Out of range: 'DD::Vessel::operator []'");
		return (*begin() + index_);
	}


	public:
	ValidityType DD_CONSTEXPR operator !() const DD_NOEXCEPT {
		return is_empty();
	}


#	if __cplusplus >= 201103L
	public:
	explicit constexpr operator ValidityType() const DD_NOEXCEPT {
		return begin() != end();
	}


#	endif
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
			this->m_end_ = copy_construct(origin_, this->begin());
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

	public:
	template <typename ValueT__>
	Vessel_(InitializerList<ValueT__> initializer) noexcept(
		noexcept(AllocatorType::allocate(initializer.size())) && noexcept(fabricate<ThisType>().unguarded_push_back(fabricate<ValueT__>()))
	) : SuperType(AllocatorType::allocate(initializer.size()), 0, initializer.size()) {
		try {
			for (auto const& value_ : initializer) {
				unguarded_push_back(value_);
			}
		} catch (...) {
			destruct_();
			throw;
		}
	}

	public:
	template <typename... ArgumentsT__>
	Vessel_(LengthType length_, ArgumentsT__ const&... arguments___) DD_NOEXCEPT_IF(
		noexcept(AllocatorType::allocate(length_)) && noexcept(fabricate<ThisType>().unguarded_emplace_back(arguments___...))
	) : SuperType(AllocatorType::allocate(length_), 0, length_) {
		try {
			while (!this->is_full()) {
				unguarded_emplace_back(arguments___...);
			}
		} catch (...) {
			destruct_();
			throw;
		}
	}
#	else
	public:
	template <typename ValueT__>
	Vessel_(LengthType length_, ValueT__ const& value___) : SuperType(AllocatorType::allocate(length_), 0, length_) {
		try {
			while (!this->is_full()) {
				unguarded_push_back(value___);
			}
		} catch (...) {
			destruct_();
			throw;
		}
	}
#	endif

	public:
	template <typename UndirectionalIteratorT__>
	Vessel_(RangeTag tag, UndirectionalIteratorT__ begin___, LengthType length_) DD_NOEXCEPT_IF(
		noexcept(SuperType(AllocatorType::allocate(length_) DD_COMMA length_)) &&
		noexcept(copy_construct(begin___ DD_COMMA next(begin___ DD_COMMA length_)))
	) : SuperType(AllocatorType::allocate(length_), length_) {
		copy_construct(begin___, next(begin___, length_));
	}

	public:
	template <typename UndirectionalIteratorT__>
	Vessel_(RangeTag tag, UndirectionalIteratorT__ const& begin___, UndirectionalIteratorT__ const& end___) DD_NOEXCEPT_IF(
		noexcept(SuperType()) &&
		noexcept(AllocatorType::allocate(length_difference(begin___ DD_COMMA end___))) &&
		noexcept(copy_construct(begin___ DD_COMMA end___ DD_COMMA fabricate<ThisType>().begin()))
	) : SuperType() {
		this->m_begin_ = AllocatorType::allocate(length_difference(begin___, end___));
		this->m_end_ = get_pointer(copy_construct(begin___, end___, this->begin()));
		this->m_storage_end_ = get_pointer(this->end());
	}


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
				stretch(capacity_ * DDCPP_VESSEL_GROWTH_RATIO);
			} catch (AllocationFailure& error_) {
				stretch(capacity_ + 1);
			}
		} else {
			stretch(1);
		}
	}


	public:
	ProcessType reserve(LengthType new_capacity_) noexcept(noexcept(fabricate<ThisType>().stretch(new_capacity_))) {
		if (new_capacity_ > this->get_length()) {
			stretch(new_capacity_);
		}
	}


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	ProcessType unguarded_emplace_back(ArgumentsT__&&... arguments___) noexcept(
		noexcept(AllocatorType::construct(fabricate<ThisType>().m_end_, forward<ArgumentsT__>(arguments___)...))
	) {
		DD_ASSERT(!this->is_full(), "Failed to insert into a full container: 'DD::Vessel::unguarded_emplace_back'");
		AllocatorType::construct(this->m_end_, forward<ArgumentsT__>(arguments___)...);
		++this->m_end_;
	}


	public:
	template <typename... ArgumentsT__>
	ProcessType emplace_back(ArgumentsT__&&... arguments___) noexcept(
		noexcept(fabricate<ThisType>().reserve()) &&
		noexcept(fabricate<ThisType>().unguarded_emplace_back(forward<ArgumentsT__>(arguments___)...))
	) {
		if (this->is_full()) {
			reserve();
		}
		unguarded_emplace_back(forward<ArgumentsT__>(arguments___)...);
	}


#	endif
	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ProcessType push_front(ValueT__&& value__) noexcept(
		noexcept(fabricate<ThisType>(insert(fabricate<ThisType>().begin(), forward<ValueT__>(value__))))
	) {
		insert(this->begin(), forward<ValueT__>(value__));
	}
#	else
	ProcessType push_front(ValueT__&& value__) {
		insert(this->begin(), value__);
	}
#	endif


	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ProcessType unguarded_push_back(ValueT__&& value___) noexcept(
		noexcept(fabricate<ThisType>().unguarded_emplace_back(forward<ValueT__>(value___)))
	) {
		DD_ASSERT(!this->is_full(), "Failed to insert into a full container: 'DD::Vessel::unguarded_push_back'");
		unguarded_emplace_back(forward<ValueT__>(value___));
	}
#	else
	ProcessType unguarded_push_back(ValueT__ const& value___) {
		DD_ASSERT(!this->is_full(), "Failed to insert into a full container: 'DD::Vessel::unguarded_push_back'");
		AllocatorType::construct(this->m_end_, value___);
		++this->m_end_;
	}
#	endif


	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ProcessType push_back(ValueT__&& value___) noexcept(
		noexcept(fabricate<ThisType>().emplace_back(forward<ValueT__>(value___)))
	) {
		emplace_back(forward<ValueT__>(value___));
	}
#	else
	ProcessType push_back(ValueT__ const& value___) {
		if (this->is_full()) {
			reserve();
		}
		unguarded_push_back(value___);
	}
#	endif


	public:
	ProcessType pop_front() DD_NOEXCEPT_AS(fabricate<ThisType>().begin()) {
		DD_ASSERT(!is_empty(), "Failed to pop from empty container: 'DD::Vessel::pop_front'.");
		erase(this->begin());
	}


	public:
	ProcessType pop_back() DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Failed to pop from empty container: 'DD::Vessel::pop_back'.");
		AllocatorType::destruct(--this->m_end_);
	}


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
		transfer_backward(this->end() - 1, position_);
	}


	public:
	ProcessType erase(Iterator position_) {
		DD_ASSERT(check_bound(*this, position), "Invalid iterator dereferenced: 'DD::Vessel::erase'");
		transfer_forward(position_, this->end() - 1);
		pop_back();
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
struct Vessel : Vessel_<ValueT_, AllocatorT_, NeedInstance<AllocatorT_>::value> {
	public:
	DD_ALIAS(SuperType, Vessel_<ValueT_ DD_COMMA AllocatorT_ DD_COMMA NeedInstance<AllocatorT_>::value>);
	DD_ALIAS(ThisType, Vessel<ValueT_ DD_COMMA AllocatorT_>);


#	if __cplusplus >= 201103L
	public:
	constexpr Vessel() = default;

	public:
	constexpr Vessel(ThisType const& origin_) = default;

	public:
	constexpr Vessel(ThisType&& origin_) = default;

	public:
	template <typename ValueT__>
	constexpr Vessel(InitializerList<ValueT__> initializer) noexcept(noexcept(SuperType(initializer))) : SuperType(initializer) {
	}

	public:
	template <typename... ArgumentsT__>
	constexpr Vessel(LengthType length_, ArgumentsT__ const&... arguments___) noexcept(
		noexcept(SuperType(length_, arguments___...))
	) : SuperType(length_, arguments___...) {
	}
#	else
	public:
	Vessel() {
	}

	public:
	template <typename ValueT__>
	Vessel(LengthType length_, ValueT__ const& value___) : SuperType(length_, value___) {
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	~Vessel() = default;


#	endif
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::RangeTag;
using detail_::Vessel;

using detail_::range_tag;



DD_END_



#endif
