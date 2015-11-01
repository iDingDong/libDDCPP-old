//	DDCPP/standard/bits/DD_next_permutation.hpp
#ifndef DD_NEXT_PERMUTATION_HPP_INCLUDED_
#	define DD_NEXT_PERMUTATION_HPP_INCLUDED_ 1



#	include "DD_previous.hpp"
#	include "DD_reverse.hpp"



DD_DETAIL_BEGIN_
template <ValidityType is_free_access_iterator_c_>
struct NextPermutation_ {
	template <typename BidirectionalIteratorT_>
	ValidityType next_permutation(
		BidirectionalIteratorT_ const& begin__,
		BidirectionalIteratorT_ const& end__
	) {
		if (begin__ != end__) {
			BidirectionalIteratorT_ back__ = previous(end__);
			if (begin__ != back__) {
				BidirectionalIteratorT_ current__;
				BidirectionalIteratorT_ head__;
				do {
					current__ = back__;
					if (*current__-- < *back__) {
						head__ = end__;
						do {
							--head__;
						} while (!(*current__ < *head__));
						swap_target(current__, head__);
						reverse(back__, end__);
						return true;
					}
				} while (current__ != begin__);
				reverse(begin__, end__);
			}
		}
		return false;
	}


};



template <typename BidirectionalIteratorT_>
ValidityType next_permutation(
	BidirectionalIteratorT_ const& begin__,
	BidirectionalIteratorT_ const& end__
) DD_NOEXCEPT_AS(static_cast<ValidityType>(
	NextPermutation_<IsFreeAccessIterator<BidirectionalIteratorT_>::value>::next_permutation(begin__ DD_COMMA end__)
)) {
	return NextPermutation_<IsFreeAccessIterator<BidirectionalIteratorT_>::value>::next_permutation(begin__, end__);
}



DD_DETAIL_END_



DD_BEGIN_
using detail_::next_permutation;



DD_END_



#endif
