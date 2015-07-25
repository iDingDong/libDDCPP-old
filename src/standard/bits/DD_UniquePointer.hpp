//	DDCPP/standard/bits/DD_UniquePointer.hpp
#ifndef _DD_UNIQUE_POINTER_HPP_INCLUDED
#	define _DD_UNIQUE_POINTER_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_Allocator.hpp"
#	include "DD_swap.hpp"



DD_BEGIN
template <typename _ValueT, typename _DeleterT = void>
struct UniquePointer {
	public:
	DD_ALIAS(ThisType, UniquePointer<_ValueT DD_COMMA _DeleterT>)
	DD_ALIAS(ValueType, _ValueT)
	DD_ALIAS(DeleterType, _DeleterT)
	
	public:
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(DifferenceType, DD::DifferenceType)
	
	
	private:
#	if __cplusplus >= 201103L
	PointerType _m_pointer = PointerType();
	DeleterType _m_deleter = DeleterType();
#	else
	PointerType _m_pointer;
	DeleterType _m_deleter;
#	endif
	
	
#	if __cplusplus >= 201103L
	public:
	constexpr UniquePointer() = default;
	
	public:
	UniquePointer(ThisType const&) = delete;
	
	public:
	constexpr UniquePointer(ThisType&& _origin) noexcept : _m_pointer(_origin.release()), _m_deleter(forward<DeleterType>(_origin._m_deleter)) {
	}
#	else
	public:
	UniquePointer() DD_NOEXCEPT : _m_pointer(), _m_deleter() {
	}
	
	private:
	UniquePointer(ThisType const&);// Deleted by undefined private declaration
#	endif
	
	public:
	explicit DD_CONSTEXPR UniquePointer(PointerType _pointer) DD_NOEXCEPT : _m_pointer(_pointer) {
	}
	
#	if __cplusplus >= 201103L
	public:
	template <typename _DeleterT_>
	constexpr UniquePointer(_DeleterT_&& _deleter) noexcept(noexcept(DeleterType(forward<_DeleterT_>(_deleter)))) : _m_deleter(forward<_DeleterT_>(_deleter)) {
	}
	
	public:
	template <typename _DeleterT_>
	constexpr UniquePointer(PointerType _pointer, _DeleterT_&& _deleter) noexcept(noexcept(DeleterType(forward<_DeleterT_>(_deleter)))) : _m_pointer(_pointer), _m_deleter(forward<_DeleterT_>(_deleter)) {
	}
#	else
	public:
	template <typename _DeleterT_>
	UniquePointer(_DeleterT_ const& _deleter) : _m_pointer(), _m_deleter(_deleter) {
	}
	
	public:
	template <typename _DeleterT_>
	constexpr UniquePointer(PointerType _pointer, _DeleterT_ const& _deleter) : _m_pointer(_pointer), _m_deleter(_deleter) {
	}
#	endif
	
	
	public:
	~UniquePointer() DD_NOEXCEPT {
		destroy();
	}
	
	
	public:
	ProcessType reset(PointerType _pointer = PointerType()) DD_NOEXCEPT {
		destroy();
		_m_pointer = _pointer;
	}
	
	
	public:
	PointerType release() DD_NOEXCEPT {
#	if __cplusplus >= 201103L
		auto _temp(_m_pointer);
#	else
		PointerType _temp(_m_pointer);
#	endif
		_m_pointer = PointerType();
		return _temp;
	}
	
	
	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT {
		using DD::swap;
		swap(_m_pointer, _target._m_pointer);
		swap(_m_deleter, _target._m_deleter);
	}
	
	
	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return _m_pointer;
	}
	
	
	private:
	ProcessType destroy() const DD_NOEXCEPT {
		_m_deleter(_m_pointer);
	}
	
	
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const&) = delete;
	
	public:
	ThisType& operator =(ThisType&& _origin) noexcept(true) {
		swap(_origin);
	}
#	else
	private:
	ThisType& operator =(ThisType const&);
#	endif
	
	public:
	ThisType& operator =(PointerType _pointer) DD_NOEXCEPT {
		reset(_pointer);
	}
	
	
	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *_m_pointer;
	}
	
	
	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return _m_pointer;
	}
	
	
};



template <typename _ValueT, ValidityType _manage_pool>
struct UniquePointer<_ValueT, Allocator<_ValueT, _manage_pool>> {
	public:
	DD_ALIAS(ThisType, UniquePointer<_ValueT DD_COMMA Allocator<_ValueT DD_COMMA _manage_pool>>)
	DD_ALIAS(ValueType, _ValueT)
	DD_ALIAS(DeleterType, Allocator<_ValueT DD_COMMA _manage_pool>)
	
	public:
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(DifferenceType, DD::DifferenceType)
	
	
	private:
#	if __cplusplus >= 201103L
	PointerType _m_pointer = PointerType();
#	else
	PointerType _m_pointer;
#	endif
	
	
#	if __cplusplus >= 201103L
	public:
	constexpr UniquePointer() = default;
	
	public:
	UniquePointer(ThisType const&) = delete;
	
	public:
	constexpr UniquePointer(ThisType&& _origin) noexcept : _m_pointer(_origin.release()) {
	}
#	else
	public:
	UniquePointer() throw() : _m_pointer() {
	}
	
	private:
	UniquePointer(ThisType const&);// Deleted by undefined private declaration
#	endif
	
	public:
	explicit DD_CONSTEXPR UniquePointer(PointerType _pointer) DD_NOEXCEPT : _m_pointer(_pointer) {
	}
	
	
	public:
	~UniquePointer() DD_NOEXCEPT {
		destroy();
	}
	
	
	public:
	ProcessType reset(PointerType _pointer = PointerType()) DD_NOEXCEPT {
		destroy();
		_m_pointer = _pointer;
	}
	
	
	public:
	PointerType release() DD_NOEXCEPT {
#	if __cplusplus >= 201103L
		auto _temp(_m_pointer);
#	else
		PointerType _temp(_m_pointer);
#	endif
		_m_pointer = PointerType();
		return _temp;
	}
	
	
	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT {
		using DD::swap;
		swap(_m_pointer, _target._m_pointer);
	}
	
	
	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return _m_pointer;
	}
	
	
	private:
	ProcessType destroy() const DD_NOEXCEPT {
		DeleterType::destroy(_m_pointer);
		DeleterType::deallocate(_m_pointer);
	}
	
	
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const&) = delete;
	
	public:
	ThisType& operator =(ThisType&& _origin) noexcept(true) {
		swap(_origin);
	}
#	else
	private:
	ThisType& operator =(ThisType const&);
#	endif
	
	public:
	ThisType& operator =(PointerType _pointer) DD_NOEXCEPT {
		reset(_pointer);
	}
	
	
	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *_m_pointer;
	}
	
	
	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return _m_pointer;
	}
	
	
};



template <typename _ValueT>
struct UniquePointer<_ValueT, void> {
	public:
	DD_ALIAS(ThisType, UniquePointer<_ValueT DD_COMMA void>)
	DD_ALIAS(ValueType, _ValueT)
	DD_ALIAS(DeleterType, void)
	
	public:
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(DifferenceType, DD::DifferenceType)
	
	
	private:
#	if __cplusplus >= 201103L
	PointerType _m_pointer = PointerType();
#	else
	PointerType _m_pointer;
#	endif
	
	
	public:
#	if __cplusplus >= 201103L
	constexpr UniquePointer() = default;
	
	public:
	UniquePointer(ThisType const&) = delete;
	
	public:
	constexpr UniquePointer(ThisType&& _origin) noexcept : _m_pointer(_origin.release()) {
	}
#	else
	UniquePointer() throw() : _m_pointer() {
	}
	
	private:
	UniquePointer(ThisType const&);// Deleted by undefined private declaration
#	endif
	
	public:
	explicit DD_CONSTEXPR UniquePointer(PointerType _pointer) DD_NOEXCEPT : _m_pointer(_pointer) {
	}
	
	
	public:
	~UniquePointer() DD_NOEXCEPT {
		destroy();
	}
	
	
	public:
	ProcessType reset(PointerType _pointer = PointerType()) DD_NOEXCEPT {
		destroy();
		_m_pointer = _pointer;
	}
	
	
	public:
	PointerType release() DD_NOEXCEPT {
#	if __cplusplus >= 201103L
		auto temp(_m_pointer);
#	else
		PointerType temp(_m_pointer);
#	endif
		_m_pointer = PointerType();
		return temp;
	}
	
	
	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT {
		using DD::swap;
		swap(_m_pointer, _target._m_pointer);
	}
	
	
	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return _m_pointer;
	}
	
	
	private:
	ProcessType destroy() const DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type. ");
		delete _m_pointer;
	}
	
	
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const&) = delete;
	
	public:
	ThisType& operator =(ThisType&& _origin) noexcept(true) {
		swap(_origin);
	}
#	else
	private:
	ThisType& operator =(ThisType const&);
#	endif
	
	public:
	ThisType& operator =(PointerType _pointer) DD_NOEXCEPT {
		reset(_pointer);
	}
	
	
	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *_m_pointer;
	}
	
	
	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return _m_pointer;
	}
	
	
};



template <typename _ValueT>
struct UniquePointer<_ValueT[], void> {
	public:
	DD_ALIAS(ThisType, UniquePointer<_ValueT DD_COMMA void>)
	DD_ALIAS(ValueType, _ValueT)
	DD_ALIAS(DeleterType, void)
	
	public:
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(DifferenceType, DD::DifferenceType)
	
	
	private:
#	if __cplusplus >= 201103L
	PointerType _m_pointer = PointerType();
#	else
	PointerType _m_pointer;
#	endif
	
	
	public:
#	if __cplusplus >= 201103L
	constexpr UniquePointer() = default;
	
	public:
	UniquePointer(ThisType const& _origin) = delete;
	
	public:
	constexpr UniquePointer(ThisType&& _origin) noexcept : _m_pointer(_origin.release()) {
	}
#	else
	UniquePointer() throw() : _m_pointer() {
	}
	
	private:
	UniquePointer(ThisType const&);// Deleted by undefined private declaration
#	endif
	
	public:
	DD_CONSTEXPR UniquePointer(PointerType _pointer) DD_NOEXCEPT : _m_pointer(_pointer) {
	}
	
	
	public:
	~UniquePointer() DD_NOEXCEPT {
		destroy();
	}
	
	
	public:
	ProcessType reset(PointerType target = PointerType()) DD_NOEXCEPT {
		destroy();
		_m_pointer = target;
	}
	
	
	public:
	PointerType release() DD_NOEXCEPT {
#	if __cplusplus >= 201103L
		auto _temp(_m_pointer);
#	else
		PointerType _temp(_m_pointer);
#	endif
		_m_pointer = PointerType();
		return _temp;
	}
	
	
	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT {
		using DD::swap;
		swap(_m_pointer, _target._m_pointer);
	}
	
	
	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return _m_pointer;
	}
	
	
	private:
	ProcessType destroy() const DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type. ");
		delete[] _m_pointer;
	}
	
	
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const&) = delete;
	
	public:
	ThisType& operator =(ThisType&& _origin) noexcept {
		swap(_origin);
	}
#	else
	private:
	ThisType& operator =(ThisType const&);
#	endif
	
	public:
	ThisType& operator =(PointerType _pointer) DD_NOEXCEPT {
		reset(_pointer);
	}
	
	
	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *_m_pointer;
	}
	
	
	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return _m_pointer;
	}
	
	
};



template <typename _ValueT, typename _DeleterT>
inline ProcessType swap(
	UniquePointer<_ValueT, _DeleterT>& _unique_pointer_1,
	UniquePointer<_ValueT, _DeleterT>& _unique_pointer_2
) DD_NOEXCEPT {
	_unique_pointer_1.swap(_unique_pointer_2);
}



DD_END



#endif
