//	DDCPP/standard/bits/DD_IntrusivePointer.hpp
#ifndef DD_INTRUSIVE_POINTER_HPP_INCLUDED_
#	define DD_INTRUSIVE_POINTER_HPP_INCLUDED_ 1



#	include "DD_fabricate.hpp"
#	include "DD_Agent.hpp"
#	include "DD_Destroy.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
ProcessType refer_intrusived(ValueT_* pointer_) DD_NOEXCEPT {
	pointer_->intrusively_referred();
}


template <typename ValueT_>
ProcessType release_intrusived(ValueT_* pointer_) DD_NOEXCEPT {
	pointer_->intrusively_released();
}


template <typename ValueT_>
LengthType get_intrusived_reference_count(ValueT_* pointer_) DD_NOEXCEPT {
	return pointer_->intrusively_get_reference_count();
}


template <typename ValueT_>
ProcessType destroy_intrusived(ValueT_* pointer_) DD_NOEXCEPT {
	::DD::destroy(pointer_, pointer_->get_deleter());
}



template <typename DeleterT_ = UniversalDeleter>
struct Intrusive : protected Agent<DeleterT_> {
	protected:
	DD_ALIAS(DestroyAgent, Agent<DeleterT_>);
	DD_ALIAS(ThisType, Intrusive);
	DD_ALIAS(DeleterType, DeleterT_);


	private:
	template <typename ValueT__>
	friend ProcessType refer_intrusived(ValueT__* pointer_) DD_NOEXCEPT;


	private:
	template <typename ValueT__>
	friend ProcessType release_intrusived(ValueT__* pointer_) DD_NOEXCEPT;


	private:
	template <typename ValueT__>
	friend LengthType get_intrusived_reference_count(ValueT__* pointer_) DD_NOEXCEPT;


	private:
	template <typename ValueT__>
	friend ProcessType destroy_intrusived(ValueT__* pointer_) DD_NOEXCEPT;


	private:
	LengthType mutable m_reference_count_ DD_IN_CLASS_INITIALIZE(LengthType());


	protected:
#	if __cplusplus >= 201103L
	constexpr Intrusive() = default;
#	else
	Intrusive() : m_reference_count_() {
	}
#	endif

	protected:
	DD_DELETE_COPY_CONSTRUCTOR(Intrusive)

	protected:
	DD_DELETE_MOVE_CONSTRUCTOR(Intrusive)


	protected:
	ProcessType intrusively_referred() const DD_NOEXCEPT {
		++m_reference_count_;
	}


	protected:
	ProcessType intrusively_released() const DD_NOEXCEPT {
		--m_reference_count_;
	}


	protected:
	LengthType intrusively_get_reference_count() const DD_NOEXCEPT {
		return m_reference_count_;
	}


	protected:
	UniversalDeleter get_deleter() const DD_NOEXCEPT {
		return DestroyAgent::get_instance();
	}


	protected:
	DD_DELETE_ALL_ASSIGNMENTS(Intrusive)


};



template <typename ValueT_>
struct IntrusivePointer {
	public:
	DD_ALIAS(ThisType, IntrusivePointer<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);


	public:
	template <typename ValueT__>
	friend struct IntrusivePointer;


	private:
	PointerType m_pointer_ DD_IN_CLASS_INITIALIZE(PointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr IntrusivePointer() = default;
#	else
	IntrusivePointer() throw() : m_pointer_() {
	}
#	endif

	public:
	IntrusivePointer(ThisType const& origin_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().process_after_refer_()
	) : m_pointer_(origin_.get_pointer()) {
		process_after_refer_();
	}

#	if __cplusplus >= 201103L
	public:
	IntrusivePointer(ThisType&& origin_) DD_NOEXCEPT : m_pointer_(origin_.get_pointer()) {
		origin_.m_pointer_ = PointerType();
	}

#	endif
	public:
	template <typename ValueT__>
	IntrusivePointer(IntrusivePointer<ValueT__> const& origin_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().process_after_refer_()
	) : m_pointer_(origin_.get_pointer()) {
		process_after_refer_();
	}

#	if __cplusplus >= 201103L
	public:
	template <typename ValueT__>
	IntrusivePointer(IntrusivePointer<ValueT__>&& origin_) DD_NOEXCEPT : m_pointer_(origin_.get_pointer()) {
		origin_.m_pointer_ = typename IntrusivePointer<ValueT__>::PointerType();
	}

#	endif
	public:
	IntrusivePointer(PointerType pointer_) DD_NOEXCEPT_AS(
		::DD::fabricate<ThisType>().process_after_refer_()
	) : m_pointer_(pointer_) {
		process_after_refer_();
	}


	public:
	~IntrusivePointer() DD_NOEXCEPT {
		destruct_();
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return m_pointer_;
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return get_pointer();
	}


	public:
	LengthType unguarded_get_reference_count() const DD_NOEXCEPT {
		return get_intrusived_reference_count(get_pointer());
	}


	public:
	LengthType get_reference_count() const DD_NOEXCEPT {
		return is_valid() ? unguarded_get_reference_count() : LengthType();
	}


	private:
	ProcessType process_after_refer_() const DD_NOEXCEPT_AS(
		refer_intrusived(::DD::fabricate<ThisType>().get_pointer())
	) {
		if (is_valid()) {
			refer_intrusived(get_pointer());
		}
	}


	public:
	ProcessType swap(ThisType& other_) DD_NOEXCEPT {
		::DD::swap(m_pointer_, other_.m_pointer_);
	}


	public:
	ProcessType reset() DD_NOEXCEPT {
		destruct_();
		m_pointer_ = PointerType();
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


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		if (is_valid()) {
			release_intrusived(get_pointer());
			if (!unguarded_get_reference_count()) {
				destroy_intrusived(get_pointer());
			}
		}
	}


	public:
	ThisType& operator =(ThisType const& origin_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().reset(origin_)) {
		reset(origin_);
		return *this;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& origin_) noexcept(noexcept(::DD::fabricate<ThisType>().reset(::DD::move(origin_)))) {
		reset(::DD::move(origin_));
		return *this;
	}

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
	ReferenceType DD_CONSTEXPR operator *() const DD_NOEXCEPT {
		return *get_pointer();
	}


	public:
	PointerType DD_CONSTEXPR operator ->() const DD_NOEXCEPT {
		return get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit constexpr operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Intrusive;

using detail_::IntrusivePointer;



DD_END_



#endif
