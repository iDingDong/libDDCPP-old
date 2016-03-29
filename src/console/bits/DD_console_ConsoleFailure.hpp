//	DDCPP/console/bits/DD_console_ConsoleFailure.hpp
#ifndef DD_CONSOLE_CONSOLE_FAILURE_HPP_INCLUDED_
#	define DD_CONSOLE_CONSOLE_FAILURE_HPP_INCLUDED_ 1



#	include <standard/bits/DD_Exception.hpp>

#	include "DD_console_definitions.hpp"



DD_CONSOLE_DETAIL_BEGIN_
#	if DD_CONSOLE_IS_ON_WIN32
using ErrorCodeType = DWORD;
#	endif



struct ConsoleFailure : ::DD::Exception {
	public:
	using SuperType = ::DD::Exception;
	using ThisType = ConsoleFailure;


	private:
	ErrorCodeType m_code_ = ErrorCodeType();


	public:
	constexpr ConsoleFailure() = default;

	public:
	constexpr ConsoleFailure(ThisType const& origin_) = default;

	public:
	constexpr ConsoleFailure(ThisType&& origin_) = default;

	public:
	constexpr ConsoleFailure(PromptType prompt_) noexcept : SuperType(prompt_) {
	}

	public:
	constexpr ConsoleFailure(ErrorCodeType code_) noexcept : m_code_(code_) {
	}

	public:
	constexpr ConsoleFailure(
		PromptType prompt_, ErrorCodeType code_
	) noexcept : SuperType(prompt_), m_code_(code_) {
	}


	public:
	~ConsoleFailure() override = default;


	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


};



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::ErrorCodeType;

using ::DD::console::detail_::ConsoleFailure;



DD_CONSOLE_END_



#endif
