//	DDCPP/standard/bits/DD_BuildInTypes.hpp
#ifndef DD_BUILD_IN_TYPES_HPP_INCLUDED_
#	define DD_BUILD_IN_TYPES_HPP_INCLUDED_ 1



#	include <cstdint>

#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
DD_ALIAS(Char, char);
DD_ALIAS(UnsignedChar, unsigned char);
DD_ALIAS(SignedChar, signed char);
DD_ALIAS(UnsignedShortInt, unsigned short int);
DD_ALIAS(SignedShortInt, signed short int);
DD_ALIAS(UnsignedInt, unsigned int);
DD_ALIAS(SignedInt, signed int);
DD_ALIAS(UnsignedLongInt, unsigned long int);
DD_ALIAS(SignedLongInt, signed long int);
#	if __cplusplus >= 201103L
using UnsignedLongLongInt = unsigned long long int;
using SignedLongLongInt = signed long long int;
#	endif

DD_ALIAS(Float, float);
DD_ALIAS(Double, double);
DD_ALIAS(LongDouble, long double);

#	if __cplusplus >= 201103L
using UnsignedInt8 = std::uint8_t;
using SignedInt8 = std::int8_t;
using UnsignedInt16 = std::uint16_t;
using SignedInt16 = std::int16_t;
using UnsignedInt32 = std::uint32_t;
using SignedInt32 = std::int32_t;
using UnsignedInt64 = std::uint64_t;
using SignedInt64 = std::int64_t;
#	elif defined(WIN64_)
typedef UnsignedChar UnsignedInt8;
typedef SignedChar SignedInt8;
typedef UnsignedShort UnsignedInt16;
typedef SignedShort SignedInt16;
typedef UnsignedInt UnsignedInt32;
typedef SignedInt SignedInt32;
typedef UnsignedLongInt UnsignedInt64;
typedef SignedLongInt SignedInt64;
#	else
typedef UnsignedChar UnsignedInt8;
typedef SignedChar SignedInt8;
typedef UnsignedShort UnsignedInt16;
typedef SignedShort SignedInt16;
typedef UnsignedLongInt UnsignedInt32;
typedef SignedLongInt SignedInt32;
#	endif



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
