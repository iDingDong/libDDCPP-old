//	DDCPP/dummy/bits/DD_Identification.hpp
#ifndef DD_IDENTIFICATION_HPP_INCLUDED_
#	define DD_IDENTIFICATION_HPP_INCLUDED_ 1



#	include "DD_Object.hpp"
#	include "../../standard/bits/DD_ValueType.hpp"
#	include "../../concurrence/bits/DD_Atomic.hpp"
#	include "../../concurrence/bits/DD_AtomicFlag.hpp"



#	if !defined(DDCPP_ENABLE_OBJECT_REFERENCE_COUNT)
#		define DDCPP_ENABLE_OBJECT_REFERENCE_COUNT DD_ON
#	endif
#	if !defined(DDCPP_ENABLE_INSTANT_RECYCLE)
#		define DDCPP_ENABLE_INSTANT_RECYCLE DD_ON
#	endif



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct Link;



struct Identification : virtual Object {
	public:
	using SuperType = Object;
	using ThisType = Identification;


	public:
	friend Link<ThisType>;


	private:
	AtomicFlag m_reachable_ = DD_INITIAL_ATOMIC_FLAG;
#	if DDCPP_ENABLE_OBJECT_REFERENCE_COUNT
	Atomic<LengthType> m_reference_count_ = Atomic
#	endif


	public:
	constexpr Identification() = default;

	public:
	constexpr Identification(ThisType const& origin_) noexcept {
	}

	public:
	constexpr Identification(ThisType&& origin_) noexcept {
	}


	public:
	~Identification() override = default;


#	if DDCPP_ENABLE_OBJECT_REFERENCE_COUNT
	public:
	LengthType get_reference_count() noexcept {
		return m_reference_count_.load();
	}


#	endif
	public:
	ThisType& operator =(ThisType const& origin_) noexcept {
	}

	public:
	ThisType& operator =(ThisType&& origin_) noexcept {
	}


};



template <>
struct Link<Identification> {
	public:
	using ThisType = Link;
	DD_VALUE_TYPE_NESTED(Identification);


	private:
	Atomic<PointerType> m_pointer_ = Atomic<PointerType>();


	public:
	constexpr Link() = default;


	public:
#	if DDCPP_ENABLE_OBJECT_REFERENCE_COUNT
	Link(ThisType const& origin_) noexcept : m_pointer_(origin_.get_pointer()) {
		get_pointer()->refered();
	}
#	else
	constexpr Link(ThisType const& origin_) noexcept : m_pointer_(origin_.get_pointer()) {
	}
#	endif

	public:
	Link(ThisType&& origin_) noexcept : m_pointer_(origin_.get_pointer()) {
	}


	public:
	PointerType get_pointer() noexcept {
		m_pointer_.load();
	}

	public:
	ConstPointerType get_pointer() const noexcept {
		return m_pointer_.load();
	}


};



template <typename ValueT_>
struct Link : Link<Identification> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Identification;



DD_END_



#endif
