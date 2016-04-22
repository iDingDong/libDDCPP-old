//	DDCPP/standard/bits/DD_console_TextAttribute.hpp
#ifndef DD_CONSOLE_TEXT_ATTRIBUTE_HPP_INCLUDED_
#	define DD_CONSOLE_TEXT_ATTRIBUTE_HPP_INCLUDED_



#	include "DD_console_Color.hpp"



DD_CONSOLE_DETAIL_BEGIN_
struct TextAttribute {
	public:
	using ThisType = TextAttribute;
	DD_VALUE_TYPE_NESTED(ValidityType)


	private:
#	if DD_CONSOLE_IS_ON_WIN32
	WORD m_value_ = 0x000E;
#	endif


#	if DD_CONSOLE_IS_ON_WIN32
	public:
	friend
	WORD extract_text_attribute_value_(TextAttribute text_attribute_) noexcept {
		return text_attribute_.m_value_;
	}


#	endif
	public:
	constexpr TextAttribute() = default;

	public:
	constexpr TextAttribute(ThisType const& origin_) = default;

	public:
	constexpr TextAttribute(ThisType&& origin_) = default;

	public:
#	if DD_CONSOLE_IS_ON_WIN32
	constexpr TextAttribute(
		Color text_color_, Color background_color_ = Color::black()
	) : m_value_(text_color_.value | FOREGROUND_INTENSITY | (background_color_.value << 4U)) {
	}
#	endif


};



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::TextAttribute;



DD_CONSOLE_END_



#endif
