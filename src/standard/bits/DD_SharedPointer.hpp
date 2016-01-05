//	DDCPP/standard/bits/DD_SharedPointer.hpp
#ifndef DD_SHARED_POINTER_HPP_INCLUDED_
#	define DD_SHARED_POINTER_HPP_INCLUDED_ 1



#	include "DD_StrongPointer.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct ObserverPointer;



template <typename ValueT_>
#	if __cplusplus >= 201103L
struct SharedPointer : Comparable<SharedPointer<ValueT_>>, StrongPointer<void> {
#	else
struct SharedPointer : Comparable<SharedPointer<ValueT_> >, StrongPointer<void> {
#	endif
	public:
	DD_ALIAS(SuperType, StrongPointer<void>);
	DD_ALIAS(ThisType, SharedPointer<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	DD_ALIAS(ObserverType, ObserverPointer<ValueType>);


	private:
	PointerType m_pointer_ DD_IN_CLASS_INITIALIZE(PointerType());


#	if __cplusplus >= 201103L
	public:
	SharedPointer() = default;

	public:
	SharedPointer(ThisType const& origin_) = default;

	public:
	SharedPointer(ThisType&& origin_) = default;
#	else
	public:
	SharedPointer() throw() : SuperType(get_nil_reference_manager_()) {
	}
#	endif

	public:
	SharedPointer(PointerType pointer_) : SuperType(pointer_), m_pointer_(pointer_) {
	}

	public:
	SharedPointer(StrongPointer<ValueType> const& origin_) : SuperType(origin_), m_pointer_(origin_.get_pointer()) {
	}

#	if __cplusplus >= 201103L
	public:
	SharedPointer(StrongPointer<ValueType>&& origin_) noexcept :
		SuperType(::DD::move(origin_)),
		m_pointer_(static_cast<PointerType>(SuperType::get_global_pointer()))
	{
	}

#	endif
	public:
	template <typename ValueT__>
	explicit SharedPointer(StrongPointer<ValueT__> const& origin_) : SuperType(origin_), m_pointer_(origin_.get_pointer()) {
	}

#	if __cplusplus >= 201103L
	public:
	template <typename ValueT__>
	explicit SharedPointer(StrongPointer<ValueT__>&& origin_) noexcept :
		SuperType(::DD::move(origin_)),
		m_pointer_(static_cast<PointerType>(SuperType::get_global_pointer()))
	{
	}

#	endif
	public:
	template <typename ValueT__>
	explicit SharedPointer(SharedPointer<ValueT__> const& origin_) : SuperType(origin_), m_pointer_(origin_.get_pointer()) {
	}

#	if __cplusplus >= 201103L
	public:
	template <typename ValueT__>
	explicit SharedPointer(SharedPointer<ValueT__>&& origin_) noexcept : SuperType(::DD::move(origin_)), m_pointer_(origin_.get_pointer()) {
	}

#	endif
	public:
	template <typename ValueT__>
	explicit SharedPointer(ValueT__* pointer_) : SuperType(pointer_), m_pointer_(pointer_) {
	}


#	if __cplusplus >= 201103L
	public:
	~SharedPointer() = default;


#	endif
	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return m_pointer_;
	}


	public:
	ProcessType swap(ThisType& other_) {
		SuperType::swap(other_);
		::DD::swap(m_pointer_, other_.m_pointer_);
	}


	public:
	ProcessType reset() DD_NOEXCEPT {
		ThisType temp_;
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
		ThisType temp_ = ::DD::forward<ObjectT_>(object__);
		swap(temp_);
	}
#	else
	public:
	template <typename ObjectT_>
	ProcessType reset(ObjectT_ const& object__) {
		ThisType temp_ = object__;
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
inline SharedPointer<ValueT_> make_shared(ArgumentsT_&&... arguments__) noexcept(
	noexcept(SharedPointer<ValueT_>(::DD::make_strong<ValueT_>(::DD::forward<ArgumentsT_>(arguments__)...)))
) {
	return SharedPointer<ValueT_>(::DD::make_strong<ValueT_>(::DD::forward<ArgumentsT_>(arguments__)...));
}
#	else
template <typename ValueT_>
inline SharedPointer<ValueT_> make_shared() {
	return SharedPointer<ValueT_>(::DD::make_strong<ValueT_>());
}

template <typename ValueT_, typename ArgumentT_>
inline SharedPointer<ValueT_> make_shared(ArgumentT_ const& argument__) {
	return SharedPointer<ValueT_>(::DD::make_strong<ValueT_>(argument__));
}
#	endif



template <typename ValueT_>
inline ValidityType operator ==(
	SharedPointer<ValueT_> const& shared_pointer_1_, SharedPointer<ValueT_> const& shared_pointer_2_
) DD_NOEXCEPT {
	return shared_pointer_1_.get_global_pointer() == shared_pointer_2_.get_global_pointer();
}

template <typename ValueT_>
inline ValidityType operator <(
	SharedPointer<ValueT_> const& shared_pointer_1_, SharedPointer<ValueT_> const& shared_pointer_2_
) DD_NOEXCEPT {
	return shared_pointer_1_.get_global_pointer() < shared_pointer_2_.get_global_pointer();
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::SharedPointer;

using detail_::make_shared;



DD_END_



#endif
