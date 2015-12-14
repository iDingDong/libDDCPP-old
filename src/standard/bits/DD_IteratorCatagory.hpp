//	DDCPP/standard/bits/DD_IteratorCatagory.hpp
#ifndef DD_ITERATOR_CATAGORY_HPP_INCLUDED_
#	define DD_ITERATOR_CATAGORY_HPP_INCLUDED_



#	include "DD_RemoveCV.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsBaseOf.hpp"
#	else
#		include "DD_IsSame.hpp"
#	endif



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



#	if __cplusplus >= 201103L
enum class IteratorCatagoryValue {
	fixed = 1,
	undirectional = 2,
	bidirectional = 3,
	free_access = 4

};
#	else
enum IteratorCatagoryValue {
	fixed = 1,
	undirectional = 2,
	bidirectional = 3,
	free_access = 4

};
#	endif



template <typename IteratorT_>
struct IteratorCatagory : IteratorCatagory_<DD_MODIFY_TRAIT(RemoveCV, IteratorT_)> {
	DD_ALIAS(Type, typename IteratorCatagory_<DD_MODIFY_TRAIT(RemoveCV, IteratorT_)>::Type);
#	if __cplusplus >= 201103L
	static IteratorCatagoryValue DD_CONSTANT value = IsBaseOf<FreeAccessIterator, Type>::value ?
		IteratorCatagoryValue::free_access :
		IsBaseOf<BidirectionalIterator, Type>::value ?
			IteratorCatagoryValue::bidirectional :
			IsBaseOf<UndirectionalIterator, Type>::value ?
				IteratorCatagoryValue::undirectional :
				IteratorCatagoryValue::fixed
	;
#	else
	static IteratorCatagoryValue DD_CONSTANT value = IsSame<FreeAccessIterator, Type>::value ?
		free_access :
		IsSame<BidirectionalIterator, Type>::value ?
			bidirectional :
			IsSame<UndirectionalIterator, Type>::value ?
				undirectional :
				fixed
	;
#	endif


};



DD_TRAIT_MODIFIER(IteratorCatagory)



DD_DETAIL_END_



DD_BEGIN_
using detail_::FixedIterator;
using detail_::UndirectionalIterator;
using detail_::BidirectionalIterator;
using detail_::FreeAccessIterator;
using detail_::IteratorCatagory;

DD_TRAIT_MODIFIER(IteratorCatagory)



DD_END_



#endif
