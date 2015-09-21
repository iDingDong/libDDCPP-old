//	DDCPP/standard/bits/DD_Exception.hpp
#ifndef _DD_EXCEPTION_HPP_INCLUDED
#	define _DD_EXCEPTION_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
struct Exception {
	private:
#	if __cplusplus >= 201103L
	PromptType _m_prompt = "Unknown Error. ";
#	else
	PromptType _m_prompt;
#	endif


	public:
#	if __cplusplus >= 201103L
	Exception() DD_NOEXCEPT = default;

	public:
	Exception(Exception const& _origin) DD_NOEXCEPT = default;
#	else
	Exception() DD_NOEXCEPT : _m_prompt() {
	};
#	endif

	public:
	DD_CONSTEXPR Exception(PromptType _prompt) DD_NOEXCEPT : _m_prompt(_prompt) {
	}


#	if __cplusplus >= 201103L
	public:
	virtual ~Exception() DD_NOEXCEPT = default;
#	else
	virtual ~Exception() DD_NOEXCEPT {
	}
#	endif


	public:
	virtual PromptType get_prompt() const DD_NOEXCEPT {
		return this->_m_prompt;
	}


#	if __cplusplus >= 201103L
	public:
	Exception& operator =(Exception const& _origin) DD_NOEXCEPT = default;


#	endif
};



_DD_END



#endif
