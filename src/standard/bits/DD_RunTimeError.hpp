//	DDCPP/standard/bits/DD_RunTimeError.hpp
#ifndef _DD_RUN_TIME_ERROR_HPP_INCLUDED
#	define _DD_RUN_TIME_ERROR_HPP_INCLUDED 1



#	include "DD_Exception.hpp"



_DD_BEGIN
struct RunTimeError : Exception {
	public:
	DD_ALIAS(SuperType, Exception);
	DD_ALIAS(ThisType, RunTimeError);


#	if __cplusplus >= 201103L
	public:
	constexpr RunTimeError() = default;

	public:
	constexpr RunTimeError(ThisType const& _origin) = default;

	public:
	constexpr RunTimeError(ThisType&& _origin) = default;

#	endif
	public:
	DD_CONSTEXPR RunTimeError(PromptType _prompt) DD_NOEXCEPT : SuperType(_prompt) {
	}


#	if __cplusplus >= 201103L
	public:
	~RunTimeError() override = default;


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
