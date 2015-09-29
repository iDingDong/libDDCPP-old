//	DDCPP/standard/bits/DD_Trait.hpp
#ifndef DD_TRAIT_HPP_INCLUDED_
#	define DD_TRAIT_HPP_INCLUDED_ 1



#	include "DD_IsVoid.hpp"
#	include "DD_IsArithmetic.hpp"
#	include "DD_IsReference.hpp"
#	include "DD_IsPointer.hpp"
#	include "DD_IsArray.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsFunction.hpp"
#	endif
#	include "DD_IsConst.hpp"
#	include "DD_IsVolatile.hpp"
#	include "DD_IsSame.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsBaseOf.hpp"
#		include "DD_IsNoexceptMoveConstructible.hpp"
#		include "DD_IsNoexceptMoveAssignable.hpp"
#	endif
#	include "DD_AddCV.hpp"
#	include "DD_RemovePointer.hpp"
#	include "DD_RemoveAllExtents.hpp"
#	if __cplusplus >= 201103L
#		include "DD_Decay.hpp"
#	else
#		include "DD_AddPointer.hpp"
#		include "DD_RemoveReference.hpp"
#		include "DD_RemoveExtent.hpp"
#	endif



DD_BEGIN_
template <typename ObjectT_>
struct Trait {
	DD_ALIAS(ObjectType, ObjectT_);

	DD_ALIAS(IsVoid, DD::IsVoid<ObjectType>);
	DD_ALIAS(IsBool, DD::IsBool<ObjectType>);
	DD_ALIAS(IsUnsignedChar, DD::IsUnsignedChar<ObjectType>);
	DD_ALIAS(IsSignedChar, DD::IsSignedChar<ObjectType>);
	DD_ALIAS(IsChar, DD::IsChar<ObjectType>);
	DD_ALIAS(IsWChar, DD::IsWChar<ObjectType>);
#	if __cplusplus >= 201103L
	using IsChar16 = DD::IsChar16<ObjectType>;
	using IsChar32 = DD::IsChar32<ObjectType>;
#	endif
	DD_ALIAS(IsCharactor, DD::IsCharactor<ObjectType>);
	DD_ALIAS(IsUnsignedShort, DD::IsUnsignedShort<ObjectType>);
	DD_ALIAS(IsSignedShort, DD::IsSignedShort<ObjectType>);
	DD_ALIAS(IsUnsignedInt, DD::IsUnsignedInt<ObjectType>);
	DD_ALIAS(IsSignedInt, DD::IsSignedInt<ObjectType>);
	DD_ALIAS(IsUnsignedLong, DD::IsUnsignedLong<ObjectType>);
	DD_ALIAS(IsSignedLong, DD::IsSignedLong<ObjectType>);
#	if __cplusplus >= 201103L
	using IsUnsignedLongLong = DD::IsUnsignedLongLong<ObjectType>;
	using IsSignedLongLong = DD::IsSignedLongLong<ObjectType>;
#	endif
	DD_ALIAS(IsIntegral, DD::IsIntegral<ObjectType>);
	DD_ALIAS(IsFloatingPoint, DD::IsFloatingPoint<ObjectType>);
	DD_ALIAS(IsArithmetic, DD::IsArithmetic<ObjectType>);
#	if __cplusplus >= 201103L
	using IsFunction = DD::IsFunction<ObjectType>;
	using IsLvalueReference = DD::IsLvalueReference<ObjectType>;
	using IsRvalueReference = DD::IsRvalueReference<ObjectType>;
#	endif
	DD_ALIAS(IsReference, DD::IsReference<ObjectType>);
	DD_ALIAS(IsPointer, DD::IsPointer<ObjectType>);
	DD_ALIAS(IsArray, DD::IsArray<ObjectType>);
#	if __cplusplus >= 201103L
	using IsUnion = DD::IsUnion<ObjectType>;
	using IsClass = DD::IsClass<ObjectType>;
#	endif
	DD_ALIAS(IsConst, DD::IsConst<ObjectType>);
	DD_ALIAS(IsVolatile, DD::IsVolatile<ObjectType>);
#	if __cplusplus >= 201103L
	using IsNoexceptMoveConstructible = DD::IsNoexceptMoveConstructible<ObjectType>;
	using IsNoexceptMoveAssignable = DD::IsNoexceptMoveAssignable<ObjectType>;
	template <typename... ObjectsT__>
	using IsSame = DD::IsSame<ObjectType, ObjectsT__...>;
	template <typename... ObjectsT__>
	using IsBaseOf = DD::IsBaseOf<ObjectType, ObjectsT__...>;
#	else


	template <typename ObjectT__>
	struct IsSame : DD::IsSame<ObjectType, ObjectT__> {
	};

#	endif

	DD_ALIAS(ConstAdded, DD_MODIFY_TRAIT(AddConst, ObjectType));
	DD_ALIAS(VolatileAdded, DD_MODIFY_TRAIT(AddVolatile, ObjectType));
	DD_ALIAS(CVAdded, DD_MODIFY_TRAIT(AddCV, ObjectType));
	DD_ALIAS(PointerAdded, DD_MODIFY_TRAIT(AddPointer, ObjectType));
	DD_ALIAS(ReferenceRemoved, DD_MODIFY_TRAIT(RemoveReference, ObjectType));
	DD_ALIAS(PointerRemoved, DD_MODIFY_TRAIT(RemovePointer, ObjectType));
	DD_ALIAS(ExtentRemoved, DD_MODIFY_TRAIT(RemoveExtent, ObjectType));
	DD_ALIAS(AllExtentsRemoved, DD_MODIFY_TRAIT(RemoveAllExtents, ObjectType));
	DD_ALIAS(ConstRemoved, DD_MODIFY_TRAIT(RemoveConst, ObjectType));
	DD_ALIAS(VolatileRemoved, DD_MODIFY_TRAIT(RemoveVolatile, ObjectType));
	DD_ALIAS(CVRemoved, DD_MODIFY_TRAIT(RemoveCV, ObjectType));
#	if __cplusplus >= 201103L
	using Decayed = DecayType<ObjectType>;
#	endif


};



DD_END_



#endif
