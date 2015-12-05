//	DDCPP/standard/bits/DD_ConstantList.hpp
#ifndef DD_CONSTANT_LIST_HPP_INCLUDED_
#	define DD_CONSTANT_LIST_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for 'DD::ConstantList'.



#	endif
#	include "DD_ValueTypeNested.hpp"
#	include "DD_StaticConcatenate.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, ValueT_... values_c__>
struct ConstantList;



template <typename ValueT_, ValueT_... values_c_1__, ValueT_... values_c_2__>
struct StaticConcatenate<ConstantList<ValueT_, values_c_1__...>, ConstantList<ValueT_, values_c_2__...>> {
	using Type = ConstantList<ValueT_, values_c_1__..., values_c_2__...>;


};



template <typename ValueT_, ValueT_... values_c__>
struct ConstantList {
	public:
	using ThisType = ConstantList<ValueT_, values_c__...>;
	DD_VALUE_TYPE_NESTED(ValueT_)


	template <ValueType... values_c___>
	using PushFront = ConstantList<ValueT_, values_c__..., values_c___...>;

	public:
	template <ValueType... values_c___>
	using PushBack = ConstantList<ValueT_, values_c__..., values_c___...>;

	public:
	template <typename ConstantListT_>
	using Concatenate = StaticConcatenateType<ThisType, ConstantListT_>;


};



template <typename ValueT_, ValueT_ begin__, ValueT_ end__, ValueT_ step__ = 1>
struct GenerateConstantArithmeticProgression {
	using Type = typename ConstantList<ValueT_, begin__>::template Concatenate<
		typename GenerateConstantArithmeticProgression<ValueT_, begin__ + step__, end__, step__>::Type
	>;


};



template <typename ValueT_, ValueT_ value__, ValueT_ step__>
struct GenerateConstantArithmeticProgression<ValueT_, value__, value__, step__> {
	using Type = ConstantList<ValueT_>;


};



template <typename ValueT_, ValueT_ begin__, ValueT_ end__, ValueT_ step__ = 1>
using GenerateConstantArithmeticProgressionType = typename GenerateConstantArithmeticProgression<
	ValueT_, begin__, end__, step__
>::Type;



template <typename ValueT_, ValueT_ begin__, ValueT_ end__, ValueT_ step__ = 2>
struct GenerateConstantGeometricProgression {
	using Type = typename ConstantList<ValueT_, begin__>::template Concatenate<
		typename GenerateConstantGeometricProgression<ValueT_, begin__ * step__, end__, step__>::Type
	>;


};



template <typename ValueT_, ValueT_ value__, ValueT_ step__>
struct GenerateConstantGeometricProgression<ValueT_, value__, value__, step__> {
	using Type = ConstantList<ValueT_>;


};



template <typename ValueT_, ValueT_ begin__, ValueT_ end__, ValueT_ step__ = 2>
using GenerateConstantGeometricProgressionType = typename GenerateConstantGeometricProgression<
	ValueT_, begin__, end__, step__
>::Type;



DD_DETAIL_END_



DD_BEGIN_
using detail_::ConstantList;
using detail_::GenerateConstantArithmeticProgression;
using detail_::GenerateConstantArithmeticProgressionType;
using detail_::GenerateConstantGeometricProgression;
using detail_::GenerateConstantGeometricProgressionType;



DD_END_



#endif
