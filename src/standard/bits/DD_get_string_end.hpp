//	DDCPP/standard/bits/DD_get_string_end.hpp
#ifndef DD_GET_STRING_END_HPP_INCLUDED_



#	include "DD_find.hpp"



DD_DETAIL_BEGIN_
template <typename CharT_>
inline CharT_* get_string_end(CharT_* cstring_) DD_NOEXCEPT {
	while (*cstring_) {
		++cstring_;
	}
	return cstring_;
}

template <typename CharT_>
inline CharT_* get_string_end(CharT_* cstring_, CharT_ delimiter__) DD_NOEXCEPT {
	while (*cstring_ != delimiter__) {
		++cstring_;
	}
	return cstring_;
}

template <typename CharT_>
inline CharT_* get_string_end(CharT_* begin_, CharT_* end_) DD_NOEXCEPT {
	while (*begin_ && begin_ < end_) {
		++begin_;
	}
	return begin_;
}

template <typename CharT_>
inline CharT_* get_string_end(CharT_* begin_, CharT_* end_, CharT_ delimiter__) DD_NOEXCEPT {
	return ::DD::find(begin_, end_, delimiter__);
}

template <typename CharT_>
inline CharT_* get_string_end(CharT_* cstring_, LengthType length_) DD_NOEXCEPT {
	return get_string_end(cstring_, cstring_ + length_);
}

template <typename CharT_>
inline CharT_* get_string_end(CharT_* cstring_, LengthType length_, CharT_ delimiter__) DD_NOEXCEPT {
	return get_string_end(cstring_, cstring_ + length_, delimiter__);
}

template <typename CharT_, LengthType length_c_>
#	if __cplusplus >= 201103L
inline CharT_* get_string_end(ArrayType<CharT_, length_c_>& cstring_) noexcept {
#	else
inline CharT_* get_string_end(CharT_(&cstring_)[length_c_]) throw() {
#	endif
	return get_string_end(DD_SPLIT_RANGE(cstring_));
}

template <typename CharT_, LengthType length_c_>
#	if __cplusplus >= 201103L
inline CharT_* get_string_end(ArrayType<CharT_, length_c_>& cstring_, CharT_ delimiter__) noexcept {
#	else
inline CharT_* get_string_end(CharT_(&cstring_)[length_c_], CharT_ delimiter__) throw() {
#	endif
	return get_string_end(DD_SPLIT_RANGE(cstring_), delimiter__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::get_string_end;



DD_END_



#endif
