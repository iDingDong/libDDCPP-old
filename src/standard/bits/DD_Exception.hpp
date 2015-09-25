//	DDCPP/standard/bits/DD_Exception.hpp
#ifndef _DD_EXCEPTION_HPP_INCLUDED
#	define _DD_EXCEPTION_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



_DD_BEGIN
struct Exception {
	public:
	DD_ALIAS(ThisType, Exception);


	private:
	PromptType _m_prompt DD_IN_CLASS_INITIALIZE("Unknown Error. ");


#	if __cplusplus >= 201103L
	public:
	constexpr Exception() = default;

	public:
	constexpr Exception(ThisType const& _origin) = default;

	public:
	constexpr Exception(ThisType&& _origin) = default;

	public:
#	else
	public:
	Exception() throw() : _m_prompt() {
	};
#	endif

	public:
	DD_CONSTEXPR Exception(PromptType _prompt) DD_NOEXCEPT : _m_prompt(_prompt) {
	}


	public:
#	if __cplusplus >= 201103L
	virtual ~Exception() = default;
#	else
	virtual ~Exception() throw() {
	}
#	endif


	public:
	virtual PromptType get_prompt() const DD_NOEXCEPT {
		return _m_prompt;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& _origin) = default;

	public:
	ThisType& operator =(ThisType&& _origin) = default;


#	endif
};



_DD_END



#endif
