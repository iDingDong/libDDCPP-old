//	DDCPP/standard/bits/DD_get_length.hpp
#ifndef DD_GET_LENGTH_HPP_INCLUDED_
#	define DD_GET_LENGTH_HPP_INCLUDED_ 1



#	include "DD_get_string_length.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, LengthType length_c_>
#	if __cplusplus >= 201103L
inline LengthType constexpr get_length(ArrayType<ValueT_, length_c_> const& array_) noexcept {
#	else
inline LengthType get_length(ValueT_(&array_)[length_c_]) throw() {
#	endif
	return length_c_;
}

template <typename CharactorT_>
LengthType DD_CONSTEXPR get_length(CharactorT_ const* cstring_) DD_NOEXCEPT {
	if (cstring_) {
		return get_string_length(cstring_);
	}
	return LengthType();
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::get_length;



DD_END_



#endif
