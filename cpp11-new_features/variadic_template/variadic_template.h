//
// Created by sen on 9/2/20.
//

#ifndef CPP_NOTES_VARIADIC_TEMPLATE_H
#define CPP_NOTES_VARIADIC_TEMPLATE_H

#include <iostream>
#include <bitset>

void print() {

}

template <typename T, typename... Types>
void print(const T& firstArgs, const Types&... args) {
    std::cout << firstArgs << std::endl;        // print first argument
    print(args...);                             // call print() for remaining arguments
}

#endif //CPP_NOTES_VARIADIC_TEMPLATE_H
