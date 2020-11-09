//
// Created by sen on 11/3/20.
//

#ifndef CPP_NOTES_PRINT_TUPLE_H
#define CPP_NOTES_PRINT_TUPLE_H

#include <iostream>
#include <tuple>


/**
 * boost: util/printtuple.hpp
 * helper: print element with index IDX of tuple with MAX elements
 * */
template<int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
    static void print(std::ostream &os, const std::tuple<Args...> &t) {
        os << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ", ");
        PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
    }
};

// partial specialization to end the recursion
template<int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
    static void print(std::ostream &os, const std::tuple<Args...> t) {

    }
};

// output operatorsofr tuples
template<typename... Args>
std::ostream &operator<<(std::ostream &os, const std::tuple<Args...> &t) {
    os << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
    return os << "]";
}

#endif //CPP_NOTES_PRINT_TUPLE_H



