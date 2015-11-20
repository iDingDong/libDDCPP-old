//	DDCPP/standard/bits/DD_CharactorClassification.hpp
#ifndef DD_CHARACTOR_CLASSIFICATION_HPP_INCLUDED_
#	define DD_CHARACTOR_CLASSIFICATION_HPP_INCLUDED_ 1



#	include <locale>

#	include "DD_Trait.hpp"
#	include "DD_ValueTypeNested.hpp"



DD_DETAIL_BEGIN_
template <typename CharactorT_>
struct CharactorClassification : Trait<CharactorT_> {
	public:
	DD_ALIAS(SuperType, Trait<CharactorT_>)
	DD_ALIAS(ThisType, CharactorClassification<CharactorT_>);
	DD_ALIAS(CharactorType, CharactorT_);

	public:
	DD_VALUE_TYPE_NESTED(CharactorType);


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
