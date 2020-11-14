//
// Created by sen on 11/10/20.
//
#include "../src/mem_pool_v1.h"
#include <iostream>

int main() {
    std::cout << sizeof(Screen) << std::endl;

    size_t const N = 100;
    Screen *p[N];

    for (size_t i = 0; i < N; ++i) {
        p[i] = new Screen(i);
    }

    for (size_t i = 0; i < 10; ++i) {
        std::cout << p[i] << std::endl;
    }

    for (size_t i = 0; i < N; ++i) {
        delete p[i];
    }
    return 0;
}
