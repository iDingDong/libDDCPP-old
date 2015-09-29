//	DDCPP/standard/bits/DD_UnusedIgnorer.hpp
#ifndef DD_UNUSED_IGNORER_HPP_INCLUDED_
#	define DD_UNUSED_IGNORER_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
struct UnusedIgnorer {
	public:
	DD_ALIAS(ThisType, UnusedIgnorer);


	public:
#	if __cplusplus >= 201103L
	template <typename... ObjectsT__>
	ProcessType operator ()(ObjectsT__ const&... objects___) const noexcept {
	}
#	else
	template <typename ObjectT__>
	ProcessType operator ()(ObjectT__ const& object___) const throw() {
	}
#	endif


	public:
	template <typename ObjectT__>
	ThisType const& operator ,(ObjectT__ const& object___) const DD_NOEXCEPT {
		return *this;
	};


} DD_CONSTANT ignore_unused;



DD_END_



#	define DD_IGNORE_UNUSED DD::ignore_unused,



#endif
