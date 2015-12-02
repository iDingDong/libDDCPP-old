//	DDCPP/standard/bits/DD_ConstReverseIterator.hpp
#ifndef DD_CONST_REVERSE_ITERATOR_HPP_INCLUDED_
#	define DD_CONST_REVERSE_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"
#	include "DD_IteratorReverse.hpp"



DD_DETAIL_BEGIN_
#	if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(ConstReverseIteratorOfStl_, RangeT_::const_reverse_iterator, void)



#	endif
template <typename RangeT_>
struct ConstReverseIterator_ {
#	if DDCPP_COMPAT_STL
	DD_ALIAS(Type, DD_MODIFY_TRAIT(ConstReverseIteratorOfStl_, RangeT_));
#	else
	DD_ALIAS(Type, void);
#	endif


};



template <typename ValueT_, LengthType length_c_>
struct ConstReverseIterator_<ValueT_[length_c_]> {
	DD_ALIAS(Type, DD_MODIFY_TRAIT(IteratorReverse, ValueT_ const*));


};



template <typename ValueT_>
struct ConstReverseIterator_<ValueT_[]> {
	DD_ALIAS(Type, DD_MODIFY_TRAIT(IteratorReverse, ValueT_ const*));


};



template <typename ValueT_>
struct ConstReverseIterator_<ValueT_*> {
	DD_ALIAS(Type, DD_MODIFY_TRAIT(IteratorReverse, ValueT_ const*));


};



#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(ConstReverseIterator, ConstReverseIterator, typename ::DD::detail_::ConstReverseIterator_<MACRO_ObjectT_>::Type)
#		else
DD_NESTED_TYPE_TRAIT(ConstReverseIterator, ConstReverseIterator, typename ::DD::detail_::ConstReverseIterator_<MACRO_ObjectT_>::Type)
#		endif



template <typename RangeT_>
using ConstReverseIteratorType = typename ConstReverseIterator<RangeT_>::Type;
#	else
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(
	ConstReverseIterator,
	ConstReverseIterator,
	typename ::DD::detail_::ConstReverseIterator_<typename RemoveCV<MACRO_ObjectT_>::Type>::Type
);
#		else
template <typename RangeT_>
struct ConstReverseIterator : ConstReverseIterator_<typename RemoveCV<RangeT_>::Type> {
};
#		endif
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::ConstReverseIterator;
#	if __cplusplus >= 201103L
using detail_::ConstReverseIteratorType;
#	endif



DD_END_



#endif



