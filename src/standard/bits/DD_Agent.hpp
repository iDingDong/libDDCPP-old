//	DDCPP/standard/bits/DD_Agent.hpp
#ifndef DD_AGENT_HPP_INCLUDED_
#	define DD_AGENT_HPP_INCLUDED_ 1



#	include "DD_NeedInstance.hpp"



DD_DETAIL_BEGIN_
template <typename InstanceT_, ValidityType need_instance_c_>
struct Agent_ {
	public:
	DD_ALIAS(ThisType, Agent_<InstanceT_ DD_COMMA need_instance_c_>);
	DD_ALIAS(InstanceType, InstanceT_);
	static ValidityType DD_CONSTANT need_instance = need_instance_c_;


#	if __cplusplus >= 201103L
	public:
	constexpr Agent_() = default;

	public:
	constexpr Agent_(ThisType const& origin_) = default;

	public:
	constexpr Agent_(ThisType&& origin_) = default;
#	else
	public:
	Agent_() throw() {
	}
#	endif

	public:
	DD_CONSTEXPR Agent_(InstanceType const& instance_) DD_NOEXCEPT {
	}


#	if __cplusplus >= 201103L
	public:
	~Agent_() = default;


#	endif
	public:
	static InstanceType& get_instance() DD_NOEXCEPT_AS(InstanceType()) {
		static InstanceType instance_;
		return instance_;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



template <typename InstanceT_>
struct Agent_<InstanceT_, true> {
	public:
	DD_ALIAS(ThisType, Agent_<InstanceT_ DD_COMMA true>);
	DD_ALIAS(InstanceType, InstanceT_);
	static ValidityType DD_CONSTANT need_instance = true;


	private:
	InstanceType mutable m_instance_;


#	if __cplusplus >= 201103L
	public:
	constexpr Agent_() = default;

	public:
	constexpr Agent_(ThisType const& origin_) = default;

	public:
	constexpr Agent_(ThisType&& origin_) = default;
#	else
	public:
	Agent_() {
	}
#	endif

	public:
	DD_CONSTEXPR Agent_(InstanceType const& instance_) : m_instance_(instance_) {
	}


#	if __cplusplus >= 201103L
	public:
	~Agent_() = default;


#	endif
	public:
	InstanceType& get_instance() const DD_NOEXCEPT {
		return m_instance_;
	}


#	if __cplusplus >= 201103L
	public:
	ThisType& operator =(ThisType const& origin_) = default;

	public:
	ThisType& operator =(ThisType&& origin_) = default;


#	endif
};



template <typename InstanceT_>
struct Agent : Agent_<InstanceT_, NeedInstance<InstanceT_>::value> {
	public:
	DD_ALIAS(SuperType, Agent_<InstanceT_ DD_COMMA NeedInstance<InstanceT_>::value>);
	DD_ALIAS(ThisType, Agent<InstanceT_>);
	DD_ALIAS(InstanceType, InstanceT_);


#	if __cplusplus >= 201103L
	public:
	using SuperType::SuperType;
#	else
	public:
	Agent() {
	}

	public:
	Agent(InstanceType const& instance_) : SuperType(instance_) {
	}
#	endif


};



DD_DETAIL_END_



DD_BEGIN_
using detail_::Agent;



DD_END_



#endif
