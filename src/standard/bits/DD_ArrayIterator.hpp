//	DDCPP/standard/bits/DD_ArrayIterator.hpp
#ifndef _DD_ARRAY_ITERATOR_HPP_INCLUDED
#	define _DD_ARRAY_ITERATOR_HPP_INCLUDED 1



#	include "DD_IteratorTrait.hpp"



_DD_BEGIN
template <typename _ValueT>
struct ArrayIterator {
	public:
	DD_ALIAS(ThisType, ArrayIterator<_ValueT>)
	DD_ALIAS(ValueType, _ValueT)

	public:
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(DifferenceType, DD::DifferenceType)
	DD_ALIAS(CatagoryType, FreeAccessIterator)

	public:
	DD_COMPAT_STL_ITERATOR


	private:
#	if __cplusplus >= 201103L
	PointerType _m_pointer = PointerType();
#	else
	PointerType _m_pointer;
#	endif


#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR ArrayIterator() DD_NOEXCEPT = default;

	public:
	DD_CONSTEXPR ArrayIterator(ThisType const& _origin) DD_NOEXCEPT = default;
#	else
	DD_CONSTEXPR ArrayIterator() DD_NOEXCEPT : _m_pointer() {
	}
#	endif

	public:
	DD_CONSTEXPR ArrayIterator(PointerType _pointer) DD_NOEXCEPT : _m_pointer(_pointer) {
	};


#	if __cplusplus >= 201103L
	public:
	~ArrayIterator() noexcept(true) = default;


#	endif
	public:
	ValidityType DD_CONSTEXPR equal(ThisType const& _target) const DD_NOEXCEPT {
		return this->_m_pointer == _target._m_pointer;
	}


	public:
	ValidityType DD_CONSTEXPR less(ThisType const& _target) const DD_NOEXCEPT {
		return this->_m_pointer < _target._m_pointer;
	}


	public:
	ValidityType DD_CONSTEXPR distance(ThisType const& _target) const DD_NOEXCEPT {
		return _target._m_pointer - this->_m_pointer;
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT {
		return this->_m_pointer;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& _origin) & noexcept(true) = default;


#	endif
	public:
	ThisType& operator ++() DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		++this->_m_pointer;
		return *this;
	}

	public:
	ThisType operator ++(int) DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		return ThisType(this->_m_pointer++);
	}


	public:
	ThisType& operator --() DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		--this->_m_pointer;
		return *this;
	}

	public:
	ThisType operator --(int) DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		return ThisType(this->_m_pointer++);
	}


	public:
	ThisType& operator +=(DifferenceType _step) DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		this->_m_pointer += _step;
		return *this;
	}


	public:
	ThisType& operator -=(DifferenceType _step) DD_CALLABLE_WITH_LVALUE_ONLY DD_NOEXCEPT {
		this->_m_pointer -= _step;
		return *this;
	}


	public:
	ReferenceType operator [](DifferenceType _index) const DD_NOEXCEPT {
		return this->_m_pointer[_index];
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *this->_m_pointer;
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return *this->_m_pointer;
	}


	public:
#	if __cplusplus >= 201103L
	explicit operator ValidityType() const DD_NOEXCEPT {
		return this->_m_pointer;
	}


#	endif
};



template <typename _ValueT>
inline ArrayIterator<_ValueT> DD_CONSTEXPR operator +(ArrayIterator<_ValueT> _array_iterator, typename ArrayIterator<_ValueT>::DifferenceType _step) DD_NOEXCEPT {
	return _array_iterator += _step;
}

template <typename _ValueT>
inline ArrayIterator<_ValueT> DD_CONSTEXPR operator +(typename ArrayIterator<_ValueT>::DifferenceType _step, ArrayIterator<_ValueT> _array_iterator) DD_NOEXCEPT {
	return _array_iterator += _step;
}


template <typename _ValueT>
inline typename ArrayIterator<_ValueT>::DifferenceType DD_CONSTEXPR operator -(
	ArrayIterator<_ValueT> const& _array_iterator_1,
	ArrayIterator<_ValueT> const& _array_iterator_2
) DD_NOEXCEPT {
	return _array_iterator_2.distance(_array_iterator_1);
}

template <typename _ValueT>
inline ArrayIterator<_ValueT> DD_CONSTEXPR operator -(ArrayIterator<_ValueT> _array_iterator, typename ArrayIterator<_ValueT>::DifferenceType _step) DD_NOEXCEPT {
	return _array_iterator -= _step;
}


template <typename _ValueT>
inline ValidityType DD_CONSTEXPR operator ==(ArrayIterator<_ValueT> const& _array_iterator_1, ArrayIterator<_ValueT> const& _array_iterator_2) DD_NOEXCEPT {
	return _array_iterator_1.equal(_array_iterator_2);
}


template <typename _ValueT>
inline ValidityType DD_CONSTEXPR operator <(ArrayIterator<_ValueT> const& _array_iterator_1, ArrayIterator<_ValueT> const& _array_iterator_2) DD_NOEXCEPT {
	return _array_iterator_1.less(_array_iterator_2.m_pointer);
}



_DD_END



#endif
