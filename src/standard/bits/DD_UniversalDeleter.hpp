//	DDCPP/standard/bits/DD_UniversalDeleter.hpp
#ifndef DD_UNIVERSAL_DELETER_HPP_INCLUDED_
#	define DD_UNIVERSAL_DELETER_HPP_INCLUDED_



#	include "DD_DefaultDeleter.hpp"



DD_DETAIL_BEGIN_
struct UniversalDeleter {
	DD_ALIAS(ThisType, UniversalDeleter);


	template <typename ValueT_>
	static ProcessType call(ValueT_* pointer_) DD_NOEXCEPT {
		DefaultDeleter<ValueT_>()(pointer_);
	}


	template <typename ValueT_>
	ProcessType operator ()(ValueT_* pointer_) const DD_NOEXCEPT {
		call(pointer_);
	}


} DD_CONSTANT universal_deleter;



DD_DETAIL_END_



DD_BEGIN_
using detail_::UniversalDeleter;

using detail_::universal_deleter;



DD_END_



#endif
