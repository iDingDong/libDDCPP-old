//	DDCPP/standard/bits/DD_MemberFunctionCheck.hpp
#ifndef _DD_MEMBER_FUNCTION_CHECK_HPP_INCLUDED
#	define _DD_MEMBER_FUNCTION_CHECK_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD_MEMBER_FUNCTION_CHECK'.



#	endif
#	include "DD_Nil.hpp"
#	include "DD_meta_definitions.hpp"
#	if __cplusplus < 201103L
#		include "DD_SizeTrait.hpp"
#	endif



#	if __cplusplus >= 201103L
#		define DD_MEMBER_FUNCTION_CHECK(_ARG_Checker, _ARG_target, _ARG_ReturnType, ...)\
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
				static ::DD::ValidityType constexpr _match(_Matcher<_MACRO_ObjectT_, &_MACRO_ObjectT_::_ARG_target>*) noexcept {\
					return true;\
				}\
				\
				private:\
				template <typename _MACRO_ObjectT_>\
				static ::DD::ValidityType constexpr _match(...) noexcept {\
					return false;\
				}\
				\
				\
				public:\
				static ::DD::ValidityType constexpr value = _match<_MACRO_ObjectT>(::DD::nil_pointer);\
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
			using _ARG_Checker = ::DD::BoolConstant<_MACRO_detail::_##_ARG_Checker<_MACRO_ObjectT>::value>;
#	else
#		define DD_MEMBER_FUNCTION_CHECK(_ARG_Checker, _ARG_target, _ARG_ReturnType, _ARG_ArgumentsType)\
			DD_MACRO_DETAIL_BEGIN\
			template <typename _MACRO_ObjectT>\
			struct _##_ARG_Checker {\
				private:\
				template <typename _MACRO_ObjectT_, _ARG_ReturnType (_MACRO_ObjectT_::*)(_ARG_ArgumentsType)>\
				struct _Matcher {\
				};\
				\
				\
				private:\
				template <typename _MACRO_ObjectT_>\
				static SizeTrait<1> _match(_Matcher<_MACRO_ObjectT_, &_MACRO_ObjectT_::_ARG_target>*) throw();\
				\
				private:\
				template <typename _MACRO_ObjectT_>\
				static SizeTrait<2> _match(...) throw();\
				\
				\
				static ::DD::ValidityType const value = sizeof(_match<_MACRO_ObjectT>(0)) == sizeof(SizeTrait<1>);\
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
			struct _ARG_Checker : ::DD::BoolConstant<_MACRO_detail::_##_ARG_Checker<_MACRO_ObjectT>::value> {\
			};
#	endif



#endif
