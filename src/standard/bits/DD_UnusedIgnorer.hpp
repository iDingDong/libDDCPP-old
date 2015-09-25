//	DDCPP/standard/bits/DD_UnusedIgnorer.hpp
#ifndef _DD_UNUSED_IGNORER_HPP_INCLUDED
#	define _DD_UNUSED_IGNORER_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
struct UnusedIgnorer {
	public:
	DD_ALIAS(ThisType, UnusedIgnorer);


	public:
#	if __cplusplus >= 201103L
	template <typename... _ObjectsT_>
	ProcessType operator ()(_ObjectsT_ const&... __objects_) const noexcept {
	}
#	else
	template <typename _ObjectT_>
	ProcessType operator ()(_ObjectT_ const& __object_) const throw() {
	}
#	endif


	public:
	template <typename _ObjectT_>
	ThisType const& operator ,(_ObjectT_ const& __object_) const DD_NOEXCEPT {
		return *this;
	};


} DD_CONSTANT ignore_unused;



_DD_END



#	define DD_IGNORE_UNUSED DD::ignore_unused,



#endif
