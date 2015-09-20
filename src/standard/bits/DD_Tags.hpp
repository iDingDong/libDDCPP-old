//	DDCPP/standard/bits/DD_Tags.hpp
#ifndef _DD_TAGS_HPP_INCLUDED
#	define _DD_TAGS_HPP_INCLUDED 1



#	include "DD_global_definitions.hpp"



DD_BEGIN
struct Tag {
} DD_CONSTANT tag;



struct DefaultTag : Tag {
} DD_CONSTANT default_tag;



struct ConstructTag : Tag {
} DD_CONSTANT construct_tag;



DD_END



#endif
