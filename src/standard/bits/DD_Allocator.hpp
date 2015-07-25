//	DDCPP/standard/bits/DD_Allocator.hpp
#ifndef _DD_ALLOCATOR_HPP_INCLUDED
#	define _DD_ALLOCATOR_HPP_INCLUDED 1



#	include <cstdlib>

#	include "DD_AllocationFailure.hpp"
#	if __cplusplus >= 201103L
#		include "DD_IsTriviallyDestructible.hpp"
#	endif
#	include "DD_address_of.hpp"



DD_BEGIN
template <typename _ValueT = void, ValidityType _manage_pool_c = true>
class Allocator {
};



template <>
class Allocator<void, true> {
	public:
	DD_ALIAS(ThisType, Allocator<void DD_COMMA true>)
	DD_ALIAS(ValueType, void)
	static ValidityType DD_CONSTANT manage_pool_constant = true;
	
	DD_ALIAS(SizeType, DD::SizeType)
	
	
};



/*template <typename _ValueT = void, ValidityType _manage_pool_c = true>
class Allocator {
	public:
#	if __cplusplus >= 201103L
	using ThisType = Allocator<_ValueT, _manage_pool_c>;
#	else
	typedef Allocator<_ValueT, _manage_pool_c> ThisType;
#	endif
	DD_ALIAS(ValueType, _ValueT)
	
	public:
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(ConstReferenceType, ValueType const&)
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ConstPointerType, ValueType const*)
	DD_ALIAS(LengthType, DD::LengthType)
	static SizeType DD_CONSTANT size_constant = sizeof(ValueType);
	
	
	private:
	template <typename _UndirectionalIteratorT_, ValidityType _is_trivially_destructible_c_>
	struct _Destroy {
		static ProcessType _destroy(_UndirectionalIteratorT_ __begin_, _UndirectionalIteratorT_ const& __end_) DD_NOEXCEPT {
			for (; __begin_ != __end_; ++__begin_) {
				__begin_->~ValueType();
			}
		}
		
		
	};
	
	private:
	template <typename _UndirectionalIteratorT_>
	struct _Destroy<_UndirectionalIteratorT_, true> {
		static ProcessType _destroy(_UndirectionalIteratorT_ const& __begin_, _UndirectionalIteratorT_ const& __end_) DD_NOEXCEPT {
		}
		
		
	};
	
	
	public:
#	if __cplusplus >= 201103L
	using HandlerType = ProcessType();
#	else
	typedef ProcessType HandlerType();
#	endif
	
	
	private:
	static HandlerType* _m_handler;
	
	
	public:
	static PointerType address(ReferenceType _object) DD_NOEXCEPT {
		return address_of(_object);
	}
	
	public:
	static ConstPointerType address(ConstReferenceType _object) DD_NOEXCEPT {
		return address_of(_object);
	}
	
	
	public:
	static PointerType allocate(LengthType _length = 1U) DD_NOEXCEPT_IF(false) {
		SizeType _size = size_constant * _length;
		PointerType _temp = reinterpret_cast<PointerType>(std::malloc(_size));
		return _temp ? _temp : ThisType::_failure_process(_size);
	}
	
	
	public:
	template <typename _PointerT_>
	static ProcessType deallocate(_PointerT_ const& __pointer_, LengthType _length) DD_NOEXCEPT {
		std::free(address_of(*__pointer_));
	}
	
	
#	if __cplusplus >= 201103L
	public:
	template <typename _PointerT_, typename... _ArgumentsT_>
	static ProcessType construct(_PointerT_ __pointer_, _ArgumentsT_&&... __arguments_) noexcept(noexcept(ValueType(__arguments_...))) {
		new (address_of(*__pointer_)) ValueType(__arguments_...);
	}
	
	
#	endif
	public:
	template <typename _PointerT_>
	static ProcessType destroy(_PointerT_ const& __pointer_) DD_NOEXCEPT {
		__pointer_->~ValueType();
	}
	
	
	public:
	template <typename _UndirectionalIteratorT_>
	static ProcessType destroy(_UndirectionalIteratorT_ const& __begin_, _UndirectionalIteratorT_ const& __end_) DD_NOEXCEPT {
#	if __cplusplus <= 201103L
		ThisType::_Destroy<_UndirectionalIteratorT_, IsTriviallyDestructible<ValueType>::value>::_destroy(__begin_, __end_);
#	else
#	endif
	}
	
	
	public:
	static HandlerType* set_handler(HandlerType* _handler) DD_NOEXCEPT {
		HandlerType* _temp = ThisType::_m_handler;
		ThisType::_m_handler = _handler;
		return _temp;
	}
	
	
	private:
	static PointerType _failure_process(SizeType _size) DD_NOEXCEPT_IF(false);
	
	
};



template <typename ValueT, ValidityType manage_pool>
typename Allocator<ValueT, manage_pool>::HandlerType* Allocator<ValueT, manage_pool>::_m_handler = Allocator<ValueT>::HandlerType();



template <typename ValueT, ValidityType manage_pool>
typename Allocator<ValueT, manage_pool>::PointerType Allocator<ValueT, manage_pool>::_failure_process(SizeType _size) DD_NOEXCEPT_IF(false) {
	PointerType _temp;
	do {
		if (!ThisType::_m_handler) {
			throw AllocationFailure("Failed to allocate. ");
		}
		ThisType::_m_handler();
		_temp = reinterpret_cast<PointerType>(std::malloc(_size));
	} while (!_temp);
	return _temp;
}



template <typename _ValueT>
class Allocator<_ValueT, true> : public Allocator<_ValueT, false> {
};// Bad realization


*/
DD_END



#endif
