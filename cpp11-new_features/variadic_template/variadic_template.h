//
// Created by sen on 9/2/20.
//

#ifndef CPP_NOTES_VARIADIC_TEMPLATE_H
#define CPP_NOTES_VARIADIC_TEMPLATE_H

#include <iostream>
#include <bitset>
#include <string>

// ===== begin =====
void print() {

}

template <typename T, typename... Types>
void print(const T& firstArgs, const Types&... args) {
    std::cout << firstArgs << std::endl;        // print first argument
    print(args...);                             // call print() for remaining arguments
}
// ===== end =====



// ===== begin =====

//template <typename... Values> class tuple;
//template <> class tuple<>{};
//
//template <typename Head, typename... Tail>
//class tuple<Head, Tail...> : private tuple<Tail...> {
//    typedef tuple<Tail...> inherited;
//public:
//    tuple(){}
//    tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {
//        // here is initialization list
//    }
//
//    typename Head::type head() {
//        return m_head;
//    }
//
//    inherited& tail() {
//        return *this;
//    }
//
//protected:
//    Head m_head;
//};

// ===== end =====

#endif //CPP_NOTES_VARIADIC_TEMPLATE_H
