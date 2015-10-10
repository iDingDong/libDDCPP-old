//	DDCPP/standard/bits/DD_ConstantSequence.hpp
#ifndef DD_CONSTANT_SEQUENCE_HPP_INCLUDED_
#	define DD_CONSTANT_SEQUENCE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ConstantSequence'.



#	endif
#	include "DD_ConstantList.hpp"



DD_DETAIL_BGIN_
template <typename ValueT_, ValueT_ begin_c_, ValueT_ end_c_, ValueT_ step_c_>
struct ConstantSequence : ConstantList<ValueT_, begin_c_>::PushBack<ConstantSequence<begin_c_ + step_c_, end_c_>> {
};



template <typename ValueT_, ValueT_ value_c_>
struct ConstantSequence<ValueT_, value_c_, value_c_> : ConstantList<ValueT_, value_c_> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::ConstantSequence;



DD_END_



#endif
