//	DDCPP/standard/bits/DD_UniquePointer.hpp
#ifndef _DD_UNIQUE_POINTER_HPP_INCLUDED
#	define _DD_UNIQUE_POINTER_HPP_INCLUDED 1



#	include "DD_ValueTypeNested.hpp"
#	include "DD_Tags.hpp"
#	include "DD_Comparable.hpp"
#	if __cplusplus >= 201103L
#		include "DD_forward.hpp"
#	endif
#	include "DD_Allocator.hpp"
#	include "DD_swap.hpp"



_DD_DETAIL_BEGIN
template <typename _ValueT, typename _DeleterT = DefaultTag>
struct UniquePointer : Comparable<_ValueT, _DeleterT> {
	public:
	DD_ALIAS(ThisType, UniquePointer<_ValueT DD_COMMA _DeleterT>);
	DD_ALIAS(DeleterType, _DeleterT);
	DD_VALUE_TYPE_NESTED(_ValueT)


	DD_ALIAS(DifferenceType, DD::DifferenceType);


	private:
	PointerType _m_pointer DD_IN_CLASS_INITIALIZE(PointerType());
	DeleterType _m_deleter DD_IN_CLASS_INITIALIZE(DeleterType());


	public:
#	if __cplusplus >= 201103L
	constexpr UniquePointer() = default;
#	else
	UniquePointer() DD_NOEXCEPT : _m_pointer(), _m_deleter() {
	}
#	endif

	DD_DELETE_COPY_CONSTRUCTOR(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	constexpr UniquePointer(ThisType&& _origin) noexcept : _m_pointer(_origin.release()), _m_deleter(forward<DeleterType>(_origin._m_deleter)) {
	}

#	endif

	public:
	explicit DD_CONSTEXPR UniquePointer(PointerType _pointer) DD_NOEXCEPT : _m_pointer(_pointer) {
	}

#	if __cplusplus >= 201103L
	public:
	template <typename _DeleterT_>
	constexpr UniquePointer(_DeleterT_&& _deleter) noexcept(
		noexcept(DeleterType(forward<_DeleterT_>(_deleter)))
	) : _m_deleter(forward<_DeleterT_>(_deleter)) {
	}

	public:
	template <typename _DeleterT_>
	constexpr UniquePointer(PointerType _pointer, _DeleterT_&& _deleter) noexcept(
		noexcept(DeleterType(forward<_DeleterT_>(_deleter)))
	) : _m_pointer(_pointer), _m_deleter(forward<_DeleterT_>(_deleter)) {
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
	PointerType get_pointer() const DD_NOEXCEPT {
		return _m_pointer;
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return get_pointer();
	}


	public:
	ProcessType reset(PointerType _pointer = PointerType()) DD_NOEXCEPT {
		destroy();
		_m_pointer = _pointer;
	}


	public:
	PointerType release() DD_NOEXCEPT {
		PointerType _temp(get_pointer());
		_m_pointer = PointerType();
		return _temp;
	}


	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT {
		using DD::swap;
		swap(_m_pointer, _target._m_pointer);
		swap(_m_deleter, _target._m_deleter);
	}


	private:
	ProcessType destroy() const DD_NOEXCEPT {
		_m_deleter(get_pointer());
	}


	DD_DELETE_COPY_ASSIGNMENT(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& _origin) noexcept(true) {
		swap(_origin);
	}

#	endif

	public:
	ThisType& operator =(PointerType _pointer) DD_NOEXCEPT {
		reset(_pointer);
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *get_pointer();
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



template <typename _ValueT>
struct UniquePointer<_ValueT, DefaultTag> : Comparable<_ValueT, DefaultTag> {
	public:
	DD_ALIAS(ThisType, UniquePointer<_ValueT DD_COMMA DefaultTag>);
	DD_ALIAS(DeleterType, void);
	DD_VALUE_TYPE_NESTED(_ValueT)

	public:
	DD_ALIAS(DifferenceType, DD::DifferenceType);


	private:
	PointerType _m_pointer DD_IN_CLASS_INITIALIZE(PointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr UniquePointer() = default;
#	else
	UniquePointer() throw() : _m_pointer() {
	}
#	endif

	DD_DELETE_COPY_CONSTRUCTOR(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	constexpr UniquePointer(ThisType&& _origin) noexcept : _m_pointer(_origin.release()) {
	}

#	endif

	public:
	explicit DD_CONSTEXPR UniquePointer(PointerType _pointer) DD_NOEXCEPT : _m_pointer(_pointer) {
	}


	public:
	~UniquePointer() DD_NOEXCEPT {
		destroy();
	}


	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return _m_pointer;
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return get_pointer();
	}


	public:
	ProcessType reset(PointerType _pointer = PointerType()) DD_NOEXCEPT {
		destroy();
		_m_pointer = _pointer;
	}


	public:
	PointerType release() DD_NOEXCEPT {
		PointerType temp(get_pointer());
		_m_pointer = PointerType();
		return temp;
	}


	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT {
		using DD::swap;
		swap(_m_pointer, _target._m_pointer);
	}


	private:
	ProcessType destroy() const DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type. ");
		delete get_pointer();
	}


	DD_DELETE_COPY_ASSIGNMENT(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& _origin) noexcept(true) {
		swap(_origin);
	}

#	endif

	public:
	ThisType& operator =(PointerType _pointer) DD_NOEXCEPT {
		reset(_pointer);
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *get_pointer();
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



template <typename _ValueT>
struct UniquePointer<_ValueT[], DefaultTag> : Comparable<_ValueT[], DefaultTag> {
	public:
	DD_ALIAS(ThisType, UniquePointer<_ValueT DD_COMMA void>);
	DD_ALIAS(DeleterType, void);
	DD_VALUE_TYPE_NESTED(_ValueT)

	public:
	DD_ALIAS(DifferenceType, DD::DifferenceType);


	private:
	PointerType _m_pointer DD_IN_CLASS_INITIALIZE(PointerType());


	public:
#	if __cplusplus >= 201103L
	constexpr UniquePointer() = default;
#	else
	UniquePointer() throw() : _m_pointer() {
	}
#	endif

	DD_DELETE_COPY_CONSTRUCTOR(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	constexpr UniquePointer(ThisType&& _origin) noexcept : _m_pointer(_origin.release()) {
	}

#	endif

	public:
	DD_CONSTEXPR UniquePointer(PointerType _pointer) DD_NOEXCEPT : _m_pointer(_pointer) {
	}


	public:
	~UniquePointer() DD_NOEXCEPT {
		destroy();
	}


	public:
	PointerType get_pointer() const DD_NOEXCEPT {
		return _m_pointer;
	}


	public:
	ValidityType is_valid() const DD_NOEXCEPT {
		return get_pointer();
	}


	public:
	ProcessType reset(PointerType target = PointerType()) DD_NOEXCEPT {
		destroy();
		_m_pointer = target;
	}


	public:
	PointerType release() DD_NOEXCEPT {
		PointerType _temp(get_pointer());
		_m_pointer = PointerType();
		return _temp;
	}


	public:
	ProcessType swap(ThisType& _target) DD_NOEXCEPT {
		using DD::swap;
		swap(_m_pointer, _target._m_pointer);
	}


	private:
	ProcessType destroy() const DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type. ");
		delete[] get_pointer();
	}


	DD_DELETE_COPY_ASSIGNMENT(UniquePointer)

#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType&& _origin) noexcept {
		swap(_origin);
	}

#	endif

	public:
	ThisType& operator =(PointerType _pointer) DD_NOEXCEPT {
		reset(_pointer);
	}


	public:
	ReferenceType operator *() const DD_NOEXCEPT {
		return *get_pointer();
	}


	public:
	PointerType operator ->() const DD_NOEXCEPT {
		return get_pointer();
	}


#	if __cplusplus >= 201103L
	public:
	explicit operator ValidityType() const DD_NOEXCEPT {
		return is_valid();
	}


#	endif
};



template <typename _ValueT, typename _DeleterT>
inline ValidityType operator ==(
	UniquePointer<_ValueT, _DeleterT> const& _unique_pointer_1,
	UniquePointer<_ValueT, _DeleterT> const& _unique_pointer_2
) DD_NOEXCEPT_AS(static_cast<ValidityType>(_unique_pointer_1.get_pointer() == _unique_pointer_2.get_pointer())) {
	return _unique_pointer_1.get_pointer() == _unique_pointer_2.get_pointer();
}



template <typename _ValueT, typename _DeleterT>
inline ValidityType operator <(
	UniquePointer<_ValueT, _DeleterT> const& _unique_pointer_1,
	UniquePointer<_ValueT, _DeleterT> const& _unique_pointer_2
) DD_NOEXCEPT_AS(static_cast<ValidityType>(_unique_pointer_1.get_pointer() < _unique_pointer_2.get_pointer())) {
	return _unique_pointer_1.get_pointer() < _unique_pointer_2.get_pointer();
}



_DD_DETAIL_END



_DD_BEGIN
using _detail::UniquePointer;



_DD_END



#endif
