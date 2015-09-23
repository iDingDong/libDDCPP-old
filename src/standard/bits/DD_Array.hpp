//	DDCPP/standard/bits/DD_Array.hpp
#ifndef _DD_ARRAY_HPP_INCLUDED
#	define _DD_ARRAY_HPP_INCLUDED 1



#	include "DD_debugger_definitions.hpp"
#	include "DD_ValueTypeNested.hpp"
#	include "DD_AccessDenied.hpp"
#	include "DD_ArrayIterator.hpp"



_DD_DETAIL_BEGIN
#	if __cplusplus >= 201103L
template <typename _ValueT, LengthType _length_c, LengthType... _lengths_c>
struct _Array : _Array<_Array<_ValueT, _lengths_c...>, _length_c> {
};




#	endif
#	if __cplusplus >= 201103L
template <typename _ValueT, LengthType _length_c>
struct _Array<_ValueT, _length_c> {
#	else
template <typename _ValueT, LengthType _length_c>
struct _Array : ValueTypeNested<_ValueT> {
#	endif
	DD_ALIAS(ThisType, _Array<_ValueT DD_COMMA _length_c>)
	DD_ALIAS(LowerType, _ValueT)
	static LengthType DD_CONSTANT length_constant = _length_c;
	DD_VALUE_TYPE_NESTED(_ValueT)

	DD_ALIAS(Iterator, PointerType)
	DD_ALIAS(ReverseIterator, typename IteratorReverse<Iterator>::Type)
	DD_ALIAS(ConstIterator, ConstPointerType)
	DD_ALIAS(ConstReverseIterator, typename IteratorReverse<ConstIterator>::Type)

#	if __cplusplus >= 201103L
	using ArrayType = DD::ArrayType<ValueType, length_constant>;
#	else
	typedef ValueType ArrayType[length_constant];
#	endif
	DD_ALIAS(ArrayRefernce, ArrayType&)
	DD_ALIAS(ArrayConstReference, ArrayType const&)
	DD_ALIAS(ArrayPointer, ArrayType*)
	DD_ALIAS(ArrayConstPointer, ArrayType const*)


	ArrayType array;


	static LengthType DD_CONSTEXPR get_length() DD_NOEXCEPT {
		return ThisType::length_constant;
	}


	static ValidityType DD_CONSTEXPR is_empty() DD_NOEXCEPT {
		return false;
	}


	ReferenceType at(LengthType _index) {
		if (_index >= length_constant) {
			throw AccessDenied("'DD::Array::at' in " __FILE__ " at " DD_TO_STRING(__LINE__));
		}
		return array[_index];
	}

	ConstReferenceType DD_CONSTEXPR at(LengthType _index) const {
#	if __cplusplus >= 201402L || __cplusplus < 201103L
		if (_index >= length_constant) {
			throw AccessDenied("'DD::Array::at' in " __FILE__ " at " DD_TO_STRING(__LINE__));
		}
		return array[_index];
#	else
		return _index < length_constant ? array[_index] : throw AccessDenied("'DD::Array::at' in " __FILE__ " at " DD_TO_STRING(__LINE__)),  *array;
#	endif
	}


	ReferenceType front() DD_NOEXCEPT {
		return *array;
	}

	ConstReferenceType DD_CONSTEXPR front() const DD_NOEXCEPT {
		return *array;
	}


	ReferenceType back() DD_NOEXCEPT {
		return array[length_constant - 1];
	}

	ConstReferenceType DD_CONSTEXPR back() const DD_NOEXCEPT {
		return array[length_constant - 1];
	}


	Iterator begin() DD_NOEXCEPT {
		return Iterator(array);
	}

	ConstIterator begin() const DD_NOEXCEPT {
		return cbegin();
	}


	Iterator end() DD_NOEXCEPT {
		return Iterator(array + length_constant);
	}

	ConstIterator end() const DD_NOEXCEPT {
		return cend();
	}


	ReverseIterator rbegin() DD_NOEXCEPT {
		return ReverseIterator(array + length_constant - 1);
	}

	ConstReverseIterator rbegin() const DD_NOEXCEPT {
		return crbegin();
	}


	ReverseIterator rend() DD_NOEXCEPT {
		return ReverseIterator(array - 1);
	}

	ConstReverseIterator rend() const DD_NOEXCEPT {
		return crend();
	}


	ConstIterator cbegin() const DD_NOEXCEPT {
		return ConstIterator(array);
	}


	ConstIterator cend() const DD_NOEXCEPT {
		return ConstIterator(array + length_constant);
	}


	ConstReverseIterator crbegin() const DD_NOEXCEPT {
		return ConstReverseIterator(array - 1);
	}


	ConstReverseIterator crend() const DD_NOEXCEPT {
		return ConstReverseIterator(array + length_constant - 1);
	}


	ArrayRefernce data() DD_NOEXCEPT {
		return array;
	}

	ArrayConstReference data() const DD_NOEXCEPT {
		return array;
	}


	ReferenceType operator [](LengthType _index) DD_NOEXCEPT {
		DD_ASSERT(_index < length_constant, "Out of range: 'DD::Array::operator []' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return array[_index];
	}

	ConstReferenceType DD_CONSTEXPR operator [](LengthType _index) const DD_NOEXCEPT {
#	if __cplusplus >= 201402L
		DD_ASSERT(_index < length_constant, "Out of range: 'DD::Array::operator []' in " __FILE__ " at " DD_TO_STRING(__LINE__))
#	endif
		return array[_index];
	}


	ReferenceType operator *() DD_NOEXCEPT {
		return *array;
	}

	ConstReferenceType DD_CONSTEXPR operator *() const DD_NOEXCEPT {
		return *array;
	}


};



template <typename _ValueT>
struct _Array<_ValueT, 0> {
	DD_ALIAS(ThisType, _Array<_ValueT DD_COMMA 0>)
	DD_ALIAS(LowerType, _ValueT)
	static LengthType DD_CONSTANT length_constant = 0;
	DD_VALUE_TYPE_NESTED(_ValueT)

	DD_ALIAS(Iterator, PointerType)
	DD_ALIAS(ReverseIterator, typename IteratorReverse<Iterator>::Type)
	DD_ALIAS(ConstIterator, ConstPointerType)
	DD_ALIAS(ConstReverseIterator, typename IteratorReverse<ConstIterator>::Type)


	static LengthType DD_CONSTEXPR get_length() DD_NOEXCEPT {
		return ThisType::length_constant;
	}


	static ValidityType DD_CONSTEXPR is_empty() DD_NOEXCEPT {
		return true;
	}


	Iterator begin() DD_NOEXCEPT {
		return Iterator();
	}

	ConstIterator begin() const DD_NOEXCEPT {
		return cbegin();
	}


	Iterator end() DD_NOEXCEPT {
		return Iterator();
	}

	ConstIterator end() const DD_NOEXCEPT {
		return cend();
	}


	ReverseIterator rbegin() DD_NOEXCEPT {
		return ReverseIterator();
	}

	ConstReverseIterator rbegin() const DD_NOEXCEPT {
		return crbegin();
	}


	ReverseIterator rend() DD_NOEXCEPT {
		return ReverseIterator();
	}

	ConstReverseIterator rend() const DD_NOEXCEPT {
		return crend();
	}


	ConstIterator cbegin() const DD_NOEXCEPT {
		return ConstIterator();
	}


	ConstIterator cend() const DD_NOEXCEPT {
		return ConstIterator();
	}


	ConstReverseIterator crbegin() const DD_NOEXCEPT {
		return ConstReverseIterator();
	}


	ConstReverseIterator crend() const DD_NOEXCEPT {
		return ConstReverseIterator();
	}


};



_DD_DETAIL_END



_DD_BEGIN
#	if __cplusplus >= 201103L
template <typename _ValueT, LengthType _length_c, LengthType... _lengths_c>
using Array = _detail::_Array<_ValueT, _length_c, _lengths_c...>;
#	else
template <typename _ValueT, LengthType _length_c>
struct Array : _detail::_Array<_ValueT, _length_c> {
};
#	endif



_DD_END



#endif
