//	DDCPP/standard/bits/DD_TypeList.hpp
#ifndef DD_TYPE_LIST_HPP_INCLUDED_
#	define DD_TYPE_LIST_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::TypeList'.



#	endif
#	include "DD_GetPackBack.hpp"
#	include "DD_ContainedByPack.hpp"



DD_DETAIL_BEGIN_
template <typename... ObjectsT_>
struct TypeList;



template <typename TypeListT1_, typename TypeListT2_>
struct ConcatTypeList_;



template <typename... ObjectsT1_, typename... ObjectsT2_>
struct ConcatTypeList_<TypeList<ObjectsT1_...>, TypeList<ObjectsT2_...>> {
	using Type = TypeList<ObjectsT1_..., ObjectsT2_...>;


};



template <typename TypeListT1_, typename TypeListT2_>
using ConcatTypeListType_ = typename ConcatTypeList_<TypeListT1_, TypeListT2_>::Type;



template <typename TypeListT_>
struct RemoveTypeListBack_;



template <typename ObjectT_, typename... ObjectsT_>
struct RemoveTypeListBack_<TypeList<ObjectT_, ObjectsT_...>> {
	using Type = ConcatTypeListType_<
		TypeList<ObjectT_>,
		typename RemoveTypeListBack_<TypeList<ObjectsT_...>>::Type
	>;


};



template <typename ObjectT_>
struct RemoveTypeListBack_<TypeList<ObjectT_>> {
	using Type = TypeList<>;


};



template <typename TypeListT_>
using RemoveTypeListBackType_ = typename RemoveTypeListBack_<TypeListT_>::Type;



template <typename... ObjectsT_>
struct TypeList {
	public:
	using ThisType = TypeList<ObjectsT_...>;
	static LengthType constexpr length = sizeof...(ObjectsT_);


	public:
	template <typename... ObjectsT__>
	using PushFront = ConcatTypeListType_<ThisType, TypeList<ObjectsT__...>>;

	public:
	template <typename... ObjectsT__>
	using PushBack = ConcatTypeListType_<TypeList<ObjectsT__...>, ThisType>;

	public:
	template <typename TypeListT_>
	using Concat = ConcatTypeListType_<ThisType, TypeListT_>;

	public:
	using Clear = TypeList<>;


	private:
	template <typename... ObjectsT__>
	struct Contains : TrueType {
	};


	private:
	template <typename ObjectT__, typename... ObjectsT__>
	struct Contains<ObjectT__, ObjectsT__...> : FalseType {
	};


	public:
	template <typename... ObjectsT__>
	static ValidityType constexpr contains() noexcept {
		return Contains<TypeList<ObjectsT__...>>::value;
	}


};



template <typename ObjectT_, typename... ObjectsT_>
struct TypeList<ObjectT_, ObjectsT_...> {
	public:
	using ThisType = TypeList<ObjectT_, ObjectsT_...>;
	static LengthType constexpr length = TypeList<ObjectsT_...>::length + 1;


	public:
	using Front = ObjectT_;
	using Back = GetPackBackType<ObjectT_, ObjectsT_...>;


	public:
	template <typename... ObjectsT__>
	using PushFront = ConcatTypeListType_<ThisType, TypeList<ObjectsT__...>>;

	public:
	template <typename... ObjectsT__>
	using PushBack = ConcatTypeListType_<TypeList<ObjectsT__...>, ThisType>;

	public:
	using PopFront = TypeList<ObjectsT_...>;

	public:
	using PopBack = RemoveTypeListBackType_<ThisType>;

	public:
	template <typename TypeListT_>
	using Concat = ConcatTypeListType_<ThisType, TypeListT_>;

	public:
	using Clear = TypeList<>;


	private:
	template <typename... ObjectsT__>
	struct Contains : TrueType {
	};


	private:
	template <typename ObjectT__, typename... ObjectsT__>
	struct Contains<ObjectT__, ObjectsT__...> : AndType<
		ContainedByPack<ObjectT__, ObjectT_, ObjectsT_...>,
		Contains<ObjectsT__...>
	> {
	};


	public:
	template <typename... ObjectsT__>
	static ValidityType constexpr contains() noexcept {
		return Contains<TypeList<ObjectsT__...>>::value;
	}


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::TypeList;



DD_END_



#endif
