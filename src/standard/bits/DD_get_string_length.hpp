//	DDCPP/standard/bits/DD_get_string_length.hpp
#ifndef DD_GET_STRING_LENGTH_HPP_
#	define DD_GET_STRING_LENGTH_HPP_ 1



#	include "DD_get_string_end.hpp"



DD_DETAIL_BEGIN_
template <typename CharT_>
inline LengthType get_string_length(CharT_ const* cstring_) {
	return ::DD::get_string_end(cstring_) - cstring_;
}

template <typename CharT_>
inline LengthType get_string_length(CharT_ const* cstring_, CharT_ delimiter__) {
	return ::DD::get_string_end(cstring_, delimiter__) - cstring_;
}

template <typename CharT_>
inline LengthType get_string_length(CharT_ const* begin_, CharT_ const* end_) {
	return ::DD::get_string_end(begin_, end_) - begin_;
}

template <typename CharT_>
inline LengthType get_string_length(CharT_ const* begin_, CharT_ const* end_, CharT_ delimiter__) {
	return ::DD::get_string_end(begin_, end_, delimiter__) - begin_;
}

template <typename CharT_>
inline LengthType get_string_length(CharT_ const* begin_, LengthType length_) {
	return ::DD::get_string_end(begin_, length_) - begin_;
}

template <typename CharT_>
inline LengthType get_string_length(CharT_ const* begin_, LengthType length_, CharT_ delimiter__) {
	return ::DD::get_string_end(begin_, length_, delimiter__) - begin_;
}

template <typename CharT_, LengthType length_c_>
#	if __cplusplus >= 201103L
inline CharT_* get_string_length(ArrayType<CharT_, length_c_>& cstring_) noexcept {
#	else
inline CharT_* get_string_length(CharT_(&cstring_)[length_c_]) throw() {
#	endif
	return get_string_end(cstring_);
}

template <typename CharT_, LengthType length_c_>
#	if __cplusplus >= 201103L
inline CharT_* get_string_length(ArrayType<CharT_, length_c_>& cstring_, CharT_ delimiter__) noexcept {
#	else
inline CharT_* get_string_length(CharT_(&cstring_)[length_c_], CharT_ delimiter__) throw() {
#	endif
	return get_string_end(cstring_, delimiter__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::get_string_length;



DD_END_



#endif
