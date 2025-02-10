#include <iostream>

#include "headers/core/Vector.h"


int main() {
    double arr[3] = {3, -4, 2};

    Vector<double> vec(3, arr);
    //vec.set_vec("../../../../github/numities/src/test.txt");

    std::cout << vec << std::endl;
    std::cout << vec.normalized() << std::endl;

    return 0;
}
