//	DDCPP/standard/bits/DD_IteratorCatagory.hpp
#ifndef _DD_ITERATOR_CATAGORY_HPP_INCLUDED
#	define _DD_ITERATOR_CATAGORY_HPP_INCLUDED



#	include "DD_RemoveCV.hpp"



_DD_DETAIL_BEGIN
struct FixedIterator {
};



struct UndirectionalIterator : FixedIterator {
};



struct BidirectionalIterator : UndirectionalIterator {
};



struct FreeAccessIterator : BidirectionalIterator {
};



template <typename _IteratorT>
struct _IteratorCatagory {
	DD_ALIAS(Type, typename _IteratorT::CatagoryType);


};



template <typename _ValueT>
struct _IteratorCatagory<_ValueT*> {
	DD_ALIAS(Type, FreeAccessIterator);


};



_DD_DETAIL_END



_DD_BEGIN
using _detail::FixedIterator;
using _detail::UndirectionalIterator;
using _detail::BidirectionalIterator;
using _detail::FreeAccessIterator;



#	if __cplusplus >= 201103L
template <typename _IteratorT>
using IteratorCatagory = _detail::_IteratorCatagory<RemoveCVType<_IteratorT>>;
template <typename _IteratorT>
using IteratorCatagoryType = typename IteratorCatagory<_IteratorT>::Type;
#	else
template <typename _IteratorT>
struct IteratorCatagory : _detail::_IteratorCatagory<typename RemoveCV<_IteratorT>::Type> {
};
#	endif



_DD_END



#endif
