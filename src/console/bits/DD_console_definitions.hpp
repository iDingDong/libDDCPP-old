//	DDCPP/console/bits/DD_console_definitions.hpp
#ifndef DD_CONSOLE_DEFINITIONS_HPP_INCLUDED_
#	define DD_CONSOLE_DEFINITIONS_HPP_INCLUDED_ 1



#	define DDCPP_WIN32 1

#	define DDCPP_ASCII 1
#	define DDCPP_UNICODE 2


#	if !defined(DDCPP_CONSOLE_TARGET_PLATFORM)
#		if defined(__WIN32)
#			define DDCPP_CONSOLE_TARGET_PLATFORM DDCPP_WIN32
#		else
#			error Detected platform is not supported by DDCPP-console.
#		endif
#	endif

#	define DD_CONSOLE_IS_ON_WIN32 DDCPP_CONSOLE_TARGET_PLATFORM == DDCPP_WIN32


#	if !defined(DDCPP_CONSOLE_ENCODING)
#		define DDCPP_CONSOLE_ENCODING DDCPP_ASCII
#	endif

#	define DD_CONSOLE_USE_ASCII DDCPP_CONSOLE_ENCODING == DDCPP_ASCII
#	define DD_CONSOLE_USE_UNICODE DDCPP_CONSOLE_ENCODING == DDCPP_UNICODE


#	if DD_CONSOLE_USE_UNICODE
#		if DD_CONSOLE_IS_ON_WIN32
#			define _UNICODE
#		endif
#	endif



#	if DD_CONSOLE_IS_ON_WIN32
#		if DD_CONSOLE_USE_UNICODE
#			include <tchar.h>
#			include <wchar.h>
#		endif
#		include <windows.h>
#	endif

#	include <standard/bits/DD_Coord.hpp>



#	define DD_CONSOLE_BEGIN_ DD_BEGIN_ namespace console {
#	define DD_CONSOLE_END_ } DD_END_

#	define DD_CONSOLE_DETAIL_BEGIN_ DD_CONSOLE_BEGIN_ namespace detail_ {
#	define DD_CONSOLE_DETAIL_END_ } DD_CONSOLE_END_



DD_CONSOLE_DETAIL_BEGIN_
#	if DD_CONSOLE_USE_ASCII
using CharactorStorageType = char;
#	else
using CharactorStorageType = char32_t;
#	endif
#	if DD_CONSOLE_IS_ON_WIN32
using CharactorType = TCHAR;
using CharactorConstType = CharactorType const;
using CStringType = CharactorType*;
using CStringConstType = CharactorConstType*;

using RealLengthType = DWORD;
using CoordValueType = SHORT;
#	endif

using Coord = ::DD::Coord<CoordValueType>;



#	if DD_CONSOLE_IS_ON_WIN32
inline CoordValueType constexpr uniform_x_(CoordValueType x) noexcept {
	return x;
}


inline CoordValueType constexpr uniform_y_(CoordValueType y) noexcept {
	return y;
}


inline COORD constexpr convert_coord_(Coord coord_) noexcept {
	return COORD{ uniform_x_(coord_.x), uniform_y_(coord_.y) };
}
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
