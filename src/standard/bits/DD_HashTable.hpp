//	DDCPP/standard/bits/DD_HashTable.hpp
#ifndef DD_HASH_TABLE_HPP_INCLUDED_
#	define DD_HASH_TABLE_HPP_INCLUDED_ 1



#	include "DD_HashOf.hpp"
#	include "DD_EqualTo.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_Array.hpp"
#	include "DD_UndirectionalList.hpp"



#	if !defined(DDCPP_HASH_TABLE_CHART)
#		define DDCPP_HASH_TABLE_CHART ::DD::detail_::DefaultHashTableChart
#	endif



DD_DETAIL_BEGIN_
Array<LengthType, 14> DD_CONSTANT DefaultHashTableChart = {
	0, 7, 13, 23, 53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593
};



DD_STATIC_ASSERT((DDCPP_HASH_TABLE_CHART)[0U] == 0U, "Growth of hash table should begin with 0.");



template <
	typename ValueT_,
	typename HasherT_ = HashOf<ValueT_>,
	typename EqualityPredicateT_ = EqualTo<ValueT_>,
	typename AllocatorT_ = Allocator<ValueT_>
>
struct HashTable : Agent<HasherT_>, Agent<EqualityPredicateT_> {
	public:
	DD_ALIAS(HashAgent, Agent<HasherT_>);
	DD_ALIAS(CompareAgent, Agent<EqualityPredicateT_>);
	DD_ALIAS(ThisType, HashTable<ValueT_ DD_COMMA HasherT_ DD_COMMA EqualityPredicateT_ DD_COMMA AllocatorT_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	DD_ALIAS(HasherType, HasherT_);
	DD_ALIAS(EqualityPredicateType, EqualityPredicateT_);
	DD_ALIAS(AllocatorType, AllocatorT_);

	public:
	DD_ALIAS(SizeType, ::DD::SizeType);
	DD_ALIAS(LengthType, ::DD::LengthType);
	DD_ALIAS(HashValueType, ::DD::HashValueType);

	private:
	DD_SPECIFIC_TYPE_NESTED(Storage, UndirectionalList<ValueType DD_COMMA AllocatorType>);
	DD_SPECIFIC_TYPE_NESTED(Node, typename StorageType::NodeType);
	DD_ALIAS(NonConstIterator_, typename StorageType::Iterator);
	DD_SPECIFIC_TYPE_NESTED(Bucket, NonConstIterator_);

	public:
	DD_ALIAS(Iterator, typename StorageType::ConstIterator);
	DD_ALIAS(ConstIterator, Iterator);


	private:
	StorageType m_storage_;
	BucketPointerType m_buckets_ DD_IN_CLASS_INITIALIZE(BucketPointerType());
	LengthType m_growth_progress_ DD_IN_CLASS_INITIALIZE(LengthType());
	LengthType m_length_ DD_IN_CLASS_INITIALIZE(LengthType());


	private:
	StorageReferenceType get_storage_() DD_NOEXCEPT {
		return m_storage_;
	}


	private:
	StorageConstReferenceType get_storage_() const DD_NOEXCEPT {
		return m_storage_;
	}


	private:
	BucketPointerType get_buckets_() const DD_NOEXCEPT {
		return m_buckets_;
	}


	private:
	LengthType DD_CONSTEXPR get_bucket_quantity_() const DD_NOEXCEPT {
		return (DDCPP_HASH_TABLE_CHART)[m_growth_progress_];
	}


	public:
	LengthType DD_CONSTEXPR get_length() DD_NOEXCEPT {
		return m_length_;
	}


	public:
	HashValueType hash(ValueType const& value_) {
		return HashAgent::get_instance()(value_);
	}


	private:
	LengthType find_previous_bucket_offset_(ValueType const& value_) const {
		return hash(value_) % get_bucket_quantity_();
	}


	private:
	LengthType find_bucket_offset_(ValueType const& value_) const {
		return find_previous_bucket_offset_() + 1;
	}


	private:
	BucketPointerType find_previous_bucket_(ValueType const& value_) const {
		return get_buckets_() + find_previous_bucket_offset_(value_);
	}


	private:
	BucketPointerType find_bucket_(ValueType const& value_) const {
		return get_buckets_() + find_bucket_offset_(value_);
	}


	public:
	NonConstIterator_ find_(ValueType const& value_) const {
		BucketPointerType previous_bucket_ = find_previous_bucket_(value_);
		NonConstIterator_ result_ = ::DD::find(::DD::next(*previous_bucket_), ::DD::next(*(previous_bucket_ + 1)), value_);
		return result_ == ::DD::next(*(previous_bucket_ + 1)) ? end() : result_;
	}


	public:
	Iterator find(ValueType const& value_) const {
		return find_(value_);
	}


	public:
	ProcessType fix_after_insertion_(BucketPointerType target_bucket_) {
		LengthType bucket_quantity_ = get_bucket_quantity_()
		for (
			BucketPointerType current_ = target_bucket_ + 1;
			current_ - m_buckets_ <= bucket_quantity_ && ::DD::next(*current_) == *target_bucket_;
			++current_
		) {
			*current_ = *target_bucket_;
		}
	}


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT_>
	Iterator quick_emplace(ArgumentsT_... arguments___) {
		ValueType value_(::DD::forward<ArgumentsT_>(arguments___)...);
		BucketPointerType target_bucket_ = find_bucket_(value_);
		*target_bucket_ = get_storage_().insert_after(*target_bucket_, ::DD::move(value_));
		fix_after_insertion_(target_bucket_);
		return *target_bucket_;
	}


	public:
	template <typename... ArgumentsT_>
	Iterator emplace(ArgumentsT_... arguments___) {
		if (get_length() >= get_bucket_quantity_()) {
			reserve();
		}
		quick_emplace(::DD::forward<ArgumentsT_>(arguments___)...);
	}
#	else
#	endif


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
