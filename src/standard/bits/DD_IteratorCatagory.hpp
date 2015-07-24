//	standard/bits/DD_IteratorCatagory.hpp
#ifndef _DD_ITERATOR_CATAGORY_HPP_INCLUDED
#	define _DD_ITERATOR_CATAGORY_HPP_INCLUDED



#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN
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



DD_DETAIL_END



DD_BEGIN
DD_ALIAS(FixedIterator, detail::_FixedIterator)
DD_ALIAS(UndirectionalIterator, detail::_UndirectionalIterator)
DD_ALIAS(BidirectionalIterator, detail::_BidirectionalIterator)
DD_ALIAS(FreeAccessIterator, detail::_FreeAccessIterator)



#	if __cplusplus >= 201103L
template <typename _IteratorT>
using IteratorCatagory = detail::_IteratorCatagory<RemoveCVType<_IteratorT>>;
template <typename _IteratorT>
using IteratorCatagoryType = typename IteratorCatagory<_IteratorT>::Type;
#	else
template <typename _IteratorT>
struct IteratorCatagory : detail::_IteratorCatagory<typename RemoveCV<_IteratorT>::Type> {
};
#	endif



DD_END



#endif
