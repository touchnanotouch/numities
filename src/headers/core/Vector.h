#pragma once

#include <iostream>


template<typename T>
class Vector {
    private:
        size_t _rows;
        T* _vec;
    public:
        Vector(
            size_t row_c
        ) : _rows(row_c) {
            _vec = new T[_rows];
            for (size_t i = 0; i < _rows; i++) {
                _vec[i] = 0.0;
            }
        };

        Vector(
            size_t row_c,
            T* vec
        ) : _rows(row_c) {
            _vec = new T[_rows];
            for (size_t i = 0; i < _rows; i++) {
                _vec[i] = vec[i];
            }
        };

        ~Vector(

        ) {
            delete[] _vec;
        };

        friend std::ostream& operator<<(
            std::ostream& out,
            const Vector& vector
            ) {
            out << "\n";
            for (size_t i = 0; i < vector._rows; i++) {
                if (i < vector._rows - 1) {
                    out << vector._vec[i] << "\n";
                }
                else {
                    out << vector._vec[i];
                }
            }

            return out;
        };

        size_t row_c(

        ) const;

        T* vec(

        ) const;

        Vector copy(

        ) const;

        bool set_row_c(
            size_t row_c
        );

        bool set_vec(
            size_t row_c,
            T* vec
        );

        bool set_vec(
            size_t row_c,
            std::string file_path,
            const char delimiter = ' '
        );

        T& operator[](
            size_t index
        ) const;

        bool operator==(
            const Vector& other
        ) const;

        Vector operator+(
            const Vector& other
        ) const;

        Vector operator+(
            const T& scalar
        ) const;

        Vector operator+=(
            const Vector& other
        ) const;

        Vector operator+=(
            const T& scalar
        ) const;

        Vector operator-(
            const Vector& other
        ) const;

        Vector operator-(
            const T& scalar
        ) const;

        Vector operator-=(
            const Vector& other
        ) const;

        Vector operator-=(
            const T& scalar
        ) const;

        Vector operator*(
            const T& scalar
        ) const;
        
        Vector operator*=(
            const T& scalar
        ) const;

        Vector operator/(
            const T& scalar
        ) const;
        
        Vector operator/=(
            const T& scalar
        ) const;

        T dot(
            const Vector& other
        ) const;

        double norm(
            int p = 1
        ) const;

        void normalize(

        );

        Vector normalized(

        ) const;
};
