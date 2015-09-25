//	DDCPP/standard/bits/DD_Illogic.hpp
#ifndef _DD_IlLOGIC_HPP_INCLUDED
#	define _DD_ILOGIC_HPP_INCLUDED 1



#	include "DD_Exception.hpp"



_DD_BEGIN
struct Illogic : Exception {
	public:
	DD_ALIAS(SuperType, Exception);
	DD_ALIAS(ThisType, Illogic);


#	if __cplusplus >= 201103L
	public:
	constexpr Illogic() = default;

	public:
	constexpr Illogic(ThisType const& _origin) = default;

	public:
	constexpr Illogic(ThisType&& _origin) = default;

#	endif
	public:
	DD_CONSTEXPR Illogic(PromptType _prompt) DD_NOEXCEPT : SuperType(_prompt) {
	}


#	if __cplusplus >= 201103L
	public:
	~Illogic() override = default;


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

