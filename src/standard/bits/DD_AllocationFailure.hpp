//	DDCPP/standard/bits/DD_AllocationFailure.hpp
#ifndef DD_ALLOCATION_FAILURE_HPP_INCLUDED_
#	define DD_ALLOCATION_FAILURE_HPP_INCLUDED_ 1



#	include "DD_RunTimeError.hpp"



DD_DETAIL_BEGIN_
struct AllocationFailure : RunTimeError {
	public:
	DD_ALIAS(SuperType, RunTimeError);
	DD_ALIAS(ThisType, AllocationFailure);


#	if __cplusplus >= 201103L
	public:
	constexpr AllocationFailure() = default;

	public:
	constexpr AllocationFailure(ThisType const& origin_) = default;

	public:
	constexpr AllocationFailure(ThisType&& origin_) = default;

#	endif
	public:
	DD_CONSTEXPR AllocationFailure(PromptType prompt_) DD_NOEXCEPT : SuperType(prompt_) {
	}


#	if __cplusplus >= 201103L
	public:
	~AllocationFailure() override = default;


#	endif
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::AllocationFailure;



DD_END_



#endif
