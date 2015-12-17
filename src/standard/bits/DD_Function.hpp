//	DDCPP/standard/bits/DD_Function.hpp
#ifndef DD_FUNCTION_HPP_INCLUDED_
#	define DD_FUNCTION_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::Function'.



#	endif
#	include "DD_Decay.hpp"
#	include "DD_NeedInstance.hpp"
#	include "DD_TypeInfo.hpp"
#	include "DD_move.hpp"
#	include "DD_release.hpp"
#	include "DD_Allocateable.hpp"
#	include "DD_Functor.hpp"



DD_DETAIL_BEGIN_
template <typename ResultT_, typename... ArgumentsT_>
struct FunctionHolderBase_ {
	public:
	using ThisType = FunctionHolderBase_<ResultT_, ArgumentsT_...>;


	public:
	constexpr FunctionHolderBase_() = default;

	public:
	DD_DELETE_COPY_CONSTRUCTOR(FunctionHolderBase_)

	public:
	DD_DELETE_MOVE_CONSTRUCTOR(FunctionHolderBase_)


	public:
	virtual ~FunctionHolderBase_() = default;


	public:
	virtual SizeType get_size_() const DD_NOEXCEPT = 0;


	public:
	virtual TypeInfo const& get_type_() const = 0;


	public:
	virtual ProcessType clone_to_(ThisType* pointer_) const = 0;


	public:
	virtual ResultT_ call_(ArgumentsT_... arguments__) = 0;


	public:
	DD_DELETE_ALL_ASSIGNMENTS(FunctionHolderBase_)


};



template <typename FunctionT_, typename ResultT_, typename... ArgumentsT_>
struct FunctionHolder_ : FunctionHolderBase_<ResultT_, ArgumentsT_...> {
	public:
	using ThisType = FunctionHolder_<FunctionT_, ResultT_, ArgumentsT_...>;
	using SuperType = FunctionHolderBase_<ResultT_, ArgumentsT_...>;
	using FunctionType = FunctionT_;


	private:
	FunctionType m_function_;


	public:
	DD_DELETE_DEFAULT_CONSTRUCTOR(FunctionHolder_)

	public:
	constexpr FunctionHolder_(ThisType const& origin_) noexcept(noexcept(FunctionType(origin_.m_function_))) : m_function_(origin_.m_function_) {
	};

	public:
	DD_DELETE_MOVE_CONSTRUCTOR(FunctionHolder_)

	public:
	template <typename FunctionT__>
	constexpr FunctionHolder_(FunctionT__&& function___) noexcept(
		noexcept(FunctionType(forward<FunctionT__>(function___)))
	) : m_function_(forward<FunctionT__>(function___)) {
	}


	public:
	~FunctionHolder_() override = default;


	public:
	SizeType get_size_() const DD_NOEXCEPT override {
		return sizeof(ThisType);
	}


	public:
	TypeInfo const& get_type_() const override {
		return typeid(m_function_);
	}


	public:
	ProcessType clone_to_(SuperType* pointer_) const override {
		::DD::construct(static_cast<ThisType*>(pointer_), *this);
	}


	public:
	ResultT_ call_(ArgumentsT_... arguments__) override {
		return m_function_(arguments__...);
	}


	public:
	DD_DELETE_ALL_ASSIGNMENTS(FunctionHolderBase_)


};



template <typename FunctionT_, typename AllocatorT_ = Allocator<void>>
struct Function;



template <typename AllocatorT_, typename ResultT_, typename... ArgumentsT_>
struct Function<ResultT_(ArgumentsT_...), AllocatorT_> : Functor<ResultT_, ArgumentsT_...>, Allocateable<AllocatorT_> {
	public:
	using SuperType = Functor<ResultT_, ArgumentsT_...>;
	using AllocateAgent = Allocateable<AllocatorT_>;
	using ThisType = Function<ResultT_(ArgumentsT_...), AllocatorT_>;
	using FunctionType = ResultT_(ArgumentsT_...);
	using AllocatorType = AllocatorT_;


	private:
	using HolderType = FunctionHolderBase_<ResultT_, ArgumentsT_...>;
	using HolderPointerType = HolderType*;

	private:
	HolderPointerType m_holder_ = HolderPointerType();


	public:
	constexpr Function() = default;

	public:
	Function(ThisType const& origin_) : AllocateAgent(origin_), m_holder_(static_cast<HolderPointerType>(
		AllocateAgent::basic_allocate(origin_.m_holder_->get_size_())
	)) {
		try {
			origin_.m_holder_->clone_to_(m_holder_);
		} catch (...) {
			AllocateAgent::basic_deallocate(m_holder_, origin_.m_holder_->get_size_());
		}
	}

	public:
	Function(ThisType&& origin_) noexcept(
		noexcept(AllocateAgent(::DD::move(origin_)))
	) : AllocateAgent(::DD::move(origin_)), m_holder_(::DD::release(origin_.m_holder_)) {
	}

	public:
	Function(ThisType& origin_) : Function(static_cast<ThisType const&>(origin_)) {
	}

	public:
	explicit Function(AllocatorType const& allocator_) : AllocateAgent(allocator_) {
	}

	public:
	Function(DecayType<FunctionType> function_) noexcept(
		noexcept(AllocateAgent()) &&
		noexcept(HolderPointerType(ThisType().make_holder_(function_)))
	) : m_holder_(make_holder_(function_)) {
	}

	public:
	Function(AllocatorType const& allocator_, DecayType<FunctionType> function_) noexcept(
		noexcept(HolderPointerType(ThisType().make_holder_(function_)))
	) : AllocateAgent(allocator_), m_holder_(make_holder_(function_)) {
	}

	public:
	template <typename FunctionT__>
	Function(FunctionT__&& function___) noexcept(
		noexcept(AllocateAgent()) &&
		noexcept(HolderPointerType(ThisType().make_holder_(forward<FunctionT__>(function___))))
	) : m_holder_(make_holder_(forward<FunctionT__>(function___))) {
	}

	public:
	template <typename FunctionT__>
	Function(AllocatorType const& allocator_, FunctionT__&& function___) noexcept(
		noexcept(AllocateAgent(allocator_)) &&
		noexcept(HolderPointerType(ThisType().make_holder_(forward<FunctionT__>(function___))))
	) : AllocateAgent(allocator_), m_holder_(make_holder_(forward<FunctionT__>(function___))) {
	}


	public:
	~Function() noexcept {
		destruct();
	}


	public:
	ValidityType constexpr is_valid() const noexcept {
		return m_holder_;
	}


	public:
	TypeInfo const& get_type() const {
		return m_holder_->get_type_();
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
		using ResultHolderType_ = FunctionHolder_<DecayType<FunctionT__>, ResultT_, ArgumentsT_...>;
		ResultHolderType_* holder_ = static_cast<ResultHolderType_*>(AllocateAgent::basic_allocate(sizeof(ResultHolderType_)));
		try {
			::DD::construct(holder_, forward<FunctionT__>(function___));
		} catch (...) {
			AllocateAgent::basic_deallocate(holder_, sizeof(ResultHolderType_));
			throw;
		}
		return holder_;
	}


	private:
	void destruct() noexcept {
		if (is_valid()) {
			SizeType size_ = m_holder_->get_size_();
			::DD::destruct(m_holder_);
			AllocateAgent::basic_deallocate(m_holder_, size_);
		}
	}


	public:
	ThisType& operator =(ThisType const& origin_) {
		ThisType temp_(origin_);
		swap(temp_);
		return *this;
	}

	public:
	ThisType& operator =(ThisType&& origin_) DD_NOEXCEPT_AS(::DD::fabricate<ThisType>().swap(origin_)) {
		swap(origin_);
		return *this;
	}

	public:
	template <typename FunctionT__>
	ThisType& operator =(FunctionT__&& function___) {
		ThisType temp_(forward<FunctionT__>(function___));
		swap(temp_);
		return *this;
	}


	public:
	ResultT_ operator ()(ArgumentsT_... arguments__) {
		return m_holder_->call_(arguments__...);
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Function;



DD_END_



#endif
