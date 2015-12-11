//	DDCPP/standard/bits/DD_debugger_definitions.hpp
#ifndef DD_DEBUGGER_DEFINITIONS_HPP_INCLUDED_
#	define DD_DEBUGGER_DEFINITIONS_HPP_INCLUDED_ 1



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



#	if __cplusplus >= 201103L
#		define DD_CURRENT_FUNCTION __func__
#	else
#		define DD_CURRENT_FUNCTION "(Unknown)"
#	endif
#	define DD_CURRENT_FILE __FILE__
#	define DD_CURRENT_LINE __LINE__


#	define DD_ASSERTION_HANDLER_DEFINITION_BEGIN\
		DD_USER_DEFINITION_BEGIN\
		ProcessType assertion_handler(CStringConstType expression_, CStringConstType prompt_, CStringConstType function_, CStringConstType file_, long line_) {
#	define DD_ASSERTION_HANDLER_DEFINITION_END\
		}\
		DD_USER_DEFINITION_END


#	if DDCPP_ENABLE_ASSERT
#		if DDCPP_ENABLE_ASSERTION_HANDLER
#			define DD_ASSERT(ARG_Expression_, ARG_Prompt_)\
				((ARG_Expression_) ? (void)0 : ::DD::detail_::user_definition::assertion_handler(\
					#ARG_Expression_,\
					(ARG_Prompt_),\
					DD_CURRENT_FUNCTION,\
					DD_CURRENT_FILE,\
					DD_CURRENT_LINE\
				));
#		else
#			include <cassert>
#			define DD_ASSERT(ARG_Expression_, ARG_Prompt_) assert((ARG_Expression_) && (ARG_Prompt_));
#		endif
#	else
#		define DD_ASSERT(ARG_Expression_, ARG_Prompt_)
#	endif



DD_USER_DEFINITION_BEGIN_
ProcessType assertion_handler(CStringConstType expression_, CStringConstType prompt_, CStringConstType function_, CStringConstType file_, long line_);



DD_USER_DEFINITION_END_



#endif
