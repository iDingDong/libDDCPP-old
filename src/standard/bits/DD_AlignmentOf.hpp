//	DDCPP/standard/bits/DD_AlignmentOf.hpp
#ifndef DD_ALIGNMENT_OF_HPP_INCLUDED_
#	define DD_ALIGNMENT_OF_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::AlignmentOf'.



#	endif
#	include <type_traits>

#	include "DD_IntegralConstant.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct AlignmentOf : StdIntegralConstant<AlignmentType, std::alignment_of<ObjectT_>::value> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::AlignmentOf;



DD_END_



#endif
