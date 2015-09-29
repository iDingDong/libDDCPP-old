//	DDCPP/standard/bits/DD_MemberFunctionCheck.hpp
#ifndef DD_MEMBER_FUNCTION_CHECK_HPP_INCLUDED_
#	define DD_MEMBER_FUNCTION_CHECK_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD_MEMBER_FUNCTION_CHECK'.



#	endif
#	include "DD_Nil.hpp"
#	include "DD_meta_definitions.hpp"
#	if __cplusplus < 201103L
#		include "DD_SizeTrait.hpp"
#	endif



#	if __cplusplus >= 201103L
#		define DD_MEMBER_FUNCTION_CHECK(ARG_Checker_, ARG_target_, ARG_ReturnType_, ...)\
			DD_MACRO_DETAIL_BEGIN\
			template <typename MACRO_ObjectT_>\
			struct ARG_Checker_##_ {\
				private:\
				template <typename MACRO_ObjectT__, ARG_ReturnType_ (MACRO_ObjectT__::*)(__VA_ARGS__)>\
				struct Matcher_ {\
				};\
				\
				\
				private:\
				template <typename MACRO_ObjectT__>\
				static ::DD::ValidityType constexpr match_(Matcher_<MACRO_ObjectT__, &MACRO_ObjectT__::ARG_target_>*) noexcept {\
					return true;\
				}\
				\
				private:\
				template <typename MACRO_ObjectT__>\
				static ::DD::ValidityType constexpr match_(...) noexcept {\
					return false;\
				}\
				\
				\
				public:\
				static ::DD::ValidityType constexpr value = match_<MACRO_ObjectT_>(::DD::nil_pointer);\
				\
				\
			};\
			\
			\
			\
			DD_MACRO_DETAIL_END\
			\
			\
			\
			template <typename MACRO_ObjectT_>\
			using ARG_Checker_ = ::DD::BoolConstant<MACRO_detail_::ARG_Checker_##_<MACRO_ObjectT_>::value>;


#	else
#		define DD_MEMBER_FUNCTION_CHECK(ARG_Checker_, ARG_target_, ARG_ReturnType_, ARG_ArgumentsType_)\
			DD_MACRO_DETAIL_BEGIN\
			template <typename MACRO_ObjectT_>\
			struct ARG_Checker_##_ {\
				private:\
				template <typename MACRO_ObjectT__, ARG_ReturnType_ (MACRO_ObjectT__::*)(ARG_ArgumentsType_)>\
				struct Matcher_ {\
				};\
				\
				\
				private:\
				template <typename MACRO_ObjectT__>\
				static SizeTrait<1> match_(Matcher_<MACRO_ObjectT__, &MACRO_ObjectT__::ARG_target_>*) throw();\
				\
				private:\
				template <typename MACRO_ObjectT__>\
				static SizeTrait<2> match_(...) throw();\
				\
				\
				static ::DD::ValidityType const value = sizeof(match_<MACRO_ObjectT_>(0)) == sizeof(SizeTrait<1>);\
				\
				\
			};\
			\
			\
			\
			DD_MACRO_DETAIL_END\
			\
			\
			\
			template <typename MACRO_ObjectT_>\
			struct ARG_Checker_ : ::DD::BoolConstant<MACRO_detail_::ARG_Checker_##_<MACRO_ObjectT_>::value> {\
			};


#	endif



#endif
