//	DDCPP/standard/bits/DD_Tags.hpp
#ifndef DD_TAGS_HPP_INCLUDED_
#	define DD_TAGS_HPP_INCLUDED_ 1



#	include "DD_global_definitions.hpp"



DD_DETAIL_BEGIN_
struct Tag {
} DD_CONSTANT tag;



struct DefaultTag : Tag {
} DD_CONSTANT default_tag;



struct ConstructTag : Tag {
} DD_CONSTANT construct_tag;



struct UnguardedTag : Tag {
} DD_CONSTANT unguarded_tag;



struct BatchTag : Tag {
} DD_CONSTANT batch_tag;



struct ReserveTag : Tag {
} DD_CONSTANT reserve_tag;



DD_DETAIL_END_



DD_BEGIN_
using detail_::Tag;
using detail_::DefaultTag;
using detail_::ConstructTag;
using detail_::UnguardedTag;
using detail_::BatchTag;
using detail_::ReserveTag;

using detail_::tag;
using detail_::default_tag;
using detail_::construct_tag;
using detail_::unguarded_tag;
using detail_::batch_tag;
using detail_::reserve_tag;



DD_END_



#endif
