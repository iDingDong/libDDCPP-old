// standard/bits/DD_compatibility_definitions.hpp
#ifndef _DD_COMPATIBILITY_DEFINITIONS_HPP_INCLUDED
#	define _DD_COMPATIBILITY_DEFINITIONS_HPP_INCLUDED 1



#	define DD_COMMA ,

#	if __cplusplus >= 201103L
#		define DD_STATIC_ASSERT(_ARG_condition, _ARG_Prompt) static_assert(_ARG_condition, _ARG_Prompt)
#	else
#		define DD_STATIC_ASSERT(_ARG_condition, _ARG_Prompt)
#	endif

#	if __cplusplus >= 201103L
#		define DD_NOEXCEPT noexcept
#		define DD_NOEXCEPT_IF(_ARG_condition) noexcept(_ARG_condition)
#		define DD_NOEXCEPT_AS(_ARG_expression) noexcept(noexcept(_ARG_expression))
#	else
#		define DD_NOEXCEPT throw()
#		define DD_NOEXCEPT_IF(_ARG_condition)
#		define DD_NOEXCEPT_AS(_ARG_expression)
#	endif

#	if __cplusplus >= 201103L
#		define DD_CALLABLE_WITH_LVALUE_ONLY &
#		define DD_CALLABLE_WITH_RVALUE_ONLY &&
#	else
#		define DD_CALLABLE_WITH_LVALUE_ONLY
#		define DD_CALLABLE_WITH_RVALUE_ONLY
#	endif

#	if __cplusplus >= 201103L
#		define DD_CONSTEXPR constexpr
#		define DD_CONSTANT constexpr
#	else
#		define DD_CONSTEXPR
#		define DD_CONSTANT const
#	endif

#	if __cplusplus >= 201103L
#		define DD_ALIAS(_ARG_Alias, _ARG_Origin) using _ARG_Alias = _ARG_Origin;
#	else
#		define DD_ALIAS(_ARG_Alias, _ARG_Origin) typedef _ARG_Origin _ARG_Alias;
#	endif

#	if __cplusplus >= 201103L
#		define DD_TRAIT_MODIFIER(_ARG_Modifier) template <typename _MACRO_ObjectT> using _ARG_Modifier##Type = typename _ARG_Modifier<_MACRO_ObjectT>::Type;
#		define DD_MODIFY_TRAIT(_ARG_Modifier, _ARG_Target) _ARG_Modifier##Type<_ARG_Target>
#	else
#		define DD_TRAIT_MODIFIER(_ARG_Modifier)
#		define DD_MODIFY_TRAIT(_ARG_Modifier, _ARG_Target) typename _ARG_Modifier<_ARG_Target>::Type
#	endif

#	if __cplusplus >= 201103L
#		define DD_IN_CLASS_INITIALIZE(_ARG_Expression) = _ARG_Expression
#	else
#		define DD_IN_CLASS_INITIALIZE(_ARG_Expression)
#	endif

#	if __cplusplus >= 201103L
#		define DD_DELETE_DEFAULT_CONSTRUCTOR(_ARG_Class) _ARG_Class() = delete;
#		define DD_DELETE_COPY_CONSTRUCTOR(_ARG_Class) _ARG_Class(_ARG_Class const& _origin) = delete;
#		define DD_DELETE_MOVE_CONSTRUCTOR(_ARG_Class) _ARG_Class(_ARG_Class&& _origin) = delete;
#		define DD_DELETE_COPY_ASSIGNMENT(_ARG_Class) _ARG_Class& operator =(_ARG_Class const& _origin) = delete;
#		define DD_DELETE_MOVE_ASSIGNMENT(_ARG_Class) _ARG_Class& operator =(_ARG_Class&& _origin) = delete;
#	else
#		define DD_DELETE_DEFAULT_CONSTRUCTOR(_ARG_Class) private: _ARG_Class();
#		define DD_DELETE_COPY_CONSTRUCTOR(_ARG_Class) private: _ARG_Class(_ARG_Class const& _origin);
#		define DD_DELETE_MOVE_CONSTRUCTOR(_ARG_Class)
#		define DD_DELETE_COPY_ASSIGNMENT(_ARG_Class) private: _ARG_Class& operator =(_ARG_Class const& _origin);
#		define DD_DELETE_MOVE_ASSIGNMENT(_ARG_Class)
#	endif

#	if __cplusplus >= 201103L
#		define DD_FINAL final
#		define DD_OVERRIDE override
#	else
#		define DD_FINAL
#		define DD_OVERRIDE
#	endif



#	endif
