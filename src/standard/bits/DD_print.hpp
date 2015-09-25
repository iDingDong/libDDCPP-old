//	DDCPP/standard/bits/DD_print.hpp
#ifndef _DD_PRINT_HPP_INCLUDED
#	define _DD_PRINT_HPP_INCLUDED 1



#	include <iostream>

#	include "DD_Tags.hpp"



_DD_DETAIL_BEGIN



_DD_DETAIL_END



_DD_BEGIN
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

	template <typename _ValueT_, typename... _ValuesT_>
	ThisType const& operator ()(
		_ValueT_ const& __value_,
		_ValuesT_ const&... __values_
	) const DD_NOEXCEPT_AS((Print(), __value_)(__values_...)) {
		return (*this, __value_)(__values_...);
	}


#	endif
	ThisType const& operator ,(FlushTag _tag) const DD_NOEXCEPT_AS(std::cout << std::flush) {
		std::cout << std::flush;
		return *this;
	}

	ThisType const& operator ,(EndLineTag _tag) const DD_NOEXCEPT_AS(std::cout << std::endl) {
		std::cout << std::endl;
		return *this;
	}

	template <typename _ValueT_>
	ThisType const& operator ,(_ValueT_ const& __value_) const DD_NOEXCEPT_AS(std::cout << __value_) {
		std::cout << __value_;
		return *this;
	}


} DD_CONSTANT print;



_DD_END



#	define DD_PRINT ::DD::print,



#endif
