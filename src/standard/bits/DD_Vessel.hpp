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
#	include "DD_Allocateable.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_InitializerList.hpp"
#	include "DD_BatchRange.hpp"
#	include "DD_get_pointer.hpp"
#	include "DD_check_bound.hpp"
#	include "DD_transconstruct.hpp"
#	include "DD_copy_length.hpp"
#	include "DD_copy_construct_length.hpp"
#	include "DD_transfer_backward.hpp"
#	if __cplusplus >= 201103L
#		include "DD_move_overlapped_forward.hpp"
#		include "DD_move_overlapped_backward.hpp"
#	else
#		include "DD_copy_overlapped_forward.hpp"
#		include "DD_copy_overlapped_backward.hpp"
#	endif



#	if !defined(DDCPP_VESSEL_GROWTH_RATIO)
#		define DDCPP_VESSEL_GROWTH_RATIO 2
#	endif



DD_DETAIL_BEGIN_
DD_STATIC_ASSERT((DDCPP_VESSEL_GROWTH_RATIO) > 1, "'DDCPP_VESSEL_GROWTH_RATIO' should be defined greater than 1");



template <typename ValueT_>
struct Vessel_ {
	public:
	DD_ALIAS(ThisType, Vessel_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(SizeType, DD::SizeType);
	DD_ALIAS(LengthType, DD::LengthType);

	public:
	DD_ALIAS(Iterator, PointerType);
	DD_ALIAS(ConstIterator, ConstPointerType);
	DD_ITERATOR_NESTED


	protected:
	PointerType m_begin_;
	PointerType m_end_;
	PointerType m_storage_end_;


	protected:
	DD_CONSTEXPR Vessel_() DD_NOEXCEPT : m_begin_(), m_end_(), m_storage_end_() {
	}

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(Vessel_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(Vessel_)

	protected:
	DD_CONSTEXPR Vessel_(UnguardedTag tag_) DD_NOEXCEPT {
	}

	protected:
	DD_CONSTEXPR Vessel_(UnguardedTag tag_, PointerType begin_) DD_NOEXCEPT : m_begin_(begin_) {
	}

#	if __cplusplus >= 201103L
	protected:
	constexpr Vessel_(
		PointerType begin_,
		LengthType length_,
		LengthType capacity_
	) noexcept : Vessel_(begin_, begin_ + length_, begin_ + capacity_) {
	}
#	else
	protected:
	Vessel_(
		PointerType begin_,
		LengthType length_,
		LengthType capacity_
	) throw() : m_begin_(begin_), m_end_(m_begin_ + length_), m_storage_end_(m_begin_ + capacity_) {
	}
#	endif

	protected:
	DD_CONSTEXPR Vessel_(
		PointerType begin_,
		PointerType end_,
		PointerType storage_end_
	) DD_NOEXCEPT : m_begin_(begin_), m_end_(end_), m_storage_end_(storage_end_) {
	}


	protected:
	~Vessel_() DD_NOEXCEPT {
		destruct_();
	}


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
	LengthType DD_CONSTEXPR get_length() const DD_NOEXCEPT {
		return end() - begin();
	}


	public:
	LengthType DD_CONSTEXPR get_capacity() const DD_NOEXCEPT {
		return storage_end() - begin();
	}


	public:
	LengthType DD_CONSTEXPR get_free_space() const DD_NOEXCEPT {
		return storage_end() - end();
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


	protected:
	Iterator transfer_to_(Iterator new_begin_) DD_NOEXCEPT_AS(static_cast<Iterator>(
		::DD::transconstruct(::DD::fabricate<ThisType>().begin(), ::DD::fabricate<ThisType>().end(), new_begin_)
	)) {
		Iterator result_ = ::DD::transconstruct(begin(), end(), new_begin_);
		destruct_();
		return result_;
	}


	private:
	Iterator transfer_to_with_hole_(Iterator position_, Iterator new_begin_, LengthType hole_size_) {
		Iterator pause_point_(::DD::transconstruct(begin(), position_, new_begin_));
		try {
			::DD::transconstruct(position_, end(), pause_point_ + hole_size_);
		} catch (...) {
			::DD::destruct(new_begin_, pause_point_);
			throw;
		}
		destruct_();
		return pause_point_;
	}


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	ProcessType unguarded_emplace_back(ArgumentsT__&&... arguments___) noexcept(
		noexcept(ValueType(::DD::forward<ArgumentsT__>(arguments___)...))
	) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Vessel::unguarded_emplace_back'");
		::DD::construct(end(), ::DD::forward<ArgumentsT__>(arguments___)...);
		++m_end_;
	}


	public:
	template <typename ValueT__>
	ProcessType unguarded_push_back(ValueT__&& value___) noexcept(
		noexcept(::DD::fabricate<ThisType>().unguarded_emplace_back(::DD::forward<ValueT__>(value___)))
	) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Vessel::unguarded_push_back'");
		unguarded_emplace_back(::DD::forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	ProcessType unguarded_push_back(ValueT__ const& value___) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Vessel::unguarded_push_back'");
		::DD::construct(end(), value___);
		++m_end_;
	}
#	endif


#	if __cplusplus >= 201103L
	protected:
	template <typename... ArgumentsT__>
	Iterator transfer_emplace_(Iterator position_, Iterator new_begin_, ArgumentsT__&&... arguments___) {
		DD_ASSERT(position_ >= begin() && position_ <= end(), "Out of range: 'DD::Vessel::unguarded_push_back'");
		::DD::construct(position_ - begin() + new_begin_, ::DD::forward<ArgumentsT__>(arguments___)...);
		try {
			return transfer_to_with_hole_(position_, new_begin_, 1);
		} catch(...) {
			::DD::destruct(position_);
			throw;
		}
	}


	public:
	template <typename... ArgumentsT__>
	Iterator unguarded_emplace(Iterator position_, ArgumentsT__&&... arguments___) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Vessel::unguarded_emplace'");
		DD_ASSERT(position_ >= begin() && position_ <= end(), "Out of range: 'DD::Vessel::unguarded_push_back'");
		if (position_ == end()) {
			unguarded_emplace_back(::DD::forward<ArgumentsT__>(arguments___)...);
		} else {
			unguarded_push_back(::DD::move(back()));
			::DD::move_overlapped_backward(position_, end() - 2, end() - 1);
			*position_ = ValueType(::DD::forward<ArgumentsT__>(arguments___)...);
		}
		return position_;
	}


	protected:
	template <typename ValueT__>
	Iterator transfer_insert_(Iterator position_, Iterator new_begin_, ValueT__&& value___) {
		return transfer_emplace_(position_, new_begin_, ::DD::forward<ValueT__>(value___));
	}


	public:
	template <typename ValueT__>
	Iterator unguarded_insert(Iterator position_, ValueT__&& value___) noexcept(
		noexcept(static_cast<Iterator>(unguarded_emplace(position_, ::DD::forward<ValueT__>(value___))))
	) {
		return unguarded_emplace(position_, ::DD::forward<ValueT__>(value___));
	}
#	else
	protected:
	template <typename ValueT__>
	Iterator transfer_insert_(Iterator position_, Iterator new_begin_, ValueT__ const& value___) {
		DD_ASSERT(position_ >= begin() && position_ <= end(), "Out of range: 'DD::Vessel::unguarded_push_back'");
		::DD::construct(position_, value___);
		try {
			return transfer_to_with_hole_(position_, new_begin_, 1);
		} catch(...) {
			::DD::destruct(position_);
			throw;
		}
	}


	public:
	template <typename... ArgumentsT__>
	Iterator unguarded_insert(Iterator position_, ArgumentsT__&&... arguments___) {
		DD_ASSERT(!is_full(), "Out of range: 'DD::Vessel::unguarded_emplace'");
		DD_ASSERT(position_ >= begin() && position_ <= end(), "Out of range: 'DD::Vessel::unguarded_push_back'");
		if (position_ == end()) {
			unguarded_push_back(value___);
		} else {
			unguarded_push_back(::DD::move(back()));
			::DD::copy_overlapped_backward(position_, end() - 2, end() - 1);
			*position_ = value___;
		}
		return position_;
	}
#	endif


	public:
	ProcessType pop_front() DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().begin()) {
		DD_ASSERT(!is_empty(), "Failed to pop from empty container: 'DD::Vessel::pop_front'.");
		erase(begin());
	}


	public:
	ProcessType pop_back() DD_NOEXCEPT {
		DD_ASSERT(!is_empty(), "Failed to pop from empty container: 'DD::Vessel::pop_back'.");
		::DD::destruct(--m_end_);
	}


	public:
	ProcessType trim_front(Iterator end_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().erase_range(::DD::fabricate<ThisType>().begin() DD_COMMA end_)
	) {
		erase_range(begin(), end_);
	}


	public:
	ProcessType trim_back(Iterator begin_) DD_NOEXCEPT {
		::DD::destruct(begin_, end());
		m_end_ = ::DD::get_pointer(begin_);
	}


	public:
	ProcessType erase(Iterator position_) {
		DD_ASSERT(::DD::check_bound(*this, position_), "Invalid iterator dereferenced: 'DD::Vessel::erase'");
		::DD::move_overlapped_forward(position_ + 1, end(), position_);
		pop_back();
	}


	public:
	ProcessType erase_range(Iterator begin_, Iterator end_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().trim_back(move_overlapped_forward(end_ DD_COMMA ::DD::fabricate<ThisType>().end() DD_COMMA begin_))
	) {
#	if __cplusplus >= 201103L
		trim_back(::DD::move_overlapped_forward(end_, end(), begin_));
#	else
		trim_back(::DD::copy_overlapped_forward(end_, end(), begin_));
#	endif
	}


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		::DD::destruct(begin(), end());
	}


	public:
	DD_DELETE_ALL_ASSIGNMENTS(Vessel_)


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



#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
#	endif
struct Vessel : Allocateable<AllocatorT_>, Vessel_<ValueT_> {
	public:
	DD_ALIAS(AllocateAgent, Allocateable<AllocatorT_>);
	DD_ALIAS(SuperType, Vessel_<ValueT_>);
	DD_ALIAS(ThisType, Vessel<ValueT_ DD_COMMA AllocatorT_>);
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
	constexpr Vessel() = default;
#	else
	Vessel() throw() {
	}
#	endif

	public:
	Vessel(ThisType const& origin_) : SuperType(unguarded_tag, AllocateAgent::allocate(origin_.get_length())) {
		try {
			this->m_end_ = copy_construct(origin_, this->begin());
		} catch (...) {
			AllocateAgent::deallocate(this->m_begin_, this->get_length());
			throw;
		}
	}

#	if __cplusplus >= 201103L
	public:
	constexpr Vessel(ThisType&& origin_) noexcept(
		noexcept(AllocateAgent(::DD::move(origin_)))
	) : AllocateAgent(::DD::move(origin_)), SuperType(
		release(origin_.m_begin_),
		release(origin_.m_end_),
		release(origin_.m_storage_end_)
	) {
	}

#	endif

	public:
	Vessel(AllocatorType const& allocator_) DD_NOEXCEPT_AS(AllocateAgent(allocator_)) : AllocateAgent(allocator_) {
	}

#	if __cplusplus >= 201103L
	public:
	Vessel(InitializerList<ValueType> initializer_) noexcept(
		noexcept(AllocateAgent()) &&
		noexcept(::DD::fabricate<ThisType>().clone_initialize_(initializer_))
	) : SuperType(unguarded_tag) {
		clone_initialize_(initializer_);
	}

	public:
	Vessel(AllocatorType const& allocator_, InitializerList<ValueType> initializer_) noexcept(
		noexcept(AllocateAgent(allocator_)) &&
		noexcept(::DD::fabricate<ThisType>().clone_initialize_(initializer_))
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(initializer_);
	}

#	endif
	public:
	DD_CONSTEXPR Vessel(
		ReserveTag tag,
		LengthType length_
	) : SuperType(length_ > 0 ? AllocateAgent::allocate(length_) : PointerType(), 0, length_) {
	}

	public:
	DD_CONSTEXPR Vessel(
		AllocatorType const& allocator_,
		ReserveTag tag,
		LengthType length_
	) : AllocateAgent(allocator_), SuperType(length_ > 0 ? AllocateAgent::allocate(length_) : PointerType(), 0, length_) {
	}

	public:
	template <typename UndirectionalIteratorT__>
	Vessel(UndirectionalIteratorT__ begin___, LengthType length_) DD_NOEXCEPT_IF(
		noexcept(AllocateAgent()) &&
		noexcept(::DD::fabricate<ThisType>().clone_initialize_(begin___ DD_COMMA length_))
	) : SuperType(unguarded_tag) {
		clone_initialize_(begin___, length_);
	}

	public:
	template <typename UndirectionalIteratorT__>
	Vessel(AllocatorType const& allocator_, UndirectionalIteratorT__ begin___, LengthType length_) DD_NOEXCEPT_IF(
		noexcept(AllocateAgent(allocator_)) &&
		noexcept(::DD::fabricate<ThisType>().clone_initialize_(begin___ DD_COMMA length_))
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(begin___, length_);
	}

	public:
	template <typename UndirectionalIteratorT__>
	Vessel(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) DD_NOEXCEPT_IF(
		noexcept(AllocateAgent()) &&
		noexcept(::DD::fabricate<ThisType>().clone_initialize_(begin___ DD_COMMA end___))
	) : SuperType(unguarded_tag) {
		clone_initialize_(begin___, end___);
	}

	public:
	template <typename UndirectionalIteratorT__>
	Vessel(AllocatorType const& allocator_, UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) DD_NOEXCEPT_IF(
		noexcept(AllocateAgent(allocator_)) &&
		noexcept(::DD::fabricate<ThisType>().clone_initialize_(begin___ DD_COMMA end___))
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(begin___, end___);
	}

	public:
	template <typename UndirectionalRangeT__>
	Vessel(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_IF(
		noexcept(AllocateAgent()) &&
		noexcept(::DD::fabricate<ThisType>().clone_initialize_(range___))
	) : SuperType(unguarded_tag) {
		clone_initialize_(range___);
	}

	public:
	template <typename UndirectionalRangeT__>
	Vessel(AllocatorType const& allocator_, UndirectionalRangeT__ const& range___) DD_NOEXCEPT_IF(
		noexcept(AllocateAgent(allocator_)) &&
		noexcept(::DD::fabricate<ThisType>().clone_initialize_(range___))
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(range___);
	}

#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	Vessel(BatchTag tag_, LengthType length_, ArgumentsT__ &&... arguments___) : SuperType(unguarded_tag) {
		clone_initialize_(BatchRange<ValueType>{ ValueType(::DD::forward<ArgumentsT__>(arguments___)...), length_ });
	}

	public:
	template <typename... ArgumentsT__>
	Vessel(
		AllocatorType const& allocator_,
		BatchTag tag_, LengthType length_,
		ArgumentsT__ &&... arguments___
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(BatchRange<ValueType>{ ValueType(::DD::forward<ArgumentsT__>(arguments___)...), length_ });
	}
#	else
	public:
	Vessel(BatchTag tag_, LengthType length_) : SuperType(unguarded_tag) {
		BatchRange<ValueType> batcher_ = { ValueType(), length_ };
		clone_initialize_(batcher_);
	}

	public:
	Vessel(AllocatorType const& allocator_, BatchTag tag_, LengthType length_) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		BatchRange<ValueType> batcher_ = { ValueType(), length_ };
		clone_initialize_(batcher_);
	}

	public:
	template <typename ValueT__>
	Vessel(BatchTag tag_, LengthType length_, ValueT__ const& value___) : SuperType(unguarded_tag) {
		BatchRange<ValueT__ const&> batcher_ = { value___, length_ };
		clone_initialize_(batcher_);
	}

	public:
	template <typename ValueT__>
	Vessel(
		AllocatorType const& allocator_,
		BatchTag tag_, LengthType length_,
		ValueT__ const& value___
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		BatchRange<ValueT__ const&> batcher_ = { value___, length_ };
		clone_initialize_(batcher_);
	}
#	endif


	public:
	~Vessel() DD_NOEXCEPT {
		destruct_();
	}


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		::DD::swap(static_cast<AllocateAgent&>(*this), static_cast<AllocateAgent&>(other_));
		::DD::swap(this->m_begin_, other_.m_begin_);
		::DD::swap(this->m_end_, other_.m_end_);
		::DD::swap(this->m_storage_end_, other_.m_storage_end_);
	}


	private:
	template <typename UndirectionalIteratorT__>
	ProcessType clone_initialize_(UndirectionalIteratorT__ begin___, LengthType length_) {
		if (length_ > 0) {
			this->m_begin_ = AllocateAgent::allocate(length_);
			try {
				this->m_end_ = ::DD::get_pointer(::DD::copy_construct_length(begin___, this->begin(), length_).second);
			} catch (...) {
				AllocateAgent::deallocate(this->m_begin_, length_);
				throw;
			}
			this->m_storage_end_ = this->m_begin_ + length_;
		} else {
			this->m_begin_ = PointerType();
			this->m_end_ = PointerType();
			this->m_storage_end_ = PointerType();
		}
	}

	private:
	template <typename UndirectionalIteratorT__>
	ProcessType clone_initialize_(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) {
		clone_initialize_(begin___, ::DD::length_difference(begin___, end___));
	}

	private:
	template <typename UndirectionalRangeT__>
	ProcessType clone_initialize_(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().clone_initialize_(DD_SPLIT_RANGE(range___))
	) {
		clone_initialize_(DD_SPLIT_RANGE(range___));
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
	ProcessType clone(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().clone(DD_SPLIT_RANGE(range___))) {
		clone(DD_SPLIT_RANGE(range___));
	}


	public:
	ProcessType stretch(LengthType new_capacity_) {
		PointerType temp_begin_ = AllocateAgent::allocate(new_capacity_);
		try {
			PointerType temp_end_ = ::DD::get_pointer(this->transfer_to_(Iterator(temp_begin_)));
			destruct_();
			this->m_begin_ = temp_begin_;
			this->m_end_ = temp_end_;
			this->m_storage_end_ = temp_begin_ + new_capacity_;
		} catch (...) {
			AllocateAgent::deallocate(temp_begin_, new_capacity_);
		}
	}


	public:
	ProcessType reserve() noexcept(noexcept(ThisType().reserve(LengthType()))) {
		LengthType capacity_ = this->get_capacity();
		if (capacity_) {
			try {
				stretch(capacity_ * (DDCPP_VESSEL_GROWTH_RATIO));
			} catch (AllocationFailure& exception_) {
				stretch(capacity_ + 1);
			}
		} else {
			stretch(1);
		}
	}


	public:
	ProcessType reserve(LengthType new_capacity_) noexcept(noexcept(::DD::fabricate<ThisType>().stretch(new_capacity_))) {
		if (new_capacity_ > this->get_length()) {
			stretch(new_capacity_);
		}
	}


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	ProcessType emplace_front(ArgumentsT__&&... arguments___) noexcept(noexcept(
		::DD::fabricate<ThisType>().emplace(::DD::fabricate<ThisType>().begin(), ::DD::forward<ArgumentsT__>(arguments___)...)
	)) {
		emplace(this->begin(), ::DD::forward<ArgumentsT__>(arguments___)...);
	}


	public:
	template <typename ValueT__>
	ProcessType push_front(ValueT__&& value__) noexcept(
		noexcept(::DD::fabricate<ThisType>().emplace_front(::DD::forward<ValueT__>(value__)))
	) {
		emplace_front(::DD::forward<ValueT__>(value__));
	}
#	else
	public:
	template <typename ValueT__>
	ProcessType push_front(ValueT__&& value__) {
		insert(this->begin(), value__);
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	ProcessType emplace_back(ArgumentsT__&&... arguments___) noexcept(
		noexcept(::DD::fabricate<ThisType>().reserve()) &&
		noexcept(::DD::fabricate<ThisType>().unguarded_emplace_back(::DD::forward<ArgumentsT__>(arguments___)...))
	) {
		if (this->is_full()) {
			reserve();
		}
		this->unguarded_emplace_back(::DD::forward<ArgumentsT__>(arguments___)...);
	}


	public:
	template <typename ValueT__>
	ProcessType push_back(ValueT__&& value___) noexcept(
		noexcept(::DD::fabricate<ThisType>().emplace_back(::DD::forward<ValueT__>(value___)))
	) {
		emplace_back(forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	ProcessType push_back(ValueT__ const& value___) {
		if (this->is_full()) {
			reserve();
		}
		this->unguarded_push_back(value___);
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	Iterator emplace(Iterator position_, ArgumentsT__&&... arguments___) {
		if (this->is_full()) {
			PointerType new_begin_;
			LengthType capacity_ = this->get_capacity();
			if (capacity_) {
				try {
					new_begin_ = AllocateAgent::allocate(capacity_ * (DDCPP_VESSEL_GROWTH_RATIO));
					capacity_ *= (DDCPP_VESSEL_GROWTH_RATIO);
				} catch (AllocationFailure& exception_) {
					new_begin_ = AllocateAgent::allocate(capacity_ + 1);
					++capacity_;
				}
			} else {
				new_begin_ = AllocateAgent::allocate(1);
				capacity_ = 1;
			}
			try {
				LengthType origin_length_ = this->get_length();
				position_ = this->transfer_emplace_(position_, Iterator(new_begin_), ::DD::forward<ArgumentsT__>(arguments___)...);
				destruct_();
				this->m_begin_ = new_begin_;
				this->m_end_ = new_begin_ + origin_length_ + 1;
				this->m_storage_end_ = new_begin_ + capacity_;
				return position_;
			} catch (...) {
				AllocateAgent::deallocate(new_begin_, capacity_);
				throw;
			}
		}
		return this->unguarded_emplace(position_, ::DD::forward<ArgumentsT__>(arguments___)...);
	}


	public:
	template <typename ValueT__>
	Iterator insert(Iterator position_, ValueT__&& value___) noexcept(noexcept(
		::DD::fabricate<ThisType>().emplace(position_, ::DD::forward<ValueT__>(value___))
	)) {
		return emplace(position_, ::DD::forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	Iterator insert(Iterator position_, ValueT__ const& value___) {
		if (this->is_full()) {
			PointerType new_begin_;
			LengthType capacity_ = this->get_capacity();
			if (capacity_) {
				try {
					new_begin_ = AllocateAgent::allocate(capacity_ * (DDCPP_VESSEL_GROWTH_RATIO));
					capacity_ *= (DDCPP_VESSEL_GROWTH_RATIO);
				} catch (AllocationFailure& exception_) {
					new_begin_ = AllocateAgent::allocate(capacity_ + 1);
					++capacity_;
				}
			} else {
				new_begin_ = AllocateAgent::allocate(1);
				capacity_ = 1;
			}
			try {
				LengthType origin_length_ = this->get_length();
				position_ = this->transfer_emplace_(position_, Iterator(new_begin_), value___);
				destruct_();
				this->m_begin_ = new_begin_;
				this->m_end_ = new_begin_ + origin_length_ + 1;
				this->m_storage_end_ = new_begin_ + capacity_;
				return position_;
			} catch (...) {
				AllocateAgent::deallocate(new_begin_, capacity_);
				throw;
			}
		}
		return this->unguarded_emplace(position_, value___);
	}
#	endif


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_concatenate_back(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) DD_NOEXCEPT_AS(
		::DD::get_pointer(::DD::copy_construct(begin___ DD_COMMA end___ DD_COMMA ::DD::fabricate<ThisType>().end()))
	) {
		this->m_end_ = ::DD::get_pointer(::DD::copy_construct(begin___, end___, this->end()));
	}


	public:
	template <typename UndirectionalRangeT__>
	ProcessType unguarded_concatenate_back(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().unguarded_concatenate(DD_SPLIT_RANGE(range___))
	) {
		unguarded_concatenate(DD_SPLIT_RANGE(range___));
	}


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType concatenate_back(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) {
		reserve(this->get_length() + ::DD::length_difference(begin___, end___));
		unguarded_concatenate(begin___, end___);
	}


	public:
	template <typename UndirectionalRangeT__>
	ProcessType concatenate_back(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().concatenate(DD_SPLIT_RANGE(range___))
	) {
		concatenate(DD_SPLIT_RANGE(range___));
	}


	public:
	ProcessType shrink() DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().stretch(::DD::fabricate<ThisType>().get_length())) {
		stretch(this->get_length());
	}


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType add(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) {

	}


	private:
	ProcessType destruct_() const DD_NOEXCEPT {
		AllocateAgent::deallocate(this->m_begin_, this->get_capacity());
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().clone(origin_)) {
		clone(origin_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().swap(origin_)) {
		swap(origin_);
		return *this;
	}

#	endif

	public:
	template <typename UndirectionalRangeT__>
	ThisType& operator =(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().clone(range___)) {
		clone(range___);
		return *this;
	}


	public:
	template <typename UndirectionalRangeT__>
	ThisType& operator +=(UndirectionalRangeT__& range___) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().concatenate(range___)) {
		concatenate(range___);
		return *this;
	}


	public:
	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ThisType& operator <<(ValueT__&& value___) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().push_back(forward<ValueT__>(value___))) {
		push_back(forward<ValueT__>(value___));
		return *this;
	}
#	else
	ThisType& operator <<(ValueT__ const& value___) {
		push_back(value___);
		return *this;
	}
#	endif


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
