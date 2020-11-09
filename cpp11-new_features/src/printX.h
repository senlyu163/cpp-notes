//
// Created by sen on 9/2/20.
//

#ifndef CPP_NOTES_VARIADIC_TEMPLATE_H
#define CPP_NOTES_VARIADIC_TEMPLATE_H

#include <iostream>

void printX() {}

template<typename T, typename... Types>
void printX(T first, const Types&... args) {
    std::cout << first << std::endl;
    printX(args...);
}

// never be executed.
template<typename... Types>
void printX(const Types&... args) {
    printX(args...);
}

/**
 *
 * if void printX(T first, const Type&... args) and void printX(const Type&... args) exist at the same time,
 * the latter is never be executed.
 * Cause the former is special version, if both exist, the general version is never called by compiler.
 *
 * */

// ===== end =====

#endif //CPP_NOTES_VARIADIC_TEMPLATE_H
