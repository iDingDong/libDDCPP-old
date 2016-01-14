//	DDCPP/standard/bits/experimental/DDLab_Find.hpp
#ifndef DDLAB_FIND_HPP_INCLUDED_
#	define DDLAB_FIND_HPP_INCLUDED_ 1



#	include "DD_experimental_definitions.hpp"



DD_LAB_DETAIL_BEGIN_
struct Find {
	template <typename UndirectionalIteratorT_, typename ValueT_, typename BinaryPredicateT_>
	static UndirectionalIteratorT_ call(
		UndirectionalIteratorT_ begin__,
		UndirectionalIteratorT_ end__,
		ValueT_ value__,
		BinaryPredicateT_ equal__
	) {
		while (begin__ != end__ && !equal__(*begin__, value__) {
			++begin__;
		}
		return begin__;
	}


} DD_CONSTANT find;



DD_LAB_DETAIL_END_



DD_LAB_BEGIN_
using detail_::Find;

using detail_::find;



DD_LAB_END_



#endif
