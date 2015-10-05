//	DDCPP/standard/bits/DD_Illogic.hpp
#ifndef DD_IlLOGIC_HPP_INCLUDED_
#	define DD_ILOGIC_HPP_INCLUDED_ 1



#	include "DD_Exception.hpp"



DD_DETAIL_BEGIN_
struct Illogic : Exception {
	public:
	DD_ALIAS(SuperType, Exception);
	DD_ALIAS(ThisType, Illogic);


#	if __cplusplus >= 201103L
	public:
	constexpr Illogic() = default;

	public:
	constexpr Illogic(ThisType const& origin_) = default;

	public:
	constexpr Illogic(ThisType&& origin_) = default;

#	endif
	public:
	DD_CONSTEXPR Illogic(PromptType prompt_) DD_NOEXCEPT : SuperType(prompt_) {
	}


#	if __cplusplus >= 201103L
	public:
	~Illogic() override = default;


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
using detail_::Illogic;



DD_END_



#endif

