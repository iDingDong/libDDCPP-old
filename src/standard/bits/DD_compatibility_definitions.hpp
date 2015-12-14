// standard/bits/DD_compatibility_definitions.hpp
#ifndef DD_COMPATIBILITY_DEFINITIONS_HPP_INCLUDED_
#	define DD_COMPATIBILITY_DEFINITIONS_HPP_INCLUDED_ 1



#	define DD_COMMA ,

#	if __cplusplus >= 201103L
#		define DD_ARGUMENT(...) __VA_ARGS__

#	endif
#	if __cplusplus >= 201103L
#		define DD_STATIC_ASSERT(ARG_condition_, ARG_Prompt_) static_assert(ARG_condition_, ARG_Prompt_)
#	else
#		define DD_STATIC_ASSERT(ARG_condition_, ARG_Prompt_)
#	endif

#	if __cplusplus >= 201103L
#		define DD_NOEXCEPT noexcept
#		define DD_NOEXCEPT_IF(ARG_condition_) noexcept(ARG_condition_)
#		define DD_NOEXCEPT_AS(ARG_expression_) noexcept(noexcept(ARG_expression_))
#	else
#		define DD_NOEXCEPT throw()
#		define DD_NOEXCEPT_IF(ARG_condition_)
#		define DD_NOEXCEPT_AS(ARG_expression_)
#	endif

#	if __cplusplus >= 201103L
#		define DD_CALLABLE_WITH_LVALUE_ONLY &
#		define DD_CALLABLE_WITH_RVALUE_ONLY &&
#	else
#		define DD_CALLABLE_WITH_LVALUE_ONLY
#		define DD_CALLABLE_WITH_RVALUE_ONLY
#	endif

#	if __cplusplus >= 201402L
#		define DD_UNCONSTRIANED_CONSTEXPR constexpr
#	else
#		define DD_UNCONSTRIANED_CONSTEXPR
#	endif
#	if __cplusplus >= 201103L
#		define DD_CONSTEXPR constexpr
#		define DD_CONSTANT constexpr
#	else
#		define DD_CONSTEXPR
#		define DD_CONSTANT const
#	endif

#	if __cplusplus >= 201103L
#		define DD_ALIAS(ARG_Alias_, ARG_Origin_) using ARG_Alias_ = ARG_Origin_
#	else
#		define DD_ALIAS(ARG_Alias_, ARG_Origin_) typedef ARG_Origin_ ARG_Alias_
#	endif

#	define DD_INHERIT_ALIAS(ARG_Alias_) DD_ALIAS(ARG_Alias_, SuperType::ARG_Alias_)
#	define DD_INHERIT_TEMPLATE_ALIAS(ARG_Alias_) DD_ALIAS(ARG_Alias_, typename SuperType::ARG_Alias_)

#	if __cplusplus >= 201103L
#		define DD_TRAIT_MODIFIER(ARG_Modifier_) template <typename MACRO_ObjectT_> using ARG_Modifier_##Type = typename ARG_Modifier_<MACRO_ObjectT_>::Type;
#		define DD_MODIFY_TRAIT(ARG_Modifier_, ARG_Target_) ARG_Modifier_##Type<ARG_Target_>
#	else
#		define DD_TRAIT_MODIFIER(ARG_Modifier_)
#		define DD_MODIFY_TRAIT(ARG_Modifier_, ARG_Target_) typename ARG_Modifier_<ARG_Target_>::Type
#	endif

#	if __cplusplus >= 201103L
#		define DD_DEFAULT_FUNCTION_TEMPLATE_ARGUMENT(ARG_Expression_) = (ARG_Expression_)
#	else
#		define DD_DEFAULT_FUNCTION_TEMPLATE_ARGUMENT(ARG_Expression_)
#	endif

#	if __cplusplus >= 201103L
#		define DD_IN_CLASS_INITIALIZE(ARG_Expression_) = ARG_Expression_
#	else
#		define DD_IN_CLASS_INITIALIZE(ARG_Expression_)
#	endif

#	if __cplusplus >= 201103L
#		define DD_DELETE_DEFAULT_CONSTRUCTOR(ARG_Class_) ARG_Class_() = delete;
#		define DD_DELETE_COPY_CONSTRUCTOR(ARG_Class_) ARG_Class_(ThisType const& origin_) = delete;
#		define DD_DELETE_MOVE_CONSTRUCTOR(ARG_Class_) ARG_Class_(ThisType&& origin_) = delete;
#		define DD_DELETE_DESTRUCTOR(ARG_Class_) ~ARG_Class_() = delete;
#		define DD_DELETE_COPY_ASSIGNMENT(ARG_Class_) ThisType& operator =(ThisType const& origin_) = delete;
#		define DD_DELETE_MOVE_ASSIGNMENT(ARG_Class_) ThisType& operator =(ThisType&& origin_) = delete;
#	else
#		define DD_DELETE_DEFAULT_CONSTRUCTOR(ARG_Class_) private: ARG_Class_();
#		define DD_DELETE_COPY_CONSTRUCTOR(ARG_Class_) private: ARG_Class_(ThisType const& origin_);
#		define DD_DELETE_MOVE_CONSTRUCTOR(ARG_Class_)
#		define DD_DELETE_DESTRUCTOR(ARG_Class_) private: ~ARG_Class_();
#		define DD_DELETE_COPY_ASSIGNMENT(ARG_Class_) private: ThisType& operator =(ThisType const& origin_);
#		define DD_DELETE_MOVE_ASSIGNMENT(ARG_Class_)
#	endif
#	define DD_DELETE_ALL_CONSTRUCTORS(ARG_Class_)\
		DD_DELETE_DEFAULT_CONSTRUCTOR(ARG_Class_)\
		DD_DELETE_COPY_CONSTRUCTOR(ARG_Class_)\
		DD_DELETE_MOVE_CONSTRUCTOR(ARG_Class_)
#	define DD_DELETE_ALL_ASSIGNMENTS(ARG_Class_)\
		DD_DELETE_COPY_ASSIGNMENT(ARG_Class_)\
		DD_DELETE_MOVE_ASSIGNMENT(ARG_Class_)

#	if __cplusplus >= 201103L
#		define DD_FINAL final
#		define DD_OVERRIDE override
#	else
#		define DD_FINAL
#		define DD_OVERRIDE
#	endif



#	endif
