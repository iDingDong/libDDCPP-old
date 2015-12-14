//	DDCPP/standard/bits/DD_BackPushIterator.hpp
#ifndef DD_BACK_PUSH_ITERATOR_HPP_INCLUDED_
#	define DD_BACK_PUSH_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_IteratorCatagory.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_address_of.hpp"



DD_DETAIL_BEGIN_;
template <typename ContainerT_>
struct BackPushIterator;



template <typename ContainerT_>
struct BackPushProxy_ {
	public:
	DD_ALIAS(ThisType, BackPushProxy_<ContainerT_>);
	DD_ALIAS(ContainerType, ContainerT_);

	public:
	DD_ALIAS(ContainerReferenceType, ContainerType&);
	DD_ALIAS(ContainerPointerType, ContainerType*);
	DD_ALIAS(ValueType, void);
	DD_ALIAS(ConstValueType, void);
	DD_ALIAS(ReferenceType, void);
	DD_ALIAS(ReferenceConstType, void);
	DD_ALIAS(PointerType, void);
	DD_ALIAS(PointerConstType, void);
	DD_ALIAS(DifferenceType, void);


	public:
	friend BackPushIterator<ContainerType>;


	private:
	ContainerPointerType m_target_;


#	if __cplusplus >= 201103L
	private:
	BackPushProxy_() = delete;

	private:
	constexpr BackPushProxy_(ThisType const& origin_) = default;

	private:
	constexpr BackPushProxy_(ThisType&& origin_) = default;
#	else
	private:
	BackPushProxy_(ThisType const& origin_) throw() : m_target_(origin_.m_target_) {
	}
#	endif

	private:
	DD_CONSTEXPR BackPushProxy_(ContainerPointerType container_) DD_NOEXCEPT : m_target_(container_) {
	}


#	if __cplusplus >= 201103L
	public:
	~BackPushProxy_() = default;


#	endif
	public:
	ContainerPointerType get_container_pointer() const DD_NOEXCEPT {
		return m_target_;
	}


#	if __cplusplus >= 201103L
	private:
	ThisType& operator =(ThisType const& origin_) = default;

	private:
	ThisType& operator =(ThisType&& origin_) = default;

	public:
	template <typename ValueT__>
	ThisType const& operator =(ValueT__&& value___) const noexcept(
		noexcept(fabricate<ThisType>().get_container_pointer()->push_back(forward<ValueT__>(value___)))
	) {
		get_container_pointer()->push_back(forward<ValueT__>(value___));
	}
#	else
	private:
	ThisType& operator =(ThisType const& origin_) throw() {
		m_target_ = origin_.m_target_;
	}

	public:
	template <typename ValueT__>
	ThisType const& operator =(ValueT__ const& value___) const {
		get_container_pointer()->push_back(value___);
	}
#	endif


};



template <typename ContainerT_>
struct BackPushIterator {
	public:
	DD_ALIAS(ThisType, BackPushIterator<ContainerT_>);
	DD_ALIAS(ContainerType, ContainerT_);

	public:
	DD_ALIAS(ContainerReferenceType, ContainerType&);
	DD_ALIAS(ContainerPointerType, ContainerType*);
	DD_ALIAS(ValueType, void);
	DD_ALIAS(ConstValueType, void);
	DD_ALIAS(ReferenceType, void);
	DD_ALIAS(ReferenceConstType, void);
	DD_ALIAS(PointerType, void);
	DD_ALIAS(PointerConstType, void);
	DD_ALIAS(DifferenceType, void);


	private:
	ContainerPointerType m_target_ DD_IN_CLASS_INITIALIZE(ContainerPointerType());


#	if __cplusplus >= 201103L
	public:
	constexpr BackPushIterator() = default;

	public:
	constexpr BackPushIterator(ThisType const& origin_) = default;

	public:
	constexpr BackPushIterator(ThisType&& origin_) = default;
#	else
	public:
	BackPushIterator() throw() : m_target_() {
	}
#	endif

	public:
	DD_CONSTEXPR BackPushIterator(ContainerReferenceType container_) DD_NOEXCEPT : m_target_(address_of(container_)) {
	}


#	if __cplusplus >= 201103L
	public:
	~BackPushIterator() = default;


#	endif
	public:
	ContainerPointerType get_container_pointer() const DD_NOEXCEPT {
		return m_target_;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
	public:
	BackPushProxy_<ContainerType> operator *() const DD_NOEXCEPT_AS(
		BackPushProxy_<ContainerType>(fabricate<ThisType>().get_container_pointer())
	) {
		return BackPushProxy_<ContainerType>(get_container_pointer());
	}


	public:
	ThisType& operator ++() DD_NOEXCEPT {
		return *this;
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::BackPushIterator;



DD_END_



#endif
