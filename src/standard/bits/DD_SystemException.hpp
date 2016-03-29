//	DDCPP/standard/bits/DD_SystemException.hpp
#ifndef DD_SYSTEM_EXCEPTION_HPP_INCLUDED_
#	define DD_SYSTEM_EXCEPTION_HPP_INCLUDED_ 1



#	include "DD_Exception.hpp"
#	if __cplusplus >= 201103L
#		include "DD_ErrorCode.hpp"
#	endif



DD_DETAIL_BEGIN_
struct SystemException : Exception {
	public:
	DD_ALIAS(SuperType, Exception);
	DD_ALIAS(ThisType, SystemException);


#	if __cplusplus >= 201103L
	private:
	ErrorCode m_code_ = ErrorCode();


#	endif
#	if __cplusplus >= 201103L
	public:
	SystemException() = default;

	public:
	SystemException(ThisType const& origin_) = default;

	public:
	SystemException(ThisType&& origin_) = default;

	public:
	SystemException(ErrorCode code_) noexcept : m_code_(code_) {
	}

#	endif
	public:
	SystemException(PromptType prompt_) DD_NOEXCEPT : SuperType(prompt_) {
	}

#	if __cplusplus >= 201103L
	public:
	SystemException(ErrorCode code_, PromptType prompt) noexcept : SuperType(prompt), m_code_(code_) {
	}

#	endif
#	if __cplusplus >= 201103L
	public:
	~SystemException() override = default;


#	endif
#	if __cplusplus >= 201103L
	public:
	ErrorCode const& get_code() const noexcept {
		return m_code_;
	}


#	endif
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



inline SystemException wrap_standard_system_error(std::system_error const& exception_) DD_NOEXCEPT {
#	if __cplusplus >= 201103L
	return SystemException(exception_.code(), exception_.what());
#	else
	return SystemException(exception_.what());
#	endif
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::SystemException;

using detail_::wrap_standard_system_error;



DD_END_



#endif

