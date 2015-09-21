//	DDCPP/standard/bits/DD_AccessDenied.hpp
#ifndef _DD_ACCESS_DENIED_HPP_INCLUDED
#	define _DD_ACCESS_DENIED_HPP_INCLUDED 1



#	include "DD_Exception.hpp"



_DD_BEGIN
struct AccessDenied : Exception {
#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR AccessDenied() DD_NOEXCEPT = default;

	public:
	DD_CONSTEXPR AccessDenied(AccessDenied const& _origin) DD_NOEXCEPT = default;

#	endif
	public:
	DD_CONSTEXPR AccessDenied(PromptType _prompt) DD_NOEXCEPT : Exception(_prompt) {
	}


#	if __cplusplus >= 201103L
	public:
	~AccessDenied() DD_NOEXCEPT override = default;


	public:
	AccessDenied& operator =(AccessDenied const& _origin) noexcept(true) = default;


#	endif
};



_DD_END



#endif
