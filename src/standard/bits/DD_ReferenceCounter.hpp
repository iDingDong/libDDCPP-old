//	DDCPP/standard/bits/DD_ReferenceCounter.hpp
#ifndef DD_REFERENCE_COUNTER_HPP_INCLUDED_
#	define DD_REFERENCE_COUNTER_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
struct ReferenceCounter {
	public:
	DD_ALIAS(ThisType, ReferenceCounter);

	public:
	DD_ALIAS(LengthType, ::DD::LengthType);


	public:
	Pair<LengthType> m_reference_count_;


	public:
	Pair<LengthType> const& get_reference_count() const DD_NOEXCEPT {
		return m_reference_count_;
	}


	public:
	LengthType get_strong_reference_count() const DD_NOEXCEPT {
		return get_reference_count().first;
	}


	public:
	LengthType get_weak_reference_count() const DD_NOEXCEPT {
		return get_reference_count().second;
	}


	public:
	ValidityType is_unique_strong_reference() const DD_NOEXCEPT {
		return get_strong_reference_count() == LengthType(1);
	}


	public:
	ValidityType is_unique_weak_reference() const DD_NOEXCEPT {
		return get_weak_reference_count() == LengthType(1);
	}


	public:
	ValidityType has_strong_reference() const DD_NOEXCEPT {
		return get_strong_reference_count();
	}


	public:
	ValidityType has_weak_reference() const DD_NOEXCEPT {
		return get_weak_reference_count();
	}


	public:
	ValidityType is_expired() const DD_NOEXCEPT {
		return !has_strong_reference();
	}


	public:
	ProcessType strongly_referred() DD_NOEXCEPT {
		++m_reference_count_.first;
	}


	public:
	ProcessType weakly_referred() DD_NOEXCEPT {
		++m_reference_count_.second;
	}


	public:
	ProcessType strongly_released() DD_NOEXCEPT {
		--m_reference_count_.first;
	}


	public:
	ProcessType weakly_released() DD_NOEXCEPT {
		--m_reference_count_.second;
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::ReferenceCounter;



DD_END_



#endif
