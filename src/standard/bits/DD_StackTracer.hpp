//	DDCPP/standard/bits/DD_StackTracer.hpp
#ifndef DD_STACK_TRACER_HPP_INCLUDED_
#	define DD_STACK_TRACER_HPP_INCLUDED_ 1



#	if __cplusplus <= 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::StackTracer'.



#	endif
#	include <iostream>

#	include "DD_debugger_definitions.hpp"
#	include "DD_have_uncaught_exception.hpp"



#	ifndef DDCPP_ENABLE_STACK_TRACE
#		define DDCPP_ENABLE_STACK_TRACE DDCPP_DEBUG
#	endif

#	ifndef DDCPP_STACK_TRACE_HANDLER
#		define DDCPP_STACK_TRACE_HANDLER ::DD::detail_::default_stack_trace_handler
#	endif



DD_DETAIL_BEGIN_
struct StackTracer;



inline void default_stack_trace_handler(StackTracer const& stack_tracer_);



struct StackTracer {
	public:
	using ThisType = StackTracer;

	private:
	SourceFileType m_file_ = DD_UNKNOWN;
	SourceLineType m_line_ = 0;
	SourceFunctionType m_function_ = DD_UNKNOWN;


	public:
	constexpr StackTracer() = default;

	public:
	constexpr StackTracer(ThisType const& origin_) = default;

	public:
	constexpr StackTracer(ThisType&& origin_) = default;

	public:
	constexpr StackTracer(
		SourceFileType file_, SourceLineType line_, SourceFunctionType function_
	) noexcept : m_file_(file_), m_line_(line_), m_function_(function_) {
	}


	public:
	~StackTracer() noexcept {
		if (::DD::have_uncaught_exception()) {
			DDCPP_STACK_TRACE_HANDLER(*this);
		}
	}


	public:
	SourceFileType get_file() const noexcept {
		return m_file_;
	}


	public:
	SourceLineType get_line() const noexcept {
		return m_line_;
	}


	public:
	SourceFunctionType get_function() const noexcept {
		return m_function_;
	}


	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


};



inline void default_stack_trace_handler(StackTracer const& stack_tracer_) {
	std::cerr <<
		"Stack unwinding: " <<
		stack_tracer_.get_file() <<
		'(' <<
		stack_tracer_.get_line() <<
		"): " <<
		stack_tracer_.get_function() <<
		std::endl
	;
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::StackTracer;



DD_END_



#	if DDCPP_ENABLE_STACK_TRACE
#		define DD_TRACE_STACK\
			::DD::StackTracer dd_stack_tracer_(\
				DD_CURRENT_FILE, DD_CURRENT_LINE, DD_CURRENT_FUNCTION\
			)
#	else
#		define DD_TRACE_STACK
#	endif



#endif
