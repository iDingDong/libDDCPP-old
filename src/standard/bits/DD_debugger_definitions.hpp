//	DDCPP/standard/bits/DD_debugger_definitions.hpp
#ifndef _DD_DEBUGGER_DEFINITIONS_HPP_INCLUDED
#	define _DD_DEBUGGER_DEFINITIONS_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



#	if !defined(DDCPP_DEBUG)
#		define DDCPP_DEBUG DD_OFF
#	endif

#	if !defined(DDCPP_ENABLE_ASSERT)
#		define DDCPP_ENABLE_ASSERT DDCPP_DEBUG
#	endif

#	if !defined(DDCPP_ENABLE_ASSERTION_HANDLER)
#		define DDCPP_ENABLE_ASSERTION_HANDLER DD_OFF
#	endif



#	if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__) || (defined(__DMC__) && (__DMC__ >= 0x810))
#		define DD_CURRENT_FUNCTION __PRETTY_FUNCTION__
#	elif defined(__FUNCSIG__)
#		define DD_CURRENT_FUNCTION __FUNCSIG__
#	elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
#		define DD_CURRENT_FUNCTION __FUNCTION__
#	elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
#		define DD_CURRENT_FUNCTION __FUNC__
#	elif (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)) || (defined(__cplusplus) && (__cplusplus >= 201103))
#		define DD_CURRENT_FUNCTION __func__
#	else
#		define DD_CURRENT_FUNCTION "(Unknown)"
#	endif// Support from boost
#	define DD_CURRENT_FILE __FILE__
#	define DD_CURRENT_LINE __LINE__


#	define DD_ASSERTION_HANDLER_DEFINITION_BEGIN\
		DD_USER_DEFINITION_BEGIN\
		ProcessType assertion_handler(CStringConstType _expression, CStringConstType _prompt, CStringConstType _function, CStringConstType _file, long _line) {
#	define DD_ASSERTION_HANDLER_DEFINITION_END\
		}\
		DD_USER_DEFINITION_END


#	if DDCPP_ENABLE_ASSERT
#		if DDCPP_ENABLE_ASSERTION_HANDLER
#			define DD_ASSERT(_ARG_Expression, _ARG_Prompt)\
				((_ARG_Expression) ? (void)0 : ::DD::_detail::user_definition::assertion_handler(\
					#_ARG_Expression,\
					(_ARG_Prompt),\
					DD_CURRENT_FUNCTION,\
					DD_CURRENT_FILE,\
					DD_CURRENT_LINE\
				));
#		else
#			include <cassert>
#			define DD_ASSERT(_ARG_Expression, _ARG_Prompt) assert((_ARG_Expression) && (_ARG_Prompt));
#		endif
#	else
#		define DD_ASSERT(_ARG_Expression, _ARG_Prompt)
#	endif



DD_USER_DEFINITION_BEGIN
ProcessType assertion_handler(CStringConstType _expression, CStringConstType _prompt, CStringConstType _function, CStringConstType _file, long _line);



DD_USER_DEFINITION_END



#endif
