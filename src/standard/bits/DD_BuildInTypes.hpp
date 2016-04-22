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
using UnsignedInt8Type = std::uint8_t;
using SignedInt8Type = std::int8_t;
using UnsignedInt16Type = std::uint16_t;
using SignedInt16Type = std::int16_t;
using UnsignedInt32Type = std::uint32_t;
using SignedInt32Type = std::int32_t;
using UnsignedInt64Type = std::uint64_t;
using SignedInt64Type = std::int64_t;
#	elif defined(WIN64_)
typedef UnsignedChar UnsignedInt8Type;
typedef SignedChar SignedInt8Type;
typedef UnsignedShortInt UnsignedInt16Type;
typedef SignedShortInt SignedInt16Type;
typedef UnsignedInt UnsignedInt32Type;
typedef SignedInt SignedInt32Type;
typedef UnsignedLongInt UnsignedInt64Type;
typedef SignedLongInt SignedInt64Type;
#	else
typedef UnsignedChar UnsignedInt8Type;
typedef SignedChar SignedInt8Type;
typedef UnsignedShortInt UnsignedInt16Type;
typedef SignedShortInt SignedInt16Type;
typedef UnsignedLongInt UnsignedInt32Type;
typedef SignedLongInt SignedInt32Type;
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::UnsignedInt8Type;
using detail_::SignedInt8Type;
using detail_::UnsignedInt16Type;
using detail_::SignedInt16Type;
using detail_::UnsignedInt32Type;
using detail_::SignedInt32Type;
using detail_::UnsignedInt64Type;
using detail_::SignedInt64Type;



DD_END_



#endif
