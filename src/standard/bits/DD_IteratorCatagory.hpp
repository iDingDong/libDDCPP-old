//	DDCPP/standard/bits/DD_IteratorCatagory.hpp
#ifndef _DD_ITERATOR_CATAGORY_HPP_INCLUDED
#	define _DD_ITERATOR_CATAGORY_HPP_INCLUDED



#	include "DD_RemoveCV.hpp"



_DD_DETAIL_BEGIN
struct _FixedIterator {
};



struct _UndirectionalIterator : _FixedIterator {
};



struct _BidirectionalIterator : _UndirectionalIterator {
};



struct _FreeAccessIterator : _BidirectionalIterator {
};



template <typename _IteratorT>
struct _IteratorCatagory {
	DD_ALIAS(Type, typename _IteratorT::CatagoryType)


};



template <typename _ValueT>
struct _IteratorCatagory<_ValueT*> {
	DD_ALIAS(Type, _FreeAccessIterator)


};



_DD_DETAIL_END



_DD_BEGIN
DD_ALIAS(FixedIterator, _detail::_FixedIterator)
DD_ALIAS(UndirectionalIterator, _detail::_UndirectionalIterator)
DD_ALIAS(BidirectionalIterator, _detail::_BidirectionalIterator)
DD_ALIAS(FreeAccessIterator, _detail::_FreeAccessIterator)



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
