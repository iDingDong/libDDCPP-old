// DDCompatibility.hpp
#ifndef _DDCOMPATIBILITY_
 #define _DDCOMPATIBILITY_



 #include "DDGlobal.hpp"
 #include <cstdint>
 #include <cfloat>



DD_BEGIN
 #if defined(_WIN16) || defined(_WIN32)
using Int8Type = __int8;
using Int16Type = __int16;
using Int32Type = __int32;
using Int64Type = __int64;

using UInt8Type = unsigned __int8;
using UInt16Type = unsigned __int16;
using UInt32Type = unsigned __int32;
using UInt64Type = unsigned __int64;

using IntLeast8Type = __int8;
using IntLeast16Type = __int16;
using IntLeast32Type = __int32;
using IntLeast64Type = __int64;

using UIntLeast8Type = unsigned __int8;
using UIntLeast16Type = unsigned __int16;
using UIntLeast32Type = unsigned __int32;
using UIntLeast64Type = unsigned __int64;

using IntFast8Type = signed char;
using IntFast16Type = signed int;
using IntFast32Type = signed long int;
using IntFast64Type = signed long long int;

using UIntFast8Type = unsigned char;
using UIntFast16Type = unsigned int;
using UIntFast32Type = unsigned long int;
using UIntFast64Type = unsigned long long int;

 #elif 0
using Int8Type = signed char;
using Int16Type = signed int;
using Int32Type = signed long int;
using Int64Type = signed long long int;

using UInt8Type = unsigned char;
using UInt16Type = unsigned int;
using UInt32Type = unsigned long int;
using UInt64Type = unsigned long long;


 #elif 0
using Int8Type = signed char;
using Int16Type = signed short int;
using Int32Type = signed int;
using Int64Type = signed long long int;

using UInt8Type = unsigned char;
using UInt16Type = unsigned short int;
using UInt32Type = unsigned int;
using UInt64Type = unsigned long long;


 #else
using Int8Type = std::int8_t;
using Int16Type = std::int16_t;
using Int32Type = std::int32_t;
using Int64Type = std::int64_t;

using UInt8Type = std::uint8_t;
using UInt16Type = std::uint16_t;
using UInt32Type = std::uint32_t;
using UInt64Type = std::uint64_t;

using IntLeast8Type = std::int_least8_t;
using IntLeast16Type = std::int_least16_t;
using IntLeast32Type = std::int_least32_t;
using IntLeast64Type = std::int_least64_t;

using UIntLeast8Type = std::uint_least8_t;
using UIntLeast16Type = std::uint_least16_t;
using UIntLeast32Type = std::uint_least32_t;
using UIntLeast64Type = std::uint_least64_t;

using IntFast8Type = std::int_fast8_t;
using IntFast16Type = std::int_fast16_t;
using IntFast32Type = std::int_fast32_t;
using IntFast64Type = std::int_fast64_t;

using UIntFast8Type = std::uint_fast8_t;
using UIntFast16Type = std::uint_fast16_t;
using UIntFast32Type = std::uint_fast32_t;
using UIntFast64Type = std::uint_fast64_t;


 #endif
static_assert(sizeof(UInt8Type) == sizeof(Int8Type), "Unsupported environment.");
static_assert(sizeof(UInt16Type) == sizeof(Int16Type), "Unsupported environment.");
static_assert(sizeof(UInt32Type) == sizeof(Int32Type), "Unsupported environment.");
static_assert(sizeof(UInt64Type) == sizeof(Int64Type), "Unsupported environment.");


constexpr bool bool_min = false;
constexpr bool bool_max = true;

constexpr unsigned char unsigned_char_min = '\0';
constexpr unsigned char unsigned_char_max = unsigned_char_min - 1;

constexpr signed char signed_char_min = unsigned_char_max / 2 + 1;
constexpr signed char signed_char_max = unsigned_char_max / 2;

constexpr unsigned short unsigned_short_min = 0;
constexpr unsigned short unsigned_short_max = unsigned_short_min - 1;

constexpr short short_min = unsigned_short_max / 2 + 1;
constexpr short short_max = unsigned_short_max / 2;

constexpr unsigned unsigned_min = 0U;
constexpr unsigned unsigned_max = unsigned_min - 1U;

constexpr int int_min = unsigned_max / 2 + 1;
constexpr int int_max = unsigned_max / 2;

constexpr unsigned long unsigned_long_min = 0UL;
constexpr unsigned long unsigned_long_max = unsigned_long_min - 1UL;

constexpr long long_min = unsigned_long_max / 2L + 1L;
constexpr long long_max = unsigned_long_max / 2L;

constexpr unsigned long long unsigned_long_long_min = 0ULL;
constexpr unsigned long long unsigned_long_long_max = unsigned_long_long_min - 1ULL;

constexpr long long long_long_min = unsigned_long_long_max / 2LL + 1LL;
constexpr long long long_long_max = unsigned_long_long_max / 2LL;

constexpr Int8Type int8_min = -128;
constexpr Int8Type int8_max = 127;

constexpr Int16Type int16_min = -32768;
constexpr Int16Type int16_max = 32767;

constexpr Int32Type int32_min = -8388608L;
constexpr Int32Type int32_max = 8388607L;

constexpr Int64Type int64_min = -2147483648LL;
constexpr Int64Type int64_max = 2147483647LL;

constexpr UInt8Type uint8_min = 0;
constexpr UInt8Type uint8_max = 255;

constexpr UInt16Type uint16_min = 0U;
constexpr UInt16Type uint16_max = 65535U;

constexpr UInt32Type uint32_min = 0UL;
constexpr UInt32Type uint32_max = 16777215UL;

constexpr UInt64Type uint64_min = 0ULL;
constexpr UInt64Type uint64_max = 4294967295ULL;


DD_END



#endif