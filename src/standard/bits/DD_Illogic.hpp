//	DDCPP/standard/bits/DD_Ilogic.hpp
#ifndef _DD_ILOGIC_HPP_INCLUDED
#	define _DD_ILOGIC_HPP_INCLUDED 1



#	include "DD_Exception.hpp"



_DD_BEGIN
struct Ilogic : Exception {
#	if __cplusplus >= 201103L
	public:
	DD_CONSTEXPR Ilogic() DD_NOEXCEPT = default;

	public:
	DD_CONSTEXPR Ilogic(AllocationFailure const& _origin) DD_NOEXCEPT = default;

#	endif
	public:
	DD_CONSTEXPR Ilogic(PromptType _prompt) DD_NOEXCEPT : Exception(_prompt) {
	}


#	if __cplusplus >= 201103L
	public:
	~Ilogic() DD_NOEXCEPT override = default;


	public:
	Ilogic& operator =(AllocationFailure const& _origin) noexcept(true) = default;


#	endif
};



_DD_END



#endif

