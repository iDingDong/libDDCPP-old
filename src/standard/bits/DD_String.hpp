//	DDCPP/standard/bits/DD_String.hpp
#ifndef DD_STRING_HPP_INCLUDED_
#	define DD_STRING_HPP_INCLUDED_ 1



#	include <string>

#	include "DD_get_length.hpp"
#	include "DD_Vessel.hpp"



DD_DETAIL_BEGIN_
template <typename CharactorT_, typename AllocatorT_ = Vessel<CharactorT_>::AllocatorType>
struct String {
	public:
	DD_ALIAS(ThisType, String<CharactorT_, AllocatorT_>);
	DD_ALIAS(CharactorType, CharactorT_);

	public:
	DD_VALUE_TYPE_NESTED(CharactorType);
	DD_ALIAS(StorageType, Vessel<CharactorT_>);
	DD_ALIAS(Iterator, typename StorageType::Iterator);
	DD_ALIAS(ConstIterator, typename StorageType::Iterator);
	DD_ITERATOR_NESTED
	DD_ALIAS(LengthType, typename StorageType::LengthType);

	private:
	StorageType m_storage_;


#	if __cplusplus >= 201103L
	public:
	constexpr String() noexcept(noexcept(StorageType({ '\0' }))) : m_storage_({ '\0' }) {
	}

	public:
	constexpr String(ThisType const& origin_) = default;

	public:
	constexpr String(ThisType&& origin_) = default;
#	else
	public:
	String() : m_storage_(1, '\0') {
	}
#	endif

	public:
	DD_CONSTEXPR String(char const* cstring_) DD_NOEXCEPT_AS(
		StorageType(range_tag DD_COMMA cstring_ DD_COMMA get_length(cstring_) + 1)
	) : m_storage_(range_tag, cstring_, get_length(cstring_) + 1) {
	}

	public:
	DD_CONSTEXPR String(std::string const& string_) DD_NOEXCEPT_AS(
		StorageType(string_.c_str() DD_COMMA get_length(string_.c_str()) + 1)
	) m_storage_(string_.c_str(), get_length(string_.c_str()) + 1) {
	}


#	if __cplusplus >= 201103L
	public:
	~String() = default;


#	endif


	public:
	StorageType& get_storage() DD_NOEXCEPT {
		return m_storage_;
	}

	public:
	StorageType const& get_storage() const DD_NOEXCEPT {
		return m_storage_;
	}


	public:
	Iterator begin() DD_NOEXCEPT {
		return get_storage().begin();
	}

	public:
	ConstIterator begin() const DD_NOEXCEPT {
		return get_storage().begin();
	}


	public:
	Iterator end() DD_NOEXCEPT {
		return get_storage().end() - 1;
	}

	public:
	ConstIterator end() const DD_NOEXCEPT {
		return get_storage().end() - 1;
	}


	public:
	LengthType get_length() const DD_NOEXCEPT {
		return get_storage().get_length() - 1;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType operator =(ThisType const& origin_) = default;

	public:
	ThisType operator =(ThisType&& origin_) = default;


#	endif
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::String;



DD_END_



#endif
