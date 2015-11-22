//	DDCPP/standard/bits/DD_swap.hpp
#ifndef DD_SWAP_HPP_INCLUDED_
#	define DD_SWAP_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include "DD_MemberFunctionCheck.hpp"
#		include "DD_move.hpp"
#	else
#		include "DD_global_definitions.hpp"
#	endif



DD_DETAIL_BEGIN_
DD_MEMBER_FUNCTION_CHECK(HasSwap_, swap, ::DD::ProcessType, MACRO_ObjectT__&)



template <ValidityType has_swap_c_>
struct Swap_ {
	template <typename ObjectT__>
	static ProcessType swap(
		ObjectT__& object_1___,
		ObjectT__& object_2___
	) DD_NOEXCEPT_AS(object_1___ = ::DD::move(object_2___) DD_COMMA ObjectT__(::DD::move(object_1___))) {
#	if __cplusplus >= 201103L
		auto temp___(::DD::move(object_1___));
		object_1___ = ::DD::move(object_2___);
		object_2___ = ::DD::move(temp___);
#	else
		ObjectT_ temp___(object_1___);
		object_1___ = object_2___;
		object_2___ = temp___;
#	endif
	}


};



template <>
struct Swap_<true> {
	template <typename ObjectT__>
	static ProcessType swap(
		ObjectT__& object_1___,
		ObjectT__& object_2___
	) DD_NOEXCEPT_AS(object_1___.swap(object_2___)) {
		object_1___.swap(object_2___);
	}


};



template <typename ObjectT_>
inline ProcessType swap(
	ObjectT_& object_1__,
	ObjectT_& object_2__
) DD_NOEXCEPT_AS(Swap_<HasSwap_<ObjectT_>::value>::swap(object_1__ DD_COMMA object_2__)) {
	Swap_<HasSwap_<ObjectT_>::value>::swap(object_1__, object_2__);
}

template <typename ObjectT_, LengthType length_c_>
#	if __cplusplus >= 201103L
inline ProcessType swap(ArrayType<ObjectT_, length_c_>& array_1_, ArrayType<ObjectT_, length_c_>& array_2_) noexcept(
	noexcept(swap(*array_1_, *array_2_))
) {
#	else
inline ProcessType swap(ObjectT_ (&array_1_)[length_c_], ObjectT_ (&array_2_)[length_c_]) {
#	endif
	using ::DD::detail_::swap;
	for (LengthType i = 0; i < length_c_; ++i) {
		swap(array_1_[i], array_2_[i]);
	}
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::swap;



DD_END_



#endif
