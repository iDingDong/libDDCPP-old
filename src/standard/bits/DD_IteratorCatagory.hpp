//	DDCPP/standard/bits/DD_IteratorCatagory.hpp
#ifndef DD_ITERATOR_CATAGORY_HPP_INCLUDED_
#	define DD_ITERATOR_CATAGORY_HPP_INCLUDED_



#	include "DD_RemoveCV.hpp"



DD_DETAIL_BEGIN_
struct FixedIterator {
};



struct UndirectionalIterator : FixedIterator {
};



struct BidirectionalIterator : UndirectionalIterator {
};



struct FreeAccessIterator : BidirectionalIterator {
};



template <typename IteratorT_>
struct IteratorCatagory_ {
	DD_ALIAS(Type, typename IteratorT_::CatagoryType);


};



template <typename ValueT_>
struct IteratorCatagory_<ValueT_*> {
	DD_ALIAS(Type, FreeAccessIterator);


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::FixedIterator;
using detail_::UndirectionalIterator;
using detail_::BidirectionalIterator;
using detail_::FreeAccessIterator;



#	if __cplusplus >= 201103L
template <typename IteratorT_>
using IteratorCatagory = detail_::IteratorCatagory_<RemoveCVType<IteratorT_>>;
template <typename IteratorT_>
using IteratorCatagoryType = typename IteratorCatagory<IteratorT_>::Type;
#	else
template <typename IteratorT_>
struct IteratorCatagory : detail_::IteratorCatagory_<typename RemoveCV<IteratorT_>::Type> {
};
#	endif



DD_END_



#endif
