//	DDCPP/standard/bits/DD_Decay.hpp
#ifndef _DD_DECAY_HPP_INCLUDED
#	define _DD_DECAY_HPP_INCLUDED 1



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



DD_BEGIN
template <typename _ObjectT>
struct Decay {
	using _TempT = RemoveReferenceType<_ObjectT>;
	using Type = ConditionalType<
		IsArray<_TempT>::value,
		RemoveExtentType<_TempT>*,
		ConditionalType<
			IsFunction<_TempT>::value,
			AddPointerType<_TempT>,
			RemoveCVType<_TempT>
		>
	>;


};



DD_TRAIT_MODIFIER(Decay)



DD_END



#endif
