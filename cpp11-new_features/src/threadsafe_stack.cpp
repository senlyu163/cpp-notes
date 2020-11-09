//
// Created by sen on 10/29/20.
//

#include "threadsafe_stack.h"

template<typename T>
void threadsafe_stack<T>::pop(T &value) {
    std::lock_guard<std::mutex> lock(m);
    if (data.empty()) throw empty_stack();

    value = data.top();
    data.pop();
}

template<typename T>
void threadsafe_stack<T>::push(T new_value) {
    std::lock_guard<std::mutex> lock(m);
    data.push(new_value);
}

template<typename T>
std::shared_ptr<T> threadsafe_stack<T>::pop() {
    std::lock_guard<std::mutex> lock(m);
    if (data.empty()) throw empty_stack();

    std::shared_ptr<T> const res(std::make_shared<T>(data.top()));  // before modify stack, align return value
    data.pop();
    return res;
}

template<typename T>
bool threadsafe_stack<T>::empty() const {
    std::lock_guard<std::mutex> lock(m);
    return data.empty();
}


#include <vector>

//namespace func_template {
//
//#include <iostream>
//
//#include <bits/move.h>
//
//#define SIZE 10
//
//    template<typename T>
//    void output_static_data(const T &obj) {
//        std::cout << obj << std::endl;
//    }
//
//    template<typename Container>
//    void test_moveable(Container c) {
//        typedef typename ::std::iterator_traits<typename Container::iterator>::value_type Valtype;
//        for (long i = 0; i < SIZE; ++i) {
//            c.insert(c.end(), Valtype());
//        }
//
//        output_static_data(*(c.begin()));
//        Container c1(c);
//        Container c2(::std::move(c));
//        c1.swap(c2);
//    }
//
//    ::std::vector<int>::iterator::value_type a = 4.2;
//
////    test_moveable (::std::vector<int>());
//}


