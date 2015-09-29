//	DDCPP/standard/bits/DD_Exception.hpp
#ifndef DD_EXCEPTION_HPP_INCLUDED_
#	define DD_EXCEPTION_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
struct Exception {
	public:
	DD_ALIAS(ThisType, Exception);


	private:
	PromptType m_prompt_ DD_IN_CLASS_INITIALIZE("Unknown Error. ");


#	if __cplusplus >= 201103L
	public:
	constexpr Exception() = default;

	public:
	constexpr Exception(ThisType const& origin_) = default;

	public:
	constexpr Exception(ThisType&& origin_) = default;

	public:
#	else
	public:
	Exception() throw() : m_prompt_() {
	};
#	endif

	public:
	DD_CONSTEXPR Exception(PromptType prompt_) DD_NOEXCEPT : m_prompt_(prompt_) {
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
		return m_prompt_;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



DD_END_



#endif
