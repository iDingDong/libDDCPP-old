//	DDCPP/standard/bits/DD_SingleStorage.hpp
#ifndef DD_SINGLE_STORAGE_HPP_INCLUDED_
#	define DD_SINGLE_STORAGE_HPP_INCLUDED_ 1



#	include "DD_ValueTypeNested.hpp"
#	if __cplusplus >= 201103L
#		include "DD_AlignmentOf.hpp"
#		include "DD_AlignedStorage.hpp"
#	endif



template <typename ValueT_>
struct SingleStorage {
	public:
	DD_ALIAS(ThisType, SingleStorage<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
#	if __cplusplus >= 201103L
	using StorageType = AlignedStorageType<sizeof(ValueType), AlignmentOf<ValueType>::value>;
#	else
	typedef typename AlignedStorage<sizeof(ValueType), AlignmentOf<ValueType>::value>::Type StorageType;
#	endif


	private:
	StorageType m_storage_;


};



#endif
