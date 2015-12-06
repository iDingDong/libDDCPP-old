//	DDCPP/standard/bits/DD_IsRange.hpp
#ifndef DD_IS_RANGE_HPP_INCLUDED_
#	define DD_IS_RANGE_HPP_INCLUDED_ 1



#	include "DD_MemberFunctionCheck.hpp"
#	include "DD_And.hpp"
#	include "DD_Iterator.hpp"



#	if !defined(DDCPP_CONSIDER_CSTRING_AS_RANGE)
#		define DDCPP_CONSIDER_CSTRING_AS_RANGE DD_OFF
#	endif



#	if DDCPP_CONSIDER_CSTRING_AS_RANGE
#		include "DD_IsCharactor.hpp"
#		include "DD_RemovePointer.hpp"
#	endif



DD_DETAIL_BEGIN_
DD_MEMBER_FUNCTION_CHECK(HasBegin_, begin, DD_MODIFY_TRAIT(Iterator, MACRO_ObjectT__), )



DD_MEMBER_FUNCTION_CHECK(HasEnd_, end, DD_MODIFY_TRAIT(Iterator, MACRO_ObjectT__), )



#	if __cplusplus >= 201103L
template <typename ObjectT_>
using HasBeginAndEnd_ = AndType<HasBegin_<ObjectT_>, HasEnd_<ObjectT_>>;
#	else
template <typename ObjectT_>
struct HasBeginAndEnd_ : And<HasBegin_<ObjectT_>, HasEnd_<ObjectT_>> {
};
#	endif



#	if __cplusplus >= 201103L
template <typename... ObjectsT_>
struct IsRange : AndType<IsRange<ObjectsT_>...> {
};



#	endif
template <typename ObjectT_>
struct IsRange<ObjectT_> : HasBeginAndEnd_<ObjectT_> {
};



template <typename ValueT_, LengthType length_c_>
struct IsRange<ValueT_[length_c_]> : TrueType {
};



#	if DDCPP_CONSIDER_CSTRING_AS_RANGE
template <typename ValueT_>
struct IsRange<ValueT_*> : IsCharactor<DD_MODIFY_TRAIT(RemovePointer, ValueT_)> {
};



template <typename ValueT_>
struct IsRange<ValueT_* const> : IsCharactor<DD_MODIFY_TRAIT(RemovePointer, ValueT_)> {
};



template <typename ValueT_>
struct IsRange<ValueT_* volatile> : IsCharactor<DD_MODIFY_TRAIT(RemovePointer, ValueT_)> {
};



template <typename ValueT_>
struct IsRange<ValueT_* const volatile> : IsCharactor<DD_MODIFY_TRAIT(RemovePointer, ValueT_)> {
};



#	endif
DD_DETAIL_END_



DD_BEGIN_
using detail_::IsRange;



DD_END_



#endif
