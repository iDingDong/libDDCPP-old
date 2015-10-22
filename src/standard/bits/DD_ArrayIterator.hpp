//	DDCPP/standard/bits/DD_ArrayIterator.hpp
#ifndef DD_ARRAY_ITERATOR_HPP_INCLUDED_
#	define DD_ARRAY_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_ValueTypeNested.hpp"
#	include "DD_IteratorTrait.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct ArrayIterator {
	public:
	DD_ALIAS(ThisType, ArrayIterator<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_);

	public:
	DD_ALIAS(DifferenceType, DD::DifferenceType);
	DD_ALIAS(CatagoryType, FreeAccessIterator);

	public:
	DD_COMPAT_STL_ITERATOR


	private:
#	if __cplusplus >= 201103L
	PointerType m_pointer_ = PointerType();
#	else
	PointerType m_pointer_;
#	endif


#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR ArrayIterator() DD_NOEXCEPT = default;

	public:
	DD_CONSTEXPR ArrayIterator(ThisType const& origin_) DD_NOEXCEPT = default;
#	else
	DD_CONSTEXPR ArrayIterator() DD_NOEXCEPT : m_pointer_() {
	}
#	endif

	public:
	DD_CONSTEXPR ArrayIterator(PointerType pointer_) DD_NOEXCEPT : m_pointer_(pointer_) {
	};


#	if __cplusplus >= 201103L
	public:
	~ArrayIterator() noexcept(true) = default;


#	endif
	public:
	ValidityType DD_CONSTEXPR equal(ThisType const& target_) const DD_NOEXCEPT {
		return this->m_pointer_ == target_.m_pointer_;
	}


	public:
	ValidityType DD_CONSTEXPR less(ThisType const& target_) const DD_NOEXCEPT {
		return this->m_pointer_ < target_.m_pointer_;
	}


	public:
	ValidityType DD_CONSTEXPR distance(ThisType const& target_) const DD_NOEXCEPT {
		return target_.m_pointer_ - this->m_pointer_;
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return this->m_pointer_;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) & noexcept(true) = default;


#	endif
	public:
	ThisType& operator ++() DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		++this->m_pointer_;
		return *this;
	}

	public:
	ThisType operator ++(int) DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		return ThisType(this->m_pointer_++);
	}


	public:
	ThisType& operator --() DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		--this->m_pointer_;
		return *this;
	}

	public:
	ThisType operator --(int) DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		return ThisType(this->m_pointer_++);
	}


	public:
	ThisType& operator +=(DifferenceType step_) DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		this->m_pointer_ += step_;
		return *this;
	}


	public:
	ThisType& operator -=(DifferenceType step_) DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		this->m_pointer_ -= step_;
		return *this;
	}


	public:
	ReferenceType operator [](DifferenceType index_) const DD_NOEXCEPT {
		return this->m_pointer_[index_];
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *this->m_pointer_;
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return *this->m_pointer_;
	}


	public:
#	if __cplusplus >= 201103L
	explicit operator ValidityType() const DD_NOEXCEPT {
		return this->m_pointer_;
	}


#	endif
};



template <typename ValueT_>
inline ArrayIterator<ValueT_> DD_CONSTEXPR operator +(ArrayIterator<ValueT_> array_iterator_, typename ArrayIterator<ValueT_>::DifferenceType step_) DD_NOEXCEPT {
	return array_iterator_ += step_;
}

template <typename ValueT_>
inline ArrayIterator<ValueT_> DD_CONSTEXPR operator +(typename ArrayIterator<ValueT_>::DifferenceType step_, ArrayIterator<ValueT_> array_iterator_) DD_NOEXCEPT {
	return array_iterator_ += step_;
}


template <typename ValueT_>
inline typename ArrayIterator<ValueT_>::DifferenceType DD_CONSTEXPR operator -(
	ArrayIterator<ValueT_> const& array_iterator_1_,
	ArrayIterator<ValueT_> const& array_iterator_2_
) DD_NOEXCEPT {
	return array_iterator_2_.distance(array_iterator_1_);
}

template <typename ValueT_>
inline ArrayIterator<ValueT_> DD_CONSTEXPR operator -(ArrayIterator<ValueT_> array_iterator_, typename ArrayIterator<ValueT_>::DifferenceType step_) DD_NOEXCEPT {
	return array_iterator_ -= step_;
}


template <typename ValueT_>
inline ValidityType DD_CONSTEXPR operator ==(ArrayIterator<ValueT_> const& array_iterator_1_, ArrayIterator<ValueT_> const& array_iterator_2_) DD_NOEXCEPT {
	return array_iterator_1_.equal(array_iterator_2_);
}


template <typename ValueT_>
inline ValidityType DD_CONSTEXPR operator <(ArrayIterator<ValueT_> const& array_iterator_1_, ArrayIterator<ValueT_> const& array_iterator_2_) DD_NOEXCEPT {
	return array_iterator_1_.less(array_iterator_2_.m_pointer);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::ArrayIterator;



DD_END_



#endif
