//	DDCPP/standard/bits/DD_Agent.hpp
#ifndef DD_AGENT_HPP_INCLUDED_
#	define DD_AGENT_HPP_INCLUDED_ 1



#	include "DD_NeedInstance.hpp"



DD_DETAIL_BEGIN_
template <typename InstanceT_, ValidityType need_instance_c_>
struct Agent_ {
	protected:
	DD_ALIAS(ThisType, CallableDependent_<FunctionT_ DD_COMMA need_instance_c_>);
	DD_ALIAS(InstanceType, InstanceT_);
	static ValidityType DD_CONSTANT need_instance = need_instance_c_;


#	if __cplusplus >= 201103L
	protected:
	constexpr Agent_() = default;

	protected:
	constexpr Agent_(ThisType const& origin_) = default;

	protected:
	constexpr Agent_(ThisType&& origin_) = default;
#	else
	protected:
	Agent_() throw() {
	}
#	endif

	protected:
	DD_CONSTEXPR Agent_(InstanceType const& instance_) DD_NOEXCEPT {
	}


#	if __cplusplus >= 201103L
	protected:
	~Agent_() = default;


#	endif
	protected:
	static InstanceType& get_instance() DD_NOEXCEPT_AS(InstanceType()) {
		static InstanceType instance_;
		return instance_;
	}


#	if __cplusplus >= 201103L
	protected:
	ThisType& operator =(ThisType const& origin_) = default;

	protected:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



template <typename InstanceT_>
struct Agent_<InstanceT_, true> {
	protected:
	DD_ALIAS(ThisType, CallableDependent_<FunctionT_ DD_COMMA true>);
	DD_ALIAS(InstanceType, InstanceT_);
	static ValidityType DD_CONSTANT need_instance = true;


	private:
	InstanceType mutable m_instance_;


#	if __cplusplus >= 201103L
	protected:
	constexpr Agent_() = default;

	protected:
	constexpr Agent_(ThisType const& origin_) = default;

	protected:
	constexpr Agent_(ThisType&& origin_) = default;
#	else
	protected:
	Agent_() {
	}
#	endif

	protected:
	DD_CONSTEXPR Agent_(InstanceType const& instance_) : m_instance_(instance_) {
	}


#	if __cplusplus >= 201103L
	protected:
	~Agent_() = default;


#	endif
	protected:
	static InstanceType& get_instance() const DD_NOEXCEPT {
		return m_instance_;
	}


#	if __cplusplus >= 201103L
	protected:
	ThisType& operator =(ThisType const& origin_) = default;

	protected:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Agent;



DD_END_



#endif
