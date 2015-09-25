//	DDCPP/standard/bits/DD_AccessDenied.hpp
#ifndef _DD_ACCESS_DENIED_HPP_INCLUDED
#	define _DD_ACCESS_DENIED_HPP_INCLUDED 1



#	include "DD_Illogic.hpp"



_DD_BEGIN
struct AccessDenied : Illogic {
	public:
	DD_ALIAS(SuperType, Illogic);
	DD_ALIAS(ThisType, AccessDenied);


#	if __cplusplus >= 201103L
	public:
	constexpr AccessDenied() = default;

	public:
	constexpr AccessDenied(ThisType const& _origin) = default;

	public:
	constexpr AccessDenied(ThisType&& _origin) = default;

#	endif
	public:
	DD_CONSTEXPR AccessDenied(PromptType _prompt) DD_NOEXCEPT : SuperType(_prompt) {
	}


#	if __cplusplus >= 201103L
	public:
	~AccessDenied() override = default;


#	endif
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& _origin) = default;

	public:
	ThisType& operator =(ThisType&& _origin) = default;


#	endif
};



_DD_END



#endif
