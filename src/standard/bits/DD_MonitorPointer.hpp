//	DDCPP/standard/bits/DD_MonitorPointer.hpp
#ifndef DD_MONITOR_POINTER_HPP_INCLUDED_
#	define DD_MONITOR_POINTER_HPP_INCLUDED_ 1



#	include "DD_WeakPointer.hpp"
#	include "DD_SharedPointer.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
#	if __cplusplus >= 201103L
struct MonitorPointer : Comparable<MonitorPointer<ValueT_>>, WeakPointer<void> {
#	else
struct MonitorPointer : Comparable<MonitorPointer<ValueT_> >, WeakPointer<void> {
#	endif
	public:
	DD_ALIAS(SuperType, WeakPointer<void>);
	DD_ALIAS(ThisType, MonitorPointer<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	DD_ALIAS(SharedType, SharedPointer<ValueType>);


	private:
	PointerType m_pointer_ DD_IN_CLASS_INITIALIZE(PointerType());


#	if __cplusplus >= 201103L
	public:
	MonitorPointer() = default;

	public:
	MonitorPointer(ThisType const& origin_) = default;

	public:
	MonitorPointer(ThisType&& origin_) = default;
#	else
	public:
	MonitorPointer() throw() : SuperType(get_nil_reference_manager_()) {
	}
#	endif

	public:
	MonitorPointer(PointerType pointer_) : SuperType(pointer_), m_pointer_(pointer_) {
	}

	public:
	MonitorPointer(WeakPointer<ValueType> const& origin_) :
		SuperType(origin_),
		m_pointer_(static_cast<PointerType>(SuperType::get_manager_pointer_().get_global_pointer_()))
	{
	}

#	if __cplusplus >= 201103L
	public:
	MonitorPointer(WeakPointer<ValueType>&& origin_) noexcept :
		SuperType(::DD::move(origin_)),
		m_pointer_(static_cast<PointerType>(SuperType::get_manager_pointer_().get_global_pointer_()))
	{
	}

#	endif
	public:
	template <typename ValueT__>
	explicit MonitorPointer(WeakPointer<ValueT__> const& origin_) :
		SuperType(origin_),
		m_pointer_(static_cast<PointerType>(SuperType::get_manager_pointer_().get_global_pointer_())) {
	}

#	if __cplusplus >= 201103L
	public:
	template <typename ValueT__>
	explicit MonitorPointer(WeakPointer<ValueT__>&& origin_) noexcept :
		SuperType(::DD::move(origin_)),
		m_pointer_(static_cast<PointerType>(SuperType::get_manager_pointer_().get_global_pointer_()))
	{
	}

#	endif
	public:
	template <typename ValueT__>
	explicit MonitorPointer(MonitorPointer<ValueT__> const& origin_) : SuperType(origin_), m_pointer_(origin_.get_pointer()) {
	}

#	if __cplusplus >= 201103L
	public:
	template <typename ValueT__>
	explicit MonitorPointer(
		MonitorPointer<ValueT__>&& origin_
	) noexcept : SuperType(::DD::move(origin_)), m_pointer_(origin_.get_pointer()) {
	}

#	endif
	public:
	template <typename ValueT__>
	explicit MonitorPointer(SharedPointer<ValueT__> const& origin_) : SuperType(origin_), m_pointer_(origin_.get_pointer()) {
	}


#	if __cplusplus >= 201103L
	public:
	~MonitorPointer() = default;


#	endif
	public:
	ProcessType swap(ThisType& other_) {
		SuperType::swap(other_);
		::DD::swap(m_pointer_, other_.m_pointer_);
	}


	public:
	SharedType lock() DD_NOEXCEPT {
		return SharedType(SuperType::lock());
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


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::MonitorPointer;



DD_END_



#endif
