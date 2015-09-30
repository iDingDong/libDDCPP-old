//	DDCPP/standard/bits/DD_Function.hpp
#ifndef DD_FUNCTION_HPP_INCLUDED_
#	define DD_FUNCTION_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Function'.



#	endif
#	include "DD_NeedInstance.hpp"
#	include "DD_Decay.hpp"
#	include "DD_move.hpp"
#	include "DD_release.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_Functor.hpp"



DD_DETAIL_BEGIN_
template <typename FunctionT_, typename AllocatorT_, ValidityType need_instance_c_>
struct Function_;



template <typename AllocatorT_, ValidityType need_instance_c_, typename ResultT_, typename... ArgumentsT_>
struct FunctionHolderBase_ {
	public:
	using ThisType = FunctionHolderBase_<AllocatorT_, need_instance_c_, ResultT_, ArgumentsT_...>;
	using AllocatorType = AllocatorT_;


	public:
	friend Function_<ResultT_(ArgumentsT_...), AllocatorT_, need_instance_c_>;
	friend AllocatorType;


	protected:
	constexpr FunctionHolderBase_() = default;

	private:
	DD_DELETE_COPY_CONSTRUCTOR(FunctionHolderBase_)
	DD_DELETE_MOVE_CONSTRUCTOR(FunctionHolderBase_)


	protected:
	virtual ~FunctionHolderBase_() = default;


	private:
	virtual ThisType* get_clone_() const = 0;


	private:
	virtual ResultT_ call_(ArgumentsT_... arguments__) = 0;


	private:
	DD_DELETE_ALL_ASSIGNMENTS(FunctionHolderBase_)


};



template <typename AllocatorT_, typename ResultT_, typename... ArgumentsT_>
struct FunctionHolderBase_<AllocatorT_, true, ResultT_, ArgumentsT_...> {
	public:
	using ThisType = FunctionHolderBase_<AllocatorT_, true, ResultT_, ArgumentsT_...>;
	using AllocatorType = AllocatorT_;


	public:
	friend Function_<ResultT_(ArgumentsT_...), AllocatorT_, true>;
	friend AllocatorType;


	protected:
	constexpr FunctionHolderBase_() = default;

	private:
	DD_DELETE_COPY_CONSTRUCTOR(FunctionHolderBase_)
	DD_DELETE_MOVE_CONSTRUCTOR(FunctionHolderBase_)


	protected:
	virtual ~FunctionHolderBase_() = default;


	private:
	virtual ThisType* get_clone_(AllocatorT_& allocator__) const = 0;


	private:
	virtual ResultT_ call_(ArgumentsT_... arguments__) = 0;


	private:
	DD_DELETE_ALL_ASSIGNMENTS(FunctionHolderBase_)


};



template <typename FunctionT_, typename AllocatorT_, ValidityType need_instance_c_, typename ResultT_, typename... ArgumentsT_>
struct FunctionHolder_ : FunctionHolderBase_<AllocatorT_, need_instance_c_, ResultT_, ArgumentsT_...> {
	public:
	using ThisType = FunctionHolder_<FunctionT_, AllocatorT_, need_instance_c_, ResultT_, ArgumentsT_...>;
	using SuperType = FunctionHolderBase_<AllocatorT_, need_instance_c_, ResultT_, ArgumentsT_...>;
	using FunctionType = FunctionT_;
	using AllocatorType = AllocatorT_;


	public:
	friend AllocatorType;


	public:
	friend Function_<ResultT_(ArgumentsT_...), AllocatorT_,  need_instance_c_>;


	private:
	FunctionType m_function_;


	private:
	FunctionHolder_() = delete;

	private:
	constexpr FunctionHolder_(ThisType const& origin_) noexcept(noexcept(FunctionType(origin_.m_function_))) : m_function_(origin_.m_function_) {
	};

	private:
	FunctionHolder_(ThisType&& origin_) = delete;

	private:
	template <typename FunctionT__>
	constexpr FunctionHolder_(FunctionT__&& function___) noexcept(
		noexcept(FunctionType(forward<FunctionT__>(function___)))
	) : m_function_(forward<FunctionT__>(function___)) {
	}


	private:
	~FunctionHolder_() override = default;


	private:
	SuperType* get_clone_() const override {
		ThisType* pointer_ = static_cast<ThisType*>(AllocatorType::Basic::allocate(sizeof(ThisType)));
		try {
			AllocatorType::Basic::construct(pointer_, *this);
		} catch (...) {
			AllocatorType::Basic::deallocate(pointer_, sizeof(ThisType));
			throw;
		}
		return pointer_;
	}


	private:
	ResultT_ call_(ArgumentsT_... arguments__) override {
		return m_function_(arguments__...);
	}


	private:
	DD_DELETE_ALL_ASSIGNMENTS(FunctionHolderBase_)


};



template <typename FunctionT_, typename AllocatorT_, typename ResultT_, typename... ArgumentsT_>
struct FunctionHolder_<FunctionT_, AllocatorT_, true, ResultT_, ArgumentsT_...> : FunctionHolderBase_<AllocatorT_, true, ResultT_, ArgumentsT_...> {
	public:
	using ThisType = FunctionHolder_<FunctionT_, AllocatorT_, true, ResultT_, ArgumentsT_...>;
	using SuperType = FunctionHolderBase_<AllocatorT_, true, ResultT_, ArgumentsT_...>;
	using FunctionType = FunctionT_;
	using AllocatorType = AllocatorT_;


	public:
	friend AllocatorType;


	public:
	friend Function_<ResultT_(ArgumentsT_...), AllocatorT_,  true>;


	private:
	FunctionType m_function_;


	private:
	FunctionHolder_() = delete;

	private:
	constexpr FunctionHolder_(ThisType const& origin_) noexcept(noexcept(FunctionType(origin_.m_function_))) : m_function_(origin_.m_function_) {
	};

	private:
	FunctionHolder_(ThisType&& origin_) = delete;

	private:
	template <typename FunctionT__>
	constexpr FunctionHolder_(FunctionT__&& function___) noexcept(
		noexcept(FunctionType(forward<FunctionT__>(function___)))
	) : m_function_(forward<FunctionT__>(function___)) {
	}


	private:
	~FunctionHolder_() override = default;


	private:
	SuperType* get_clone_(AllocatorT_& allocator__) const override {
		ThisType* pointer_ = static_cast<ThisType*>(allocator__.AllocatorType::Basic::allocate(sizeof(ThisType)));
		try {
			allocator__.AllocatorType::Basic::construct(pointer_, *this);
		} catch (...) {
			allocator__.AllocatorType::Basic::deallocate(pointer_, sizeof(ThisType));
			throw;
		}
		return pointer_;
	}


	private:
	ResultT_ call_(ArgumentsT_... arguments__) override {
		return m_function_(arguments__...);
	}


	private:
	DD_DELETE_ALL_ASSIGNMENTS(FunctionHolderBase_)


};



template <typename AllocatorT_, ValidityType need_instance_c_, typename ResultT_, typename... ArgumentsT_>
struct Function_<ResultT_(ArgumentsT_...), AllocatorT_, need_instance_c_> : Functor<ResultT_, ArgumentsT_...> {
	public:
	using ThisType = Function_<ResultT_(ArgumentsT_...), AllocatorT_, need_instance_c_>;
	using FunctionType = ResultT_(ArgumentsT_...);
	using AllocatorType = AllocatorT_;


	private:
	using HolderType = FunctionHolderBase_<AllocatorT_, need_instance_c_, ResultT_, ArgumentsT_...>;
	using HolderPointerType = HolderType*;

	private:
	HolderPointerType m_holder_ = HolderPointerType();


	public:
	constexpr Function_() = default;

	public:
	constexpr Function_(ThisType const& origin_) : m_holder_(origin_.m_holder_->get_clone_()) {
	}

	public:
	constexpr Function_(ThisType&& origin_) : m_holder_(release(origin_.m_holder_)) {
	}

	public:
	constexpr Function_(DecayType<FunctionType> function_) noexcept(
		noexcept(HolderPointerType(ThisType().make_holder_(function_)))
	) : m_holder_(make_holder_(function_)) {
	}

	public:
	template <typename FunctionT__>
	constexpr Function_(FunctionT__&& function___) noexcept(
		noexcept(HolderPointerType(ThisType().make_holder_(forward<FunctionT__>(function___))))
	) : m_holder_(make_holder_(forward<FunctionT__>(function___))) {
	}


	public:
	~Function_() noexcept {
		destruct();
	}


	public:
	ValidityType constexpr is_valid() const noexcept {
		return m_holder_;
	}


	public:
	void swap(ThisType& target_) noexcept(noexcept(swap(m_holder_, target_.m_holder_))) {
		using ::DD::swap;
		swap(m_holder_, target_.m_holder_);
	}


	public:
	void reset() noexcept {
		destruct();
		m_holder_ = nil_pointer;
	}

	public:
	template <typename FunctionT__>
	void reset(FunctionT__&& function___) {
		destruct();
		m_holder_ = make_holder_(forward<FunctionT__>(function___));
	}


	private:
	template <typename FunctionT__>
	HolderPointerType make_holder_(FunctionT__&& function___) {
		using ResultHolderType_ = FunctionHolder_<DecayType<FunctionT__>, AllocatorType, need_instance_c_, ResultT_, ArgumentsT_...>*;
		ResultHolderType_ holder_ = static_cast<ResultHolderType_>(AllocatorType::Basic::allocate(sizeof(ResultHolderType_)));
		try {
			AllocatorType::Basic::construct(holder_, forward<FunctionT__>(function___));
		} catch (...) {
			AllocatorType::Basic::deallocate(holder_, sizeof(ResultHolderType_));
			throw;
		}
		return holder_;
	}


	private:
	void destruct() noexcept {
		if (is_valid()) {
			AllocatorType::Basic::destruct(m_holder_);
			AllocatorType::Basic::deallocate(m_holder_);
		}
	}


	public:
	ThisType& operator =(ThisType const& origin_) {
		ThisType temp_(origin_);
		swap(temp_);
	}

	public:
	ThisType& operator =(ThisType&& origin_) {
		swap(origin_);
	}


	public:
	ResultT_ operator ()(ArgumentsT_... arguments__) {
		return m_holder_->call_(arguments__...);
	}


};



template <typename AllocatorT_, typename ResultT_, typename... ArgumentsT_>
struct Function_<ResultT_(ArgumentsT_...), AllocatorT_, true> : Functor<ResultT_, ArgumentsT_...> {
	public:
	using ThisType = Function_<ResultT_(ArgumentsT_...), AllocatorT_, true>;
	using FunctionType = ResultT_(ArgumentsT_...);
	using AllocatorType = AllocatorT_;


	private:
	using HolderType = FunctionHolderBase_<AllocatorT_, true, ResultT_, ArgumentsT_...>;
	using HolderPointerType = HolderType*;

	private:
	AllocatorType mutable m_allocator_ = AllocatorType();
	HolderPointerType m_holder_ = HolderPointerType();


	public:
	constexpr Function_() = default;

	public:
	constexpr Function_(ThisType const& origin_) : m_allocator_(origin_.get_allocator()), m_holder_(
		origin_.is_valid() ? origin_.m_holder_->get_clone_(get_allocator()) : HolderPointerType()
	) {
	}

	public:
	constexpr Function_(ThisType&& origin_) : m_allocator_(move(origin_.get_allocator())), m_holder_(release(origin_.m_holder_)) {
	}

	public:
	template <typename AllocatorT__>
	constexpr Function_(DecayType<FunctionType> function_, AllocatorT__&& allocator___) noexcept(
		noexcept(AllocatorType(forward<AllocatorT__>(allocator___))) &&
		noexcept(HolderPointerType(ThisType().make_holder_(function_)))
	) : m_allocator_(forward<AllocatorT__>(allocator___)), m_holder_(make_holder_(function_)) {
	}

	public:
	constexpr Function_(DecayType<FunctionType> function_) noexcept(
		noexcept(ThisType(function_, AllocatorType()))
	) : Function_(function_, AllocatorType()) {
	}

	public:
	template <typename FunctionT__, typename AllocatorT__>
	constexpr Function_(FunctionT__&& function___, AllocatorT__&& allocator___) noexcept(
		noexcept(AllocatorType(forward<AllocatorT__>(allocator___))) &&
		noexcept(HolderPointerType(ThisType().make_holder_(forward<FunctionT__>(function___))))
	) : m_allocator_(forward<AllocatorT__>(allocator___)), m_holder_(make_holder_(forward<FunctionT__>(function___))) {
	}

	public:
	template <typename FunctionT__>
	constexpr Function_(FunctionT__&& function___) noexcept(
		noexcept(ThisType(forward<FunctionT__>(function___), AllocatorType()))
	) : Function_(forward<FunctionT__>(function___), AllocatorType()) {
	}


	public:
	~Function_() noexcept {
		destruct();
	}


	public:
	ValidityType constexpr is_valid() const noexcept {
		return m_holder_;
	}


	public:
	AllocatorType& get_allocator() const noexcept {
		return m_allocator_;
	}


	public:
	void swap(ThisType& target_) noexcept(
		noexcept(swap(get_allocator(), target_.get_allocator())) &&
		noexcept(swap(m_holder_, target_.m_holder_))
	) {
		using ::DD::swap;
		swap(get_allocator(), target_.get_allocator());
		swap(m_holder_, target_.m_holder_);
	}


	public:
	void reset() noexcept {
		destruct();
		m_holder_ = nil_pointer;
	}

	public:
	template <typename FunctionT__>
	void reset(FunctionT__&& function___) {
		destruct();
		m_holder_ = make_holder_(forward<FunctionT__>(function___));
	}


	private:
	template <typename FunctionT__>
	HolderPointerType make_holder_(FunctionT__&& function___) {
		using ResultHolderType_ = FunctionHolder_<DecayType<FunctionT__>, AllocatorType, true, ResultT_, ArgumentsT_...>*;
		ResultHolderType_ holder_ = static_cast<ResultHolderType_>(get_allocator().AllocatorType::Basic::allocate(sizeof(ResultHolderType_)));
		try {
			get_allocator().AllocatorType::Basic::construct(holder_, forward<FunctionT__>(function___));
		} catch (...) {
			get_allocator().AllocatorType::Basic::deallocate(holder_, sizeof(ResultHolderType_));
			throw;
		}
		return holder_;
	}


	private:
	void destruct() noexcept {
		if (is_valid()) {
			get_allocator().AllocatorType::Basic::destruct(m_holder_);
			get_allocator().AllocatorType::Basic::deallocate(m_holder_);
		}
	}


	public:
	ThisType& operator =(ThisType const& origin_) {
		ThisType temp_(origin_);
		swap(temp_);
	}

	public:
	ThisType& operator =(ThisType&& origin_) {
		swap(origin_);
	}


	public:
	ResultT_ operator ()(ArgumentsT_... arguments__) {
		return m_holder_->call_(arguments__...);
	}


};



DD_DETAIL_END_



DD_BEGIN_
template <typename FunctionT_, typename AllocatorT_ = Allocator<void>>
using Function = detail_::Function_<FunctionT_, AllocatorT_, NeedInstance<AllocatorT_>::value>;



DD_END_



#endif
