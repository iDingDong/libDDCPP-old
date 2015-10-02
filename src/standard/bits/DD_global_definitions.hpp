//	DDCPP/standard/bits/DD_global_definitions.hpp
#ifndef DD_GLOBAL_DEFINITIONS_HPP_INCLUDED_
#	define DD_GLOBAL_DEFINITIONS_HPP_INCLUDED_ 1



#	include <cstddef>



#	define DDCPP_ 1000

#	define DD_ON 1
#	define DD_OFF 0

#	if !defined(DDCPP_DEFAULT_WARNING)
#		define DDCPP_DEFAULT_WARNING DD_ON
#	endif

#	if !defined(DDCPP_VERSION_WARNING)
#		define DDCPP_VERSION_WARNING DDCPP_DEFAULT_WARNING
#	endif

#	if !defined(DDCPP_IMPERFECT_REALIZATION_WARNING)
#		define DDCPP_IMPERFECT_REALIZATION_WARNING DDCPP_DEFAULT_WARNING
#	endif

#	if !defined(DDCPP_DEPRECATION_WARNING)
#		define DDCPP_DEPRECATION_WARNING DDCPP_DEFAULT_WARNING
#	endif

#	if !defined(DDCPP_COMPAT_DEPRECATION)
#		define DDCPP_COMPAT_DEPRECATION DD_OFF
#	endif

#	if !defined(DDCPP_COMPAT_STL)
#		define DDCPP_COMPAT_STL DD_ON
#	endif



#	if !defined(__cplusplus)
#		error Compiler should support ISO C++.
#	elif __cplusplus < 201103L && DDCPP_VERSION_WARNING
#		warning ISO/IEC 14882:2011 or a later version support is recommended. Define 'DDCPP_VERSION_WARNING' as 'DD_OFF' to ignore this warning.
#	endif


#	define DD_BEGIN_ namespace DD {
#	define DD_END_ }

#	define DD_DETAIL_BEGIN_ DD_BEGIN_ namespace detail_ {
#	define DD_DETAIL_END_ } DD_END_

#	define DD_USER_DEFINITION_BEGIN DD_DETAIL_BEGIN_ namespace user_definition {
#	define DD_USER_DEFINITION_END } DD_DETAIL_END_


#	define DD_TO_STRING(ARG_literal_) #ARG_literal_


#	define DD_BACKUP_CODE 0


#	include "DD_compatibility_definitions.hpp"



DD_BEGIN_
DD_ALIAS(ProcessType, void);

DD_ALIAS(ValidityType, bool);
DD_ALIAS(CheckType, bool);

DD_ALIAS(SizeType, std::size_t);
DD_ALIAS(LengthType, SizeType);
DD_ALIAS(QuantityType, SizeType);

DD_ALIAS(PointerDifferenceType, std::ptrdiff_t);
DD_ALIAS(DifferenceType, PointerDifferenceType);
DD_ALIAS(CounterType, PointerDifferenceType);
DD_ALIAS(SubscriptType, PointerDifferenceType);

#	if __cplusplus >= 201103L
template <typename ValueT>
using ReferenceType = ValueT&;

template <typename ValueT, LengthType LengthT>
using ArrayType = ValueT[LengthT];

template <typename ValueT>
using PointerType = ValueT*;

#	endif
DD_ALIAS(GlobalPointerType, void*);

DD_ALIAS(CStringType, char*);

DD_ALIAS(CStringConstType, char const*);
DD_ALIAS(PromptType, CStringConstType);



#	if __cplusplus >= 201103L
enum class Direction {
	unknown,
	forward,
	backward

};
#	else
struct Direction {
	public:
	static Direction const unknown;
	static Direction const forward;
	static Direction const backward;


	public:
	int m_value_;


};



inline ValidityType operator ==(Direction direction_1_, Direction direction_2_) {
	return direction_1_.m_value_ == direction_2_.m_value_;
}


inline ValidityType operator !=(Direction direction_1_, Direction direction_2_) {
	return !(direction_1_.m_value_ == direction_2_.m_value_);
}



Direction const Direction::unknown = {0};
Direction const Direction::forward = {1};
Direction const Direction::backward = {2};
#	endif



#	if __cplusplus >= 201103L
LengthType constexpr operator ""_DD_Length(unsigned long long length) {
	return length;
}



CounterType constexpr operator ""_DD_Counter(unsigned long long counter) {
	return counter;
}



#	endif
CheckType DD_CONSTANT on = true;
CheckType DD_CONSTANT off = false;



DD_END_



#endif
