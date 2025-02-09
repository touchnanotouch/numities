#include <iostream>

#include "headers/core/Vector.h"


int main() {
    Vector<double> vec1(10);
    Vector<double> vec2(10);

    vec1[0] = 27.0;
    vec2[5] = 56.0;

    std::cout << vec1;
    std::cout << vec2;

    vec1.set_vec(vec2.vec(), vec2.row_c());

    std::cout << vec1;

    return 0;
}
