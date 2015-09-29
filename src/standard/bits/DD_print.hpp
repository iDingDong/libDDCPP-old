//	DDCPP/standard/bits/DD_print.hpp
#ifndef DD_PRINT_HPP_INCLUDED_
#	define DD_PRINT_HPP_INCLUDED_ 1



#	include <iostream>

#	include "DD_Tags.hpp"



DD_DETAIL_BEGIN_



DD_DETAIL_END_



DD_BEGIN_
struct FlushTag : Tag {
} DD_CONSTANT flush;



struct EndLineTag : Tag {
} DD_CONSTANT end_line;



struct Print {
	DD_ALIAS(ThisType, Print);


#	if __cplusplus >= 201103L
	ThisType const& operator ()() const DD_NOEXCEPT {
		return *this;
	}

	template <typename ValueT__, typename... ValuesT__>
	ThisType const& operator ()(
		ValueT__ const& value___,
		ValuesT__ const&... values___
	) const DD_NOEXCEPT_AS((Print(), value___)(values___...)) {
		return (*this, value___)(values___...);
	}


#	endif
	ThisType const& operator ,(FlushTag tag_) const DD_NOEXCEPT_AS(std::cout << std::flush) {
		std::cout << std::flush;
		return *this;
	}

	ThisType const& operator ,(EndLineTag tag_) const DD_NOEXCEPT_AS(std::cout << std::endl) {
		std::cout << std::endl;
		return *this;
	}

	template <typename ValueT__>
	ThisType const& operator ,(ValueT__ const& value___) const DD_NOEXCEPT_AS(std::cout << value___) {
		std::cout << value___;
		return *this;
	}


} DD_CONSTANT print;



DD_END_



#	define DD_PRINT ::DD::print,



#endif
