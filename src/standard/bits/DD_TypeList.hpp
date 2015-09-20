//	DDCPP/standard/bits/DD_TypeList.hpp
#ifndef _DD_TYPE_LIST_HPP_INCLUDED
#	define _DD_TYPE_LIST_HPP_INCLUDED 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::TypeList'.



#	endif
#	include "DD_GetPackBack.hpp"
#	include "DD_ContainedByPack.hpp"



DD_BEGIN
template <typename... _ObjectsT>
struct TypeList {
	public:
	static LengthType constexpr length = 0;


	public:
	template <typename... _ObjectsT_>
	using PushBack = TypeList<_ObjectsT_...>;

	public:
	template <typename... _ObjectsT_>
	using PushFront = TypeList<_ObjectsT_...>;


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
	static LengthType constexpr length = sizeof...(_ObjectsT) + 1;


	public:
	using Front = _ObjectT;
	using Back = GetPackBackType<_ObjectT, _ObjectsT...>;


	public:
	template <typename... _ObjectsT_>
	using PushBack = TypeList<_ObjectsT..., _ObjectsT_...>;

	public:
	template <typename... _ObjectsT_>
	using PushFront = TypeList<_ObjectsT_..., _ObjectsT...>;


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



DD_END



#endif
