//	DDCPP/standard/bits/DD_Iterator.hpp
#ifndef DD_ITERATOR_HPP_INCLUDED_
#	define DD_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"



DD_DETAIL_BEGIN_
#	if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(IteratorOfStl_, RangeT_::iterator, void)



#	endif
template <typename RangeT_>
struct Iterator_ {
#	if DDCPP_COMPAT_STL
	DD_ALIAS(Type, DD_MODIFY_TRAIT(IteratorOfStl_, RangeT_));
#	else
	DD_ALIAS(Type, void);
#	endif


};



template <typename ValueT_, LengthType length_c_>
struct Iterator_<ValueT_[length_c_]> {
	DD_ALIAS(Type, ValueT_*);


};



template <typename ValueT_>
struct Iterator_<ValueT_[]> {
	DD_ALIAS(Type, ValueT_*);


};



template <typename ValueT_>
struct Iterator_<ValueT_*> {
	DD_ALIAS(Type, ValueT_*);


};



DD_DETAIL_END_



DD_BEGIN_
#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(Iterator, Iterator, typename detail_::Iterator_<MACRO_ObjectT_>::Type)
#		else
DD_NESTED_TYPE_TRAIT(Iterator, Iterator, typename detail_::Iterator_<MACRO_ObjectT_>::Type)
#		endif



template <typename RangeT_>
using IteratorType = typename Iterator<RangeT_>::Type;
#	else
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(Iterator, Iterator, typename detail_::Iterator_<typename RemoveCV<MACRO_ObjectT_>::Type>::Type);
#		else
template <typename RangeT_>
struct Iterator : detail_::Iterator_<typename RemoveCV<RangeT_>::Type> {
};
#		endif
#	endif



DD_END_



#endif
