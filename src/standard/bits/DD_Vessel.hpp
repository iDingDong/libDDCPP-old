//	DDCPP/standard/bits/DD_Vessel.hpp
#ifndef DD_VESSEL_HPP_INCLUDED_
#	define DD_VESSEL_HPP_INCLUDED_ 1



#	if __cplusplus >= 201103L
#		include <initializer_list>

#		include "DD_move.hpp"
#	endif
#	include "DD_UniquePointer.hpp"
#	include "DD_release.hpp"



DD_BEGIN_
template <typename ValueT_, typename AllocatorT_ = Allocator<ValueT_>>
struct Vessel {
	public:
#	if __cplusplus >= 201103L
	using ThisType = Vessel<ValueT_, AllocatorT_>;
#	else
	typedef Vessel<ValueT_, AllocatorT_> ThisType;
#	endif
	DD_ALIAS(ValueType, ValueT_)
	DD_ALIAS(AllocatorType, AllocatorT_)

	public:
	DD_ALIAS(ReferenceType, ValueType&)
	DD_ALIAS(ConstReferenceType, ValueType const&)
	DD_ALIAS(PointerType, ValueType*)
	DD_ALIAS(ConstPointerType, ValueType const*)
	DD_ALIAS(LengthType, DD::LengthType)


};



template <typename ValueT_>
struct Vessel<ValueT_, Allocator<ValueT_>> {
	public:
	DD_ALIAS(ThisType = Vessel<ValueT_ DD_COMMA Allocator<ValueT_>>);
	DD_ALIAS(ValueType, ValueT_);
	DD_ALIAS(AllocatorType, Allocator<ValueT_>);

	public:
	DD_ALIAS(ReferenceType, ValueType&);
	DD_ALIAS(ConstReferenceType, ValueType const&);
	DD_ALIAS(PointerType, ValueType*);
	DD_ALIAS(ConstPointerType, ValueType const*);


	private:
	PointerType m_begin_ = PointerType();
	PointerType m_end_ = PointerType();
	PointerType m_storage_end_ = PointerType();


	public:
	DD_CONSTEXPR Vessel() = default;

	public:
	Vessel(ThisType const& origin_) DD_NOEXCEPT_IF(false) : m_begin_(origin_.is_empty() ? PointerType() : AllocatorType::allocate(origin_.get_length())), m_end_(m_begin_), m_storage_end_(m_begin_ + origin_.get_length()) {
		throw false;// Unrealized.
	}

#	if __cplusplus >= 201103
	public:
	constexpr Vessel(ThisType&& origin_) noexcept : m_begin_(release(origin_.m_begin_)), m_end_(release(origin_.m_end_)), m_storage_end_(origin_.m_storage_end_) {
	}

	public:
	Vessel(std::initializer_list<ValueType> initializer_) noexcept(false) : m_begin_(initializer_.empty() ? PointerType() : AllocatorType::allocate(initializer_.size())), m_end_(m_begin_), m_storage_end_(m_begin_ + initializer_.size()) {
		for (auto& value_ : initializer_) {
			try {
				AllocatorType::construct(this->m_end_++, move(value_));
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
		return this->m_end_ - this->m_begin_;
	}


	public:
	LengthType DD_CONSTEXPR get_capacity() const DD_NOEXCEPT {
		return this->m_storage_end_ - this->m_begin_;
	}


	public:
	LengthType DD_CONSTEXPR get_space() const DD_NOEXCEPT {
		return this->m_storage_end_ - this->m_end_;
	}


	public:
	LengthType DD_CONSTEXPR is_empty() const DD_NOEXCEPT {
		return this->m_begin_ >= this->m_end_;
	}


	public:
	LengthType DD_CONSTEXPR is_full() const DD_NOEXCEPT {
		return this->m_end_ >= this->m_storage_end_;
	}


	public:
	ProcessType DD_CONSTEXPR clear() const DD_NOEXCEPT {
		AllocatorType::destroy(this->m_begin_, this->m_end_);
		AllocatorType::destruct(this->m_begin_, this->get_capacity());
	}


};



DD_END_



#endif
