//	DDCPP/standard/bits/DD_Tags.hpp
#ifndef DD_TAGS_HPP_INCLUDED_
#	define DD_TAGS_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_BEGIN_
struct Tag {
} DD_CONSTANT tag;



struct DefaultTag : Tag {
} DD_CONSTANT default_tag;



struct ConstructTag : Tag {
} DD_CONSTANT construct_tag;



DD_END_



#endif
