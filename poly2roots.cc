/*
 * compile with GNU compiler collection 3.6.+:
 * g++ -o poly2roots poly2roots.cc
 */

#include <string>
#include <iostream>
#include <math.h>

//use c++14 lambda with capture by value

int main(int argc, char *argv[]) {
    // print warning and usage help if not enough arguments given
    if(argc < 4) {
        std::cout << "run " << argv[0] << " with 3 line options: a, b and c" << std::endl;
        std::cout << "e.g." << std::endl;
        std::cout << argv[0] << " 1 -5 6" << std::endl;
        return -1;
    }
    double a, b, c;
    double discriminant, root_discriminant, x1, x2;
    // convert lineopts string arguments to doubles
    a = std::stod(argv[1]);
    b = std::stod(argv[2]);
    c = std::stod(argv[3]);
    // find discriminant
    discriminant = b * b - 4 * a * c;
    std::cout << "equation  " << std::endl << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
    // compare it with zero
    if(discriminant < 0.0) { // no roots
        std::cout << "has no roots" << std::endl;
    } else if(discriminant == 0.0) { // 2-multiple root
        x1 = -b / (2.0 * a);
        std::cout << "has 2-multiple root x = " << x1 << std::endl;
    } else {
        root_discriminant = sqrt(discriminant);
        x1 = (-b + root_discriminant) / (2.0 * a);
        x2 = (-b - root_discriminant) / (2.0 * a);
        std::cout << "has roots x1 = " << x1 << " and x2 = " << x2 << std::endl;
    }
    return 0;
}
