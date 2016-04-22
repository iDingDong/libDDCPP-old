//	DDCPP/console/bits/DD_console_Color.hpp
#ifndef DD_CONSOLE_COLOR_HPP_INCLUDED_
#	define DD_CONSOLE_COLOR_HPP_INCLUDED_ 1



#	include <standard/bits/DD_BuildInTypes.hpp>
#	include <standard/bits/DD_ValueTypeNested.hpp>
#	include <standard/bits/DD_EqualityComparable.hpp>

#	include "DD_console_definitions.hpp"



DD_CONSOLE_DETAIL_BEGIN_
struct Color : EqualityComparable<Color> {
	public:
	using ThisType = Color;
	DD_VALUE_TYPE_NESTED(ValidityType);


	public:
	template <UnsignedInt8Type position_>
	struct ValueProxy {
		public:
		using ThisType = ValueProxy;


		public:
		friend Color;


		private:
		Color* const m_pointer_;


		private:
		DD_DELETE_DEFAULT_CONSTRUCTOR(ValueProxy);


		private:
		DD_DELETE_COPY_CONSTRUCTOR(ValueProxy);


		private:
		ValueProxy(ThisType&& origin_) = default;


		private:
		ValueProxy(Color* pointer_) noexcept : m_pointer_(pointer_) {
		}


		public:
		DD_DELETE_ALL_ASSIGNMENTS(ValueProxy);


		public:
		ThisType& operator =(ValueType bit_value_) noexcept {
			m_pointer_->value & (bit_value_ << position_);
		}


		public:
		operator ValueType() const noexcept {
			return m_pointer_->value & (1 << position_);
		}


	};


	public:
	UnsignedInt8Type value = UnsignedInt8Type();


	public:
	constexpr Color() = default;

	public:
	constexpr Color(ThisType const& origin_) = default;

	public:
	constexpr Color(ThisType&& origin_) = default;

	public:
	constexpr Color(ValueType r_, ValueType g_, ValueType b_) noexcept : value(
		(UnsignedInt8Type(r_) << 2U) | (UnsignedInt8Type(g_) << 1U) | UnsignedInt8Type(b_)
	) {
	}


	public:
	static ValidityType constexpr equal(
		ThisType const& color_1_, ThisType const& color_2_
	) noexcept {
		return color_1_.value == color_2_.value;
	}


	public:
	ValueProxy<2> r() noexcept {
		return ValueProxy<2>(this);
	}

	public:
	ValueType constexpr r() const noexcept {
		return value & 0x04U;
	}


	public:
	ValueType constexpr g() const noexcept {
		return value & 0x02U;
	}

	public:
	ValueProxy<1> g() noexcept {
		return ValueProxy<1>(this);
	}


	public:
	ValueType constexpr b() const noexcept {
		return value & 0x01U;
	}

	public:
	ValueProxy<0> b() noexcept {
		return ValueProxy<0>(this);
	}


	public:
	static ThisType constexpr black() noexcept {
		return Color(0, 0, 0);
	}


	public:
	static ThisType constexpr red() noexcept {
		return Color(1, 0, 0);
	}


	public:
	static ThisType constexpr green() noexcept {
		return Color(0, 1, 0);
	}


	public:
	static ThisType constexpr blue() noexcept {
		return Color(0, 0, 1);
	}


	public:
	static ThisType constexpr yellow() noexcept {
		return Color(1, 1, 0);
	}


	public:
	static ThisType constexpr cyan() noexcept {
		return Color(0, 1, 1);
	}


	public:
	static ThisType constexpr magenta() noexcept {
		return Color(1, 0, 1);
	}


	public:
	static ThisType constexpr white() noexcept {
		return Color(1, 1, 1);
	}


};



inline ValidityType constexpr operator ==(
	Color const& color_1_, Color const& color_2_
) noexcept {
	return Color::equal(color_1_, color_2_);
}



DD_CONSOLE_DETAIL_END_



DD_CONSOLE_BEGIN_
using ::DD::console::detail_::Color;



DD_CONSOLE_END_



#endif
