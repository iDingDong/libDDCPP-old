//	DDCPP/standard/bits/DD_AlignmentOf.hpp
#ifndef DD_ALIGNMENT_OF_HPP_INCLUDED_
#	define DD_ALIGNMENT_OF_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_IntegralConstant.hpp"


DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ObjectT_>
struct AlignmentOf : StdIntegralConstant<std::alignment_of<ObjectT_>> {
};
#	else
template <typename ObjectT_>
struct AlignmentOfHelper_ {
	char m_char_;
	ObjectT_ m_object_;


};



template <typename ObjectT_>
struct AlignmentOf : IntegralConstant<AlignmentType, sizeof(AlignmentOfHelper_<ObjectT_>) - sizeof(ObjectT_)> {
};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::AlignmentOf;



DD_END_



#endif
