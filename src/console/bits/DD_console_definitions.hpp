//	DDCPP/console/bits/DD_console_definitions.hpp
#ifndef DD_CONSOLE_DEFINITIONS_HPP_INCLUDED_
#	define DD_CONSOLE_DEFINITIONS_HPP_INCLUDED_ 1



#	define DDCPP_WIN32 1


#	if !defined(DDCPP_CONSOLE_TARGET_PLATFORM)
#		if defined(__WIN32)
#			define DDCPP_CONSOLE_TARGET_PLATFORM DDCPP_WIN32
#		else
#			error Detected platform is not supported by DDCPP-console.
#		endif
#	endif

#	define DD_CONSOLE_IS_ON_WIN32 DDCPP_CONSOLE_TARGET_PLATFORM == DDCPP_WIN32



#	if DD_CONSOLE_IS_ON_WIN32
#		include <windows.h>
#	endif

#	include <standard/bits/DD_Coord.hpp>



#	define DD_CONSOLE_BEGIN_ DD_BEGIN_ namespace console {
#	define DD_CONSOLE_END_ } DD_END_

#	define DD_CONSOLE_DETAIL_BEGIN_ DD_CONSOLE_BEGIN_ namespace detail_ {
#	define DD_CONSOLE_DETAIL_END_ } DD_CONSOLE_END_



DD_CONSOLE_DETAIL_BEGIN_
#	if DD_CONSOLE_IS_ON_WIN32
using CharactorType = TCHAR;
using CharactorConstType = CharactorType const;
using CStringType = CharactorType*;
using CStringConstType = CharactorConstType*;

using RealLengthType = DWORD;
using CoordValueType = SHORT;

using Coord = ::DD::Coord<CoordValueType>;
#	endif



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::CharactorType;
using ::DD::console::detail_::CharactorConstType;
using ::DD::console::detail_::CStringType;
using ::DD::console::detail_::CStringConstType;
using ::DD::console::detail_::RealLengthType;
using ::DD::console::detail_::CoordValueType;
using ::DD::console::detail_::Coord;



DD_CONSOLE_END_



#endif
