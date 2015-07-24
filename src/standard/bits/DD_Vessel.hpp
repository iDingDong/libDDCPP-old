//	standard/bits/DD_Vessel.hpp
#ifndef _DD_VESSEL_HPP_INCLUDED
#	define _DD_VESSEL_HPP_INCLUDED 1



#	if __cplusplus >= 201103L
#		include <initializer_list>

#		include "DD_move.hpp"
#	endif
#	include "DD_UniquePointer.hpp"
#	include "DD_release.hpp"



DD_BEGIN
template <typename _ValueT, typename _AllocatorT = Allocator<_ValueT>>
struct Vessel {
	public:
#	if __cplusplus >= 201103L
	using ThisType = Vessel<_ValueT, _AllocatorT>;
#	else
	typedef Vessel<_ValueT, _AllocatorT> ThisType;
#	endif
	DD_ALIAS(ValueType, _ValueT)
	DD_ALIAS(AllocatorType, _AllocatorT)
	
	public:
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(ConstReferenceType, ValueType const&)
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ConstPointerType, ValueType const*)
	DD_ALIAS(LengthType, DD::LengthType)
	
	
};



template <typename _ValueT>
struct Vessel<_ValueT, Allocator<_ValueT>> {
	public:
#	if __cplusplus >= 201103L
	using ThisType = Vessel<_ValueT, Allocator<_ValueT>>;
#	else
	typedef Vessel<_ValueT, Allocator<_ValueT>> ThisType;
#	endif
	DD_ALIAS(ValueType, _ValueT)
	DD_ALIAS(AllocatorType, Allocator<_ValueT>)
	
	public:
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(ConstReferenceType, ValueType const&)
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ConstPointerType, ValueType const*)
	
	
	private:
	PointerType _m_begin = PointerType();
	PointerType _m_end = PointerType();
	PointerType _m_storage_end = PointerType();
	
	
	public:
	DD_CONSTEXPR Vessel() = default;
	
	public:
	Vessel(ThisType const& _origin) DD_NOEXCEPT_IF(false) : _m_begin(_origin.is_empty() ? PointerType() : AllocatorType::allocate(_origin.get_length())), _m_end(_m_begin), _m_storage_end(_m_begin + _origin.get_length()) {
		throw false;// Unrealized.
	}
	
#	if __cplusplus >= 201103
	public:
	constexpr Vessel(ThisType&& _origin) noexcept : _m_begin(release(_origin._m_begin)), _m_end(release(_origin._m_end)), _m_storage_end(_origin._m_storage_end) {
	}
	
	public:
	Vessel(std::initializer_list<ValueType> _initializer) noexcept(false) : _m_begin(_initializer.empty() ? PointerType() : AllocatorType::allocate(_initializer.size())), _m_end(_m_begin), _m_storage_end(_m_begin + _initializer.size()) {
		for (auto& _value : _initializer) {
			try {
				AllocatorType::construct(this->_m_end++, move(_value));
			} catch (...) {
				this->clear();
				throw;
			}
		}
	}
	
#	endif
	
	public:
	~Vessel() DD_NOEXCEPT {
		this->clear();
	}
	
	
	public:
	LengthType DD_CONSTEXPR get_length() const DD_NOEXCEPT {
		return this->_m_end - this->_m_begin;
	}
	
	
	public:
	LengthType DD_CONSTEXPR get_capacity() const DD_NOEXCEPT {
		return this->_m_storage_end - this->_m_begin;
	}
	
	
	public:
	LengthType DD_CONSTEXPR get_space() const DD_NOEXCEPT {
		return this->_m_storage_end - this->_m_end;
	}
	
	
	public:
	LengthType DD_CONSTEXPR is_empty() const DD_NOEXCEPT {
		return this->_m_begin >= this->_m_end;
	}
	
	
	public:
	LengthType DD_CONSTEXPR is_full() const DD_NOEXCEPT {
		return this->_m_end >= this->_m_storage_end;
	}
	
	
	public:
	ProcessType DD_CONSTEXPR clear() const DD_NOEXCEPT {
		AllocatorType::destroy(this->_m_begin, this->_m_end);
		AllocatorType::destruct(this->_m_begin, this->get_capacity());
	}
	
	
};



DD_END



#endif
