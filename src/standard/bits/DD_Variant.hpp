//	DDCPP/standard/bits/DD_Variant.hpp
#ifndef DD_VARIANT_HPP_INCLUDED_
#	define DD_VARIANT_HPP_INCLUDED_ 1



#	if __cplusplus <= 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Variant'.



#	endif
#	include "DD_StaticMax.hpp"
#	include "DD_AlignmentOf.hpp"
#	include "DD_AlignedStorage.hpp"



DD_DETAIL_BEGIN_
template <typename... ValuesT_>
struct VariantStorage_ {
	using Type = AlignedStorageType<
		StaticMax<SizeType, sizeof(ValuesT_)...>::value,
		StaticMax<AlignmentType, AlignmentOf<ValuesT_>::value...>
	>;


};



template <typename... ValuesT_>
struct Variant {
	public:
	using ThisType = Variant;

	private:
	using StorageType_ = typename VariantStorage_<ValuesT_...>::Type;


	private:
	StorageType_ m_storage_;


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
