//	DDCPP/standard/bits/DD_AllocationFailure.hpp
#ifndef _DD_ALLOCATION_FAILURE_HPP_INCLUDED
#	define _DD_ALLOCATION_FAILURE_HPP_INCLUDED 1



#	include "DD_Exception.hpp"



_DD_BEGIN
struct AllocationFailure : Exception {
	public:
	DD_ALIAS(SuperType, Exception);
	DD_ALIAS(ThisType, AllocationFailure);


#	if __cplusplus >= 201103L
	public:
	constexpr AllocationFailure() = default;

	public:
	constexpr AllocationFailure(ThisType const& _origin) = default;

	public:
	constexpr AllocationFailure(ThisType&& _origin) = default;

#	endif
	public:
	DD_CONSTEXPR AllocationFailure(PromptType _prompt) DD_NOEXCEPT : SuperType(_prompt) {
	}


#	if __cplusplus >= 201103L
	public:
	~AllocationFailure() override = default;


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
