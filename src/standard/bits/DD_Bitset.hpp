//	DDCPP/standard/bits/DD_Bitset.hpp
#ifndef DD_BITSET_HPP_INCLUDED_
#	define DD_BITSET_HPP_INCLUDED_ 1



#	include <cstring>

#	include "DD_ArithmeticLimit.hpp"
#	include "DD_Array.hpp"



DD_DETAIL_BEGIN_
template <LengthType length_c_>
struct Bitset_ {
	protected:
	DD_ALIAS(ThisType, Bitset_<length_c_>);
	static DD_CONSTEXPR LengthType length = length_c_;

	protected:
	DD_ALIAS(WordType_, unsigned long int);


	private:
	Array<WordType_, length> m_words_ DD_IN_CLASS_INITIALIZE({});


#	if __cplusplus >= 201103L
	protected:
	constexpr Bitset_() = default;

	protected:
	constexpr Bitset_(ThisType const& origin_) = default;

	protected:
	constexpr Bitset_(ThisType&& origin_) = default;
#	else
	protected:
	Bitset_() : m_words_{} {
	}
#	endif


#	if __cplusplus >= 201103L
	public:
	~Bitset_() = default;


#	endif
	public:
	ProcessType bit_and(ThisType const& other_) DD_NOEXCEPT {
		for (LengthType current_ = 0; current_ < length; ++current_) {
			m_words_[current_] &= other_.m_words_[current_];
		}
	}


	public:
	ProcessType bit_or(ThisType const& other_) DD_NOEXCEPT {
		for (LengthType current_ = 0; current_ < length; ++current_) {
			m_words_[current_] |= other_.m_words_[current_];
		}
	}


	public:
	ProcessType clear() DD_NOEXCEPT {
		std::memset(m_words_, 0, sizeof(m_words_));
	}


#	if __cplusplus >= 201103L
	protected:
	ThisType& operator =(ThisType const& origin_) = default;

	protected:
	ThisType& operator =(ThisType&& origin_) = default;

#	endif

	public:
	ThisType& operator &=(ThisType const& other_) DD_NOEXCEPT {
		bit_and(other_);
		return *this;
	}


	public:
	ThisType& operator |=(ThisType const& other_) DD_NOEXCEPT {
		bit_or(other_);
		return *this;
	}


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
