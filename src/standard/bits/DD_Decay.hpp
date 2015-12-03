//	DDCPP/standard/bits/DD_Decay.hpp
#ifndef DD_DECAY_HPP_INCLUDED_
#	define DD_DECAY_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Decay'.



#	endif
#	include "DD_Conditional.hpp"
#	include "DD_IsArray.hpp"
#	include "DD_IsFunction.hpp"
#	include "DD_AddPointer.hpp"
#	include "DD_RemoveCV.hpp"
#	include "DD_RemoveReference.hpp"
#	include "DD_RemoveExtent.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct Decay {
	using TempT_ = RemoveReferenceType<ObjectT_>;
	using Type = ConditionalType<
		IsArray<TempT_>::value,
		RemoveExtentType<TempT_>*,
		ConditionalType<
			IsFunction<TempT_>::value,
			AddPointerType<TempT_>,
			RemoveCVType<TempT_>
		>
	>;


};



DD_TRAIT_MODIFIER(Decay)



DD_DETAIL_END_



DD_BEGIN_
using detail_::Decay;
#	if __cplusplus >= 201103L
using detail_::DecayType;
#	endif



DD_END_



#endif
