//
// Created by sen on 11/1/20.
//

#include "./XCls.h"
#include <iostream>

template<typename T>
void output_static_data(T t) {
    std::cout << t << std::endl;
}

template<typename T, template<class> class Container>
XCls<T, Container>::XCls() {
    for (long i = 0; i < SIZE; ++i) {
        c.insert(c.end(), T());
    }

    output_static_data(T());
    Container<T> c1(c);
    Container<T> c2(std::move(c));
    c1.swap(c2);
}
