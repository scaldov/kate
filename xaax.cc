/*
 * compile with GNU compiler collection 4.7.+:
 * g++ -std=c++14 -o xaax xaax.cc
 */

#include <string>
#include <iostream>

//use c++14 lambda with capture by value
auto Fn = [=](auto x, auto a){return x / a + a / x;};

int main(int argc, char *argv[]) {
    std::cout << argc << std::endl;
    // print warning and usage help if not enough arguments given
    if(argc < 3) {
        std::cout << "run " << argv[0] << " with 2 line options: x and a" << std::endl;
        std::cout << "e.g." << std::endl;
        std::cout << argv[0] << " 1 2" << std::endl;
        return -1;
    }
    double x, a;
    // convert lineopts string arguments to doubles
    x = std::stod(argv[1]);
    a = std::stod(argv[2]);
    // call lambda function with auto deducing return type
    auto f = Fn(x, a);
    std::cout << "f(" << x << "," << a << ") = " << f << std::endl;
    return 0;
}
