//	DDCPP/standard/bits/DD_StrongPointer.hpp
#ifndef DD_SRONG_POINTER_HPP_INCLUDED_
#	define DD_SRONG_POINTER_HPP_INCLUDED_ 1



#	include "DD_SpecificTypeNested.hpp"
#	include "DD_address_of.hpp"
#	include "DD_Deleter.hpp"
#	include "DD_Destroy.hpp"
#	include "DD_construct.hpp"
#	include "DD_ReferenceCounter.hpp"
#	include "DD_Pair.hpp"



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


	private:
	GlobalPointerType get_global_pointer_() const DD_NOEXCEPT DD_OVERRIDE {
		return get_pointer_();
	}


	private:
	LengthType get_strong_reference_count_() const DD_NOEXCEPT DD_OVERRIDE {
		return get_strong_reference_count();
	}


	private:
	LengthType get_weak_reference_count_() const DD_NOEXCEPT DD_OVERRIDE {
		return get_weak_reference_count();
	}


	private:
	ProcessType strongly_referred_() DD_NOEXCEPT DD_OVERRIDE {
		strongly_referred();
	}


	private:
	ProcessType weakly_referred_() DD_NOEXCEPT DD_OVERRIDE {
		weakly_referred();
	}


	private:
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


	private:
	ProcessType weakly_released_() DD_NOEXCEPT DD_OVERRIDE {
		if (is_expired() && is_unique_weak_reference()) {
			destroy_this_();
		} else {
			weakly_released();
		}
	}


	private:
	ProcessType destroy_target_() DD_NOEXCEPT {
		::DD::destroy(get_pointer_(), DestroyAgent::get_instance());
	}


	private:
	ProcessType destroy_this_() DD_NOEXCEPT {
		::DD::destroy(this, DestroyThisAgent::get_instance());
	}


	private:
	DD_DELETE_ALL_ASSIGNMENTS(ReferenceManager_)


};



template <typename ValueT_>
struct StrongPointer;



template <>
struct StrongPointer<void> {
	public:
	DD_ALIAS(ThisType, StrongPointer<void>);
	DD_ALIAS(ValueType, void);

	public:
	DD_ALIAS(ValueConstType, void);
	DD_ALIAS(ReferenceType, void);
	DD_ALIAS(ConstReferenceType, void);
	DD_ALIAS(PointerType, void*);
	DD_ALIAS(ConstPointerType, void*);

	public:
	DD_SPECIFIC_TYPE_NESTED(Manager, ReferenceManagerBase_);


	private:
	ManagerPointerType m_manager_pointer_ DD_IN_CLASS_INITIALIZE(get_nil_reference_manager_());


	public:
#	if __cplusplus >= 201103L
	constexpr StrongPointer() = default;
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
		create_manager_((DDCPP_DEFAULT_REFERENCE_MANAGER_ALLOCATOR), universal_deleter, pointer_)
	) {
		get_manager_pointer_()->strongly_referred_();
	}

	protected:
	StrongPointer(ManagerPointerType manager_pointer_) DD_NOEXCEPT : m_manager_pointer_(manager_pointer_) {
		get_manager_pointer_()->strongly_referred_();
	}


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


	protected:
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
	static ManagerPointerType create_manager_(AllocatorT__ allocator___, DeleterT__ const& deleter___, ValueT__* pointer_) {
		if (pointer_) {
			ReferenceManager_<
				ValueT__, DeleterT__, Deleter<AllocatorT__>
			>* result_ = static_cast<ReferenceManager_<
				ValueT__, DeleterT__, Deleter<AllocatorT__>
			>*>(allocator___.AllocatorT__::Basic::allocate(
				sizeof(ReferenceManager_<ValueT__, DeleterT__, Deleter<AllocatorT__>>)
			));
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



template <typename ValueT_>
struct WeakPointer;



template <typename ValueT_>
struct StrongPointer : StrongPointer<void> {
	public:
	DD_ALIAS(SuperType, StrongPointer<void>);
	DD_ALIAS(ThisType, StrongPointer<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(WeakType, WeakPointer<ValueType>);

	private:
	DD_SPECIFIC_TYPE_NESTED(Manager, ReferenceManagerBase_);


	public:
	friend WeakType;


#	if __cplusplus >= 201103L
	public:
	constexpr StrongPointer() = default;

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
	public:
	~StrongPointer() = default;


#	endif
	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return static_cast<PointerType>(get_global_pointer());
	}


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
template <typename ValueT_, typename... ArgumentsT_>
StrongPointer<ValueT_> make_strong(ArgumentsT_&&... arguments__) {
	return StrongPointer<ValueT_>(new ValueT_(::DD::forward<ArgumentsT_>(arguments__)...));
}
#	else
template <typename ValueT_>
StrongPointer<ValueT_> make_strong() {
	return StrongPointer<ValueT_>(new ValueT_());
}

template <typename ValueT_, typename ArgumentT_>
StrongPointer<ValueT_> make_strong(ArgumentT_ const& argument__) {
	return StrongPointer<ValueT_>(new ValueT_(argument__));
}
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::StrongPointer;
using detail_::make_strong;



DD_END_



#endif
