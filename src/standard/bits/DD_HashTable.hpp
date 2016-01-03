//	DDCPP/standard/bits/DD_HashTable.hpp
#ifndef DD_HASH_TABLE_HPP_INCLUDED_
#	define DD_HASH_TABLE_HPP_INCLUDED_ 1



#	include "DD_IteratorNested.hpp"
#	include "DD_HashOf.hpp"
#	include "DD_EqualTo.hpp"
#	include "DD_Allocator.hpp"
#	include "DD_get_length.hpp"
#	include "DD_Array.hpp"
#	include "DD_UndirectionalList.hpp"
#	include "DD_fill_length.hpp"
#	include "DD_fill_construct_length.hpp"



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
struct HashTable : protected Agent<HasherT_>, protected Agent<EqualityPredicateT_> {
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
	DD_ALIAS(ListType_, UndirectionalList<ValueType DD_COMMA AllocatorType>);
	DD_SPECIFIC_TYPE_NESTED(Storage, ListType_);
	DD_SPECIFIC_TYPE_NESTED(Node, typename StorageType::NodeType);
	DD_ALIAS(NonConstIterator_, typename StorageType::Iterator);
	DD_SPECIFIC_TYPE_NESTED(Bucket, NonConstIterator_);

	public:
	DD_ALIAS(Iterator, typename StorageType::ConstIterator);
	DD_ALIAS(ConstIterator, Iterator);


	public:
	template <typename ValueT__, typename HasherT__, typename EqualityPredicateT__, typename AllocatorT__>
	friend struct HashTable;


	private:
	StorageType m_storage_;
	LengthType m_length_;
	LengthType m_growth_progress_;
	BucketPointerType m_buckets_;


	public:
	DD_CONSTEXPR HashTable() DD_NOEXCEPT_AS(StorageType()) : m_length_(), m_growth_progress_(), m_buckets_() {
	}

	public:
	HashTable(ThisType const& origin_) :
		m_storage_(origin_.get_storage_()),
		m_length_(origin_.get_length())
	{
		clone_buckets_(origin_);
	}

	public:
	HashTable(ThisType&& origin_) DD_NOEXCEPT_AS(StorageType(::DD::move(origin_.get_storage_()))) :
		m_storage_(::DD::move(origin_.get_storage_())),
		m_length_(origin_.get_length()),
		m_growth_progress_(origin_.get_growth_progress_()),
		m_buckets_(origin_.get_buckets_())
	{
		*m_buckets_ = get_storage_().before_begin();
		origin_.m_buckets_ = BucketPointerType();
	}


	public:
	~HashTable() {
		destruct_();
	}


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
	static LengthType DD_CONSTEXPR get_quantity_of_(LengthType length_index_) DD_NOEXCEPT {
		return (DDCPP_HASH_TABLE_CHART)[length_index_];
	}


	private:
	LengthType DD_CONSTEXPR get_growth_index_() const DD_NOEXCEPT {
		return m_growth_progress_;
	}


	private:
	LengthType DD_CONSTEXPR get_bucket_quantity_() const DD_NOEXCEPT {
		return get_quantity_of_(get_growth_index_());
	}


	public:
	LengthType DD_CONSTEXPR get_length() DD_NOEXCEPT {
		return m_length_;
	}


	public:
	AllocatorType& get_allocator() DD_NOEXCEPT {
		return get_storage_().get_allocator();
	}


	public:
	HashValueType hash(ValueType const& value_) {
		return HashAgent::get_instance()(value_);
	}


	private:
	LengthType find_bucket_offset_implement_(LengthType bucket_quantity_, ValueType const& value_) const {
		return hash(value_) % bucket_quantity_;
	}


	private:
	LengthType find_bucket_offset_(ValueType const& value_) const {
		return find_bucket_offset_implement_(get_bucket_quantity_(), value_);
	}


	private:
	LengthType find_bucket_implement_(BucketPointerType buckets_, LengthType bucket_quantity_, ValueType const& value_) {
		return buckets_ + find_bucket_offset_implement_(bucket_quantity_, value_);
	}


	private:
	BucketPointerType find_bucket_(ValueType const& value_) const {
		return find_bucket_implement_(get_buckets_(), get_bucket_quantity_(), value_);
	}


	private:
	Range<NonConstIterator_> get_bucket_range_(BucketPointerType target_bucket_) const {
		return Range<ConstIterator>(
			*target_bucket_,
			target_bucket_ - get_buckets_() == get_bucket_quantity_() - 1 ? *get_buckets_() : *(target_bucket_ + 1)
		);
	}


	public:
	NonConstIterator_ find_(ValueType const& value_) const {
		Range<NonConstIterator_> range_ = get_bucket_range_(find_bucket_(value_));
		NonConstIterator_ result_ = ::DD::find(range_, value_, CompareAgent::get_instance());
		return result_ == range_.end() ? *get_buckets_() : result_;
	}


	public:
	Iterator find(ValueType const& value_) const {
		return find_(value_);
	}


	private:
	template <typename AllocatorT__>
	ProcessType clone_buckets_(HashTable<ValueType, HasherType, EqualityPredicateType, AllocatorT__> const& origin_) {
		m_growth_progress_ = origin_.get_growth_progress();
		LengthType bucket_quantity_ = get_bucket_quantity_();
		m_buckets_ = get_allocator().AllocatorType::Basic::allocate(sizeof(BucketType) * bucket_quantity_);
		try {
			typename HashTable<
				ValueType, HasherType, EqualityPredicateType, AllocatorT__
			>::BucketType current_origin_ = origin_.get_storage().before_begin();
			BucketType current_ = get_storage_().before_begin();
			for (LengthType index_ = LengthType(); index_ < bucket_quantity_; ++index_) {
				try {
					while (current_origin_ != *(origin_.get_buckets_() + index_)) {
						++current_origin_;
						++current_;
					}
					::DD::construct(get_buckets_() + index_, current_);
				} catch (...) {
					::DD::destruct(get_buckets_(), get_buckets_() + index_);
					throw;
				}
			}
		} catch (...) {
			get_allocator().AllocatorType::Basic::deallocate(get_buckets_(), sizeof(BucketType) * bucket_quantity_);
			throw;
		}
	}


	public:
	static ProcessType fix_after_insertion_implement_(
		BucketPointerType buckets_end_,
		BucketPointerType target_bucket_
	) DD_NOEXCEPT {
		for (
			BucketPointerType current_ = target_bucket_ + 1;
			current_ != buckets_end_ && *current_ == *target_bucket_;
			++current_
		) {
			++*current_;
		}
	}


	public:
	ProcessType fix_after_insertion_(BucketPointerType target_bucket_) DD_NOEXCEPT {
		fix_after_insertion_implement_(get_buckets_() + get_bucket_quantity_(), target_bucket_);
	}


	private:
	ProcessType stretch_to_(LengthType length_index_) {
		LengthType new_growth_progress_ = get_quantity_of_(length_index_);
		BucketPointerType new_buckets_ = static_cast<BucketPointerType>(
			get_allocator().AllocatorType::Basic::allocate(sizeof(BucketType) * (new_growth_progress_ + 1))
		);
		try {
			::DD::fill_construct_length(new_buckets_, new_growth_progress_, get_storage_().before_begin());
			try {
				for (NonConstIterator_ current__ = get_storage_().before_begin(); ::DD::next(current__) != get_storage_().end(); ) {
					BucketPointerType target_bucket_ = find_bucket_implement_(
						new_buckets_, new_growth_progress_, *::DD::next(current__)
					);
					get_storage_().transfer_after(current__++, *target_bucket_);
					fix_after_insertion_implement_(new_buckets_ + new_growth_progress_, target_bucket_);
				}
			} catch (...) {
				::DD::destruct(new_buckets_, new_buckets_ + new_growth_progress_);
				reset();
				throw;
			}
		} catch (...) {
			get_allocator().AllocatorType::Basic::deallocate(new_buckets_, sizeof(BucketType) * (new_growth_progress_ + 1));
			throw;
		}
		destruct_();
		m_buckets_ = new_buckets_;
		m_growth_progress_ = length_index_;
	}


	public:
	ProcessType reserve() {
		LengthType new_progress_ = get_bucket_quantity_() + 1;
		if (new_progress_ < ::DD::get_length(DDCPP_HASH_TABLE_CHART)) {
			stretch_to_(new_progress_);
		}
	}


#	if __cplusplus >= 201103L
	public:
	template <typename... ArgumentsT_>
	Iterator quick_emplace(ArgumentsT_... arguments___) {
		ValueType value_(::DD::forward<ArgumentsT_>(arguments___)...);
		BucketPointerType target_bucket_ = find_bucket_(value_);
		get_storage_().insert_after(*target_bucket_, ::DD::move(value_));
		++m_length_;
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


	public:
	ProcessType clear() DD_NOEXCEPT {
		get_storage_().clear();
		::DD::fill_length(get_buckets_(), get_bucket_quantity_(), get_storage_().before_begin());
	}


	public:
	ProcessType reset() DD_NOEXCEPT {
		get_storage_().clear();
		destruct_();
		m_buckets_ = BucketPointerType();
		m_growth_progress_ = LengthType();
		m_length_ = LengthType();
	}


	private:
	ProcessType destruct_() DD_NOEXCEPT {
		LengthType bucket_quantity_ = get_bucket_quantity_();
		::DD::destruct(get_buckets_(), get_buckets_() + bucket_quantity_);
		get_allocator().AllocatorType::Basic::deallocate(get_buckets_(), sizeof(BucketType) * bucket_quantity_);
	}


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
