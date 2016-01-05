//	DDCPP/standard/bits/DD_UndirectionalList.hpp
#ifndef DD_UNDIRECTIONAL_LIST_HPP_INCLUDED_
#	define DD_UNDIRECTIONAL_LIST_HPP_INCLUDED_ 1



#	include "DD_InitializerList.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_BatchRange.hpp"
#	include "DD_UndirectionalListIterator.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct UndirectionalList_;



template <>
struct UndirectionalList_<void> {
	protected:
	DD_ALIAS(ThisType, UndirectionalList_<void>);
	DD_VALUE_TYPE_NESTED(void)

	protected:
	DD_ALIAS(SizeType, ::DD::SizeType);
	DD_ALIAS(LengthType, ::DD::LengthType);

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
	Iterator before_begin() DD_NOEXCEPT {
		return sentry_();
	}

	protected:
	ConstIterator DD_UNCONSTRIANED_CONSTEXPR before_begin() const DD_NOEXCEPT {
		return sentry_();
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
	ProcessType unguarded_reset_() DD_NOEXCEPT {
		link_(sentry_(), sentry_());
	}


	protected:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		::DD::swap(m_sentry_, other_.m_sentry_);
		Iterator current_(sentry_());
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
	DD_DELETE_ALL_ASSIGNMENTS(UndirectionalList_)


};



template <typename ValueT_>
struct UndirectionalList_ : UndirectionalList_<void> {
	protected:
	DD_ALIAS(SuperType, UndirectionalList_<void>);
	DD_ALIAS(ThisType, UndirectionalList_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	protected:
	DD_SPECIFIC_TYPE_NESTED(Node, UndirectionalListNode<ValueType>);


	protected:
	DD_INHERIT_ALIAS(SizeType);
	DD_INHERIT_ALIAS(LengthType);


	protected:
	DD_ALIAS(Iterator, UndirectionalListIterator<ValueType>);
	DD_ALIAS(ConstIterator, UndirectionalListIterator<ValueConstType>);
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
	Iterator before_begin() DD_NOEXCEPT {
		return Iterator(SuperType::before_begin());
	}

	protected:
	ConstIterator DD_CONSTEXPR before_begin() const DD_NOEXCEPT {
		return ConstIterator(SuperType::before_begin());
	}


	public:
	ConstIterator DD_CONSTEXPR cbefore_begin() const DD_NOEXCEPT {
		return before_begin();
	}


	protected:
	Iterator begin() DD_NOEXCEPT {
		return Iterator(SuperType::begin());
	}

	protected:
	ConstIterator DD_CONSTEXPR begin() const DD_NOEXCEPT {
		return ConstIterator(SuperType::begin());
	}


	protected:
	Iterator end() DD_NOEXCEPT {
		return Iterator(SuperType::end());
	}

	protected:
	ConstIterator DD_CONSTEXPR end() const DD_NOEXCEPT {
		return ConstIterator(SuperType::end());
	}


	protected:
	DD_RANGE_NESTED


	public:
	ReferenceType front() DD_NOEXCEPT_AS(static_cast<ReferenceType>(*::DD::fabricate<ThisType>().begin())) {
		return *begin();
	}

	public:
	ConstReferenceType front() const DD_NOEXCEPT_AS(
		static_cast<ConstReferenceType>(*::DD::fabricate<ThisType const>().begin())
	) {
		return *begin();
	}


	protected:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		SuperType::swap(other_);
	}


	protected:
	static ProcessType transfer_after(Iterator from_after_, Iterator to_after_) DD_NOEXCEPT {
		SuperType::transfer_after(from_after_, to_after_);
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



template <typename ValueT_, typename AllocatorT_>
struct GuardedUndirectionalListIterator_ : UndirectionalListIterator<ValueT_> {
	public:
	DD_ALIAS(SuperType, UndirectionalListIterator<ValueT_>);
	DD_ALIAS(ThisType, GuardedUndirectionalListIterator_<ValueT_ DD_COMMA AllocatorT_>);

	public:
	DD_INHERIT_TEMPLATE_ALIAS(ValueType);
	DD_INHERIT_TEMPLATE_ALIAS(ValueConstType);
	DD_INHERIT_TEMPLATE_ALIAS(ReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(ConstReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(PointerType);
	DD_INHERIT_TEMPLATE_ALIAS(ConstPointerType);

	public:
	DD_INHERIT_TEMPLATE_ALIAS(NodeType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeConstType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeConstReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(NodePointerType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeConstPointerType);

#	if __cplusplus >= 201103L
	public:
	using SuperType::SuperType;
#	else
	public:
	GuardedUndirectionalListIterator_() {
	}

	public:
	explicit GuardedUndirectionalListIterator_(typename SuperType::SuperType origin_) : SuperType(origin_) {
	}

	public:
	GuardedUndirectionalListIterator_(NodePointerType pointer_) : SuperType(pointer_) {
	}
#	endif


	public:
	ProcessType swap_target(ThisType const& other_) const DD_NOEXCEPT_AS(
		::DD::fabricate<SuperType>().SuperType::swap_target(other_)
	) {
		SuperType::swap_target(other_);
	}


	public:
	ThisType& operator ++() DD_NOEXCEPT_AS(++static_cast<SuperType&>(::DD::fabricate<ThisType>())) {
		++static_cast<SuperType&>(*this);
		return *this;
	}

	public:
	ThisType operator ++(int) DD_NOEXCEPT_AS(ThisType(++::DD::fabricate<ThisType>())) {
		ThisType result_(*this);
		++*this;
		return result_;
	}


};



template <typename ValueT_, typename AllocatorT_>
inline ValidityType DD_CONSTEXPR operator ==(
	GuardedUndirectionalListIterator_<ValueT_, AllocatorT_> const& iterator_1__,
	GuardedUndirectionalListIterator_<ValueT_, AllocatorT_> const& iterator_2__
) DD_NOEXCEPT {
	return iterator_1__.GuardedUndirectionalListIterator_<ValueT_, AllocatorT_>::SuperType::equal(iterator_2__);
}



#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
#	endif
struct UndirectionalList : protected Allocateable<AllocatorT_>, UndirectionalList_<ValueT_> {
	public:
	DD_ALIAS(AllocateAgent, Allocateable<AllocatorT_>);
	DD_ALIAS(SuperType, UndirectionalList_<ValueT_>);
	DD_ALIAS(ThisType, UndirectionalList<ValueT_ DD_COMMA AllocatorT_>);
	DD_ALIAS(AllocatorType, AllocatorT_);

	public:
	DD_INHERIT_TEMPLATE_ALIAS(ValueType);
	DD_INHERIT_TEMPLATE_ALIAS(ValueConstType);
	DD_INHERIT_TEMPLATE_ALIAS(ReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(ConstReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(PointerType);
	DD_INHERIT_TEMPLATE_ALIAS(ConstPointerType);

	protected:
	DD_INHERIT_TEMPLATE_ALIAS(SizeType);
	DD_INHERIT_TEMPLATE_ALIAS(LengthType);

	public:
	DD_INHERIT_TEMPLATE_ALIAS(NodeType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeConstType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeConstReferenceType);
	DD_INHERIT_TEMPLATE_ALIAS(NodePointerType);
	DD_INHERIT_TEMPLATE_ALIAS(NodeConstPointerType);

	public:
	DD_ALIAS(Iterator, GuardedUndirectionalListIterator_<ValueType DD_COMMA AllocatorType>);
	DD_ALIAS(ConstIterator, typename UndirectionalList<ValueConstType DD_COMMA AllocatorType>::Iterator);
	DD_ITERATOR_NESTED


	public:
#	if __cplusplus >= 201103L
	constexpr UndirectionalList() = default;
#	else
	UndirectionalList() {
	};
#	endif

	public:
	UndirectionalList(ThisType const& origin_) : SuperType(unguarded_tag) {
		clone_initialize_(origin_);
	}

#	if __cplusplus >= 201103L
	public:
	UndirectionalList(ThisType&& origin_) noexcept(
		noexcept(AllocateAgent(::DD::move(origin_)))
	) : AllocateAgent(::DD::move(origin_)), SuperType(unguarded_tag) {
		*SuperType::sentry_().get_node_pointer() = *origin_.sentry_().get_node_pointer();
		origin_.unguarded_reset_();
	}

#	endif
	public:
	UndirectionalList(AllocatorType const& allocator_) DD_NOEXCEPT_AS(AllocateAgent(allocator_)) : AllocateAgent(allocator_) {
	}

#	if __cplusplus >= 201103L
	public:
	UndirectionalList(InitializerList<ValueType> list_) : SuperType(unguarded_tag) {
		clone_initialize_(list_);
	}

	public:
	UndirectionalList(AllocatorType const& allocator_, InitializerList<ValueType> list_) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(list_);
	}

#	endif
	public:
	template <typename UndirectionalIteratorT__>
	UndirectionalList(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) : SuperType(unguarded_tag) {
		clone_initialize_(begin___, end___);
	}

	public:
	template <typename UndirectionalIteratorT__>
	UndirectionalList(
		AllocatorType const& allocator_,
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(begin___, end___);
	}

	public:
	template <typename UndirectionalRangeT__>
	UndirectionalList(UndirectionalRangeT__ const& range___) : SuperType(unguarded_tag) {
		clone_initialize_(range___);
	}

	public:
	template <typename UndirectionalRangeT__>
	UndirectionalList(
		AllocatorType const& allocator_,
		UndirectionalRangeT__ const& range___
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(range___);
	}

#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	UndirectionalList(BatchTag tag_, LengthType length_, ArgumentsT__&&... arguments___) : SuperType(unguarded_tag) {
		clone_initialize_(BatchRange<ValueType>{ ValueType(forward<ArgumentsT__>(arguments___)...), length_ });
	}

	public:
	template <typename... ArgumentsT__>
	UndirectionalList(
		AllocatorType const& allocator_,
		BatchTag tag_, LengthType length_,
		ArgumentsT__&&... arguments___
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(BatchRange<ValueType>{ ValueType(forward<ArgumentsT__>(arguments___)...), length_ });
	}
#	else
	public:
	UndirectionalList(BatchTag tag_, LengthType length_) : SuperType(unguarded_tag) {
		BatchRange<ValueType> batcher_ = { ValueType(), length_ };
		clone_initialize_(batcher_);
	}

	public:
	UndirectionalList(AllocatorType const& allocator_, BatchTag tag_, LengthType length_) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		BatchRange<ValueType> batcher_ = { ValueType(), length_ };
		clone_initialize_(batcher_);
	}

	public:
	template <typename ValueT__>
	UndirectionalList(BatchTag tag_, LengthType length_, ValueT__ const& value___) : SuperType(unguarded_tag) {
		BatchRange<ValueT__ const&> batcher_ = { value___, length_ };
		clone_initialize_(batcher_);
	}

	public:
	template <typename ValueT__>
	UndirectionalList(
		AllocatorType const& allocator_,
		BatchTag tag_,
		LengthType length_,
		ValueT__ const& value___
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		BatchRange<ValueT__ const&> batcher_ = { value___, length_ };
		clone_initialize_(batcher_);
	}
#	endif


	public:
	~UndirectionalList() DD_NOEXCEPT {
		destruct_();
	}


	public:
	Iterator before_begin() DD_NOEXCEPT_AS(Iterator(::DD::fabricate<ThisType>().SuperType::begin())) {
		return Iterator(SuperType::before_begin());
	}

	public:
	ConstIterator DD_CONSTEXPR before_begin() const DD_NOEXCEPT_AS(ConstIterator(::DD::fabricate<ThisType const>().SuperType::begin())) {
		return ConstIterator(SuperType::before_begin());
	}


	public:
	ConstIterator DD_CONSTEXPR cbefore_begin() const DD_NOEXCEPT_AS(::DD::fabricate<ThisType const>().before_begin()) {
		return before_begin();
	}


	public:
	Iterator begin() DD_NOEXCEPT_AS(Iterator(::DD::fabricate<ThisType>().SuperType::begin())) {
		return Iterator(SuperType::begin());
	}

	public:
	ConstIterator DD_CONSTEXPR begin() const DD_NOEXCEPT_AS(ConstIterator(::DD::fabricate<ThisType const>().SuperType::begin())) {
		return ConstIterator(SuperType::begin());
	}


	public:
	Iterator end() DD_NOEXCEPT_AS(Iterator(::DD::fabricate<ThisType>().SuperType::end())) {
		return Iterator(SuperType::end());
	}

	public:
	ConstIterator DD_CONSTEXPR end() const DD_NOEXCEPT_AS(ConstIterator(::DD::fabricate<ThisType const>().SuperType::end())) {
		return ConstIterator(SuperType::end());
	}


	public:
	DD_RANGE_NESTED


	public:
	AllocatorType& get_allocator() const DD_NOEXCEPT {
		return AllocateAgent::get_allocator;
	}


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT_AS(
		::DD::swap(static_cast<AllocateAgent&>(fabricate<ThisType>()) DD_COMMA static_cast<AllocateAgent&>(other_))
	) {
		::DD::swap(static_cast<AllocateAgent&>(*this), static_cast<AllocateAgent&>(other_));
		SuperType::swap(other_);
	}


	public:
	static ProcessType transfer_after(Iterator from_after_, Iterator to_after_) DD_NOEXCEPT {
		SuperType::transfer_after(from_after_, to_after_);
	}


	private:
#	if __cplusplus >= 201103L
	template <typename... ArgumentsT__>
	Iterator create_node_(ArgumentsT__&&... arguments___) {
#	else
	template <typename ValueT__>
	Iterator create_node_(ValueT__ const& value___) {
#	endif
		NodePointerType new_node_ = static_cast<NodePointerType>(AllocateAgent::basic_allocate(sizeof(NodeType)));
		try {
#	if __cplusplus >= 201103L
			::DD::construct(::DD::address_of(new_node_->value), ::DD::forward<ArgumentsT__>(arguments___)...);
#	else
			::DD::construct(::DD::address_of(new_node_->value), value___);
#	endif
		} catch(...) {
			AllocateAgent::basic_deallocate(new_node_, sizeof(NodeType));
		}
		return Iterator(new_node_);
	}


	private:
	template <typename UndirectionalIteratorT__>
	ProcessType unguarded_create_range_between_(
		Iterator head_,
		Iterator tail_,
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) {
		Iterator first_;
		try {
			first_ = create_node_(*begin___);
		} catch (...) {
			SuperType::link_(head_, tail_);
			throw;
		}
		Iterator last_(first_);
		try {
			for(; ++begin___ != end___; ++last_) {
				SuperType::link_(last_, create_node_(*begin___));
			}
		} catch (...) {
			SuperType::link_(head_, first_);
			SuperType::link_(last_, tail_);
			throw;
		}
		SuperType::link_(head_, first_);
		SuperType::link_(last_, tail_);
	}


	private:
	ProcessType destroy_node_(Iterator target_) DD_NOEXCEPT {
		::DD::destruct(target_.unguarded_get_pointer());
		AllocateAgent::basic_deallocate(target_.get_node_pointer(), sizeof(NodeType));
	}


	private:
	template <typename UndirectionalIteratorT__>
	ProcessType clone_initialize_(
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().unguarded_create_range_between_(
		Iterator(::DD::fabricate<ThisType>().SuperType::sentry_()) DD_COMMA
		Iterator(::DD::fabricate<ThisType>().SuperType::sentry_()) DD_COMMA
		begin___ DD_COMMA
		end___
	)) {
		if (begin___ != end___) {
			unguarded_create_range_between_(Iterator(SuperType::sentry_()), Iterator(SuperType::sentry_()), begin___, end___);
		} else {
			this->unguarded_reset_();
		}
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
		destruct_();
		clone_initialize_(begin___, end___);
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType clone(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().clone(DD_SPLIT_RANGE(range___))) {
		clone(DD_SPLIT_RANGE(range___));
	}


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	ProcessType emplace_front(ArgumentsT__&&... arguments___) {
		emplace_after(before_begin(), forward<ArgumentsT__>(arguments___)...);
	}


	public:
	template <typename ValueT__>
	ProcessType push_front(ValueT__&& value___) {
		emplace_front(forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	ProcessType push_front(ValueT__ const& value___) {
		insert(before_begin(), value___);
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	Iterator emplace_after(Iterator position_, ArgumentsT__&&... arguments___) {
		return Iterator(SuperType::enlink_after_(position_, create_node_(::DD::forward<ArgumentsT__>(arguments___)...)));
	}


	public:
	template <typename ValueT__>
	Iterator insert_after(Iterator position_, ValueT__&& value___) {
		return emplace_after(position_, forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	Iterator insert_after(Iterator position_, ValueT__ const& value___) {
		return Iterator(SuperType::enlink_after_(position_, create_node_(value___)));
	}
#	endif


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType concatenate_front(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) DD_NOEXCEPT_AS(
		insert_range(::DD::fabricate<ThisType>().begin() DD_COMMA begin___ DD_COMMA end___)
	) {
		insert_range(begin(), begin___, end___);
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
	ProcessType insert_range_after(
		Iterator position_,
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().unguarded_create_range_between_(
		position_ DD_COMMA ::DD::next(position_) DD_COMMA begin___ DD_COMMA end___
	)) {
		unguarded_create_range_between_(position_, ::DD::next(position_), begin___, end___);
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType insert_range_after(Iterator position_, UndirectionalRangeT__ const& begin___) DD_NOEXCEPT_AS(
		insert_range_after(position_ DD_COMMA DD_SPLIT_RANGE(begin___))
	) {
		insert_range_after(position_, DD_SPLIT_RANGE(begin___));
	}


	public:
	ProcessType pop_front() DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().erase_after(::DD::fabricate<ThisType>().before_begin())) {
		erase_after(before_begin());
	}


	public:
	ProcessType trim_front(Iterator end_) DD_NOEXCEPT_AS(erase_range_between(fabricate<ThisType>().before_begin(), end_)) {
		erase_range_between(before_begin(), end_);
	}


	public:
	ProcessType erase_after(Iterator position_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().SuperType::delink_after_(position_)) {
		SuperType::delink_after_(position_++);
		destroy_node_(position_);
	}


	public:
	ProcessType erase_range_between(Iterator head_, Iterator tail_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().SuperType::delink_between_(head_++ DD_COMMA tail_)
	) {
		SuperType::delink_between_(head_++, tail_);
	}


	public:
	ProcessType clear() DD_NOEXCEPT {
		destruct_();
		SuperType::unguarded_reset_();
	}


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		for (Iterator current_(begin()); current_ != end(); ) {
			destroy_node_(current_++);
		}
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().clone(origin_)) {
		clone(origin_);
		return *this;
	}

	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().swap(origin_)) {
		swap(origin_);
		return *this;
	}

	public:
	template <typename UndirectionalRangeT__>
	ThisType& operator =(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().clone(range___)) {
		clone(range___);
		return *this;
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::UndirectionalList;



DD_END_



#endif
