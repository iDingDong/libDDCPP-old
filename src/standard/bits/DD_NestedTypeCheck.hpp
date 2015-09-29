//	DDCPP/standard/bits/DD_NestedTypeCheck.hpp
#ifndef DD_NESTED_TYPE_CHECK_HPP_INCLUDED_
#	define DD_NESTED_TYPE_CHECK_HPP_INCLUDED_ 1



#	include "DD_Nil.hpp"
#	include "DD_meta_definitions.hpp"
#	if __cplusplus >= 201103L
#		include "DD_VoidType.hpp"
#	else
#		include "DD_SizeTrait.hpp"
#	endif
#	include "DD_IntegralConstant.hpp"



#	if __cplusplus >= 201103L
#		define DD_NESTED_TYPE_CHECK(ARG_Checker_, ...)\
			DD_MACRO_DETAIL_BEGIN\
			template <typename MACRO_ObjectT_, typename VoidT_>\
			struct ARG_Checker_##_ : ::DD::FalseType {\
			};\
			\
			\
			\
			template <typename MACRO_ObjectT_>\
			struct ARG_Checker_##_<MACRO_ObjectT_, ::DD::VoidType<typename MACRO_ObjectT_::__VA_ARGS__>> : ::DD::TrueType {\
			};\
			\
			\
			\
			DD_MACRO_DETAIL_END\
			\
			\
			\
			template <typename MACRO_ObjectT_>\
			using ARG_Checker_ = ::DD::BoolConstant<MACRO_detail_::ARG_Checker_##_<MACRO_ObjectT_, ::DD::VoidType<>>::value>;


#		define DD_NESTED_TYPE_TRAIT(ARG_Checker_, ARG_Target_, ...)\
			template <typename MACRO_ObjectT_>\
			struct ARG_Checker_ {\
				private:\
				template <typename MACRO_ObjectT__>\
				static typename MACRO_ObjectT__::ARG_Target_ match_(::DD::detail_::NestedTypeMatcher_<typename MACRO_ObjectT__::ARG_Target_>*) noexcept(true);\
				\
				private:\
				template <typename MACRO_ObjectT__>\
				static __VA_ARGS__ match_(...) noexcept(true);\
				\
				\
				public:\
				using Type = decltype(match_<MACRO_ObjectT_>(::DD::nil_pointer));\
				\
				\
			};\
			\
			\
			\
			template <typename ARG_ObjectT_>\
			using ARG_Checker_##Type = typename ARG_Checker_<ARG_ObjectT_>::Type;


#	else
#		define DD_NESTED_TYPE_CHECK(ARG_Checker_, ARG_Target_)\
			DD_MACRO_DETAIL_BEGIN\
			template <typename MACRO_ObjectT_>\
			struct ARG_Checker_##_ {\
				template <typename MACRO_ObjectT__>\
				static SizeTrait<1> match_(::DD::detail_::NestedTypeMatcher_<typename MACRO_ObjectT__::ARG_Target_>*);\
				\
				template <typename MACRO_ObjectT__>\
				static SizeTrait<2> match_(...);\
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



#		define DD_NESTED_TYPE_TRAIT(ARG_Checker_, ARG_Target_, ARG_Default_)\
			DD_MACRO_DETAIL_BEGIN\
			DD_NESTED_TYPE_CHECK(CHECK_##ARG_Checker_##_, ARG_Target_)\
			\
			\
			\
			template <typename MACRO_ObjectT_, ValidityType MACRO_has_target_c_>\
			struct ARG_Checker_##_ {\
				typedef ARG_Default_ Type;\
				\
				\
			};\
			\
			\
			\
			template <typename MACRO_ObjectT_>\
			struct ARG_Checker_##_<MACRO_ObjectT_, true> {\
				typedef typename MACRO_ObjectT_::ARG_Target_ Type;\
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
			struct ARG_Checker_ {\
				typedef typename MACRO_detail_::_##ARG_Checker_<\
					MACRO_ObjectT_,\
					MACRO_detail_::CHECK_##ARG_Checker_##_<MACRO_ObjectT_>::value\
				>::Type Type;\
				\
				\
			};


#	endif



DD_DETAIL_BEGIN_
template <typename ObjectT>
struct NestedTypeMatcher_ {
};



DD_DETAIL_END_



#endif
