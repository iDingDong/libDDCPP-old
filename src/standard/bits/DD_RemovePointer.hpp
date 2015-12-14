//	DDCPP/standard/bits/DD_RemovePointer.hpp
#ifndef DD_REMOVE_POINTER_HPP_INCLUDED_
#	define DD_REMOVE_POINTER_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>

#	endif
#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
template <typename ObjectT_>
struct RemovePointer {
#	if __cplusplus >= 201402L
	using Type = std::remove_pointer_t<ObjectT_>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_pointer<ObjectT_>::type;
#	else
	typedef ObjectT_ Type;
#	endif


};



template <typename ValueT_>
struct RemovePointer<ValueT_*> {
	DD_ALIAS(Type, ValueT_);


};



template <typename ValueT_>
struct RemovePointer<ValueT_* const> {
	DD_ALIAS(Type, ValueT_);


};



template <typename ValueT_>
struct RemovePointer<ValueT_* volatile> {
	DD_ALIAS(Type, ValueT_);


};



template <typename ValueT_>
struct RemovePointer<ValueT_* const volatile> {
	DD_ALIAS(Type, ValueT_);


};



DD_TRAIT_MODIFIER(RemovePointer)



DD_DETAIL_END_



DD_BEGIN_
using detail_::RemovePointer;
#	if __cplusplus >= 201103L
using detail_::RemovePointerType;
#	endif



DD_END_



#endif
