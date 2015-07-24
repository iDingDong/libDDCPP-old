//	standard/bits/DD_AllocationFailure.hpp
#ifndef _DD_ALLOCATION_FAILURE_HPP_INCLUDED
#	define _DD_ALLOCATION_FAILURE_HPP_INCLUDED 1



#	include "DD_Exception.hpp"



DD_BEGIN
struct AllocationFailure : Exception {
#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR AllocationFailure() DD_NOEXCEPT = default;
	
	public:
	DD_CONSTEXPR AllocationFailure(AllocationFailure const& _origin) DD_NOEXCEPT = default;
	
#	endif
	public:
	DD_CONSTEXPR AllocationFailure(PromptType _prompt) DD_NOEXCEPT : Exception(_prompt) {
	}
	
	
#	if __cplusplus >= 201103L
	public:
	~AllocationFailure() DD_NOEXCEPT override = default;
	
	
	public:
	AllocationFailure& operator =(AllocationFailure const& _origin) noexcept(true) = default;
	
	
#	endif
};



DD_END



#endif 
