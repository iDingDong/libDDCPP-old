//	DDCPP/concurrency/bits/DD_Thread.hpp
#ifndef DD_THREAD_HPP_INCLUDED_
#	define DD_THREAD_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Thread'.



#	endif
#	include <thread>

#	include <standard/bits/DD_fabricate.hpp>
#	include <standard/bits/DD_SystemException.hpp>

#	include "DD_concurrency_definitions.hpp"



DD_DETAIL_BEGIN_
class Thread : protected std::thread {
	public:
	using SuperType = std::thread;
	using ThisType = Thread;

	public:
	using IdType = SuperType::id;
	using NativeHandleType = SuperType::native_handle_type;


	public:
	using SuperType::SuperType;


	public:
	static unsigned get_hardware_concurrency() noexcept {
		return SuperType::hardware_concurrency();
	}


	public:
	SuperType& to_standard_thread() noexcept {
		return static_cast<SuperType&>(*this);
	}


	public:
	SuperType const& to_standard_thread() const noexcept {
		return static_cast<SuperType const&>(*this);
	};


	public:
	ValidityType is_joinable() const noexcept {
		return SuperType::joinable();
	}


	public:
	NativeHandleType get_native_handle() noexcept(
		noexcept(static_cast<NativeHandleType>(::DD::fabricate<SuperType>().native_handle()))
	) {
		return SuperType::native_handle();
	}


	public:
	ProcessType join() {
		try {
			SuperType::join();
		} catch (std::system_error const& error_) {
			throw ::DD::wrap_standard_system_error(error_);
		}
	}


	public:
	ProcessType detach() {
		try {
			SuperType::detach();
		} catch (std::system_error const& error_) {
			throw ::DD::wrap_standard_system_error(error_);
		}
	}


	public:
	ProcessType swap(ThisType& other) noexcept {
		SuperType::swap(other);
	}


	public:
	using SuperType::operator =;


	public:
	operator SuperType&() noexcept {
		return to_standard_thread();
	}


	public:
	operator SuperType const&() const noexcept {
		return to_standard_thread();
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Thread;



DD_END_



#endif
