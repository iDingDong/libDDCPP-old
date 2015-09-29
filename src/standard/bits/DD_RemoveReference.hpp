//	DDCPP/standard/bits/DD_RemoveReference.hpp
#ifndef DD_REMOVE_REFERENCE_HPP_INCLUDED_
#	define DD_REMOVE_REFERENCE_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <type_traits>
#	endif

#	include "DD_global_definitions.hpp"



DD_BEGIN_
template <typename ObjectT_>
struct RemoveReference {
#	if __cplusplus >= 201402L
	using Type = std::remove_reference_t<ObjectT_>;
#	elif __cplusplus >= 201103L
	using Type = typename std::remove_reference<ObjectT_>::type;
#	else
	typedef ObjectT_ Type;
#	endif


};



template <typename ValueT_>
struct RemoveReference<ValueT_&> {
	DD_ALIAS(Type, ValueT_);


};



#	if __cplusplus >= 201103L
template <typename ValueT_>
struct RemoveReference<ValueT_&&> {
	using Type = ValueT_;


};



#	endif
DD_TRAIT_MODIFIER(RemoveReference)



DD_END_



#endif
