//	DDCPP/standard/bits/DD_IsRange.hpp
#ifndef _DD_IS_RANGE_HPP_INCLUDED
#	define _DD_IS_RANGE_HPP_INCLUDED 1



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



DD_DETAIL_BEGIN
DD_MEMBER_FUNCTION_CHECK(_HasBegin, begin, DD_MODIFY_TRAIT(Iterator, _MACRO_ObjectT_), )



DD_MEMBER_FUNCTION_CHECK(_HasEnd, end, DD_MODIFY_TRAIT(Iterator, _MACRO_ObjectT_), )



#	if __cplusplus >= 201103L
template <typename _ObjectT>
using _HasBeginAndEnd = AndType<_HasBegin<_ObjectT>, _HasEnd<_ObjectT>>;
#	else
template <typename _ObjectT>
struct _HasBeginAndEnd : And<_HasBegin<_ObjectT>, _HasEnd<_ObjectT>> {
};
#	endif



template <typename _ObjectT>
struct _IsRange : _detail::_HasBeginAndEnd<_ObjectT> {
};



template <typename _ValueT, LengthType _length_c>
struct _IsRange<_ValueT[_length_c]> : TrueType {
};



#	if DDCPP_CONSIDER_CSTRING_AS_RANGE
template <typename _ValueT>
struct _IsRange<_ValueT*> : IsCharactor<DD_MODIFY_TRAIT(RemovePointer, _ValueT)> {
};



template <typename _ValueT>
struct _IsRange<_ValueT* const> : IsCharactor<DD_MODIFY_TRAIT(RemovePointer, _ValueT)> {
};



template <typename _ValueT>
struct _IsRange<_ValueT* volatile> : IsCharactor<DD_MODIFY_TRAIT(RemovePointer, _ValueT)> {
};



template <typename _ValueT>
struct _IsRange<_ValueT* const volatile> : IsCharactor<DD_MODIFY_TRAIT(RemovePointer, _ValueT)> {
};



#	endif
DD_DETAIL_END



DD_BEGIN
#	if __cplusplus >= 201103L
template <typename... _ObjectsT>
using IsRange = AndType<_detail::_IsRange<_ObjectsT>...>;
#	else
template <typename _ObjectT>
struct IsRange : _detail::_IsRange<_ObjectT> {
};
#	endif



DD_END



#endif
