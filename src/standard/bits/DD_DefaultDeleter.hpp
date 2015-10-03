//	DDCPP/standard/bits/DD_DefualtDeleter.hpp
#ifndef DD_DEFAULT_DELETER_HPP_INCLUDED_
#	define DD_DEFAULT_DELETER_HPP_INCLUDED_ 1



#	include "DD_Deleter.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_>
class DefaultDeleter {
	public:
	DD_ALIAS(ThisType, DefaultDeleter<ValueT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)


#	if __cplusplus >= 201103L
	public:
	constexpr DefaultDeleter() = default;

	public:
	constexpr DefaultDeleter(ThisType const& origin_) = default;

	public:
	constexpr DefaultDeleter(ThisType&& origin_) = default;


#	endif
	public:
	ProcessType operator ()(ValueType* pointer_) DD_NOEXCEPT {
		destroy(pointer_);
	}


	public:
	static ProcessType destroy(ValueType* pointer_) DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type.");
		delete pointer_;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



template <typename ValueT_>
class DefaultDeleter<ValueT_[]> {
	public:
	DD_ALIAS(ThisType, DefaultDeleter<ValueT_[]>);
	DD_VALUE_TYPE_NESTED(ValueT_)


#	if __cplusplus >= 201103L
	public:
	constexpr DefaultDeleter() = default;

	public:
	constexpr DefaultDeleter(ThisType const& origin_) = default;

	public:
	constexpr DefaultDeleter(ThisType&& origin_) = default;


#	endif
	public:
	ProcessType operator ()(ValueType* pointer_) DD_NOEXCEPT {
		destroy(pointer_);
	}


	public:
	static ProcessType destroy(ValueType* pointer_) DD_NOEXCEPT {
		DD_STATIC_ASSERT(sizeof(ValueType) > 0, "Cannot delete a pointer to an imcomplete type.");
		delete[] pointer_;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::DefaultDeleter;



DD_END_



#endif
