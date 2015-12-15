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
#	include "DD_Allocator.hpp"
#	include "DD_InitializerList.hpp"
#	include "DD_BatchRange.hpp"
#	include "DD_ListIterator.hpp"
#	include "DD_length_difference.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct ListBase_;



template <>
struct ListBase_<void> {
	protected:
	DD_ALIAS(ThisType, ListBase_<void>);
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
	DD_CONSTEXPR ListBase_() DD_NOEXCEPT : m_sentry_{ ::DD::address_of(m_sentry_), ::DD::address_of(m_sentry_) } {
	}

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(ListBase_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(ListBase_)

	protected:
	ListBase_(NilTag tag_) DD_NOEXCEPT {
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
		::DD::detail_::link_list_node_(sentry_(), sentry_());
	}


	protected:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		sentry_().swap_target(other_.sentry_());
	}


	protected:
	static ProcessType link_(Iterator iterator_1_, Iterator iterator_2_) DD_NOEXCEPT {
		::DD::detail_::link_list_node_(iterator_1_, iterator_2_);
	}


	protected:
	static ProcessType enlink_(Iterator position_, Iterator new_node_) DD_NOEXCEPT {
		::DD::detail_::enlink_list_node_(position_, new_node_);
	}

	protected:
	static ProcessType enlink_(Iterator position_, Iterator first_, Iterator last_) DD_NOEXCEPT {
		::DD::detail_::enlink_list_node_(position_, first_, last_);
	}


	protected:
	static ProcessType delink_(Iterator target_) DD_NOEXCEPT {
		::DD::detail_::delink_list_node_(target_);
	}

	protected:
	static ProcessType delink_(Iterator first_, Iterator last_) DD_NOEXCEPT {
		::DD::detail_::delink_list_node_(first_, last_);
	}


	protected:
	static ProcessType unguarded_splice(Iterator position_, Iterator begin_, Iterator end_) DD_NOEXCEPT {
		::DD::detail_::splice_list_node_(position_, begin_, end_);
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
	DD_DELETE_ALL_ASSIGNMENTS(ListBase_)


};



template <typename ValueT_>
struct ListBase_ : ListBase_<void> {
	protected:
	DD_ALIAS(SuperType, ListBase_<void>);
	DD_ALIAS(ThisType, ListBase_<ValueT_>);
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
	constexpr ListBase_() = default;
#	else
	ListBase_() throw() {
	}
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(ListBase_);

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(ListBase_);

	protected:
	DD_CONSTEXPR ListBase_(NilTag tag_) DD_NOEXCEPT : SuperType(tag_) {
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
	DD_DELETE_ALL_ASSIGNMENTS(ListBase_);


};



template <typename ValueT_, typename AllocatorT_, ValidityType need_instance_c_>
struct List_ : ListBase_<ValueT_> {
	public:
	DD_ALIAS(SuperType, ListBase_<ValueT_>);
	DD_ALIAS(ThisType, List_<ValueT_ DD_COMMA AllocatorT_ DD_COMMA need_instance_c_>);
	DD_ALIAS(AllocatorType, AllocatorT_);
	static ValidityType DD_CONSTANT need_instance = need_instance_c_;

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
			fabricate<SuperType>().SuperType::swap_target(other_)
		) {
			SuperType::swap_target(other_);
		}


		public:
		ValidityType DD_CONSTEXPR operator ==(ThisType const& other_) const DD_NOEXCEPT_AS(static_cast<ValidityType>(
			static_cast<SuperType const&>(fabricate<ThisType const>()) == static_cast<SuperType const&>(other_)
		)) {
			return static_cast<SuperType const&>(*this) == static_cast<SuperType const&>(other_);
		}


		public:
		ThisType& operator ++() DD_NOEXCEPT_AS(++static_cast<SuperType&>(fabricate<ThisType>())) {
			++static_cast<SuperType&>(*this);
			return *this;
		}

		public:
		ThisType operator ++(int) DD_NOEXCEPT_AS(ThisType(++fabricate<ThisType>())) {
			ThisType result_(*this);
			++*this;
			return result_;
		}


		public:
		ThisType& operator --() DD_NOEXCEPT_AS(--static_cast<SuperType&>(fabricate<ThisType>())) {
			--static_cast<SuperType&>(*this);
			return *this;
		}

		public:
		ThisType operator --(int) DD_NOEXCEPT_AS(ThisType(--fabricate<ThisType>())) {
			ThisType result_(*this);
			--*this;
			return result_;
		}


	};


	public:
	DD_ALIAS(ConstIterator, typename List_<ValueConstType DD_COMMA AllocatorType DD_COMMA need_instance>::Iterator);
	DD_ITERATOR_NESTED


	public:
#	if __cplusplus >= 201103L
	constexpr List_() = default;
#	else
	List_() {
	};
#	endif

	public:
	List_(ThisType const& origin_) : SuperType(nil_tag) {
		try {
			clone_initialize_(origin_);
		} catch(...) {
			destruct();
			throw;
		}
	}

	public:
	List_(ThisType&& origin_) : SuperType(nil_tag) {
		*SuperType::sentry_().get_node_pointer() = *origin_.sentry_().get_node_pointer();
		origin_.reset_();
	}

	public:
	List_(InitializerList<ValueType> list_) : SuperType(nil_tag) {
		try {
			clone_initialize_(list_);
		} catch(...) {
			destruct();
			throw;
		}
	}

	public:
	template <typename UndirectionalIteratorT__>
	List_(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) : SuperType(nil_tag) {
		try {
			clone_initialize_(begin___, end___);
		} catch(...) {
			destruct();
			throw;
		}
	}

	public:
	template <typename UndirectionalRangeT__>
	List_(UndirectionalRangeT__ const& range___) : SuperType(nil_tag) {
		try {
			clone_initialize_(range___);
		} catch(...) {
			destruct();
			throw;
		}
	}

#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT__>
	List_(BatchTag tag_, LengthType length_, ArgumentsT__&&... arguments___) : SuperType(nil_tag) {
		try {
			clone_initialize_(BatchRange<ValueType>{ ValueType(forward<ArgumentsT__>(arguments___)...), length_ });
		} catch(...) {
			destruct();
			throw;
		}
	}
#	else
	public:
	List_(BatchTag tag_, LengthType length_) : SuperType(nil_tag) {
		try {
			BatchRange<ValueType> batcher_ = { ValueType(), length_ };
			clone_initialize_(batcher_);
		} catch(...) {
			destruct();
			throw;
		}
	}

	public:
	template <typename ValueT__>
	List_(BatchTag tag_, LengthType length_, ValueT__ const& value___) : SuperType(nil_tag) {
		try {
			BatchRange<ValueT__ const&> batcher_ = { value___, length_ };
			clone_initialize_(batcher_);
		} catch(...) {
			destruct();
			throw;
		}
	}
#	endif


	public:
	~List_() DD_NOEXCEPT {
		destruct();
	}


	public:
	Iterator begin() DD_NOEXCEPT_AS(Iterator(fabricate<ThisType>().SuperType::begin())) {
		return Iterator(SuperType::begin());
	}

	public:
	ConstIterator DD_CONSTEXPR begin() const DD_NOEXCEPT_AS(ConstIterator(fabricate<ThisType const>().SuperType::begin())) {
		return ConstIterator(SuperType::begin());
	}


	public:
	Iterator end() DD_NOEXCEPT_AS(Iterator(fabricate<ThisType>().SuperType::end())) {
		return Iterator(SuperType::end());
	}

	public:
	ConstIterator DD_CONSTEXPR end() const DD_NOEXCEPT_AS(ConstIterator(fabricate<ThisType const>().SuperType::end())) {
		return ConstIterator(SuperType::end());
	}


	public:
	DD_RANGE_NESTED


	public:
	Iterator rbegin() DD_NOEXCEPT_AS(Iterator(fabricate<ThisType>().SuperType::rbegin())) {
		return Iterator(SuperType::rbegin());
	}

	public:
	ConstIterator DD_CONSTEXPR rbegin() const DD_NOEXCEPT_AS(ConstIterator(fabricate<ThisType const>().SuperType::rbegin())) {
		return ConstIterator(SuperType::rbegin());
	}


	public:
	Iterator rend() DD_NOEXCEPT_AS(Iterator(fabricate<ThisType>().SuperType::rend())) {
		return Iterator(SuperType::rend());
	}

	public:
	ConstIterator DD_CONSTEXPR rend() const DD_NOEXCEPT_AS(ConstIterator(fabricate<ThisType const>().SuperType::rend())) {
		return ConstIterator(SuperType::rend());
	}


	public:
	DD_REVERSE_RANGE_NESTED


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT_AS(fabricate<ThisType>().SuperType::swap(other_)) {
		SuperType::swap(other_);
	}


	private:
#	if __cplusplus >= 201103L
	template <typename... ArgumentsT__>
	static Iterator create_node_(ArgumentsT__&&... arguments___) {
#	else
	template <typename ValueT__>
	static Iterator create_node_(ValueT__ const& value___) {
#	endif
		NodePointerType new_node_ = static_cast<NodePointerType>(AllocatorType::Basic::allocate(sizeof(NodeType)));
		try {
#	if __cplusplus >= 201103L
			AllocatorType::construct(::DD::address_of(new_node_->value), ::DD::forward<ArgumentsT__>(arguments___)...);
#	else
			AllocatorType::construct(::DD::address_of(new_node_->value), value___);
#	endif
		} catch(...) {
			AllocatorType::Basic::deallocate(new_node_, sizeof(NodeType));
		}
		return Iterator(new_node_);
	}


	private:
	static ProcessType destroy_node_(Iterator target_) DD_NOEXCEPT {
		AllocatorType::destruct(target_.unguarded_get_pointer());
		AllocatorType::Basic::deallocate(target_.get_node_pointer(), sizeof(NodeType));
	}


	private:
	template <typename UndirectionalIteratorT__>
	ProcessType clone_initialize_(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) {
		Iterator current_(SuperType::sentry_());
		try {
			for (; begin___ != end___; ++current_, ++begin___) {
				SuperType::link_(current_, create_node_(*begin___));
			}
		} catch(...) {
			SuperType::link_(current_, SuperType::sentry_());
			throw;
		}
		SuperType::link_(current_, SuperType::sentry_());
	}

	private:
	template <typename UndirectionalRangeT__>
	ProcessType clone_initialize_(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(
		fabricate<ThisType>().clone_initialize_(DD_SPLIT_RANGE(range___))
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
	ProcessType clone(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(fabricate<ThisType>().clone(DD_SPLIT_RANGE(range___))) {
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
	static ProcessType emplace(Iterator position_, ArgumentsT__&&... arguments___) {
		SuperType::enlink_(position_, create_node_(::DD::forward<ArgumentsT__>(arguments___)...));
	}


	public:
	template <typename ValueT__>
	static ProcessType insert(Iterator position_, ValueT__&& value___) {
		emplace(position_, forward<ValueT__>(value___));
	}
#	else
	public:
	template <typename ValueT__>
	static ProcessType insert(Iterator position_, ValueT__ const& value___) {
		SuperType::enlink_(position_, create_node_(value___));
	}
#	endif


	public:
	static ProcessType erase(Iterator position_) DD_NOEXCEPT_AS(fabricate<ThisType>().SuperType::delink_(position_)) {
		SuperType::delink_(position_);
		destroy_node_(position_);
	}


	public:
	static ProcessType erase_range(Iterator begin_, Iterator end_) DD_NOEXCEPT_AS(
		fabricate<ThisType>().SuperType::delink_(begin_ DD_COMMA --end_)
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
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT_AS(fabricate<ThisType>().clone(origin_)) {
		clone(origin_);
		return *this;
	}

	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT_AS(fabricate<ThisType>().swap(origin_)) {
		swap(origin_);
		return *this;
	}

	public:
	template <typename UndirectionalRangeT__>
	ThisType& operator =(UndirectionalRangeT__ const& range___) DD_NOEXCEPT_AS(fabricate<ThisType>().clone(range___)) {
		clone(range___);
		return *this;
	}


};



#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
#	endif
struct List : List_<ValueT_, AllocatorT_, NeedInstance<AllocatorT_>::value> {
	public:
	DD_ALIAS(SuperType, List_<ValueT_ DD_COMMA AllocatorT_ DD_COMMA NeedInstance<AllocatorT_>::value>);
	DD_ALIAS(ThisType, List<ValueT_ DD_COMMA AllocatorT_>);

	public:
	DD_INHERIT_TEMPLATE_ALIAS(SizeType);
	DD_INHERIT_TEMPLATE_ALIAS(LengthType);


#	if __cplusplus >= 201103L
	public:
	using SuperType::SuperType;
#	else
	public:
	List() {
	}

	public:
	template <typename UndirectionalIteratorT__>
	List(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) : SuperType(begin___, end___) {
	}

	public:
	template <typename UndirectionalRangeT__>
	List(UndirectionalRangeT__& range___) : SuperType(range___) {
	}

	public:
	List(BatchTag tag_, LengthType length_) : SuperType(tag_, length_) {
	}

	public:
	template <typename ValueT__>
	List(BatchTag tag_, LengthType length_, ValueT__ const& value___) : SuperType(tag_, length_, value___) {
	}
#	endif


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT_AS(fabricate<ThisType>().SuperType::swap(other_)) {
		SuperType::swap(other_);
	}


	public:
	using SuperType::operator =;


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::List;



DD_END_



#endif
