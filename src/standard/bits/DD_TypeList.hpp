//	DDCPP/standard/bits/DD_TypeList.hpp
#ifndef _DD_TYPE_LIST_HPP_INCLUDED
#	define _DD_TYPE_LIST_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::TypeList'.



#	endif
#	include "DD_GetPackBack.hpp"
#	include "DD_ContainedByPack.hpp"



_DD_DETAIL_BEGIN
template <typename... _ObjectsT>
struct TypeList;



template <typename _TypeListT1, typename _TypeListT2>
struct _ConcatTypeList;



template <typename... _ObjectsT1, typename... _ObjectsT2>
struct _ConcatTypeList<TypeList<_ObjectsT1...>, TypeList<_ObjectsT2...>> {
	using Type = TypeList<_ObjectsT1..., _ObjectsT2...>;


};



template <typename _TypeListT1, typename _TypeListT2>
using _ConcatTypeListType = typename _ConcatTypeList<_TypeListT1, _TypeListT2>::Type;



template <typename _TypeListT>
struct _RemoveTypeListBack;



template <typename _ObjectT, typename... _ObjectsT>
struct _RemoveTypeListBack<TypeList<_ObjectT, _ObjectsT...>> {
	using Type = _ConcatTypeListType<
		TypeList<_ObjectT>,
		typename _RemoveTypeListBack<TypeList<_ObjectsT...>>::Type
	>;


};



template <typename _ObjectT>
struct _RemoveTypeListBack<TypeList<_ObjectT>> {
	using Type = TypeList<>;


};



template <typename _TypeListT>
using _RemoveTypeListBackType = typename _RemoveTypeListBack<_TypeListT>::Type;



template <typename... _ObjectsT>
struct TypeList {
	public:
	using ThisType = TypeList<_ObjectsT...>;
	static LengthType constexpr length = sizeof...(_ObjectsT);


	public:
	template <typename... _ObjectsT_>
	using PushFront = _ConcatTypeListType<ThisType, TypeList<_ObjectsT_...>>;

	public:
	template <typename... _ObjectsT_>
	using PushBack = _ConcatTypeListType<TypeList<_ObjectsT_...>, ThisType>;

	public:
	template <typename _TypeListT>
	using Concat = _ConcatTypeListType<ThisType, _TypeListT>;

	public:
	using Clear = TypeList<>;


	private:
	template <typename... _ObjectsT_>
	struct Contains : TrueType {
	};


	private:
	template <typename _ObjectT_, typename... _ObjectsT_>
	struct Contains<_ObjectT_, _ObjectsT_...> : FalseType {
	};


	public:
	template <typename... _ObjectsT_>
	static ValidityType constexpr contains() noexcept {
		return Contains<TypeList<_ObjectsT_...>>::value;
	}


};



template <typename _ObjectT, typename... _ObjectsT>
struct TypeList<_ObjectT, _ObjectsT...> {
	public:
	using ThisType = TypeList<_ObjectT, _ObjectsT...>;
	static LengthType constexpr length = TypeList<_ObjectsT...>::length + 1;


	public:
	using Front = _ObjectT;
	using Back = GetPackBackType<_ObjectT, _ObjectsT...>;


	public:
	template <typename... _ObjectsT_>
	using PushFront = _ConcatTypeListType<ThisType, TypeList<_ObjectsT_...>>;

	public:
	template <typename... _ObjectsT_>
	using PushBack = _ConcatTypeListType<TypeList<_ObjectsT_...>, ThisType>;

	public:
	using PopFront = TypeList<_ObjectsT...>;

	public:
	using PopBack = _RemoveTypeListBackType<ThisType>;

	public:
	template <typename _TypeListT>
	using Concat = _ConcatTypeListType<ThisType, _TypeListT>;

	public:
	using Clear = TypeList<>;


	private:
	template <typename... _ObjectsT_>
	struct Contains : TrueType {
	};


	private:
	template <typename _ObjectT_, typename... _ObjectsT_>
	struct Contains<_ObjectT_, _ObjectsT_...> : AndType<
		ContainedByPack<_ObjectT_, _ObjectT, _ObjectsT...>,
		Contains<_ObjectsT_...>
	> {
	};


	public:
	template <typename... _ObjectsT_>
	static ValidityType constexpr contains() noexcept {
		return Contains<TypeList<_ObjectsT_...>>::value;
	}


};



_DD_DETAIL_END



_DD_BEGIN
using _detail::TypeList;



_DD_END



#endif
