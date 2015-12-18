//	standard/bits/DD_List.hpp
#ifndef DD_LIST_HPP_
#	define DD_LIST_HPP_ 1



#	include "DD_IteratorNested.hpp"
#	include "DD_NeedInstance.hpp"
#	include "DD_IteratorReverse.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_address_of.hpp"
#	include "DD_Allocateable.hpp"
#	include "DD_InitializerList.hpp"
#	include "DD_BatchRange.hpp"
#	include "DD_ListIterator.hpp"
#	include "DD_length_difference.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct List_;



template <>
struct List_<void> {
	protected:
	DD_ALIAS(ThisType, List_<void>);
	DD_ALIAS(ValueType, void);

	protected:
	DD_ALIAS(ValueConstType, void);
	DD_ALIAS(ReferenceType, void);
	DD_ALIAS(ConstReferenceType, void);
	DD_ALIAS(PointerType, void);
	DD_ALIAS(ConstPointerType, void);

	protected:
	DD_ALIAS(SizeType, ::DD::SizeType);
	DD_ALIAS(LengthType, ::DD::LengthType);

	protected:
	DD_SPECIFIC_TYPE_NESTED(Node, ListNode<ValueType>);


	protected:
	DD_ALIAS(Iterator, ListIterator<void>);
	DD_ALIAS(ConstIterator, ListIterator<void>);
	DD_ITERATOR_NESTED


	private:
	NodeType m_sentry_;


	protected:
	DD_CONSTEXPR List_() DD_NOEXCEPT : m_sentry_{ ::DD::address_of(m_sentry_), ::DD::address_of(m_sentry_) } {
	}

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(List_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(List_)

	protected:
	List_(UnguardedTag tag_) DD_NOEXCEPT {
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


	protected:
	ReverseIterator rbegin() DD_NOEXCEPT {
		return ReverseIterator(::DD::previous(sentry_()));
	}

	protected:
	ConstReverseIterator DD_UNCONSTRIANED_CONSTEXPR rbegin() const DD_NOEXCEPT {
		return ConstReverseIterator(::DD::previous(sentry_()));
	}


	protected:
	ReverseIterator rend() DD_NOEXCEPT {
		return ReverseIterator(sentry_());
	}

	protected:
	ConstReverseIterator DD_UNCONSTRIANED_CONSTEXPR rend() const DD_NOEXCEPT {
		return ConstReverseIterator(sentry_());
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
		::DD::detail_::link_list_(sentry_(), sentry_());
	}


	protected:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		sentry_().swap_target(other_.sentry_());
	}


	protected:
	static ProcessType link_(Iterator iterator_1_, Iterator iterator_2_) DD_NOEXCEPT {
		::DD::detail_::link_list_(iterator_1_, iterator_2_);
	}


	protected:
	static Iterator enlink_(Iterator position_, Iterator node_) DD_NOEXCEPT {
		::DD::detail_::enlink_list_(position_, node_);
		return node_;
	}

	protected:
	static ProcessType enlink_(Iterator position_, Iterator first_, Iterator last_) DD_NOEXCEPT {
		::DD::detail_::enlink_list_(position_, first_, last_);
	}


	protected:
	static ProcessType delink_(Iterator target_) DD_NOEXCEPT {
		::DD::detail_::delink_list_(target_);
	}

	protected:
	static ProcessType delink_(Iterator first_, Iterator last_) DD_NOEXCEPT {
		::DD::detail_::delink_list_(first_, last_);
	}


	protected:
	static ProcessType unguarded_splice(Iterator position_, Iterator begin_, Iterator end_) DD_NOEXCEPT {
		::DD::detail_::splice_list_(position_, begin_, end_);
	}

	protected:
	template <typename ListRangeT__>
	static ProcessType unguarded_splice(Iterator position_, ListRangeT__& range___) DD_NOEXCEPT {
		unguarded_splice(position_, DD_SPLIT_RANGE(range___));
	}


	protected:
	static ProcessType splice(Iterator position_, Iterator begin_, Iterator end_) DD_NOEXCEPT {
		if (begin_ != end_) {
			unguarded_splice(position_, begin_, end_);
		}
	}

	protected:
	template <typename ListRangeT__>
	static ProcessType splice(Iterator position_, ListRangeT__& range___) DD_NOEXCEPT {
		splice(position_, DD_SPLIT_RANGE(range___));
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(List_)


};



template <typename ValueT_>
struct List_ : List_<void> {
	protected:
	DD_ALIAS(SuperType, List_<void>);
	DD_ALIAS(ThisType, List_<ValueT_>);
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
	constexpr List_() = default;
#	else
	List_() throw() {
	}
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(List_);

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(List_);

	protected:
	DD_CONSTEXPR List_(UnguardedTag tag_) DD_NOEXCEPT : SuperType(tag_) {
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
	ReverseIterator DD_CONSTEXPR rbegin() DD_NOEXCEPT {
		return ReverseIterator(SuperType::rbegin());
	}

	protected:
	ConstReverseIterator DD_CONSTEXPR rbegin() const DD_NOEXCEPT {
		return ConstReverseIterator(SuperType::rbegin());
	}


	protected:
	ReverseIterator DD_CONSTEXPR rend() DD_NOEXCEPT {
		return ReverseIterator(SuperType::rend());
	}

	protected:
	ConstReverseIterator DD_CONSTEXPR rend() const DD_NOEXCEPT {
		return ConstReverseIterator(SuperType::rend());
	}


	protected:
	DD_REVERSE_RANGE_NESTED


	protected:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		SuperType::swap(other_);
	}


	protected:
	static ProcessType unguarded_splice(Iterator position_, Iterator begin_, Iterator end_) DD_NOEXCEPT {
		SuperType::unguarded_splice(position_, begin_, end_);
	}

	protected:
	template <typename ListRangeT__>
	static ProcessType unguarded_splice(Iterator position_, ListRangeT__& range___) DD_NOEXCEPT {
		SuperType::unguarded_splice(position_, range___);
	}


	protected:
	static ProcessType splice(Iterator position_, Iterator begin_, Iterator end_) DD_NOEXCEPT {
		SuperType::splice(position_, begin_, end_);
	}

	protected:
	template <typename ListRangeT__>
	static ProcessType splice(Iterator position_, ListRangeT__& range___) DD_NOEXCEPT {
		SuperType::splice(position_, range___);
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(List_);


};



#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
#	endif
struct List : Allocateable<AllocatorT_>, List_<ValueT_> {
	public:
	DD_ALIAS(AllocateAgent, Allocateable<AllocatorT_>);
	DD_ALIAS(SuperType, List_<ValueT_>);
	DD_ALIAS(ThisType, List<ValueT_ DD_COMMA AllocatorT_>);
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
	struct Iterator : SuperType::Iterator {
		public:
		DD_ALIAS(SuperType, typename SuperType::Iterator);
		DD_ALIAS(ThisType, Iterator);

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
		Iterator() {
		}

		public:
		explicit Iterator(typename SuperType::SuperType origin_) : SuperType(origin_) {
		}

		public:
		Iterator(NodePointerType pointer_) : SuperType(pointer_) {
		}
#	endif


		public:
		ProcessType swap_target(ThisType const& other_) const DD_NOEXCEPT_AS(
			::DD::fabricate<SuperType>().SuperType::swap_target(other_)
		) {
			SuperType::swap_target(other_);
		}


		public:
		ValidityType DD_CONSTEXPR operator ==(ThisType const& other_) const DD_NOEXCEPT_AS(static_cast<ValidityType>(
			static_cast<SuperType const&>(::DD::fabricate<ThisType const>()) == static_cast<SuperType const&>(other_)
		)) {
			return static_cast<SuperType const&>(*this) == static_cast<SuperType const&>(other_);
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


		public:
		ThisType& operator --() DD_NOEXCEPT_AS(--static_cast<SuperType&>(::DD::fabricate<ThisType>())) {
			--static_cast<SuperType&>(*this);
			return *this;
		}

		public:
		ThisType operator --(int) DD_NOEXCEPT_AS(ThisType(--::DD::fabricate<ThisType>())) {
			ThisType result_(*this);
			--*this;
			return result_;
		}


	};


	public:
	DD_ALIAS(ConstIterator, typename List<ValueConstType DD_COMMA AllocatorType>::Iterator);
	DD_ITERATOR_NESTED


	public:
#	if __cplusplus >= 201103L
	constexpr List() = default;
#	else
	List() {
	};
#	endif

	public:
	List(ThisType const& origin_) : SuperType(unguarded_tag) {
		clone_initialize_(origin_);
	}

#	if __cplusplus >= 201103L
	public:
	List(ThisType&& origin_) : SuperType(unguarded_tag) {
		*SuperType::sentry_().get_node_pointer() = *origin_.sentry_().get_node_pointer();
		origin_.reset_();
	}

#	endif
	public:
	List(AllocatorType const& allocator_) DD_NOEXCEPT_AS(AllocateAgent(allocator_)) : AllocateAgent(allocator_) {
	}

#	if __cplusplus >= 201103L
	public:
	List(InitializerList<ValueType> list_) : SuperType(unguarded_tag) {
		clone_initialize_(list_);
	}

	public:
	List(AllocatorType const& allocator_, InitializerList<ValueType> list_) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(list_);
	}

#	endif
	public:
	template <typename UndirectionalIteratorT__>
	List(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) : SuperType(unguarded_tag) {
		clone_initialize_(begin___, end___);
	}

	public:
	template <typename UndirectionalIteratorT__>
	List(
		AllocatorType const& allocator_,
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(begin___, end___);
	}

	public:
	template <typename UndirectionalRangeT__>
	List(UndirectionalRangeT__ const& range___) : SuperType(unguarded_tag) {
		clone_initialize_(range___);
	}

	public:
	template <typename UndirectionalRangeT__>
	List(
		AllocatorType const& allocator_,
		UndirectionalRangeT__ const& range___
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(range___);
	}

#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	List(BatchTag tag_, LengthType length_, ArgumentsT__&&... arguments___) : SuperType(unguarded_tag) {
		clone_initialize_(BatchRange<ValueType>{ ValueType(forward<ArgumentsT__>(arguments___)...), length_ });
	}

	public:
	template <typename... ArgumentsT__>
	List(
		AllocatorType const& allocator_,
		BatchTag tag_, LengthType length_,
		ArgumentsT__&&... arguments___
	) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		clone_initialize_(BatchRange<ValueType>{ ValueType(forward<ArgumentsT__>(arguments___)...), length_ });
	}
#	else
	public:
	List(BatchTag tag_, LengthType length_) : SuperType(unguarded_tag) {
		BatchRange<ValueType> batcher_ = { ValueType(), length_ };
		clone_initialize_(batcher_);
	}

	public:
	List(AllocatorType const& allocator_, BatchTag tag_, LengthType length_) : AllocateAgent(allocator_), SuperType(unguarded_tag) {
		BatchRange<ValueType> batcher_ = { ValueType(), length_ };
		clone_initialize_(batcher_);
	}

	public:
	template <typename ValueT__>
	List(BatchTag tag_, LengthType length_, ValueT__ const& value___) : SuperType(unguarded_tag) {
		BatchRange<ValueT__ const&> batcher_ = { value___, length_ };
		clone_initialize_(batcher_);
	}

	public:
	template <typename ValueT__>
	List(
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
	~List() DD_NOEXCEPT {
		destruct();
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
	ReferenceType front() DD_NOEXCEPT_AS(static_cast<ReferenceType>(*::DD::fabricate<ThisType>().begin())) {
		return *begin();
	}

	public:
	ConstReferenceType front() const DD_NOEXCEPT_AS(
		static_cast<ConstReferenceType>(*::DD::fabricate<ThisType const>().begin())
	) {
		return *begin();
	}


	public:
	ReferenceType back() DD_NOEXCEPT_AS(static_cast<ReferenceType>(*::DD::previous(::DD::fabricate<ThisType>().end()))) {
		return *::DD::previous(end());
	}

	public:
	ConstReferenceType back() const DD_NOEXCEPT_AS(
		static_cast<ConstReferenceType>(*::DD::previous(::DD::fabricate<ThisType const>().end()))
	) {
		return **::DD::previous(end());
	}


	public:
	Iterator rbegin() DD_NOEXCEPT_AS(Iterator(::DD::fabricate<ThisType>().SuperType::rbegin())) {
		return Iterator(SuperType::rbegin());
	}

	public:
	ConstIterator DD_CONSTEXPR rbegin() const DD_NOEXCEPT_AS(ConstIterator(::DD::fabricate<ThisType const>().SuperType::rbegin())) {
		return ConstIterator(SuperType::rbegin());
	}


	public:
	Iterator rend() DD_NOEXCEPT_AS(Iterator(::DD::fabricate<ThisType>().SuperType::rend())) {
		return Iterator(SuperType::rend());
	}

	public:
	ConstIterator DD_CONSTEXPR rend() const DD_NOEXCEPT_AS(ConstIterator(::DD::fabricate<ThisType const>().SuperType::rend())) {
		return ConstIterator(SuperType::rend());
	}


	public:
	DD_REVERSE_RANGE_NESTED


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().SuperType::swap(other_)) {
		SuperType::swap(other_);
	}


	public:
	ProcessType join_front(Iterator begin_, Iterator end_) DD_NOEXCEPT_AS(
		splice(::DD::fabricate<ThisType>().begin() DD_COMMA begin_ DD_COMMA end_)
	) {
		splice(begin(), begin_, end_);
	}

	public:
	template <typename ListRangeT__>
	ProcessType join_front(ListRangeT__& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().join_front(DD_SPLIT_RANGE(range___))
	) {
		join_front(DD_SPLIT_RANGE(range___));
	}


	public:
	ProcessType join_back(Iterator begin_, Iterator end_) DD_NOEXCEPT_AS(
		splice(::DD::fabricate<ThisType>().end() DD_COMMA begin_ DD_COMMA end_)
	) {
		splice(end(), begin_, end_);
	}

	public:
	template <typename ListRangeT__>
	ProcessType join_back(ListRangeT__& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().join_back(DD_SPLIT_RANGE(range___))
	) {
		join_back(DD_SPLIT_RANGE(range___));
	}


	public:
	static ProcessType splice(Iterator position_, Iterator begin_, Iterator end_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().SuperType::splice(position_ DD_COMMA begin_ DD_COMMA end_)
	) {
		SuperType::splice(position_, begin_, end_);
	}

	public:
	template <typename ListRangeT__>
	static ProcessType splice(Iterator position_, ListRangeT__& range___) DD_NOEXCEPT_AS(
		SuperType::splice(position_ DD_COMMA DD_SPLIT_RANGE(range___))
	) {
		SuperType::splice(position_, DD_SPLIT_RANGE(range___));
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
	ProcessType created_range_between_(
		Iterator head_,
		Iterator tail_,
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) {
		try {
			for (; begin___ != end___; ++head_, ++begin___) {
				SuperType::link_(head_, create_node_(*begin___));
			}
		} catch(...) {
			SuperType::link_(head_, tail_);
			throw;
		}
		SuperType::link_(head_, tail_);
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
	) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().created_range_between_(
		Iterator(::DD::fabricate<ThisType>().SuperType::sentry_()) DD_COMMA
		Iterator(::DD::fabricate<ThisType>().SuperType::sentry_()) DD_COMMA
		begin___ DD_COMMA
		end___
	)) {
		created_range_between_(Iterator(SuperType::sentry_()), Iterator(SuperType::sentry_()), begin___, end___);
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
		destruct();
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
		emplace(begin(), forward<ArgumentsT__>(arguments___)...);
	}


	public:
	template <typename ValueT__>
	ProcessType push_front(ValueT__&& value___) {
		insert(begin(), forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	ProcessType push_front(ValueT__ const& value___) {
		insert(begin(), value___);
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	ProcessType emplace_back(ArgumentsT__&&... arguments___) {
		emplace(end(), forward<ArgumentsT__>(arguments___)...);
	}


	public:
	template <typename ValueT__>
	ProcessType push_back(ValueT__&& value___) {
		insert(end(), forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	ProcessType push_back(ValueT__ const& value___) {
		insert(end(), value___);
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	Iterator emplace(Iterator position_, ArgumentsT__&&... arguments___) {
		return Iterator(SuperType::enlink_(position_, create_node_(::DD::forward<ArgumentsT__>(arguments___)...)));
	}


	public:
	template <typename ValueT__>
	Iterator insert(Iterator position_, ValueT__&& value___) {
		return emplace(position_, forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	Iterator insert(Iterator position_, ValueT__ const& value___) {
		return Iterator(SuperType::enlink_(position_, create_node_(value___)));
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
	ProcessType concatenate_back(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) DD_NOEXCEPT_AS(
		insert_range(::DD::fabricate<ThisType>().end() DD_COMMA begin___ DD_COMMA end___)
	) {
		insert_range(end(), begin___, end___);
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType concatenate_back(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().concatenate_back(DD_SPLIT_RANGE(range___))
	) {
		concatenate_back(DD_SPLIT_RANGE(range___));
	}


	public:
	template <typename UndirectionalIteratorT__>
	ProcessType insert_range(
		Iterator position_,
		UndirectionalIteratorT__ begin___,
		UndirectionalIteratorT__ end___
	) DD_NOEXCEPT_AS(created_range_between_(::DD::previous(position_) DD_COMMA position_ DD_COMMA begin___ DD_COMMA end___)) {
		created_range_between_(::DD::previous(position_), position_, begin___, end___);
	}

	public:
	template <typename UndirectionalRangeT__>
	ProcessType insert_range(Iterator position_, UndirectionalRangeT__ const& begin___) DD_NOEXCEPT_AS(
		insert_range(position_ DD_COMMA DD_SPLIT_RANGE(begin___))
	) {
		insert_range(position_, DD_SPLIT_RANGE(begin___));
	}


	public:
	ProcessType pop_front() DD_NOEXCEPT_AS(erase(::DD::fabricate<ThisType>().begin())) {
		erase(begin());
	}


	public:
	ProcessType pop_back() DD_NOEXCEPT_AS(erase(::DD::previous(::DD::fabricate<ThisType>().end()))) {
		erase(::DD::previous(end()));
	}


	public:
	ProcessType trim_front(Iterator end_) DD_NOEXCEPT_AS(erase_range(fabricate<ThisType>().begin(), end_)) {
		erase_range(begin(), end_);
	}


	public:
	ProcessType trim_back(Iterator begin_) DD_NOEXCEPT_AS(erase_range(begin_, fabricate<ThisType>().end())) {
		erase_range(begin_, end());
	}


	public:
	ProcessType erase(Iterator position_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().SuperType::delink_(position_)) {
		SuperType::delink_(position_);
		destroy_node_(position_);
	}


	public:
	ProcessType erase_range(Iterator begin_, Iterator end_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().SuperType::delink_(begin_ DD_COMMA --end_)
	) {
		if (begin_ != end_) {
			SuperType::delink_(begin_, ::DD::previous(end_));
			for (; ; ) {
				destroy_node_(begin_++);
				if (begin_ == end_) {
					break;
				}
			}
		}
	}


	public:
	ProcessType clear() DD_NOEXCEPT {
		destruct();
		SuperType::reset_();
	}


	private:
	ProcessType destruct() DD_NOEXCEPT {
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


	public:
	template <typename UndirectionalRangeT__>
	ThisType& operator +=(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().concatenate_back(range___)) {
		concatenate_back(range___);
	}


	template <typename ValueT__>
#	if __cplusplus >= 201103L
	ThisType& operator <<(ValueT__&& value___) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().push_back(forward<ValueT__>(value___))) {
		push_back(forward<ValueT__>(value___));
	}
#	else
	ThisType& operator <<(ValueT__ const& value___) {
		push_back(value___);
	}
#	endif


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::List;



DD_END_



#endif
