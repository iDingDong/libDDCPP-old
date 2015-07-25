//	DDCPP/standard/bits/DD_get_last_argument.hpp
#ifndef _DD_GET_LAST_ARGUMENT_HPP_INCLUDED
#	define _DD_GET_LAST_ARGUMENT_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::get_last_argument'.



#	endif
#	include "DD_GetPackBack.hpp"
#	include "DD_forward.hpp"



DD_BEGIN
template <typename _Argument>
_Argument&& get_last_argument(_Argument&& __argument) noexcept {
	return forward<_Argument>(__argument);
}



template <typename _Argument, typename... _ArgumentsT>
GetPackBackType<_Argument, _ArgumentsT...>&& get_last_argument(_Argument&& __argument, _ArgumentsT&&... __arguments) noexcept {
	return get_last_argument(forward<_ArgumentsT>(__arguments)...);
}



DD_END



#endif
