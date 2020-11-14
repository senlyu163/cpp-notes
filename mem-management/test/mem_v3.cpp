//
// Created by sen on 11/14/20.
//
#include "../src/mem_pool_v3.h"
#include <iostream>
#include <string>

class Foo {
public:
    long L;
    std::string str;
    static allocator myAlloc;

public:
    Foo(long l) : L(l) {}

    static void *operator new(size_t size) {
        return myAlloc.allocate(size);
    }

    static void operator delete(void *pdead, size_t size) {
        return myAlloc.deallocate(pdead, size);
    }
};

allocator Foo::myAlloc;

int main() {

    Foo *p[100];

    std::cout << "sizeof(Foo)=" << sizeof(Foo) << std::endl;
    for (int i = 0; i < 23; ++i) {
        p[i] = new Foo(i);
        std::cout << p[i] << ' ' << p[i]->L << std::endl;
    }

    for (int i = 0; i < 23; ++i) {
        delete p[i];
    }

    return 0;
}
