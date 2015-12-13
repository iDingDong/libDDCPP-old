//	standard/bits/DD_List.hpp
#ifndef DD_LIST_HPP_
#	define DD_LIST_HPP_ 1



#	include "DD_IteratorNested.hpp"
#	include "DD_NeedInstance.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_address_of.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_InitializerList.hpp"
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
	DD_ALIAS(NodeType, ListNode<void>);
	DD_ALIAS(NodeConstType, NodeType const);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodeConstReferenceType, NodeConstType&);
	DD_ALIAS(NodePointerType, NodeType*);
	DD_ALIAS(NodeConstPointerType, NodeConstType*);

	protected:
	DD_ALIAS(NodeType, EmptyNode);
	DD_ALIAS(NodeConstType, NodeType const);
	DD_ALIAS(NodeReferenceType, NodeType&);
	DD_ALIAS(NodeConstReferenceType, NodeConstType&);
	DD_ALIAS(NodePointerType, NodeType*);
	DD_ALIAS(NodeConstPointerType, NodeConstType*);


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
	Iterator sentry_() DD_NOEXCEPT {
		return Iterator(m_sentry_);
	}

	protected:
	ConstIterator DD_CONSTEXPR sentry_() const DD_NOEXCEPT {
		return Iterator(m_sentry_);
	}


	protected:
	Iterator DD_CONSTEXPR begin() DD_NOEXCEPT {
		return ::DD::next(sentry_());
	}

	protected:
	ConstIterator DD_CONSTEXPR begin() const DD_NOEXCEPT {
		return ::DD::next(sentry_());
	}


	protected:
	Iterator DD_CONSTEXPR end() DD_NOEXCEPT {
		return sentry_();
	}

	protected:
	ConstIterator DD_CONSTEXPR end() const DD_NOEXCEPT {
		return sentry_();
	}


	protected:
	DD_RANGE_NESTED


	protected:
	ReverseIterator DD_CONSTEXPR rbegin() DD_NOEXCEPT {
		return ReverseIterator(::DD::previous(sentry_()));
	}

	protected:
	ConstReverseIterator DD_CONSTEXPR rbegin() const DD_NOEXCEPT {
		return ConstReverseIterator(::DD::previous(sentry_()));
	}


	protected:
	ReverseIterator DD_CONSTEXPR rend() DD_NOEXCEPT {
		return ReverseIterator(sentry_());
	}

	protected:
	ConstReverseIterator DD_CONSTEXPR rend() const DD_NOEXCEPT {
		return ConstReverseIterator(sentry_());
	}


	protected:
	DD_REVERSE_RANGE_NESTED


	protected:
	static ProcessType transfer(Iterator from_, Iterator to_) DD_NOEXCEPT {
		::DD::detail_::unguarded_delink_list_node_(from_.get_node_pointer_());
		::DD::detail_::unguarded_enlink_list_node_(to_.get_node_pointer_(), from_.get_node_pointer_())
	}


	protected:
	static ProcessType unguarded_splice(Iterator position_, Iterator begin_, Iterator end_) DD_NOEXCEPT {
		::DD::detail_::unguarded_delink_list_node_(begin_.get_node_pointer(), (--end_).get_node_pointer());
		::DD::detail_::unguarded_enlink_list_node_(
			position_.get_node_pointer(),
			begin_.get_node_poitner(),
			end_.get_node_pointer()
		);
	}

	protected:
	template <typename ListRangeT__>
	static ProcessType unguarded_splice(Iterator position_, ListRangeT_& range___) DD_NOEXCEPT {
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
	static ProcessType splice(Iterator position_, ListRangeT_& range___) DD_NOEXCEPT {
		splice(position_, DD_SPLIT_RANGE(range___));
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(ListBase_)


};



template <typename ValueT_>
struct ListBase_ : List<void> {
	public:
	DD_ALIAS(SuperType)


};



template <typename ValueT_, typename AllocatorT_, ValidityType need_instance_c_>
struct List_ : ListBase_<ValueT_> {
	public:
	struct Iterator : ListIterator<ValueType> {
		public:
		DD_ALIAS(SuperType, ListIterator<ValueType>);
		DD_ALIAS(ThisType, Iterator);

		public:
		DD_INHERIT_ALIAS(ValueType);
		DD_INHERIT_ALIAS(ValueConstType);
		DD_INHERIT_ALIAS(ReferenceType);
		DD_INHERIT_ALIAS(ConstReferenceType);
		DD_INHERIT_ALIAS(PointerType);
		DD_INHERIT_ALIAS(ConstPointerType);

		public:
		DD_INHERIT_ALIAS(NodeType);
		DD_INHERIT_ALIAS(NodeConstType);
		DD_INHERIT_ALIAS(NodeReferenceType);
		DD_INHERIT_ALIAS(NodeConstType);
		DD_INHERIT_ALIAS(NodePointerType);
		DD_INHERIT_ALIAS(NodeConstPointerType);

#	if __cplusplus >= 201103L
		public:
		using SuperType::SuperType;
#	else
		public:
		Iterator() {
		}

		public:
		Iterator(NodePointerType pointer_) : SuperType(pointer_) {
		}
#	endif


		public:
		ProcessType swap_target(ThisType const& other_) const DD_NOEXCEPT_AS(
			static_cast<SuperType&>(fabricate<SuperType>()).swap_target(other_)
		) {
			static_cast<SuperType&>(*this).swap_target(other_);
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
			return *this;
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
			return *this;
		}


	};


};



#	if __cplusplus >= 201103L
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
#	else
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_> >
#	endif
struct List : List_<ValueT_, AllocatorT_, NeedInstance<AllocatorT_>::value> {
	public:
	DD_ALIAS(SuperType, List_<ValueT_, AllocatorT_, NeedInstance<AllocatorT_>::value>);
	DD_ALIAS(ThisType, List<ValueT_, AllocatorT_>);

	public:
	DD_INHERIT_ALIAS(ValueType);
	DD_INHERIT_ALIAS(ValueConstType);
	DD_INHERIT_ALIAS(ReferenceType);
	DD_INHERIT_ALIAS(ConstReferenceType);
	DD_INHERIT_ALIAS(PointerType);
	DD_INHERIT_ALIAS(ConstPointerType);


#	if __cplusplus >= 201103L
	public:
	using SuperType::SuperType;
#	else
	public:
	List() {
	}

	public:
	List()

	public:
	template <typename UndirectionalIteratorT__>
	List(UndirectionalIteratorT__ begin___, UndirectionalIteratorT__ end___) : SuperType(begin___, end___) {
	}

	public:
	template <typename UndirectionalRangeT__>
	List(UndirectionalRangeT__& range___) : SuperType(range___) {
	}
#	endif


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::List;



DD_END_



#endif
