//	DDCPP/standard/bits/DD_Array.hpp
#ifndef DD_ARRAY_HPP_INCLUDED_
#	define DD_ARRAY_HPP_INCLUDED_ 1



#	include "DD_debugger_definitions.hpp"
#	include "DD_ValueTypeNested.hpp"
#	include "DD_AccessDenied.hpp"
#	include "DD_ArrayIterator.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ValueT_, LengthType length_c_, LengthType... lengths_c_>
struct Array : Array<Array<ValueT_, lengths_c_...>, length_c_> {
};




#	endif
#	if __cplusplus >= 201103L
template <typename ValueT_, LengthType length_c_>
struct Array<ValueT_, length_c_> {
#	else
template <typename ValueT_, LengthType length_c_>
struct Array : ValueTypeNested<ValueT_> {
#	endif
	DD_ALIAS(ThisType, Array<ValueT_ DD_COMMA length_c_>);
	DD_ALIAS(LowerType, ValueT_);
	static LengthType DD_CONSTANT length_constant = length_c_;
	DD_VALUE_TYPE_NESTED(ValueT_);

	DD_ALIAS(Iterator, PointerType);
	DD_ALIAS(ReverseIterator, typename IteratorReverse<Iterator>::Type);
	DD_ALIAS(ConstIterator, ConstPointerType);
	DD_ALIAS(ConstReverseIterator, typename IteratorReverse<ConstIterator>::Type);

#	if __cplusplus >= 201103L
	using ArrayType = DD::ArrayType<ValueType, length_constant>;
#	else
	typedef ValueType ArrayType[length_constant];
#	endif
	DD_ALIAS(ArrayRefernce, ArrayType&);
	DD_ALIAS(ArrayConstReference, ArrayType const&);
	DD_ALIAS(ArrayPointer, ArrayType*);
	DD_ALIAS(ArrayConstPointer, ArrayType const*);


	ArrayType array;


	static LengthType DD_CONSTEXPR get_length() DD_NOEXCEPT {
		return ThisType::length_constant;
	}


	static ValidityType DD_CONSTEXPR is_empty() DD_NOEXCEPT {
		return false;
	}


	ReferenceType at(LengthType index_) {
		if (index_ >= length_constant) {
			throw AccessDenied("'DD::Array::at' in " __FILE__ " at " DD_TO_STRING(__LINE__));
		}
		return array[index_];
	}

	ConstReferenceType DD_CONSTEXPR at(LengthType index_) const {
#	if __cplusplus >= 201402L || __cplusplus < 201103L
		if (index_ >= length_constant) {
			throw AccessDenied("'DD::Array::at' in " __FILE__ " at " DD_TO_STRING(__LINE__));
		}
		return array[index_];
#	else
		return index_ < length_constant ? array[index_] : throw AccessDenied("'DD::Array::at' in " __FILE__ " at " DD_TO_STRING(__LINE__)),  *array;
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
		return Iterator(array);
	}


	Iterator end() DD_NOEXCEPT {
		return Iterator(array + length_constant);
	}

	ConstIterator end() const DD_NOEXCEPT {
		return Iterator(array + length_constant);
	}


	ReverseIterator rbegin() DD_NOEXCEPT {
		return ReverseIterator(array + length_constant - 1);
	}

	ConstReverseIterator rbegin() const DD_NOEXCEPT {
		return ReverseIterator(array + length_constant - 1);
	}


	ReverseIterator rend() DD_NOEXCEPT {
		return ReverseIterator(array - 1);
	}

	ConstReverseIterator rend() const DD_NOEXCEPT {
		return ReverseIterator(array - 1);
	}


	ConstIterator cbegin() const DD_NOEXCEPT {
		return begin();
	}


	ConstIterator cend() const DD_NOEXCEPT {
		return end();
	}


	ConstReverseIterator crbegin() const DD_NOEXCEPT {
		return rbegin();
	}


	ConstReverseIterator crend() const DD_NOEXCEPT {
		return rend();
	}


	ArrayRefernce data() DD_NOEXCEPT {
		return array;
	}

	ArrayConstReference data() const DD_NOEXCEPT {
		return array;
	}


	ReferenceType operator [](LengthType index_) DD_NOEXCEPT {
		DD_ASSERT(index_ < length_constant, "Out of range: 'DD::Array::operator []' in " __FILE__ " at " DD_TO_STRING(__LINE__))
		return array[index_];
	}

	ConstReferenceType DD_CONSTEXPR operator [](LengthType index_) const DD_NOEXCEPT {
#	if __cplusplus >= 201402L
		DD_ASSERT(index_ < length_constant, "Out of range: 'DD::Array::operator []' in " __FILE__ " at " DD_TO_STRING(__LINE__))
#	endif
		return array[index_];
	}


	ReferenceType operator *() DD_NOEXCEPT {
		return *array;
	}

	ConstReferenceType DD_CONSTEXPR operator *() const DD_NOEXCEPT {
		return *array;
	}


	operator PointerType() DD_NOEXCEPT {
		return array;
	}

	constexpr operator ConstPointerType() const DD_NOEXCEPT {
		return array;
	}


};



template <typename ValueT_>
struct Array<ValueT_, 0> {
	DD_ALIAS(ThisType, Array<ValueT_ DD_COMMA 0>);
	DD_ALIAS(LowerType, ValueT_);
	static LengthType DD_CONSTANT length_constant = 0;
	DD_VALUE_TYPE_NESTED(ValueT_);

	DD_ALIAS(Iterator, PointerType);
	DD_ALIAS(ReverseIterator, typename IteratorReverse<Iterator>::Type);
	DD_ALIAS(ConstIterator, ConstPointerType);
	DD_ALIAS(ConstReverseIterator, typename IteratorReverse<ConstIterator>::Type);


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
		return Iterator();
	}


	Iterator end() DD_NOEXCEPT {
		return Iterator();
	}

	ConstIterator end() const DD_NOEXCEPT {
		return Iterator();
	}


	ReverseIterator rbegin() DD_NOEXCEPT {
		return ReverseIterator();
	}

	ConstReverseIterator rbegin() const DD_NOEXCEPT {
		return ReverseIterator();
	}


	ReverseIterator rend() DD_NOEXCEPT {
		return ReverseIterator();
	}

	ConstReverseIterator rend() const DD_NOEXCEPT {
		return ReverseIterator();
	}


	ConstIterator cbegin() const DD_NOEXCEPT {
		return begin();
	}


	ConstIterator cend() const DD_NOEXCEPT {
		return end();
	}


	ConstReverseIterator crbegin() const DD_NOEXCEPT {
		return rbegin();
	}


	ConstReverseIterator crend() const DD_NOEXCEPT {
		return rend();
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Array;



DD_END_



#endif
