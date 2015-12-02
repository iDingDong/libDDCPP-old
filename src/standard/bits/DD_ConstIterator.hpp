//	DDCPP/standard/bits/DD_ConstIterator.hpp
#ifndef DD_CONST_ITERATOR_HPP_INCLUDED_
#	define DD_CONST_ITERATOR_HPP_INCLUDED_ 1



#	include "DD_NestedTypeCheck.hpp"
#	if __cplusplus < 201103L
#		include "DD_RemoveCV.hpp"
#	endif
#	include "DD_RemoveReference.hpp"



DD_DETAIL_BEGIN_
#	if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(ConstIteratorOfStl_, RangeT_::const_iterator, void)



#	endif
template <typename RangeT_>
struct ConstIterator_ {
#	if DDCPP_COMPAT_STL
	DD_ALIAS(Type, DD_MODIFY_TRAIT(ConstIteratorOfStl_, RangeT_));
#	else
	DD_ALIAS(Type, void);
#	endif


};



template <typename ValueT_, LengthType length_c_>
struct ConstIterator_<ValueT_[length_c_]> {
	DD_ALIAS(Type, ValueT_ const*);


};



template <typename ValueT_>
struct ConstIterator_<ValueT_[]> {
	DD_ALIAS(Type, ValueT_ const*);


};



template <typename ValueT_>
struct ConstIterator_<ValueT_*> {
	DD_ALIAS(Type, ValueT_ const*);


};



#	if __cplusplus >= 201103L
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(ConstIterator, ConstIterator, typename ::DD::detail_::ConstIterator_<MACRO_ObjectT_>::Type)
#		else
DD_NESTED_TYPE_TRAIT(ConstIterator, ConstIterator, typename ::DD::detail_::ConstIterator_<MACRO_ObjectT_>::Type)
#		endif



template <typename RangeT_>
using ConstIteratorType = typename ConstIterator<RangeT_>::Type;
#	else
#		if DDCPP_COMPAT_STL
DD_NESTED_TYPE_TRAIT(
	ConstIterator,
	ConstIterator,
	typename ::DD::detail_::ConstIterator_<typename RemoveCV<MACRO_ObjectT_>::Type>::Type
);
#		else
template <typename RangeT_>
struct ConstIterator : ConstIterator_<typename RemoveCV<RangeT_>::Type> {
};
#		endif
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::ConstIterator;
#	if __cplusplus >= 201103L
using detail_::ConstIteratorType;
#	endif



DD_END_



#endif

