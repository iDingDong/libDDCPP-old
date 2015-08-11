//	DDCPP/standard/bits/DD_MemberFunctionCheck.hpp
#ifndef _DD_MEMBER_FUNCTION_CHECK_HPP_INCLUDED
#	define _DD_MEMBER_FUNCTION_CHECK_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD_MEMBER_FUNCTION_CHECK'.



#	endif
#	include "DD_Nil.hpp"
#	include "DD_meta_definitions.hpp"



#	define DD_MEMBER_FUNCTION_CHECK(_ARG_Checker, _ARG_target, _ARG_ReturnType, ...)\
		DD_MACRO_DETAIL_BEGIN\
		template <typename _MACRO_ObjectT>\
		struct _##_ARG_Checker {\
			private:\
			template <typename _MACRO_ObjectT_, _ARG_ReturnType (_MACRO_ObjectT_::*)(__VA_ARGS__)>\
			struct _Matcher {\
			};\
			\
			\
			private:\
			template <typename _MACRO_ObjectT_>\
			static ValidityType constexpr _match(_Matcher<_MACRO_ObjectT_, &_MACRO_ObjectT_::_ARG_target>*) noexcept {\
				return true;\
			}\
			\
			private:\
			template <typename _MACRO_ObjectT_>\
			static ValidityType constexpr _match(...) noexcept {\
				return false;\
			}\
			\
			\
			public:\
			static ValidityType constexpr value = _match<_MACRO_ObjectT>(nil_pointer);\
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
		template <typename _MACRO_ObjectT>\
		using _ARG_Checker = BoolConstant<_MACRO_detail::_##_ARG_Checker<_MACRO_ObjectT>::value>;



#endif
