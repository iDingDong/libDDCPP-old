//	DDCPP/standard/bits/DD_StrongPointer.hpp
#ifndef DD_SRONG_POINTER_HPP_INCLUDED_
#	define DD_SRONG_POINTER_HPP_INCLUDED_ 1



#	include "DD_SpecificTypeNested.hpp"
#	include "DD_Comparable.hpp"
#	include "DD_address_of.hpp"
#	include "DD_Deleter.hpp"
#	include "DD_Destroy.hpp"
#	include "DD_construct.hpp"
#	include "DD_ReferenceCounter.hpp"
#	include "DD_Pair.hpp"
#	include "DD_SingleStorage.hpp"



#	if !defined(DDCPP_DEFAULT_REFERENCE_MANAGER_ALLOCATOR)
#		if __cplusplus >= 201103L
#			define DDCPP_DEFAULT_REFERENCE_MANAGER_ALLOCATOR get_instance<Allocator<void>>()
#		else
#			define DDCPP_DEFAULT_REFERENCE_MANAGER_ALLOCATOR get_instance<Allocator<void> >()
#		endif
#	endif



DD_DETAIL_BEGIN_
struct ReferenceManagerBase_ {
	protected:
	DD_ALIAS(ThisType, ReferenceManagerBase_);


	private:
	friend ThisType& get_instance<ThisType>() DD_NOEXCEPT;


	protected:
#	if __cplusplus >= 201103L
	constexpr ReferenceManagerBase_() = default;
#	else
	ReferenceManagerBase_() throw() {
	}
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(ReferenceManagerBase_)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(ReferenceManagerBase_)


	protected:
#	if __cplusplus >= 201103L
	virtual ~ReferenceManagerBase_() = default;
#	else
	virtual ~ReferenceManagerBase_() {
	}
#	endif


	public:
	static ThisType* get_nil_reference_manager_() DD_NOEXCEPT {
		return ::DD::address_of(get_instance<ThisType>());
	}


	public:
	virtual GlobalPointerType get_global_pointer_() const DD_NOEXCEPT {
		return GlobalPointerType();
	}


	public:
	GlobalConstPointerType get_global_const_pointer_() const DD_NOEXCEPT {
		return get_global_pointer_();
	}


	public:
	virtual LengthType get_strong_reference_count_() const DD_NOEXCEPT {
		return LengthType();
	}


	public:
	virtual LengthType get_weak_reference_count_() const DD_NOEXCEPT {
		return LengthType();
	}


	public:
	virtual ProcessType strongly_referred_() DD_NOEXCEPT {
	}


	public:
	virtual ProcessType weakly_referred_() DD_NOEXCEPT {
	}


	public:
	virtual ProcessType strongly_released_() DD_NOEXCEPT {
	}


	public:
	virtual ProcessType weakly_released_() DD_NOEXCEPT {
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(ReferenceManagerBase_)


};



template <typename ValueT_, typename DeleterT_, typename ThisDeleterT_>
struct ReferenceManager_ :
	protected Agent<DeleterT_>,
	protected Agent<ThisDeleterT_>,
	ReferenceManagerBase_,
	protected ReferenceCounter
{
	private:
	DD_ALIAS(DestroyAgent, Agent<DeleterT_>);
	DD_ALIAS(DestroyThisAgent, Agent<ThisDeleterT_>);
	DD_ALIAS(SuperType, ReferenceManagerBase_);
	DD_ALIAS(CounterType, ReferenceCounter);
	DD_ALIAS(ThisType, ReferenceManager_<ValueT_ DD_COMMA DeleterT_ DD_COMMA ThisDeleterT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(DeleterType, DeleterT_);
	DD_ALIAS(ThisDeleterType, ThisDeleterT_);


	private:
	PointerType m_pointer_;


	private:
	DD_DELETE_ALL_CONSTRUCTORS(ReferenceManager_)


	public:
	ReferenceManager_(DeleterType const& deleter_, ThisDeleterType const& this_deleter_, PointerType pointer_) DD_NOEXCEPT_IF(
		noexcept(DestroyAgent(deleter_)) && noexcept(DestroyThisAgent(this_deleter_))
	) : DestroyAgent(deleter_), DestroyThisAgent(this_deleter_), m_pointer_(pointer_) {
	}


	public:
#	if __cplusplus >= 201103L
	~ReferenceManager_() override = default;
#	else
	~ReferenceManager_() throw() {
	}
#	endif


	private:
	PointerType get_pointer_() const DD_NOEXCEPT {
		return m_pointer_;
	}


	public:
	GlobalPointerType get_global_pointer_() const DD_NOEXCEPT DD_OVERRIDE {
		return get_pointer_();
	}


	public:
	LengthType get_strong_reference_count_() const DD_NOEXCEPT DD_OVERRIDE {
		return get_strong_reference_count();
	}


	public:
	LengthType get_weak_reference_count_() const DD_NOEXCEPT DD_OVERRIDE {
		return get_weak_reference_count();
	}


	public:
	ProcessType strongly_referred_() DD_NOEXCEPT DD_OVERRIDE {
		strongly_referred();
	}


	public:
	ProcessType weakly_referred_() DD_NOEXCEPT DD_OVERRIDE {
		weakly_referred();
	}


	public:
	ProcessType strongly_released_() DD_NOEXCEPT DD_OVERRIDE {
		strongly_released();
		if (is_expired()) {
			destroy_target_();
			if (has_weak_reference()) {
				m_pointer_ = PointerType();
			} else {
				destroy_this_();
			}
		}
	}


	public:
	ProcessType weakly_released_() DD_NOEXCEPT DD_OVERRIDE {
		if (is_expired() && is_unique_weak_reference()) {
			destroy_this_();
		} else {
			weakly_released();
		}
	}


	private:
	ProcessType destroy_target_() const DD_NOEXCEPT {
		::DD::destroy(get_pointer_(), DestroyAgent::get_instance());
	}


	private:
	ProcessType destroy_this_() DD_NOEXCEPT {
		::DD::destroy(this, DestroyThisAgent::get_instance());
	}


	private:
	DD_DELETE_ALL_ASSIGNMENTS(ReferenceManager_)


};



#	if __cplusplus >= 201103L
template <typename ValueT_, typename DeleterT_>
struct AggregateReferenceManager_ : protected Agent<DeleterT_>, ReferenceManagerBase_, protected ReferenceCounter {
	private:
	using DestroyAgent = Agent<DeleterT_>;
	using SuperType = ReferenceManagerBase_;
	using CounterType = ReferenceCounter;
	using ThisType = AggregateReferenceManager_<ValueT_, DeleterT_>;
	DD_VALUE_TYPE_NESTED(ValueT_)
	using DeleterType = DeleterT_;


	private:
	SingleStorage<ValueType> mutable m_storage_;


	private:
	DD_DELETE_ALL_CONSTRUCTORS(AggregateReferenceManager_)


	public:
	template <typename... ArgumentsT__>
	AggregateReferenceManager_(DeleterType const& deleter_, ArgumentsT__&&... arguments___) noexcept(
		noexcept(DestroyAgent(deleter_)) && noexcept(m_storage_.construct(::DD::forward<ArgumentsT__>(arguments___)...))
	) : DestroyAgent(deleter_) {
		m_storage_.construct(::DD::forward<ArgumentsT__>(arguments___)...);
	}


	public:
	~AggregateReferenceManager_() override = default;


	private:
	PointerType get_pointer_() const noexcept {
		return has_strong_reference() ? m_storage_.get_pointer() : PointerType();
	}


	public:
	GlobalPointerType get_global_pointer_() const noexcept override {
		return get_pointer_();
	}


	public:
	LengthType get_strong_reference_count_() const noexcept override {
		return get_strong_reference_count();
	}


	public:
	LengthType get_weak_reference_count_() const noexcept override {
		return get_weak_reference_count();
	}


	public:
	ProcessType strongly_referred_() noexcept override {
		strongly_referred();
	}


	public:
	ProcessType weakly_referred_() noexcept override {
		weakly_referred();
	}


	public:
	ProcessType strongly_released_() noexcept override {
		strongly_released();
		if (is_expired()) {
			destruct_target_();
			if (!has_weak_reference()) {
				destroy_this_();
			}
		}
	}


	public:
	ProcessType weakly_released_() noexcept override {
		if (is_expired() && is_unique_weak_reference()) {
			destroy_this_();
		} else {
			weakly_released();
		}
	}


	private:
	ProcessType destruct_target_() const noexcept {
		m_storage_.destruct();
	}


	private:
	ProcessType destroy_this_() noexcept {
		::DD::destroy(this, DestroyAgent::get_instance());
	}


	private:
	DD_DELETE_ALL_ASSIGNMENTS(AggregateReferenceManager_)


};



#	endif
template <typename ValueT_>
struct StrongPointer;



template <typename ValueT_>
struct WeakPointer;



template <typename ValueT_>
struct StronglyReferable;



#	if __cplusplus >= 201103L
template <typename ValueT_>
inline ProcessType try_set_manager_for_strongly_referable_(
	ReferenceManagerBase_* manager_pointer_,
	StronglyReferable<ValueT_>* pointer_
) noexcept;



#	endif
template <typename ValueT_>
struct StronglyReferable {
	protected:
	DD_ALIAS(ThisType, StronglyReferable<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	protected:
	DD_ALIAS(StrongPointerType, StrongPointer<ValueType>);
	DD_ALIAS(ConstStrongPointerType, StrongPointer<ValueConstType>);
	DD_ALIAS(WeakPointerType, WeakPointer<ValueType>);
	DD_ALIAS(ConstWeakPointerType, WeakPointer<ValueConstType>);

	private:
	DD_SPECIFIC_TYPE_NESTED(Manager, ReferenceManagerBase_);


	private:
	friend StrongPointer<void>;
#	if __cplusplus >= 201103L
	template <typename ValueT__>
	friend inline ProcessType try_set_manager_for_strongly_referable_(
		ReferenceManagerBase_* manager_pointer_,
		StronglyReferable<ValueT__>* pointer_
	) noexcept;
#	endif


	private:
	WeakPointerType m_weak_pointer_;


	protected:
	StronglyReferable() DD_NOEXCEPT;

	protected:
	StronglyReferable(ThisType const& origin_) DD_NOEXCEPT;

#	if __cplusplus >= 201103L
	protected:
	StronglyReferable(ThisType&& origin_) noexcept;

#	endif

	protected:
	StrongPointerType get_strong_pointer() DD_NOEXCEPT;

	protected:
	ConstStrongPointerType get_strong_pointer() const DD_NOEXCEPT;


	protected:
	WeakPointerType get_weak_pointer() DD_NOEXCEPT;

	protected:
	ConstWeakPointerType get_weak_pointer() const DD_NOEXCEPT;


	private:
	ProcessType set_manager_(ManagerPointerType manager_pointer_) DD_NOEXCEPT;


	protected:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT {
	}

#	if __cplusplus >= 201103L
	protected:
	ThisType& operator =(ThisType&& origin_) noexcept {
	}

#	endif

};



template <>
#	if __cplusplus >= 201103L
struct StrongPointer<void> : Comparable<StrongPointer<void>> {
#	else
struct StrongPointer<void> : Comparable<StrongPointer<void> > {
#	endif
	public:
	DD_ALIAS(ThisType, StrongPointer<void>);
	DD_VALUE_TYPE_NESTED(void)

	public:
	DD_ALIAS(ConstStrongType, StrongPointer<ValueConstType>);
	DD_ALIAS(WeakType, WeakPointer<ValueType>);
	DD_ALIAS(ConstWeakType, WeakPointer<ValueConstType>);

	protected:
	DD_SPECIFIC_TYPE_NESTED(Manager, ReferenceManagerBase_);


	public:
	friend ConstStrongType;
	friend WeakType;
	friend ConstWeakType;


	private:
	ManagerPointerType m_manager_pointer_ DD_IN_CLASS_INITIALIZE(get_nil_reference_manager_());


	public:
#	if __cplusplus >= 201103L
	StrongPointer() = default;
#	else
	StrongPointer() throw() : m_manager_pointer_(get_nil_reference_manager_()) {
	}
#	endif


	public:
	StrongPointer(ThisType const& origin_) DD_NOEXCEPT : m_manager_pointer_(origin_.get_manager_pointer_()) {
		get_manager_pointer_()->strongly_referred_();
	}

	public:
	StrongPointer(ThisType&& origin_) DD_NOEXCEPT : m_manager_pointer_(origin_.get_manager_pointer_()) {
		origin_.m_manager_pointer_ = get_nil_reference_manager_();
	}

	public:
	template <typename ValueT__>
	StrongPointer(ValueT__* pointer_) : m_manager_pointer_(
		create_manager_((DDCPP_DEFAULT_REFERENCE_MANAGER_ALLOCATOR), universal_deleter, pointer_, pointer_)
	) {
		get_manager_pointer_()->strongly_referred_();
	}

	protected:
	StrongPointer(ManagerPointerType manager_pointer_) DD_NOEXCEPT : m_manager_pointer_(manager_pointer_) {
		get_manager_pointer_()->strongly_referred_();
	}

#	if __cplusplus >= 201103L
	protected:
	StrongPointer(UnguardedTag tag_, ManagerPointerType manager_pointer_) DD_NOEXCEPT : m_manager_pointer_(manager_pointer_) {
	}

#	endif

	public:
	~StrongPointer() DD_NOEXCEPT {
		destruct_();
	}


	private:
	static ManagerPointerType get_nil_reference_manager_() DD_NOEXCEPT {
		return ManagerType::get_nil_reference_manager_();
	}


	protected:
	ManagerPointerType get_manager_pointer_() const DD_NOEXCEPT {
		return m_manager_pointer_;
	}


	public:
	PointerType get_global_pointer() const DD_NOEXCEPT {
		return get_manager_pointer_()->get_global_pointer_();
	}


	public:
	LengthType get_strong_reference_count() const DD_NOEXCEPT {
		return get_manager_pointer_()->get_strong_reference_count_();
	}


	public:
	LengthType get_weak_reference_count() const DD_NOEXCEPT {
		return get_manager_pointer_()->get_weak_reference_count_();
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return get_manager_pointer_() != get_nil_reference_manager_();
	}


	public:
	ValidityType is_unique() const DD_NOEXCEPT {
		return get_strong_reference_count() == LengthType(1);
	}


	public:
	ValidityType equal(ThisType const& other_) const DD_NOEXCEPT {
		return get_manager_pointer_() == other_.get_manager_pointer_();
	}


	public:
	ValidityType less(ThisType const& other_) const DD_NOEXCEPT {
		return get_manager_pointer_() < other_.get_manager_pointer_();
	}


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		::DD::swap(m_manager_pointer_, other_.m_manager_pointer_);
	}


	public:
	ProcessType reset() DD_NOEXCEPT {
		ThisType temp_;
		swap(temp_);
	}

	public:
	ProcessType reset(ThisType const& origin_) DD_NOEXCEPT {
		ThisType temp_(origin_);
		swap(temp_);
	}

#	if __cplusplus >= 201103L
	public:
	ProcessType reset(ThisType&& origin_) noexcept {
		swap(origin_);
	}

#	endif

	private:
	template <typename AllocatorT__, typename DeleterT__, typename ValueT__>
	static ManagerPointerType create_manager_(
		AllocatorT__ allocator___,
		DeleterT__ const& deleter___,
		ValueT__* pointer_,
		StronglyReferable<ValueT__>* strongly_referable_target_
	) {
		ManagerPointerType result_ = create_manager_(allocator___, deleter___, pointer_);
		strongly_referable_target_->set_manager_(result_);
		return result_;
	}

	private:
	template <typename AllocatorT__, typename DeleterT__, typename ValueT__>
	static ManagerPointerType create_manager_(
		AllocatorT__ allocator___,
		DeleterT__ const& deleter___,
		ValueT__* pointer_,
		void const volatile* workaround_
	) {
		if (pointer_) {
			ReferenceManager_<
				ValueT__, DeleterT__, Deleter<AllocatorT__>
			>* result_ = static_cast<ReferenceManager_<
				ValueT__, DeleterT__, Deleter<AllocatorT__>
			>*>(allocator___.AllocatorT__::Basic::allocate(sizeof(*result_)));
			try {
#	if __cplusplus >= 201103L
				::DD::construct(result_, deleter___, Deleter<AllocatorT__>(allocator___), pointer_);
#	else
				new (result_) ReferenceManager_<
					ValueT__, UniversalDeleter, Deleter<AllocatorT__>
				>(deleter___, Deleter<AllocatorT__>(allocator___), pointer_);
#	endif
			} catch (...) {
				allocator___.AllocatorT__::Basic::deallocate(result_, sizeof(*result_));
				throw;
			}
			return result_;
		}
		return get_nil_reference_manager_();
	}


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		get_manager_pointer_()->strongly_released_();
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT {
		reset(origin_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) noexcept {
		reset(::DD::move(origin_));
		return *this;
	}

#	endif

#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



#	if __cplusplus >= 201103L
template <typename ValueT_, typename... ArgumentsT_>
inline StrongPointer<ValueT_> make_strong(ArgumentsT_&&... arguments__);



#	endif
template <typename ValueT_>
#	if __cplusplus >= 201103L
struct StrongPointer : Comparable<StrongPointer<ValueT_>>, StrongPointer<void> {
#	else
struct StrongPointer : Comparable<StrongPointer<ValueT_> >, StrongPointer<void> {
#	endif
	public:
	DD_ALIAS(SuperType, StrongPointer<void>);
	DD_ALIAS(ThisType, StrongPointer<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(ConstStrongType, StrongPointer<ValueConstType>);
	DD_ALIAS(WeakType, WeakPointer<ValueType>);
	DD_ALIAS(ConstWeakType, WeakPointer<ValueConstType>);


	private:
	DD_SPECIFIC_TYPE_NESTED(Manager, ReferenceManagerBase_);


	public:
	friend WeakType;
	friend StrongPointer<DD_MODIFY_TRAIT(RemoveConst, ValueType)>;
#	if __cplusplus >= 201103L
	template <typename ValueT__, typename... ArgumentsT__>
	friend inline StrongPointer<ValueT__> make_strong(ArgumentsT__&&... arguments__);
#	endif



#	if __cplusplus >= 201103L
	public:
	StrongPointer() = default;

	public:
	StrongPointer(ThisType const& origin_) = default;

	public:
	StrongPointer(ThisType&& origin_) = default;
#	else
	public:
	StrongPointer() throw() : SuperType(get_nil_reference_manager_()) {
	}
#	endif

	public:
	StrongPointer(PointerType pointer_) : SuperType(pointer_) {
	}

	private:
	StrongPointer(ManagerPointerType manager_pointer_) : SuperType(manager_pointer_) {
	}

#	if __cplusplus >= 201103L
	private:
	StrongPointer(UnguardedTag tag_, ManagerPointerType manager_pointer_) : SuperType(tag_, manager_pointer_) {
	}

#	endif

#	if __cplusplus >= 201103L
	public:
	~StrongPointer() = default;


#	endif
	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return static_cast<PointerType>(get_global_pointer());
	}


	public:
	ValidityType equal(ThisType const& other_) const DD_NOEXCEPT {
		return SuperType::equal(other_);
	}


	public:
	ValidityType less(ThisType const& other_) const DD_NOEXCEPT {
		return SuperType::less(other_);
	}


	public:
	ConstStrongType get_const_strong_pointer() const DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		return ConstStrongType(get_manager_pointer_());
	}

#	if __cplusplus >= 201103L
	public:
	ConstStrongType get_const_strong_pointer() const DD_CALLABLE_WITH_RVALUE_ONLY DD_NOEXCEPT {
		ManagerPointerType manager_pointer_ = get_manager_pointer_();
		m_manager_pointer_ = get_nil_reference_manager_();
		return ConstStrongType(unguarded_tag, manager_pointer_);
	}

#	endif

	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		SuperType::swap(other_);
	}


	public:
	ProcessType reset() DD_NOEXCEPT {
		ThisType temp_();
		swap(temp_);
	}

#	if __cplusplus >= 201103L
	public:
	ProcessType reset(ThisType&& origin_) noexcept {
		swap(origin_);
	}

	public:
	template <typename ObjectT_>
	ProcessType reset(ObjectT_&& object__) noexcept(noexcept(ThisType(::DD::forward<ObjectT_>(object__)))) {
		ThisType temp_(::DD::forward<ObjectT_>(object__));
		swap(temp_);
	}
#	else
	public:
	template <typename ObjectT_>
	ProcessType reset(ObjectT_ const& object__) {
		ThisType temp_(object__);
		swap(temp_);
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;

	public:
	template <typename ObjectT__>
	ThisType& operator =(ObjectT__&& object___) noexcept(
		noexcept(::DD::fabricate<ThisType>().reset(::DD::forward<ObjectT__>(object___)))
	) {
		reset(::DD::forward<ObjectT__>(object___));
		return *this;
	}
#	else
	public:
	template <typename ObjectT__>
	ThisType& operator =(ObjectT__ const& object___) {
		reset(object___);
		return *this;
	}
#	endif


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *get_pointer();
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return get_pointer();
	}


};



#	if __cplusplus >= 201103L
template <typename ValueT_>
inline ProcessType try_set_manager_for_strongly_referable_(
	ReferenceManagerBase_* manager_pointer_,
	StronglyReferable<ValueT_>* pointer_
) noexcept {
	pointer_->set_manager_(manager_pointer_);
}



inline ProcessType try_set_manager_for_strongly_referable_(
	ReferenceManagerBase_* manager_pointer_,
	void const volatile* workaround_
) noexcept {
}



template <typename ValueT_, typename AllocatorT_, typename... ArgumentsT_>
inline AggregateReferenceManager_<ValueT_, Deleter<AllocatorT_>>* create_aggregate_reference_manager_(
	AllocatorT_ allocator__, ArgumentsT_&&... arguments__
) {
	AggregateReferenceManager_<
		ValueT_, Deleter<AllocatorT_>
	>* result_ = static_cast<AggregateReferenceManager_<
		ValueT_, Deleter<AllocatorT_>
	>*>(allocator__.AllocatorT_::Basic::allocate(sizeof(*result_)));
	try {
		::DD::construct(result_, Deleter<AllocatorT_>(allocator__), ::DD::forward<ArgumentsT_>(arguments__)...);
	} catch (...) {
		allocator__.AllocatorT_::Basic::deallocate(result_, sizeof(*result_));
		throw;
	}
	try_set_manager_for_strongly_referable_(result_, static_cast<ValueT_*>(result_->get_global_pointer_()));
	return result_;
}


template <typename ValueT_, typename... ArgumentsT_>
inline StrongPointer<ValueT_> make_strong(ArgumentsT_&&... arguments__) {
	return StrongPointer<ValueT_>(create_aggregate_reference_manager_<ValueT_>(
		(DDCPP_DEFAULT_REFERENCE_MANAGER_ALLOCATOR), ::DD::forward<ArgumentsT_>(arguments__)...
	));
}
#	else
template <typename ValueT_>
inline StrongPointer<ValueT_> make_strong() {
	return StrongPointer<ValueT_>(new ValueT_());
}

template <typename ValueT_, typename ArgumentT_>
inline StrongPointer<ValueT_> make_strong(ArgumentT_ const& argument__) {
	return StrongPointer<ValueT_>(new ValueT_(argument__));
}
#	endif



template <typename ValueT_>
inline ValidityType operator ==(
	StrongPointer<ValueT_> const& strong_pointer_1_, StrongPointer<ValueT_> const& strong_pointer_2_
) DD_NOEXCEPT {
	return strong_pointer_1_.equal(strong_pointer_2_);
}


template <typename ValueT_>
inline ValidityType operator <(
	StrongPointer<ValueT_> const& strong_pointer_1_, StrongPointer<ValueT_> const& strong_pointer_2_
) DD_NOEXCEPT {
	return strong_pointer_1_.less(strong_pointer_2_);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::StrongPointer;
using detail_::make_strong;



DD_END_



#endif
