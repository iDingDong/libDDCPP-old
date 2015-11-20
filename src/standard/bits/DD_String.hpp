//	DDCPP/standard/bits/DD_String.hpp
#ifndef DD_STRING_HPP_INCLUDED_
#	define DD_STRING_HPP_INCLUDED_ 1



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

	private:
	StorageType m_storage_;


#	if __cplusplus >= 201103L
	public:
	constexpr String() = default;

	public:
	constexpr String(ThisType const& origin_) = default;

	public:
	constexpr String(ThisType&& origin_) = default;
#	else
	public:
	String() {
	}
#	endif

	public:
	DD_CONSTEXPR String(char const* cstring_) DD_NOEXCEPT_AS(
		StorageType(range_tag DD_COMMA cstring_ DD_COMMA get_length(cstring_) + 1)
	) : m_storage_(range_tag, cstring_, get_length(cstring_) + 1) {
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::String;



DD_END_



#endif
