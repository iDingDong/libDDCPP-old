//	DDCPP/standard/bits/DD_BinaryOperators.hpp
#ifndef DD_BINARY_OPERATORS_HPP_INCLUDED_
#	define DD_BINARY_OPERATORS_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



#	define DD_BINARY_OPERATOR(ARG_Operator_, ARG_symbol_)\
	template <typename MACRO_ObjectT1_, typename MACRO_ObjectT2_ = MACRO_ObjectT1_>\
	struct ARG_Operator_ {\
		DD_ALIAS(Type1, MACRO_ObjectT1_);\
		DD_ALIAS(Type2, MACRO_ObjectT2_);\
		\
		\
		friend Type1 operator ARG_symbol_(\
			Type1 const& object_1_,\
			Type2 const& object_2_\
		) DD_NOEXCEPT_AS(const_cast<Type1>(object_1_ ARG_symbol_##= object_2_) DD_COMMA Type1(object_1_)) {\
			Type1 temp_(object_1_);\
			temp_ ARG_symbol_##= object_2_;\
			return temp_;\
		}\
		\
		\
	};



DD_BEGIN_
DD_BINARY_OPERATOR(Addable, +)
DD_BINARY_OPERATOR(Subtractable, -)
DD_BINARY_OPERATOR(Multipliable, *)
DD_BINARY_OPERATOR(Dividable, /)
DD_BINARY_OPERATOR(Modable, %)
DD_BINARY_OPERATOR(Orable, |)
DD_BINARY_OPERATOR(Andable, &)



DD_END_



#	undef DD_BINARY_OPERATOR



#endif
