//	DDCPP/standard/bits/DD_ArithmeticLimit.hpp
#ifndef DD_ARITHMETIC_LIMIT_HPP_INCLUDED_
#	define DD_ARITHMETIC_LIMIT_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <limits>
#	else
#		include <cstdint>
#	endif

#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
#	if __cplusplus >= 201103L
template <typename ArithmeticT_>
struct ArithmeticLimit {
	using Type = ArithmeticT_;
	static Type constexpr min = std::numeric_limits<Type>::min();
	static Type constexpr max = std::numeric_limits<Type>::max();


};
#	else
template <typename ArithmeticT_>
struct ArithmeticLimit;



template <>
struct ArithmeticLimit<bool> {
	typedef bool Type;
	static Type const min = false;
	static Type const max = true;


};



template <>
struct ArithmeticLimit<char> {
	typedef char Type;
	static Type const min = CHAR_MIN;
	static Type const max = CHAR_MAX;


};



template <>
struct ArithmeticLimit<unsigned char> {
	typedef unsigned char Type;
	static Type const min = 0;
	static Type const max = UCHAR_MAX;


};



template <>
struct ArithmeticLimit<signed char> {
	typedef signed char Type;
	static Type const min = SCHAR_MIN;
	static Type const max = SCHAR_MAX;


};



template <>
struct ArithmeticLimit<unsigned short int> {
	typedef unsigned short int Type;
	static Type const min = 0;
	static Type const max = USHRT_MAX;


};



template <>
struct ArithmeticLimit<signed short int> {
	typedef signed short int Type;
	static Type const min = SHRT_MIN;
	static Type const max = SHRT_MAX;


};



template <>
struct ArithmeticLimit<unsigned int> {
	typedef unsigned int Type;
	static Type const min = 0;
	static Type const max = UINT_MAX;


};



template <>
struct ArithmeticLimit<signed int> {
	typedef signed int Type;
	static Type const min = INT_MIN;
	static Type const max = INT_MAX;


};



template <>
struct ArithmeticLimit<unsigned long int> {
	typedef unsigned long int Type;
	static Type const min = 0;
	static Type const max = ULONG_MAX;


};



template <>
struct ArithmeticLimit<signed long int> {
	typedef signed long int Type;
	static Type const min = LONG_MIN;
	static Type const max = LONG_MAX;


};



template <>
ArithmeticLimit<float> {
	typedef float Type;
	static Type const min = FLT_MIN;
	static Type const max = FLT_MAX;


};



template <>
ArithmeticLimit<double> {
	typedef double Type;
	static Type const min = DBL_MIN;
	static Type const max = DBL_MAX;


};



template <>
ArithmeticLimit<long double> {
	typedef long double Type;
	static Type const min = LDBL_MIN;
	static Type const max = LDBL_MAX;


};
#	endif



DD_DETAIL_END_



DD_BEGIN_
using detail_::ArithmeticLimit;



DD_END_



#endif
