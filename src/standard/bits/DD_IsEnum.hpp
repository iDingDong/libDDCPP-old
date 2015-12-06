//	DDCPP/standard/bits/DD_IsEnum.hpp
#ifndef DD_IS_ENUM_HPP_INCLUDED_
#	define DD_IS_ENUM_HPP_INCLUDED_ 1



#	if __cplusplus < 201103L
#		error ISO/IEC 14882:2011 or a later version support is required for'DD::IsEnum'.



#	endif
#	include <type_traits>

#	include "DD_And.hpp"



DD_DETAIL_BEGIN_
template <typename... ObjectsT_>
struct IsEnum : AndType<IsEnum<ObjectsT_>...> {
};



template <typename ObjectT_>
struct IsEnum<ObjectT_> : StdBoolConstant<std::is_enum<ObjectT_>> {
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::IsEnum;



DD_END_



#endif
