//
// Created by sen on 11/3/20.
//
#include "print_tuple.h"
#include <bitset>
#include <string>

int main () {
    // overload operator<< to implement following function
    std::cout << std::make_tuple(7, std::bitset<16>(444), "make tuple", 2.2) << std::endl;

    auto ttt = std::tuple<int, float, char, std::string, std::string>(1, 1.2, 'c', "aaaaaaaaaaaaaaaaaaaaaaaaa", "ccc");
    std::cout << sizeof(std::string) << std::endl;
    std::cout << sizeof(ttt) << std::endl;
    std::cout << std::get<0>(ttt) << std::endl;
    std::cout << std::get<1>(ttt) << std::endl;
    return 0;
}



