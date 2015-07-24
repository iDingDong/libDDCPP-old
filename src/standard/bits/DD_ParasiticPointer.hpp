//	standard/bits/DD_ParasiticPointer.hpp
#ifndef _DD_INTRUSIVE_POINTER_HPP_INCLUDED
#	define _DD_INTRUSIVE_POINTER_HPP_INCLUDED 1



#	include "DD_Tags.hpp"
#	include "DD_address_of.hpp"
#	include "DD_release.hpp"
#	include "DD_Pair.hpp"



DD_BEGIN
template <typename _ValueT, typename _DeleterT = void>
struct ParasiticPointer {
};



template <typename _ValueT>
struct ParasiticPointer<_ValueT, void> {
	public:
	DD_ALIAS(ThisType, ParasiticPointer<_ValueT DD_COMMA void>)
	DD_ALIAS(ValueType, _ValueT)
	DD_ALIAS(DeleterType, void)
	
	public:
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(DifferenceType, DD::DifferenceType)
	
	public:
	DD_ALIAS(ParasitiferValueType, Pair<LengthType DD_COMMA ValueType>)
	DD_ALIAS(ParasitiferReferenceType, ParasitiferValueType&)
	DD_ALIAS(ParasitiferPointerType, ParasitiferValueType*)
	DD_ALIAS(ParasitiferDifferenceType, DD::DifferenceType)
	
	
	private:
#	if __cplusplus >= 201103L
	ParasitiferPointerType _m_pointer = ParasitiferPointerType();
#	else
	ParasitiferPointerType _m_pointer;
#	endif
	
	
#	if __cplusplus >= 201103L
	public:
	constexpr ParasiticPointer() = default;
#	else
	public:
	ParasiticPointer() throw() : _m_pointer() {
	}
#	endif
	
	public:
	DD_CONSTEXPR ParasiticPointer(ThisType const& _origin) DD_NOEXCEPT : _m_pointer((++_origin._m_pointer->first, _origin._m_pointer)) {
	}
	
#	if __cplusplus >= 201103L
	public:
	ParasiticPointer(ThisType&& _origin) noexcept : _m_pointer(release(_origin._m_pointer)) {
	}
	
#	endif
	public:
	explicit DD_CONSTEXPR ParasiticPointer(
		ParasitiferPointerType _parasitifer_target
	) DD_NOEXCEPT : _m_pointer(_parasitifer_target ? (++_parasitifer_target->first, _parasitifer_target) : ParasitiferPointerType()) {
	}
	
#	if __cplusplus >= 201103L
	public:
	template <typename... _ArgumentsT_>
	explicit constexpr ParasiticPointer(
		ConstructTag _tag,
		_ArgumentsT_&&... __arguments_
	) DD_NOEXCEPT_AS(new ParasitiferValueType{1 DD_COMMA ValueType(__arguments_...)}) : _m_pointer(new ParasitiferValueType{1, ValueType(__arguments_...)}) {
	};
#	else
	public:
	explicit ParasiticPointer(ConstructTag _tag) : _m_pointer(new ParasitiferValueType()) {
	}
#	endif
	
	
	public:
	~ParasiticPointer() DD_NOEXCEPT {
		unrefer();
	}
	
	
	private:
	ProcessType unrefer() DD_NOEXCEPT {
		if (_m_pointer) {
			if (_m_pointer->first > 1) {
				--_m_pointer->first;
			} else {
				DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type. ");
				delete _m_pointer;
			}
		}
	}
	
	
	public:
	ProcessType swap(ThisType& _target) {
		using DD::swap;
		DD::swap(_m_pointer, _target._m_pointer);
	}
	
	
	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return address_of(_m_pointer->second);
	}
	
	
	public:
	ParasitiferReferenceType get_parasitifer() const DD_NOEXCEPT {
		return *_m_pointer;
	}
	
	
	public:
	LengthType get_reference_count() const DD_NOEXCEPT {
		return _m_pointer->reference_count;
	}
	
	
	public:
	ThisType& operator =(ThisType const& _origin) DD_NOEXCEPT {
		ThisType _temp(_origin);
		swap(_temp);
	}
	
#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& _origin) DD_NOEXCEPT {
		swap(_origin);
	}
	
#	endif
	
	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return _m_pointer->second;
	}
	
	
	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return get_pointer();
	}
	
	
	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return _m_pointer;
	}
	
	
};



DD_END



#endif 
