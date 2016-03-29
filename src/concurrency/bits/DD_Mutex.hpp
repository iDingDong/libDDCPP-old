//	DDCPP/standard/bits/DD_Mutex.hpp
#ifndef DD_MUTEX_HPP_INCLUDED_
#	define DD_MUTEX_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Mutex'.



#	endif
#	include <mutex>

#	include <standard/bits/DD_SystemException.hpp>

#	include "DD_concurrency_definitions.hpp"



DD_DETAIL_BEGIN_
class Mutex : protected std::mutex {
	public:
	using SuperType = std::mutex;
	using ThisType = Mutex;

	public:
	using NativeHandleType = SuperType::native_handle_type;


	public:
	ValidityType is_locked_by_another_thread() {
		if (try_lock()) {
			unlock();
			return false;
		}
		return true;
	}


	public:
	ProcessType lock() {
		try {
			SuperType::lock();
		} catch (std::system_error const& error_) {
			throw ::DD::wrap_standard_system_error(error_);
		}
	}


	public:
	ProcessType unlock() {
		try {
			SuperType::unlock();
		} catch (std::system_error const& error_) {
			throw ::DD::wrap_standard_system_error(error_);
		}
	}


	ValidityType try_lock() {
		try {
			return SuperType::try_lock();
		} catch (std::system_error const& error_) {
			throw ::DD::wrap_standard_system_error(error_);
		}
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Mutex;



DD_END_



#endif
