//	DDCPP/standard/bits/DD_Function.hpp
#ifndef _DD_FUNCTION_HPP_INCLUDED
#	define _DD_FUNCTION_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Function'.



#	endif
#	include "DD_NeedInstance.hpp"
#	include "DD_Decay.hpp"
#	include "DD_move.hpp"
#	include "DD_release.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_Functor.hpp"



_DD_DETAIL_BEGIN
template <typename _FunctionT, typename _AllocatorT, ValidityType _need_instance_c>
struct _Function;



template <typename _AllocatorT, ValidityType _need_instance_c, typename _ResultT, typename... _ArgumentsT>
struct _FunctionHolderBase {
	public:
	using ThisType = _FunctionHolderBase<_AllocatorT, _need_instance_c, _ResultT, _ArgumentsT...>;
	using AllocatorType = _AllocatorT;


	public:
	friend _Function<_ResultT(_ArgumentsT...), _AllocatorT, _need_instance_c>;
	friend AllocatorType;


	protected:
	constexpr _FunctionHolderBase() = default;

	private:
	DD_DELETE_COPY_CONSTRUCTOR(_FunctionHolderBase)
	DD_DELETE_MOVE_CONSTRUCTOR(_FunctionHolderBase)


	protected:
	virtual ~_FunctionHolderBase() = default;


	private:
	virtual ThisType* _get_clone() const = 0;


	private:
	virtual _ResultT _call(_ArgumentsT... __arguments) = 0;


	private:
	DD_DELETE_ALL_ASSIGNMENTS(_FunctionHolderBase)


};



template <typename _AllocatorT, typename _ResultT, typename... _ArgumentsT>
struct _FunctionHolderBase<_AllocatorT, true, _ResultT, _ArgumentsT...> {
	public:
	using ThisType = _FunctionHolderBase<_AllocatorT, true, _ResultT, _ArgumentsT...>;
	using AllocatorType = _AllocatorT;


	public:
	friend _Function<_ResultT(_ArgumentsT...), _AllocatorT, true>;
	friend AllocatorType;


	protected:
	constexpr _FunctionHolderBase() = default;

	private:
	DD_DELETE_COPY_CONSTRUCTOR(_FunctionHolderBase)
	DD_DELETE_MOVE_CONSTRUCTOR(_FunctionHolderBase)


	protected:
	virtual ~_FunctionHolderBase() = default;


	private:
	virtual ThisType* _get_clone(_AllocatorT& __allocator) const = 0;


	private:
	virtual _ResultT _call(_ArgumentsT... __arguments) = 0;


	private:
	DD_DELETE_ALL_ASSIGNMENTS(_FunctionHolderBase)


};



template <typename _FunctionT, typename _AllocatorT, ValidityType _need_instance_c, typename _ResultT, typename... _ArgumentsT>
struct _FunctionHolder : _FunctionHolderBase<_AllocatorT, _need_instance_c, _ResultT, _ArgumentsT...> {
	public:
	using ThisType = _FunctionHolder<_FunctionT, _AllocatorT, _need_instance_c, _ResultT, _ArgumentsT...>;
	using SuperType = _FunctionHolderBase<_AllocatorT, _need_instance_c, _ResultT, _ArgumentsT...>;
	using FunctionType = _FunctionT;
	using AllocatorType = _AllocatorT;


	public:
	friend AllocatorType;


	public:
	friend _Function<_ResultT(_ArgumentsT...), _AllocatorT,  _need_instance_c>;


	private:
	FunctionType _m_function;


	private:
	_FunctionHolder() = delete;

	private:
	constexpr _FunctionHolder(ThisType const& _origin) noexcept(noexcept(FunctionType(_origin._m_function))) : _m_function(_origin._m_function) {
	};

	private:
	_FunctionHolder(ThisType&& _origin) = delete;

	private:
	template <typename _FunctionT_>
	constexpr _FunctionHolder(_FunctionT_&& __function_) noexcept(
		noexcept(FunctionType(forward<_FunctionT_>(__function_)))
	) : _m_function(forward<_FunctionT_>(__function_)) {
	}


	private:
	~_FunctionHolder() override = default;


	private:
	SuperType* _get_clone() const override {
		ThisType* _pointer = static_cast<ThisType*>(AllocatorType::Basic::allocate(sizeof(ThisType)));
		try {
			AllocatorType::Basic::construct(_pointer, *this);
		} catch (...) {
			AllocatorType::Basic::deallocate(_pointer, sizeof(ThisType));
			throw;
		}
		return _pointer;
	}


	private:
	_ResultT _call(_ArgumentsT... __arguments) override {
		return _m_function(__arguments...);
	}


	private:
	DD_DELETE_ALL_ASSIGNMENTS(_FunctionHolderBase)


};



template <typename _FunctionT, typename _AllocatorT, typename _ResultT, typename... _ArgumentsT>
struct _FunctionHolder<_FunctionT, _AllocatorT, true, _ResultT, _ArgumentsT...> : _FunctionHolderBase<_AllocatorT, true, _ResultT, _ArgumentsT...> {
	public:
	using ThisType = _FunctionHolder<_FunctionT, _AllocatorT, true, _ResultT, _ArgumentsT...>;
	using SuperType = _FunctionHolderBase<_AllocatorT, true, _ResultT, _ArgumentsT...>;
	using FunctionType = _FunctionT;
	using AllocatorType = _AllocatorT;


	public:
	friend AllocatorType;


	public:
	friend _Function<_ResultT(_ArgumentsT...), _AllocatorT,  true>;


	private:
	FunctionType _m_function;


	private:
	_FunctionHolder() = delete;

	private:
	constexpr _FunctionHolder(ThisType const& _origin) noexcept(noexcept(FunctionType(_origin._m_function))) : _m_function(_origin._m_function) {
	};

	private:
	_FunctionHolder(ThisType&& _origin) = delete;

	private:
	template <typename _FunctionT_>
	constexpr _FunctionHolder(_FunctionT_&& __function_) noexcept(
		noexcept(FunctionType(forward<_FunctionT_>(__function_)))
	) : _m_function(forward<_FunctionT_>(__function_)) {
	}


	private:
	~_FunctionHolder() override = default;


	private:
	SuperType* _get_clone(_AllocatorT& __allocator) const override {
		ThisType* _pointer = static_cast<ThisType*>(__allocator.AllocatorType::Basic::allocate(sizeof(ThisType)));
		try {
			__allocator.AllocatorType::Basic::construct(_pointer, *this);
		} catch (...) {
			__allocator.AllocatorType::Basic::deallocate(_pointer, sizeof(ThisType));
			throw;
		}
		return _pointer;
	}


	private:
	_ResultT _call(_ArgumentsT... __arguments) override {
		return _m_function(__arguments...);
	}


	private:
	DD_DELETE_ALL_ASSIGNMENTS(_FunctionHolderBase)


};



template <typename _AllocatorT, ValidityType _need_instance_c, typename _ResultT, typename... _ArgumentsT>
struct _Function<_ResultT(_ArgumentsT...), _AllocatorT, _need_instance_c> : Functor<_ResultT, _ArgumentsT...> {
	public:
	using ThisType = _Function<_ResultT(_ArgumentsT...), _AllocatorT, _need_instance_c>;
	using AllocatorType = _AllocatorT;


	private:
	using HolderType = _FunctionHolderBase<_AllocatorT, _need_instance_c, _ResultT, _ArgumentsT...>;
	using HolderPointerType = HolderType*;

	private:
	HolderPointerType _m_holder = HolderPointerType();


	public:
	constexpr _Function() = default;

	public:
	constexpr _Function(ThisType const& _origin) : _m_holder(_origin._m_holder->_get_clone()) {
	}

	public:
	constexpr _Function(ThisType&& _origin) : _m_holder(release(_origin._m_holder)) {
	}

	public:
	template <typename _FunctionT_>
	constexpr _Function(_FunctionT_&& __function_) noexcept(
		noexcept(HolderPointerType(ThisType()._make_holder(forward<_FunctionT_>(__function_))))
	) : _m_holder(_make_holder(forward<_FunctionT_>(__function_))) {
	}


	public:
	~_Function() noexcept {
		destruct();
	}


	public:
	ValidityType constexpr is_valid() const noexcept {
		return _m_holder;
	}


	public:
	void swap(ThisType& _target) noexcept(noexcept(swap(_m_holder, _target._m_holder))) {
		using ::DD::swap;
		swap(_m_holder, _target._m_holder);
	}


	public:
	void reset() noexcept {
		destruct();
		_m_holder = nil_pointer;
	}

	public:
	template <typename _FunctionT_>
	void reset(_FunctionT_&& __function_) {
		destruct();
		_m_holder = _make_holder(forward<_FunctionT_>(__function_));
	}


	private:
	template <typename _FunctionT_>
	HolderPointerType _make_holder(_FunctionT_&& __function_) {
		using _ResultHolderType = _FunctionHolder<DecayType<_FunctionT_>, AllocatorType, _need_instance_c, _ResultT, _ArgumentsT...>*;
		_ResultHolderType _holder = static_cast<_ResultHolderType>(AllocatorType::Basic::allocate(sizeof(_ResultHolderType)));
		try {
			AllocatorType::Basic::construct(_holder, forward<_FunctionT_>(__function_));
		} catch (...) {
			AllocatorType::Basic::deallocate(_holder, sizeof(_ResultHolderType));
			throw;
		}
		return _holder;
	}


	private:
	void destruct() noexcept {
		if (is_valid()) {
			AllocatorType::Basic::destruct(_m_holder);
			AllocatorType::Basic::deallocate(_m_holder);
		}
	}


	public:
	ThisType& operator =(ThisType const& _origin) {
		ThisType _temp(_origin);
		swap(_temp);
	}

	public:
	ThisType& operator =(ThisType&& _origin) {
		swap(_origin);
	}


	public:
	_ResultT operator ()(_ArgumentsT... __arguments) {
		return _m_holder->_call(__arguments...);
	}


};



template <typename _AllocatorT, typename _ResultT, typename... _ArgumentsT>
struct _Function<_ResultT(_ArgumentsT...), _AllocatorT, true> : Functor<_ResultT, _ArgumentsT...> {
	public:
	using ThisType = _Function<_ResultT(_ArgumentsT...), _AllocatorT, true>;
	using AllocatorType = _AllocatorT;


	private:
	using HolderType = _FunctionHolderBase<_AllocatorT, true, _ResultT, _ArgumentsT...>;
	using HolderPointerType = HolderType*;

	private:
	AllocatorType mutable _m_allocator = AllocatorType();
	HolderPointerType _m_holder = HolderPointerType();


	public:
	constexpr _Function() = default;

	public:
	constexpr _Function(ThisType const& _origin) : _m_allocator(_origin.get_allocator()), _m_holder(_origin._m_holder->_get_clone(get_allocator())) {
	}

	public:
	constexpr _Function(ThisType&& _origin) : _m_allocator(move(_origin.get_allocator())), _m_holder(release(_origin._m_holder)) {
	}

	public:
	template <typename _FunctionT_, typename _AllocatorT_>
	constexpr _Function(_FunctionT_&& __function_, _AllocatorT_&& __allocator_) noexcept(
		noexcept(AllocatorType(forward<_AllocatorT_>(__allocator_))) &&
		noexcept(HolderPointerType(ThisType()._make_holder(forward<_FunctionT_>(__function_))))
	) : _m_allocator(forward<_AllocatorT_>(__allocator_)), _m_holder(_make_holder(forward<_FunctionT_>(__function_))) {
	}

	public:
	template <typename _FunctionT_>
	constexpr _Function(_FunctionT_&& __function_) noexcept(
		noexcept(ThisType(forward<_FunctionT_>(__function_), AllocatorType()))
	) : _Function(forward<_FunctionT_>(__function_), AllocatorType()) {
	}


	public:
	~_Function() noexcept {
		destruct();
	}


	public:
	ValidityType constexpr is_valid() const noexcept {
		return _m_holder;
	}


	public:
	AllocatorType& get_allocator() const noexcept {
		return _m_allocator;
	}


	public:
	void swap(ThisType& _target) noexcept(
		noexcept(swap(get_allocator(), _target.get_allocator())) &&
		noexcept(swap(_m_holder, _target._m_holder))
	) {
		using ::DD::swap;
		swap(get_allocator(), _target.get_allocator());
		swap(_m_holder, _target._m_holder);
	}


	public:
	void reset() noexcept {
		destruct();
		_m_holder = nil_pointer;
	}

	public:
	template <typename _FunctionT_>
	void reset(_FunctionT_&& __function_) {
		destruct();
		_m_holder = _make_holder(forward<_FunctionT_>(__function_));
	}


	private:
	template <typename _FunctionT_>
	HolderPointerType _make_holder(_FunctionT_&& __function_) {
		using _ResultHolderType = _FunctionHolder<DecayType<_FunctionT_>, AllocatorType, true, _ResultT, _ArgumentsT...>*;
		_ResultHolderType _holder = static_cast<_ResultHolderType>(get_allocator().AllocatorType::Basic::allocate(sizeof(_ResultHolderType)));
		try {
			get_allocator().AllocatorType::Basic::construct(_holder, forward<_FunctionT_>(__function_));
		} catch (...) {
			get_allocator().AllocatorType::Basic::deallocate(_holder, sizeof(_ResultHolderType));
			throw;
		}
		return _holder;
	}


	private:
	void destruct() noexcept {
		if (is_valid()) {
			get_allocator().AllocatorType::Basic::destruct(_m_holder);
			get_allocator().AllocatorType::Basic::deallocate(_m_holder);
		}
	}


	public:
	ThisType& operator =(ThisType const& _origin) {
		ThisType _temp(_origin);
		swap(_temp);
	}

	public:
	ThisType& operator =(ThisType&& _origin) {
		swap(_origin);
	}


	public:
	_ResultT operator ()(_ArgumentsT... __arguments) {
		return _m_holder->_call(__arguments...);
	}


};



_DD_DETAIL_END



_DD_BEGIN
template <typename _FunctionT, typename _AllocatorT = Allocator<void>>
using Function = _detail::_Function<_FunctionT, _AllocatorT, NeedInstance<_AllocatorT>::value>;



_DD_END



#endif
