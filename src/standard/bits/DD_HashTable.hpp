//	DDCPP/standard/bits/DD_HashTable.hpp
#ifndef DD_HASH_TABLE_HPP_INCLUDED_
#	define DD_HASH_TABLE_HPP_INCLUDED_ 1



#	include "DD_Hash.hpp"
#	include "DD_EqualTo.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_UndirectionalListIterator.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct HashTableBase_ {
	protected:
	DD_ALIAS(ThisType, HashTableBase_<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	protected:
	DD_ALIAS(SizeType, ::DD::SizeType);
	DD_ALIAS(LengthType, ::DD::LengthType);

	protected:
	DD_SPECIFIC_TYPE_NESTED(Node, UndirectionalListNode<ValueType>);


};



template <typename ValueT_>
struct HashTable



template <
	typename ValueT_,
	typename HashT_ = Hash<ValueT_>,
	typename EqualT_ = EqualTo<ValueT_>,
	typename AllocatorT_ = Allocator<ValueT_>
>
struct HashTable {
};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
