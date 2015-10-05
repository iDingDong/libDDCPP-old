//	DDCPP/standard/bits/DD_AccessDenied.hpp
#ifndef DD_ACCESS_DENIED_HPP_INCLUDED_
#	define DD_ACCESS_DENIED_HPP_INCLUDED_ 1



#	include "DD_Illogic.hpp"



DD_DETAIL_BEGIN_
struct AccessDenied : Illogic {
	public:
	DD_ALIAS(SuperType, Illogic);
	DD_ALIAS(ThisType, AccessDenied);


#	if __cplusplus >= 201103L
	public:
	constexpr AccessDenied() = default;

	public:
	constexpr AccessDenied(ThisType const& origin_) = default;

	public:
	constexpr AccessDenied(ThisType&& origin_) = default;

#	endif
	public:
	DD_CONSTEXPR AccessDenied(PromptType prompt_) DD_NOEXCEPT : SuperType(prompt_) {
	}


#	if __cplusplus >= 201103L
	public:
	~AccessDenied() override = default;


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
using detail_::AccessDenied;



DD_END_



#endif
