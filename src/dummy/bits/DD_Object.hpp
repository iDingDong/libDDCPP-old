//	DDCPP/dummy/bits/DD_Object.hpp
#ifndef DD_OBJECT_HPP_INCLUDED_
#	define DD_OBJECT_HPP_INCLUDED_



#	include "DD_dummy_definitions.hpp"
#	include "../../standard/bits/DD_TypeInfo.hpp"



DD_DETAIL_BEGIN_
struct Object {
	public:
	using ThisType = Object;

	public:
	constexpr Object() = default;

	protected:
	constexpr Object(ThisType const& origin_) = default;

	protected:
	constexpr Object(ThisType&& origin_) = default;


	public:
	virtual ~Object() = default;


	public:
	virtual TypeInfo& get_type() const = 0;


	protected:
	ThisType operator =(ThisType const& origin_) = default;

	protected:
	ThisType operator =(ThisType&& origin_) = default;


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Object;



DD_END_



#endif
