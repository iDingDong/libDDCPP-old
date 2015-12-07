//	DDCPP/math/bits/DD_Matrix.hpp
#ifndef DD_MATRIX_HPP_INCLUDED_
#	define DD_MATRIX_HPP_INCLUDED_



#	include "DD_math_definitions.hpp"
#	include "../../standard/bits/DD_Array.hpp"



DD_DETAIL_BEGIN_
template <typename ValueT_, LengthType rows_c_, LengthType columns_c_>
struct Matrix;



template <typename ValueT_, LengthType columns_c_>
struct MatrixAccessProxy_ {
	public:
	DD_ALIAS(ThisType, MatrixAccessProxy_);
	DD_VALUE_TYPE_NESTED(ValueT_);
	static LengthType DD_CONSTANT columns = columns_c_;

	public:
	DD_ALIAS(StorageType, Array<ValueType DD_COMMA columns_c_>);
	DD_ALIAS(StorageConstType, StorageType const);
	DD_ALIAS(StorageReferenceType, StorageType&);
	DD_ALIAS(StorageConstReferenceType, StorageType const&);


	public:
	template <typename ValueT__, LengthType rows_c__, LengthType columns_c__>
	friend struct Matrix;


	private:
	StorageReferenceType m_row_;


	private:
	DD_DELETE_DEFAULT_CONSTRUCTOR(MatrixAccessProxy_);

#	if __cplusplus >= 201103L
	private:
	constexpr MatrixAccessProxy_(ThisType const& origin_) = default;

	private:
	constexpr MatrixAccessProxy_(ThisType&& origin_) = default;

#	endif
	private:
	DD_CONSTEXPR MatrixAccessProxy_(StorageReferenceType row_) noexcept : m_row_(row_) {
	}


	private:
	DD_DELETE_ALL_ASSIGNMENTS(MatrixAccessProxy_)


	public:
	ReferenceType operator [](LengthType column_) DD_NOEXCEPT {
		return m_row_[column_];
	}


};



template <typename ValueT_, LengthType columns_c_>
struct ConstMatrixAccessProxy_ {
	public:
	DD_ALIAS(ThisType, ConstMatrixAccessProxy_);
	DD_VALUE_TYPE_NESTED(ValueT_);
	static LengthType DD_CONSTANT columns = columns_c_;

	public:
	DD_ALIAS(StorageType, Array<ValueType DD_COMMA columns_c_>);
	DD_ALIAS(StorageConstType, StorageType const);
	DD_ALIAS(StorageReferenceType, StorageType&);
	DD_ALIAS(StorageConstReferenceType, StorageType const&);


	public:
	template <typename ValueT__, LengthType rows_c__, LengthType columns_c__>
	friend struct Matrix;


	private:
	StorageConstReferenceType m_row_;


	private:
	DD_DELETE_DEFAULT_CONSTRUCTOR(ConstMatrixAccessProxy_);

#	if __cplusplus >= 201103L
	private:
	constexpr ConstMatrixAccessProxy_(ThisType const& origin_) = default;

	private:
	constexpr ConstMatrixAccessProxy_(ThisType&& origin_) = default;

#	endif
	private:
	DD_CONSTEXPR ConstMatrixAccessProxy_(StorageConstReferenceType row_) noexcept : m_row_(row_) {
	}


	private:
	DD_DELETE_ALL_ASSIGNMENTS(ConstMatrixAccessProxy_)


	public:
	ConstReferenceType DD_CONSTEXPR operator [](LengthType column_) const DD_NOEXCEPT {
		return m_row_[column_];
	}


};



template <typename ValueT_, LengthType rows_c_, LengthType columns_c_>
struct Matrix {
	public:
	DD_ALIAS(ThisType, Matrix<ValueT_ DD_COMMA rows_c_ DD_COMMA columns_c_>);
	DD_VALUE_TYPE_NESTED(ValueT_)
	static LengthType DD_CONSTANT rows = rows_c_;
	static LengthType DD_CONSTANT columns = columns_c_;

	public:
#	if __cplusplus >= 201103L
	using StorageType = Array<ValueType, rows, columns>;
#	else
	typedef Array<ValueType, rows, Array<ValueType, columns> > StorageType;
#	endif
	DD_ALIAS(StorageConstType, StorageType const);
	DD_ALIAS(StorageReferenceType, StorageType&);
	DD_ALIAS(StorageConstReferenceType, StorageType const&);


	private:
	StorageType m_storage_;


	public:
	StorageReferenceType get_storage() DD_NOEXCEPT {
		return m_storage_;
	}

	public:
	StorageConstReferenceType get_storage() const DD_NOEXCEPT {
		return m_storage_;
	}


	public:
	MatrixAccessProxy_<ValueT_, columns_c_> operator [](LengthType row_) DD_NOEXCEPT {
		return MatrixAccessProxy_<ValueT_, columns_c_>(get_storage()[row_]);
	}

	public:
	ConstMatrixAccessProxy_<ValueT_, columns_c_> DD_CONSTEXPR operator [](LengthType row_) const DD_NOEXCEPT {
		return MatrixAccessProxy_<ValueT_, columns_c_>(get_storage()[row_]);
	}


};



DD_DETAIL_END_



DD_BEGIN_



DD_END_



#endif
