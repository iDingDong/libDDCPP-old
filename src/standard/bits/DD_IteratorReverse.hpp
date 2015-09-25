//	DDCPP/standard/bits/DD_IteratorReverse.hpp
#ifndef _DD_ITERATOR_REVERSE_HPP_INCLUDED
#	define _DD_ITERATOR_REVERSE_HPP_INCLUDED



#	include "DD_CompatStlIterator.hpp"
#	include "DD_NestedTypeCheck.hpp"
#	include "DD_Or.hpp"
#	include "DD_IsSame.hpp"
#	if __cplusplus >= 201103L
#		include "DD_move.hpp"
#	endif
#	include "DD_relationship_operators.hpp"
#	include "DD_IteratorReference.hpp"
#	include "DD_IteratorPointer.hpp"
#	include "DD_IteratorDifference.hpp"
#	include "DD_IteratorCatagory.hpp"
#	include "DD_address_of.hpp"



_DD_DETAIL_BEGIN
template <typename _IteratorT>
struct _ReverseIterator {
	public:
	DD_ALIAS(ReverseType, _IteratorT);
	DD_ALIAS(ThisType, _ReverseIterator<ReverseType>);

	public:
	DD_ALIAS(ValueType, typename IteratorValue<ReverseType>::Type);
	DD_ALIAS(ReferenceType, typename IteratorReference<ReverseType>::Type);
	DD_ALIAS(PointerType, typename IteratorPointer<ReverseType>::Type);
	DD_ALIAS(DifferenceType, typename IteratorDifference<ReverseType>::Type);
	DD_ALIAS(CatagoryType, typename IteratorCatagory<ReverseType>::Type);
	DD_COMPAT_STL_ITERATOR


	private:
#	if __cplusplus >= 201103L
	ReverseType _m_iterator = ReverseType();
#	else
	ReverseType _m_iterator;
#	endif


	public:
#	if __cplusplus >= 201103L
	constexpr _ReverseIterator() noexcept(noexcept(ReverseType())) = default;

	public:
	constexpr _ReverseIterator(ThisType const& _origin) = default;

	public:
	constexpr _ReverseIterator(ThisType&& _origin) = default;
#	else
	_ReverseIterator() : _m_iterator() {
	}
#	endif

	public:
	DD_CONSTEXPR _ReverseIterator(ReverseType const& _iterator) DD_NOEXCEPT_AS(ReverseType(_iterator)) : _m_iterator(_iterator) {
	}

	public:
#	if __cplusplus >= 201103L
	template <typename... _ArgumentsT>
	constexpr _ReverseIterator(_ArgumentsT const&... __arguments) noexcept(noexcept(ReverseType(__arguments...))) : _m_iterator(__arguments...) {
#	else
	template <typename _ArgumentT>
	_ReverseIterator(_ArgumentT const& __argument) : _m_iterator(__argument) {
#	endif
	}// Global reference doesn't work here. See test2.cpp


#	if __cplusplus >= 201103L
	public:
	~_ReverseIterator() noexcept(noexcept(_m_iterator.~ReverseType())) = default;


#	endif
	public:
	ValidityType DD_CONSTEXPR equal(ThisType const& _target) const DD_NOEXCEPT_AS(_m_iterator == _target._m_iterator) {
		return this->_m_iterator == _target._m_iterator;
	}


	public:
	ValidityType DD_CONSTEXPR less(ThisType const& _target) const DD_NOEXCEPT_AS(_target._m_iterator < _m_iterator) {
		return _target._m_iterator < this->_m_iterator;
	}


	public:
	DifferenceType DD_CONSTEXPR difference(ThisType const& _target) const DD_NOEXCEPT_AS(_target._m_iterator - _m_iterator) {
		return _target._m_iterator - this->_m_iterator;
	}


	public:
	PointerType DD_CONSTEXPR get_pointer() const DD_NOEXCEPT_AS(address_of(*_m_iterator)) {
		return address_of(*this->_m_iterator);
	}


	public:
	ReverseType DD_CONSTEXPR reverse() const DD_NOEXCEPT_AS(ReverseType(_m_iterator)) {
		return _m_iterator;
	}



#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& _origin) = default;

	public:
	ThisType& operator =(ThisType&& _origin) = default;

#	endif
	public:
	ThisType& operator =(ReverseType const& _iterator) DD_NOEXCEPT_AS(_m_iterator = _iterator) {
		this->_m_iterator = _iterator;
	}

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ReverseType&& _iterator) DD_NOEXCEPT_AS(_m_iterator = move(_iterator)) {
		this->_m_iterator = move(_iterator);
	}

#	endif
	public:
	template <typename _ArgumentT>
	ThisType& operator =(_ArgumentT const& __argument) DD_NOEXCEPT_AS(_m_iterator = __argument) {
		this->_m_iterator = __argument;
	}// Global reference doesn't work here. See test2.cpp


	public:
	ThisType& operator ++() DD_NOEXCEPT_AS(--_m_iterator) {
		--this->_m_iterator;
		return *this;
	}

	public:
	ThisType operator ++(int) DD_NOEXCEPT_AS(_m_iterator--) {
		return ThisType(_m_iterator--);
	}


	public:
	ThisType& operator --() DD_NOEXCEPT_AS(++_m_iterator) {
		++this->_m_iterator;
		return *this;
	}

	public:
	ThisType operator --(int) DD_NOEXCEPT_AS(_m_iterator++) {
		return ThisType(_m_iterator++);
	}


	public:
	ThisType& operator +=(DifferenceType _step) DD_NOEXCEPT_AS(_m_iterator -= _step) {
		this->_m_iterator -= _step;
		return *this;
	}


	public:
	ThisType& operator -=(DifferenceType _step) DD_NOEXCEPT_AS(_m_iterator += _step) {
		this->_m_iterator += _step;
		return *this;
	}


	public:
	ReferenceType operator [](DifferenceType _index) const DD_NOEXCEPT_AS(_m_iterator[-_index]) {
		return this->_m_iterator[-_index];
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT_AS(*_m_iterator) {
		return *this->_m_iterator;
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT_AS(get_pointer()) {
		return this->get_pointer();
	}


};



template <typename _IteratorT>
inline ValidityType DD_CONSTEXPR operator ==(
	_ReverseIterator<_IteratorT> const& __reverse_iterator_1,
	_ReverseIterator<_IteratorT> const& __reverse_iterator_2
) DD_NOEXCEPT_AS(__reverse_iterator_1.equal(__reverse_iterator_2)) {
	return __reverse_iterator_1.equal(__reverse_iterator_2);
}


template <typename _IteratorT>
inline ValidityType DD_CONSTEXPR operator <(
	_ReverseIterator<_IteratorT> const& __reverse_iterator_1,
	_ReverseIterator<_IteratorT> const& __reverse_iterator_2
) DD_NOEXCEPT_AS(__reverse_iterator_1.less(__reverse_iterator_2)) {
	return __reverse_iterator_1.less(__reverse_iterator_2);
}



_DD_DETAIL_END



_DD_BEGIN
DD_NESTED_TYPE_TRAIT(IteratorReverse, ReverseType, _detail::_ReverseIterator<_MACRO_ObjectT>)



#	if __cplusplus >= 201103L
template <typename _IteratorT>
using IteratorReverseType = typename IteratorReverse<_IteratorT>::Type;



#	endif
_DD_END



#endif
