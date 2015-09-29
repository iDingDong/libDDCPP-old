//	DDCPP/standard/bits/DD_RunTimeError.hpp
#ifndef DD_RUN_TIME_ERROR_HPP_INCLUDED_
#	define DD_RUN_TIME_ERROR_HPP_INCLUDED_ 1



#	include "DD_Exception.hpp"



DD_BEGIN_
struct RunTimeError : Exception {
	public:
	DD_ALIAS(SuperType, Exception);
	DD_ALIAS(ThisType, RunTimeError);


#	if __cplusplus >= 201103L
	public:
	constexpr RunTimeError() = default;

	public:
	constexpr RunTimeError(ThisType const& origin_) = default;

	public:
	constexpr RunTimeError(ThisType&& origin_) = default;

#	endif
	public:
	DD_CONSTEXPR RunTimeError(PromptType prompt_) DD_NOEXCEPT : SuperType(prompt_) {
	}


#	if __cplusplus >= 201103L
	public:
	~RunTimeError() override = default;


#	endif
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



DD_END_



#endif
