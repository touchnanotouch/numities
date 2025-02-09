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
        }

        ~Vector(

        ) {
            delete[] _vec;
        }

        friend std::ostream& operator<<(
            std::ostream& out,
            const Vector& vector
        ) {
            for (size_t i = 0; i < vector._rows; i++) {
                out << vector._vec[i] << "\n";
            }
            out << std::endl;

            return out;
        }

        size_t row_c(

        ) const;

        T* vec(

        ) const;

        bool set_row_c(
            size_t row_c
        );

        bool set_vec(
            T* vec,
            size_t row_c
        );

        T& operator[](
            size_t i
        ) const;
};
