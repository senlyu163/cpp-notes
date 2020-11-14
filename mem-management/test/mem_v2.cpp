//
// Created by sen on 11/14/20.
//
#include <iostream>
#include "../src/mem_pool_v2.h"

int main() {
    std::cout << sizeof(Airplane) << std::endl;
    size_t const N = 100;
    Airplane *p[N];

    for (int i = 0; i < N; ++i) {
        p[i] = new Airplane;
    }

    p[1]->set(1000, 'A');
    p[5]->set(2000, 'B');
    p[9]->set(500000, 'C');

    for (int i = 0; i < 10; ++i) {
        std::cout << p[i] << std::endl;
    }

    for (int i = 0; i < N; ++i) {
        delete p[i];
    }
    return 0;
}
