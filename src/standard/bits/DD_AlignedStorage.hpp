//	DDCPP/standard/bits/DD_AlignmentStorage.hpp
#ifndef DD_ALIGNMENT_STORAGE_HPP_INCLUDED_
#	define DD_ALIGNMENT_STORAGE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::AlignedStorage'.



#	endif
#	include <type_traits>

#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <SizeType size_c_, AlignmentType alignment_c_>
struct AlignedStorage {
#	if __cplusplus >= 201402L
	using Type = std::aligned_storage_t<size_c_, alignment_c_>;
#	else
	using Type = typename std::aligned_storage<size_c_, alignment_c_>::type;
#	endif


};



template <SizeType size_c_, AlignmentType alignment_c_>
using AlignedStorageType = typename AlignedStorage<size_c_, alignment_c_>::Type;



DD_DETAIL_END_



DD_BEGIN_
using detail_::AlignedStorage;
using detail_::AlignedStorageType;



DD_END_



#endif

