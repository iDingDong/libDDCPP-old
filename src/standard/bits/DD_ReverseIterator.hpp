//	DDCPP/standard/bits/DD_ReverseIterator.hpp
#ifndef DD_REVERSE_ITERATOR_HPP_INCLUDED_
#	define DD_REVERSE_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"
#	include "DD_IteratorReverse.hpp"



DD_DETAIL_BEGIN_
#	if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(ReverseIteratorOfStl_, RangeT_::reverse_iterator, void)



#	endif
template <typename RangeT_>
struct ReverseIterator_ {
#	if DDCPP_COMPAT_STL
	DD_ALIAS(Type, DD_MODIFY_TRAIT(ReverseIteratorOfStl_, RangeT_));
#	else
	DD_ALIAS(Type, void);
#	endif


};



template <typename ValueT_, LengthType length_c_>
struct ReverseIterator_<ValueT_[length_c_]> {
	DD_ALIAS(Type, DD_MODIFY_TRAIT(IteratorReverse, ValueT_*));


};



template <typename ValueT_>
struct ReverseIterator_<ValueT_[]> {
	DD_ALIAS(Type, DD_MODIFY_TRAIT(IteratorReverse, ValueT_*));


};



template <typename ValueT_>
struct ReverseIterator_<ValueT_*> {
	DD_ALIAS(Type, DD_MODIFY_TRAIT(IteratorReverse, ValueT_*));


};



#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(ReverseIterator, ReverseIterator, typename ::DD::detail_::ReverseIterator_<MACRO_ObjectT_>::Type)
#		else
DD_NESTED_TYPE_TRAIT(ReverseIterator, ReverseIterator, typename ::DD::detail_::ReverseIterator_<MACRO_ObjectT_>::Type)
#		endif



template <typename RangeT_>
using ReverseIteratorType = typename ReverseIterator<RangeT_>::Type;
#	else
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(
	ReverseIterator,
	ReverseIterator,
	typename ::DD::detail_::ReverseIterator_<typename RemoveCV<MACRO_ObjectT_>::Type>::Type
);
#		else
template <typename RangeT_>
struct ReverseIterator : ReverseIterator_<typename RemoveCV<RangeT_>::Type> {
};
#		endif
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::ReverseIterator;
#	if __cplusplus >= 201103L
using detail_::ReverseIteratorType;
#	endif



DD_END_



#endif


