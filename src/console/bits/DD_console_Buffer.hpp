//	DDCPP/console/bits/DD_console_Buffer.hpp
#ifndef DD_CONSOLE_BUFFER_HPP_INCLUDED_
#	define DD_CONSOLE_BUFFER_HPP_INCLUDED_ 1



#	include <standard/bits/DD_Multidimention.hpp>

#	include "DD_console_put.hpp"



DD_CONSOLE_DETAIL_BEGIN_
struct Buffer {
	public:
	using ThisType = Buffer;

	private:
	using CharactorStorageType_ = Multidimention<CharactorStorageType, 2U>;
	using AttributeStorageType_ = Multidimention<WORD, 2U>;


	private:
	CharactorStorageType_ m_charactor_storage_;
	AttributeStorageType_ m_attribute_storage_;


	public:
    Buffer(CoordValueType width_, CoordValueType height_) :
    	m_charactor_storage_(width_, height_), m_attribute_storage_(width_, height_)
	{
    }


	public:
	ProcessType output() {
#	if DD_CONSOLE_IS_ON_WIN32
		RealLengthType workaround_;
		for (LengthType row_ = 0U; row_ < get_height(); ++row_) {
			if (!WriteConsoleOutputAttribute(
				GetStdHandle(STD_OUTPUT_HANDLE),
				::DD::address_of(attribute_),
				get_width(),
				::DD::console::detail_::convert_coord_(Coord{ 0, row_ }),
				::DD::address_of(workaround_)
			)) {
				throw ConsoleFailure("Unable to print: 'DD::console::put'", GetLastError());
			}
		}
#	endif
	}


	public:
	ProcessType draw_at(Pixel const& pixel_, Coord coord_) noexcept {
		m_charactor_storage_[coord_.x][coord_.y] = pixel_.charactor;
		m_attribute_storage_[coord_.x][coord_.y] = pixel_.extract_text_attribute_value_();
	}


};



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::Buffer;



DD_CONSOLE_END_



#endif
