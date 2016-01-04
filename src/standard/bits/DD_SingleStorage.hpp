//	DDCPP/standard/bits/DD_SingleStorage.hpp
#ifndef DD_SINGLE_STORAGE_HPP_INCLUDED_
#	define DD_SINGLE_STORAGE_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::SingleStorage'.



#	endif
#	include "DD_ValueTypeNested.hpp"
#	include "DD_AlignmentOf.hpp"
#	include "DD_AlignedStorage.hpp"
#	include "DD_construct.hpp"
#	include "DD_destruct.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
struct SingleStorage {
	public:
	using ThisType = SingleStorage<ValueT_>;
	DD_VALUE_TYPE_NESTED(ValueT_)

	public:
	using StorageType = AlignedStorageType<sizeof(ValueType), AlignmentOf<ValueType>::value>;


	private:
	StorageType m_storage_;


	public:
	constexpr SingleStorage() = default;

	public:
	DD_DELETE_COPY_CONSTRUCTOR(SingleStorage)

	public:
	DD_DELETE_MOVE_CONSTRUCTOR(SingleStorage)


	public:
	~SingleStorage() = default;


	public:
	PointerType get_pointer() noexcept {
		static_cast<PointerType>(::DD::address_of(m_storage_));
	}

	public:
	ConstPointerType get_pointer() const noexcept {
		static_cast<ConstPointerType>(::DD::address_of(m_storage_));
	}


	public:
	template <typename... ArgumentsT__>
	ProcessType construct(ArgumentsT__&&... arguments___) noexcept(noexcept(
		::DD::construct(::DD::fabricate<ThisType>().get_pointer() DD_COMMA ::DD::forward<ArgumentsT__>(arguments___)...)
	)) {
		::DD::construct(get_pointer(), ::DD::forward<ArgumentsT__>(arguments___)...);
	}


	public:
	ProcessType destruct() noexcept {
		::DD::destruct(get_pointer());
	}


	public:
	DD_DELETE_ALL_ASSIGNMENTS(SingleStorage)


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::SingleStorage;



DD_END_



#endif
