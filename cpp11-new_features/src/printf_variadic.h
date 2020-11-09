//
// Created by sen on 11/3/20.
//

#ifndef CPP_NOTES_PRINTF_VARIADIC_H
#define CPP_NOTES_PRINTF_VARIADIC_H

#include <iostream>

void printff(const char* s) {
    while (*s) {
        if (*s == '%' && *(++s) != '%') {
            throw std::runtime_error("invalid format string: missing argument");
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void printff(const char* s, T value, const Args... args) {
    while (*s) {
        if (*s == '%' && *(++s) != '%') {
            std::cout << value;
            printff(++s, args...);  // call even when *s == 0 to detect extra arguments
            return;
        }
        std::cout << *s++;
    }
    throw std::logic_error("extra arguments provided to printf");
}

#endif //CPP_NOTES_PRINTF_VARIADIC_H
