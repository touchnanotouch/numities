#pragma once

#include <iostream>


template<typename T>
class Matrix {
    private:
        size_t _rows;
        size_t _cols;
        T** _mat;
    public:
        Matrix(
            size_t row_c,
            size_t col_c
        ) : _rows(row_c), _cols(col_c) {
            _mat = new T*[_rows];
            for (size_t i = 0; i < _rows; i++) {
                _mat[i] = new T[_cols];
                for (size_t j = 0; j < _cols; j++) {
                    _mat[i][j] = 0;
                }
            }
        };

        Matrix(
            size_t row_c,
            size_t col_c,
            T** mat
        ) : _rows(row_c), _cols(col_c) {
            _mat = new T * [_rows];
            for (size_t i = 0; i < _rows; i++) {
                _mat[i] = new T[_cols];
                for (size_t j = 0; j < _cols; j++) {
                    _mat[i][j] = mat[i][j];
                }
            }
        };

        ~Matrix(

        ) {
            for (size_t i = 0; i < _rows; i++) {
                delete[] _mat[i];
            }

            delete[] _mat;
        };

        friend std::ostream& operator<<(
            std::ostream& out,
            const Matrix& matrix
        ) {
            out << "\n";
            for (size_t i = 0; i < matrix._rows; i++) {
                for (size_t j = 0; j < matrix._cols; j++) {
                    out << matrix._mat[i][j] << " ";
                }

                if (i < matrix._rows - 1) {
                    out << std::endl;
                }
            }

            return out;
        };

        size_t row_c(

        ) const;

        size_t col_c(

        ) const;

        T** mat(

        ) const;

        Matrix copy(

        ) const;

        bool set_row_c(
            size_t row_c
        );

        bool set_col_c(
            size_t col_c
        );

        bool set_mat(
            size_t row_c,
            size_t col_c,
            T** mat
        );

        bool set_mat(
            size_t row_c,
            size_t col_c,
            std::string file_path,
            const char delimiter = ' '
        );

        T*& operator[](
            size_t index
        ) const;

        bool operator==(
            const Matrix& other
        ) const;

        // Matrix operator+(
        //     const Matrix& other
        // ) const;

        // Matrix operator+(
        //     const T& scalar
        // ) const;

        // Matrix operator+=(
        //     const Matrix& other
        // ) const;

        // Matrix operator+=(
        //     const T& scalar
        // ) const;

        // Matrix operator-(
        //     const Matrix& other
        // ) const;

        // Matrix operator-(
        //     const T& scalar
        // ) const;

        // Matrix operator-=(
        //     const Matrix& other
        // ) const;

        // Matrix operator-=(
        //     const T& scalar
        // ) const;

        // Matrix operator*(
        //     const Matrix& other
        // ) const;

        // Matrix operator*(
        //     const T& scalar
        // ) const;

        // Matrix operator*=(
        //     const Matrix& other
        // ) const;

        // Matrix operator*=(
        //     const T& scalar
        // ) const;

        // Matrix operator/(
        //     const T& scalar
        // ) const;

        // Matrix operator/=(
        //     const T& scalar
        // ) const;
};
