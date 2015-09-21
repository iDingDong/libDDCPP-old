//	DDCPP/standard/bits/DD_IteratorTrait.hpp
#ifndef _DD_ITERATOR_TRAIT_HPP_INCLUDED
#	define _DD_ITERATOR_TRAIT_HPP_INCLUDED 1



#	include "DD_Trait.hpp"
#	include "DD_IteratorReverse.hpp"
#	include "DD_IsUndirectionalIterator.hpp"
#	include "DD_IsBidirectionalIterator.hpp"
#	include "DD_IsFreeAccessIterator.hpp"



_DD_BEGIN
template <typename _IteratorT>
struct IteratorTrait : Trait<_IteratorT> {
	DD_ALIAS(IteratorType, _IteratorT);

	DD_ALIAS(IsUndiretionalIterator, DD::IsUndirectionalIterator<IteratorType>)
	DD_ALIAS(IsBidiretionalIterator, DD::IsBidirectionalIterator<IteratorType>)
	DD_ALIAS(IsFreeAccessIterator, DD::IsFreeAccessIterator<IteratorType>)

	DD_ALIAS(ValueType, DD_MODIFY_TRAIT(IteratorValue, IteratorType))
	DD_ALIAS(ReferenceType, DD_MODIFY_TRAIT(IteratorReference, IteratorType))
	DD_ALIAS(PointerType, DD_MODIFY_TRAIT(IteratorPointer, IteratorType))
	DD_ALIAS(DifferenceType, DD_MODIFY_TRAIT(IteratorDifference, IteratorType))
	DD_ALIAS(CatagoryType, DD_MODIFY_TRAIT(IteratorCatagory, IteratorType))
	DD_ALIAS(ReverseType, DD_MODIFY_TRAIT(IteratorReverse, IteratorType))


};



_DD_END



#endif
