//	DDCPP/standard/bits/DD_get_last_argument.hpp
#ifndef DD_GET_LAST_ARGUMENT_HPP_INCLUDED_
#	define DD_GET_LAST_ARGUMENT_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::get_last_argument'.



#	endif
#	include "DD_GetPackBack.hpp"
#	include "DD_forward.hpp"



DD_BEGIN_
template <typename Argument_>
Argument_&& get_last_argument(Argument_&& argument__) noexcept {
	return forward<Argument_>(argument__);
}



template <typename Argument_, typename... ArgumentsT_>
GetPackBackType<Argument_, ArgumentsT_...>&& get_last_argument(
	Argument_&& argument__,
	ArgumentsT_&&... arguments__
) noexcept {
	return get_last_argument(forward<ArgumentsT_>(arguments__)...);
}



DD_END_



#endif
