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
DD_STATIC_ASSERT((DDCPP_VESSEL_GROWTH_RATIO) > 1, "'DDCPP_VESSEL_GROWTH_RATIO' should be defined greater than 1");



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

#	endif

#	if __cplusplus >= 201103L
	public:
	Vessel_(ThisType& origin_) : ThisType(static_cast<ThisType const&>(origin_)) {
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

#	endif

	public:
	DD_CONSTEXPR Vessel_(ReserveTag tag, LengthType length_) DD_NOEXCEPT_AS(
		SuperType(length_ > 0 ? AllocatorType::allocate(length_) : PointerType() DD_COMMA 0 DD_COMMA length_)
	) : SuperType(length_ > 0 ? AllocatorType::allocate(length_) : PointerType(), 0, length_) {
	}

	public:
	template <typename UndirectionalIteratorT__>
	Vessel_(UndirectionalIteratorT__ begin___, LengthType length_) DD_NOEXCEPT_IF(
		noexcept(length_ > 0 ? SuperType(AllocatorType::allocate(length_) DD_COMMA length_) : PointerType()) &&
		noexcept(copy_construct(begin___ DD_COMMA next(begin___ DD_COMMA length_)))
	) : SuperType(length_ > 0 ? AllocatorType::allocate(length_) : PointerType(), length_) {
		copy_construct(begin___, next(begin___, length_));
	}

	public:
	template <typename UndirectionalIteratorT__>
	Vessel_(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) DD_NOEXCEPT_IF(
		noexcept(SuperType()) &&
		noexcept(AllocatorType::allocate(length_difference(begin___ DD_COMMA end___))) &&
		noexcept(copy_construct(begin___ DD_COMMA end___ DD_COMMA fabricate<ThisType>().begin()))
	) : SuperType() {
		LengthType length_ = length_difference(begin___, end___);
		if (length_ > 0) {
			this->m_begin_ = AllocatorType::allocate(length_difference(begin___, end___));
			this->m_end_ = get_pointer(copy_construct(begin___, end___, this->begin()));
			this->m_storage_end_ = get_pointer(this->end());
		} else {
			this->m_begin_ = PointerType();
			this->m_end_ = PointerType();
			this->m_storage_end_ = PointerType();
		}
	}

	public:
	template <typename UndirectionalRangeT__>
	Vessel_(UndirectionalRangeT__& range___) : SuperType() {
		clone(range___);
	}

#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	Vessel_(BatchTag tag_, LengthType length_, ArgumentsT__ const&... arguments___) DD_NOEXCEPT_IF(
		noexcept(AllocatorType::allocate(length_)) && noexcept(fabricate<ThisType>().unguarded_emplace_back(arguments___...))
	) : SuperType(length_ > 0 ? AllocatorType::allocate(length_) : PointerType(), 0, length_) {
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
	Vessel_(BatchTag tag_, LengthType length_) : SuperType(length_ > 0 ? AllocatorType::allocate(length_) : PointerType(), 0, length_) {
		try {
			while (!this->is_full()) {
				unguarded_push_back(ValueType());
			}
		} catch (...) {
			destruct_();
			throw;
		}
	}

	public:
	template <typename ValueT__>
	Vessel_(
		BatchTag tag_,
		LengthType length_,
		ValueT__ const& value___
	) : SuperType(length_ > 0 ? AllocatorType::allocate(length_) : PointerType(), 0, length_) {
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
	~Vessel_() DD_NOEXCEPT {
		destruct_();
	}


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		::DD::swap(this->m_begin_, other_.m_begin_);
		::DD::swap(this->m_end_, other_.m_end_);
		::DD::swap(this->m_storage_end_, other_.m_storage_end_);
	}


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType clone(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) {
		Pair<UndirectionalIteratorT__, Iterator> result_ = ::DD::copy(begin___, end___, this->begin(), this->end());
		if (result_.first != end___) {
			concatenate(result_.first, end___);
		} else {
			trim_back(result_.second);
		}
	}


	public:
	template <typename UndirectionalRangeT__>
	ProcessType clone(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(fabricate<ThisType>().clone(DD_SPLIT_RANGE(range___))) {
		clone(DD_SPLIT_RANGE(range___));
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
				stretch(capacity_ * (DDCPP_VESSEL_GROWTH_RATIO));
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
		DD_ASSERT(!this->is_empty(), "Failed to pop from empty container: 'DD::Vessel::pop_front'.");
		erase(this->begin());
	}


	public:
	ProcessType pop_back() DD_NOEXCEPT {
		DD_ASSERT(!this->is_empty(), "Failed to pop from empty container: 'DD::Vessel::pop_back'.");
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
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_concatenate(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) DD_NOEXCEPT_AS(
		::DD::get_pointer(::DD::copy_construct(begin___ DD_COMMA end___ DD_COMMA fabricate<ThisType>().end()))
	) {
		this->m_end_ = ::DD::get_pointer(::DD::copy_construct(begin___, end___, this->end()));
	}


	public:
	public:
	template <typename UndirectionalRangeT__>
	ProcessType unguarded_concatenate(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(
		fabricate<ThisType>().unguarded_concatenate(DD_SPLIT_RANGE(range___))
	) {
		unguarded_concatenate(DD_SPLIT_RANGE(range___));
	}


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType concatenate(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) {
		reserve(this->get_length() + ::DD::length_difference(begin___, end___));
		unguarded_concatenate(begin___, end___);
	}


	public:
	template <typename UndirectionalRangeT__>
	ProcessType concatenate(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(
		fabricate<ThisType>().concatenate(DD_SPLIT_RANGE(range___))
	) {
		concatenate(DD_SPLIT_RANGE(range___));
	}


	public:
	ProcessType trim_back(Iterator new_end_) DD_NOEXCEPT {
		AllocatorType::destruct(new_end_, this->end());
		this->m_end_ = ::DD::get_pointer(new_end_);
	}


	public:
	ProcessType erase(Iterator position_) {
		DD_ASSERT(::DD::check_bound(*this, position_), "Invalid iterator dereferenced: 'DD::Vessel::erase'");
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


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType add(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) {

	}


	private:
	ProcessType destruct_() const DD_NOEXCEPT {
		AllocatorType::destruct(this->m_begin_, this->m_end_);
		AllocatorType::deallocate(this->m_begin_, this->get_capacity());
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT_AS(fabricate<ThisType>().clone(origin_)) {
		clone(origin_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT_AS(fabricate<ThisType>().swap(origin_)) {
		swap(origin_);
		return *this;
	}

#	endif

	public:
	template <typename UndirectionalRangeT__>
	ThisType& operator =(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(fabricate<ThisType>().clone(range___)) {
		clone(range___);
		return *this;
	}


	public:
	template <typename UndirectionalRangeT__>
	ThisType& operator +=(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(fabricate<ThisType>().concatenate(range___)) {
		concatenate(range___);
		return *this;
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
	using SuperType::SuperType;
#	else
	public:
	Vessel() {
	}

	public:
	Vessel(LengthType length_) : SuperType(length_) {
	}

	public:
	Vessel(ReverseTag_ tag_, LengthType length_) : SuperType(tag_, length_) {
	}

	public:
	template <typename UndirectionalIteratorT_>
	Vessel(UndirectionalIteratorT_ begin__, UndirectionalIteratorT_ end__) : SuperType(begin__, end__) {
	}

	public:
	template <typename UndirectionalRangeT_>
	Vessel(UndirectionalRangeT_& range__) : SuperType(range__) {
	}

	public:
	Vessel(BatchTag tag_, LengthType length_) : SuperType(tag_, length_) {
	}

	public:
	template <typename ValueT__>
	Vessel(BatchTag tag_, LengthType length_, ValueT__ const& value___) : SuperType(tag_, length_, value___) {
	}
#	endif


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT_AS(fabricate<ThisType>().SuperType::swap(other_)) {
		SuperType::swap(other_);
	}


	public:
	using SuperType::operator =;


};



template <typename ValueT_, typename AllocatorT_>
inline Vessel<ValueT_, AllocatorT_> DD_CONSTEXPR operator +(
	Vessel<ValueT_, AllocatorT_> const& vessel_1_,
	Vessel<ValueT_, AllocatorT_> const& vessel_2_
) {
	Vessel<ValueT_, AllocatorT_> result_(reserve_tag, vessel_1_.get_length() + vessel_2_.get_length());
	result_.unguarded_concatenate(vessel_1_, vessel_2_);
	return result_;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::Vessel;



DD_END_



#endif
