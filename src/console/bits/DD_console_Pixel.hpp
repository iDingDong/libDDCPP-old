//	DDCPP/console/bits/DD_console_Pixel.hpp
#ifndef DD_CONSOLE_PIXEL_HPP_INCLUDED_
#	define DD_CONSOLE_PIXEL_HPP_INCLUDED_



#	include "DD_console_TextAttribute.hpp"



DD_CONSOLE_DETAIL_BEGIN_
struct Pixel {
	public:
	using ThisType = Pixel;


	public:
	CharactorStorageType charactor;
	TextAttribute attribute;


};



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::Pixel;



DD_CONSOLE_END_



#endif
